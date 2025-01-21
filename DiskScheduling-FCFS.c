#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, totalHeadMovement = 0;

    // Input the number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    // Input the request queue
    printf("Enter the disk requests (cylinder numbers):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    // Input the initial position of the disk head
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    // Calculate total head movement
    for (int i = 0; i < n; i++) {
        totalHeadMovement += abs(requests[i] - head);
        head = requests[i];
    }

    printf("Total Head Movement using FCFS: %d\n", totalHeadMovement);

    return 0;
}
