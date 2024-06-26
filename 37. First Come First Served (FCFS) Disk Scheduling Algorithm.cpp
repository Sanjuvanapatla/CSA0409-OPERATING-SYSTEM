#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, n, TotalHeadMovement = 0, initial;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter initial head position: ");
    scanf("%d", &initial);

    for (i = 0; i < n; i++) {
        TotalHeadMovement += abs(RQ[i] - initial);
        initial = RQ[i];
    }

    printf("Total head movement is %d\n", TotalHeadMovement);
    return 0;
}
