
#include <stdio.h>

int main() {

    printf("Output of First fit \n");
    int nb, np;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);
    int blocks[nb];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < nb; i++) {
        scanf("%d", &blocks[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &np);
    int processes[np], allocation[np];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < np; i++) {
        scanf("%d", &processes[i]);
        allocation[i] = -1; // Initialize allocation as -1
    }

    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nb; j++) {
            if (blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    printf("Process\tSize\tBlock Allocated\n");
    for (int i = 0; i < np; i++) {
        printf("%d\t%d\t", i + 1, processes[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
