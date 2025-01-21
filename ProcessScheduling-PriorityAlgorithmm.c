
#include <stdio.h>

int main() {
    printf("Process Scheduling using Priority Algorithm \n");

    int n, i, j, temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst[n], priority[n], wait[n], turnaround[n], process[n];
    float totalWait = 0, totalTurnaround = 0;

    printf("Enter burst times and priorities of the processes:\n");
    for (i = 0; i < n; i++) {
        process[i] = i + 1;
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &burst[i]);
        printf("Process %d Priority: ", i + 1);
        scanf("%d", &priority[i]);
    }

    // Sort processes by priority
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                temp = burst[j]; burst[j] = burst[j + 1]; burst[j + 1] = temp;
                temp = priority[j]; priority[j] = priority[j + 1]; priority[j + 1] = temp;
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
