#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Variable to store the process ID
    pid_t pid;

    // Loop to create 5 child processes
    for (int i = 1; i <= 5; i++) {
        pid = fork();

        // Check for fork failure
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        // Child process
        if (pid == 0) {
            // Child process runs for 5 seconds
            sleep(5);
            printf("Child %d with PID %d completed\n", i, getpid());
            exit(EXIT_SUCCESS);
        }
    }

    // Parent process
    // Wait for all child processes to complete
    for (int i = 1; i <= 5; i++) {
        int status;
        pid_t child_pid = wait(&status);

        if (WIFEXITED(status)) {
            printf("Parent: Child %d with PID %d exited with status %d\n", i, child_pid, WEXITSTATUS(status));
        } else {
            printf("Parent: Child %d with PID %d terminated abnormally\n", i, child_pid);
        }
    }

    printf("All child processes completed.\n");

    return 0;
}
