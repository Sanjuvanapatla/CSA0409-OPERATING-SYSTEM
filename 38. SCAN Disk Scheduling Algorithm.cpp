#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[100], n, headPosition, i, j, seek = 0, maxRange;

    printf("Enter the maximum range of the disk: ");
    scanf("%d", &maxRange);

    printf("Enter the number of queue requests: ");
    scanf("%d", &n);

    printf("Enter the initial head position: ");
    scanf("%d", &headPosition);

    printf("Enter the disk positions to be read (queue): ");
    for (i = 1; i <= n; i++)
        scanf("%d", &queue[i]);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    queue[n + 1] = maxRange;

    for (i = 1; i <= n + 1; i++) {
        seek += abs(queue[i] - headPosition);
        headPosition = queue[i];
    }

    printf("Total number of seek operations = %d\n", seek);
    return 0;
}
