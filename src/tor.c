#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "init.h"

void usage() {
    printf("Usage: tor init|plan|apply|destroy [project_dir]\n");
    printf("       project_dir is the directory where your tor configuration is\n");
    printf("       If omitted, default project_dir is .\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    char* proj_dir = ".";
    char* cmd = "";
    
    if (argc < 2 || argc > 3) {
        usage();
    }
    cmd = argv[1];
    if (argc == 3) { //project_dir was given
        proj_dir = argv[2];
    }
    if (strcmp(cmd,"init") == 0) {
        if (init_tor(proj_dir) != 0) {
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
        
    }
    else if (strcmp(cmd,"plan") == 0 || strcmp(cmd,"apply") == 0|| strcmp(cmd,"destroy") == 0) {
        printf("Not implemented yet\n");
        return EXIT_SUCCESS;
    }
    else {
        usage();
    }
}
