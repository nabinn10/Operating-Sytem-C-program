
#include <stdio.h>

int main() {
    int pages[] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5, 2};
    int n = 12; // Number of pages
    int frames = 3, frame[3], page_faults = 0, index = 0;

    // Initialize frames as empty
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If not found, replace the oldest page
        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            page_faults++;
        }
    }

    printf("Total Page Faults using FIFO: %d\n", page_faults);
    return 0;
}
