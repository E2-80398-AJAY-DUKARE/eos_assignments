// main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"


int main() {
    pid_t child_pids[6]; 
    int status;

    for (int i = 0; i < 6; ++i) {
        child_pids[i] = fork();

        if (child_pids[i] == 0) {
            char *source_files[] = {"circle.c", "square.c", "rectangle.c", "main.c", NULL};
            execlp("gcc", "gcc", "-c", source_files[i], NULL);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else if (child_pids[i] < 0) {
            perror("fork");
			sleep(3);
            exit(EXIT_FAILURE);
        }
    }

    
    for (int i = 0; i < 6; ++i) {
        waitpid(child_pids[i], &status, 0);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
            printf("Error: Compilation failed for one or more files.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Linking step
    pid_t link_pid = fork();

    if (link_pid == 0) {
        execlp("gcc", "gcc", "-o", "program.out", "circle.o", "square.o", "rectangle.o", "main.o", NULL);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else if (link_pid < 0) {
        perror("fork");
		sleep(3);
        exit(EXIT_FAILURE);
    }

    
    waitpid(link_pid, &status, 0);
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
        printf("Error: Linking failed.\n");
        exit(EXIT_FAILURE);
    }

    pid_t run_pid = fork();

    if (run_pid == 0) {
        execlp("./program.out", "./program.out", NULL);
        perror("execvp");
		sleep(3);
        exit(EXIT_FAILURE);
    } else if (run_pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    
    waitpid(run_pid, &status, 0);
    if (!WIFEXITED(status)) {
        printf("Error: Child process did not terminate normally.\n");
        exit(EXIT_FAILURE);
    }

    printf("Child exit status: %d\n", WEXITSTATUS(status));

    return 0;
}
