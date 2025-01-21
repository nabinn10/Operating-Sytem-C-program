
#include <stdio.h>

int main() {
    printf("Process Scheduling using SJF Algorithm \n");
    int n, i, j, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst[n], wait[n], turnaround[n], process[n];
    float totalWait = 0, totalTurnaround = 0;

    printf("Enter burst times of the processes:\n");
    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    // Sort processes by burst time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (burst[j] > burst[j + 1]) {
                temp = burst[j]; burst[j] = burst[j + 1]; burst[j + 1] = temp;
                temp = process[j]; process[j] = process[j + 1]; process[j + 1] = temp;
            }
        }
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
