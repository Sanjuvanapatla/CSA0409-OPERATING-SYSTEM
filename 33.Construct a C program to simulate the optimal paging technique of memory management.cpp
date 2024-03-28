#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10

int pageFaults = 0;

int findOptimalPage(int pages[], int n, int index, int frame[]) {
    int res = -1, farthest = index;
    for (int i = 0; i < MAX_FRAMES; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n)
            return i;
    }
    return (res == -1) ? 0 : res;
}

void optimalPageReplacement(int pages[], int n, int capacity) {
    int frame[MAX_FRAMES];
    bool inFrame[MAX_PAGES] = {false};

    for (int i = 0; i < n; i++) {
        if (!inFrame[pages[i]]) {
            int replaceIndex = findOptimalPage(pages, n, i + 1, frame);
            inFrame[frame[replaceIndex]] = false;
            frame[replaceIndex] = pages[i];
            inFrame[pages[i]] = true;
            pageFaults++;
        }
    }
}

int main() {
    int n, pages[MAX_PAGES];

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    optimalPageReplacement(pages, n, MAX_FRAMES);

    printf("Number of page faults using Optimal Paging: %d\n", pageFaults);

    return 0;
}
