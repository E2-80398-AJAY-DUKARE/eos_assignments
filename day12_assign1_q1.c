#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
    int sig_num, process_id;

    printf("Enter signal number: ");
    scanf("%d", &sig_num);

    printf("Enter the process id: ");
    scanf("%d", &process_id);


    if (kill(process_id, sig_num) == 0)
    {
        printf("Signal %d sent to process %d Successfully!\n", sig_num, process_id);
    }
    else{
        perror("Error sending singnal");
        _exit(0);
    }
    return 0;

}