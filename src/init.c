#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ftw.h>

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

void mkdir_tor(char* path) {
    struct stat sb;
    //if path is a dir and is accessible
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        //if .tor folder already exists, we get rid of it
        char* tor_path = strcat(path, "/.tor");
        if (stat(tor_path, &sb) == 0 && S_ISDIR(sb.st_mode)) { 
            if(rmdir(tor_path) != 0) {
                printf("ERROR: Something went wrong when removing existing .tor folder and its content\n");
                exit(1);
            }
            
        }
        if (mkdir(tor_path, S_IRWXU) == 0) {
            char* providers_path = strcat(tor_path, "/providers");
            if (mkdir(providers_path, S_IRWXU) != 0) {
                printf("ERROR: Could not create %s directory\n", providers_path);
                exit(1);        
            }
        }
        else {
            printf("ERROR: Could not create %s directory\n", tor_path);
            exit(1); 
        }
        
    }
    else {
        printf("ERROR: Could not access %s or %s is not a directory\n", path, path);
        exit(1);
    }
}