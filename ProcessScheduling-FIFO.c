
#include <stdio.h>

int main() {
    printf("Process Scheduling using FCFS Algorithm \n");
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst[n], wait[n], turnaround[n];
    float totalWait = 0, totalTurnaround = 0;

    printf("Enter burst times of the processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    wait[0] = 0;  // First process waiting time is 0
    for (i = 1; i < n; i++) {
        wait[i] = wait[i - 1] + burst[i - 1];
    }

    for (i = 0; i < n; i++) {
        turnaround[i] = wait[i] + burst[i];
        totalWait += wait[i];
        totalTurnaround += turnaround[i];
    }

    printf("Average Waiting Time: %.2f\n", totalWait / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaround / n);

    return 0;
}
