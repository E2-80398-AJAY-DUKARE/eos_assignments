#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>


struct msg_buffer {
    long msg_type;
    int num1;
    int num2;
};

int main() {
    key_t key;
    int msgid;
    pid_t child_pid;
    int status;
    
    // Generate a unique key for the message queue
    key = ftok("parent_child_communication", 'A');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Create a message queue
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Child process

        // Message buffer for sending data
        struct msg_buffer msg_send;

        // Set the message type
        msg_send.msg_type = 1;

        // Child process sends two numbers to the parent
        msg_send.num1 = 10;
        msg_send.num2 = 20;

        // Send the message
        if (msgsnd(msgid, &msg_send, sizeof(struct msg_buffer), 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        // Exit after sending the message
        exit(EXIT_SUCCESS);
    } else {
        // Parent process

        // Message buffer for receiving data
        struct msg_buffer msg_receive;

        // Wait for the child to complete
        waitpid(child_pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            // Child process successfully sent the message

            // Receive the message from the child
            if (msgrcv(msgid, &msg_receive, sizeof(struct msg_buffer), 1, 0) == -1) {
                perror("msgrcv");
                exit(EXIT_FAILURE);
            }

            // Calculate the sum
            int sum = msg_receive.num1 + msg_receive.num2;

            // Print the result
            printf("Sum received from child: %d\n", sum);
        } else {

            fprintf(stderr, "Child process failed to send the message.\n");
        }

        
        if (msgctl(msgid, IPC_RMID, NULL) == -1) {
            perror("msgctl");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
