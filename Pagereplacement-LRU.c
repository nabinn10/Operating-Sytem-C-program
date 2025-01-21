
#include <stdio.h>

int main() {
    int pages[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int n = 12; // Number of pages
    int frames = 3, frame[3], page_faults = 0, least_recent[3];

    // Initialize frames as empty
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        least_recent[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                least_recent[j] = i; // Update the usage index
                break;
            }
        }

        // If not found, replace the least recently used page
        if (!found) {
            int lru_index = 0;
            for (int j = 1; j < frames; j++) {
                if (frame[j] == -1 || least_recent[j] < least_recent[lru_index]) {
                    lru_index = j;
                }
            }
            frame[lru_index] = pages[i];
            least_recent[lru_index] = i;
            page_faults++;
        }
    }

    printf("Total Page Faults using LRU: %d\n", page_faults);
    return 0;
}
