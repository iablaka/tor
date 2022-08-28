#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ftw.h>
#include <sys/types.h>
#include <fts.h>

int unlink_cb(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
        int rv = remove(fpath);
        if (rv) {
                perror(fpath);
        }
        return rv;
}

int rmdir(char *path)
{
        return nftw(path, unlink_cb, 64, FTW_DEPTH | FTW_PHYS);
}

int mkdir_tor(char *path)
{
        struct stat sb;
        //if path is a dir and is accessible
        if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)) {
                //if .tor folder already exists, we get rid of it
                char* tor_path = strcat(path, "/.tor");
                if (stat(tor_path, &sb) == 0 && S_ISDIR(sb.st_mode)) { 
                        if(rmdir(tor_path) != 0) {
                                printf("ERROR: Something went wrong when removing existing .tor folder and its content\n");
                                return EXIT_FAILURE;
                        }
                        
                }
                if (mkdir(tor_path, S_IRWXU) == 0) {
                        char* providers_path = strcat(tor_path, "/providers");
                        if (mkdir(providers_path, S_IRWXU) != 0) {
                                printf("ERROR: Could not create %s directory\n", providers_path);
                                return EXIT_FAILURE;        
                        }
                }
                else {
                        printf("ERROR: Could not create %s directory\n", tor_path);
                        return EXIT_FAILURE; 
                }
                
        }
        else {
                printf("ERROR: Could not access %s or %s is not a directory\n", path, path);
                return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
}

// int list_providers(char *path, providers)
// {
//         //returns -1 in case of an error or the number of providers
//         return 0;

// }

int init_tor(char *path)
{
        //char *providers[16]; //There cannot more than 16 providers in a project so far!

        if (mkdir_tor(path) != 0) {
                return EXIT_FAILURE;
        }
        // if (list_providers(path, *providers) < 0) {
        //         return EXIT_FAILURE;
        // }
        return EXIT_SUCCESS;
}