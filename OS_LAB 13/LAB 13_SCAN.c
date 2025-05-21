#include <stdio.h>
#include <conio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], sum = 0, p;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the initial position of the head: ");
    scanf("%d", &h);

    t[0] = 0;      // Beginning of disk
    t[1] = h;      // Current head position

    printf("Enter the track numbers: \n");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }

    // Sort the tracks including head and 0
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find the index of head position in sorted array
    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
            break;
        }
    }

    // Going down to track 0 first (SCAN to 0)
    p = 0;
    while (t[j] != 0) {
        atr[p++] = t[j--];
    }
    atr[p++] = t[j]; // Add track 0

    // Then go up
    for (i = k + 1; i < n + 2; i++) {
        atr[p++] = t[i];
    }

    // Calculate distances
    for (i = 0; i < n + 1; i++) {
        d[i] = (atr[i] > atr[i + 1]) ? (atr[i] - atr[i + 1]) : (atr[i + 1] - atr[i]);
        sum += d[i];
    }

    printf("\nTotal Head Movement: %d", sum);
    printf("\nAverage Head Movement: %.2f", (float)sum / n);

    getch();
    return 0;
}
