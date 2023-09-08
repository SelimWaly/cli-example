#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

void clearScreen() {
    system("clear");
}

int main() {
    clearScreen();
    char currentDir[256];
    getcwd(currentDir, sizeof(currentDir));
    
    printf(" _______  __   __  _______  __   __  __   __  __   __  __   __  __   __  __   __  __   __  __   __\n");
    printf("|       ||  | |  ||       ||  | |  ||  | |  ||  | |  ||  | |  ||  | |  ||  | |  ||  | |  ||  | |  |\n");
    printf("|  _____||  |_|  ||    _  ||  |_|  ||  | |  ||  |_|  ||  |_|  ||  |_|  ||  |_|  ||  |_|  ||  | |  |\n");
    printf("| |_____ |       ||   |_| ||       ||  |_|  ||       ||       ||       ||       ||       ||  |_|  |\n");
    printf("|_____  ||       ||    ___||       ||       ||       ||       ||       ||       ||       ||       |\n");
    printf(" _____| ||   _   ||   |    |   _   | |     | |   _   ||   _   | |     | | |     | |     | |     |\n");
    printf("|_______||__| |__||___|    |__| |__|  |___|  |__| |__||__| |__|  |___|   |___|   |___|   |___|  \n");
    printf("(c) Copyright AUTHOR. All rights reserved.\n\n");

    while (1) {
        try {
            char command[256];
            if (strcmp(currentDir, "C:\\Users\\") == 0) {
                printf("%s@CLI ~ $ ", getenv("USERNAME"));
            } else {
                printf("%s@CLI %s $ ", getenv("USERNAME"), currentDir);
            }
            fgets(command, sizeof(command), stdin);

            if (command[0] == ' ' || strlen(command) == 0) {
                continue;
            } else if (strcmp(command, "cls\n") == 0 || strcmp(command, "clear\n") == 0) {
                clearScreen();
            } else if (strcmp(command, "license\n") == 0) {
                printf("\n[CLI]:
