
#include <stdio.h>
#include <stdlib.h>

void sort(int requests[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (requests[i] > requests[j]) {
                int temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
}

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

    // Sort the request array
    sort(requests, n);

    // Find the closest end of the  disk (either 0 or max)
    int start = 0;
    while (start < n && requests[start] < head) {
        start++;
    }

    // Move towards the farthest end first
    for (int i = start - 1; i >= 0; i--) {
        totalHeadMovement += abs(requests[i] - head);
        head = requests[i];
    }
    for (int i = start; i < n; i++) {
        totalHeadMovement += abs(requests[i] - head);
        head = requests[i];
    }

    printf("Total Head Movement using LOOK : %d\n", totalHeadMovement);

    return 0;
}
