
#include <stdio.h>

int main() {
    printf("Process Scheduling using Round Robin Algorithm \n");
    int n, i, time = 0, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burst[n], remaining[n], wait[n], turnaround[n];
    float totalWait = 0, totalTurnaround = 0;

    printf("Enter burst times of the processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
        wait[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;  // Process is not done yet
                if (remaining[i] > tq) {
                    time += tq;
                    remaining[i] -= tq;
                } else {
                    time += remaining[i];
                    wait[i] = time - burst[i];
                    remaining[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (i = 0; i < n; i++) {
        turnaround[i] = burst[i] + wait[i];
        totalWait += wait[i];
        totalTurnaround += turnaround[i];
    }

    printf("Average Waiting Time: %.2f\n", totalWait / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaround / n);

    return 0;
}
