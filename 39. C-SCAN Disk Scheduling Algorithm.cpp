#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, n, TotalHeadMovement = 0, initial, size, move;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    printf("Enter total disk size: ");
    scanf("%d", &size);

    printf("Enter the head movement direction (1 for high to low, 0 for low to high): ");
    scanf("%d", &move);

    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (RQ[i] > RQ[j]) {
                int temp = RQ[i];
                RQ[i] = RQ[j];
                RQ[j] = temp;
            }
        }
    }

    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }

    if (move == 1) {
        for (i = index; i < n; i++) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMovement += abs(size - RQ[i - 1] - 1);
        TotalHeadMovement += abs(size - 1 - 0);
        initial = 0;
        for (i = 0; i < index; i++) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else {
        for (i = index - 1; i >= 0; i--) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMovement += abs(RQ[i + 1] - 0);
        TotalHeadMovement += abs(size - 1 - 0);
        initial = size - 1;
        for (i = n - 1; i >= index; i--) {
            TotalHeadMovement += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    printf("Total head movement is %d\n", TotalHeadMovement);
    return 0;
}
