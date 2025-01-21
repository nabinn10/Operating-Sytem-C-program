
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, totalHeadMovement = 0;

    // Input the number of requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];
    int visited[n];

    // Input the request queue
    printf("Enter the disk requests (cylinder numbers):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
        visited[i] = 0;  // Mark all requests as unvisited
    }

    // Input the initial position of the disk head
    printf("Enter the initial position of the disk head: ");
    scanf("%d", &head);

    // Calculate total head movement using SSTF
    for (int i = 0; i < n; i++) {
        int minDist = 100000, closestRequest = -1;

        // Find the closest unvisited request
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                int dist = abs(requests[j] - head);
                if (dist < minDist) {
                    minDist = dist;
                    closestRequest = j;
                }
            }
        }

        // Visit the closest request
        visited[closestRequest] = 1;
        totalHeadMovement += minDist;
        head = requests[closestRequest];
    }

    printf("Total Head Movement using SSTF: %d\n", totalHeadMovement);

    return 0;
}
