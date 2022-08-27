#include <stdio.h>
#include <stdlib.h>
#include "init.h"

void usage() {
    printf("Usage: tor [init|apply|destroy] <src_dir>\n");
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc !=3) {
        usage();
    }
    //printf("args = %s, %s\n", argv[1], argv[2]);
    mkdir_tor(argv[2]);
    return 0;
}
