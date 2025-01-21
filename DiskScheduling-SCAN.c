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
    int n, head, totalHeadMovement = 0, direction;

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

    // Input the direction of movement (0 for left, 1 for right)
    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    // Sort the request array
    sort(requests, n);

    // Move towards the direction first
    if (direction == 1) {
        for (int i = 0; i < n; i++) {
            if (requests[i] >= head) {
                totalHeadMovement += abs(requests[i] - head);
                head = requests[i];
            }
        }
        // Then reverse the direction
        for (int i = n - 1; i >= 0; i--) {
            if (requests[i] < head) {
                totalHeadMovement += abs(requests[i] - head);
                head = requests[i];
            }
        }
    } else {
        // Reverse direction
        for (int i = n - 1; i >= 0; i--) {
            if (requests[i] <= head) {
                totalHeadMovement += abs(requests[i] - head);
                head = requests[i];
            }
        }
        // Then move towards the other end
        for (int i = 0; i < n; i++) {
            if (requests[i] > head) {
                totalHeadMovement += abs(requests[i] - head);
                head = requests[i];
            }
        }
    }

    printf("Total Head Movement using SCAN : %d\n", totalHeadMovement);

    return 0;
}

