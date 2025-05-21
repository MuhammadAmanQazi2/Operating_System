#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], i, st, j, len, c, k;

    // Initialize all blocks to free
    for (i = 0; i < 50; i++)
        f[i] = 0;

    while (1) {
        printf("\nEnter the starting block and length of the file: ");
        scanf("%d %d", &st, &len);

        if (st < 0 || st + len > 50) {
            printf("Invalid input. Block range exceeds disk size.\n");
            continue;
        }

        // Check availability
        for (j = st; j < st + len; j++) {
            if (f[j] != 0) {
                printf("Block %d already allocated.\n", j);
                break;
            }
        }

        // If all blocks are available
        if (j == st + len) {
            for (j = st; j < st + len; j++) {
                f[j] = 1;
                printf("%d -> Allocated\n", j);
            }
            printf("The file is successfully allocated to disk.\n");
        } else {
            printf("File cannot be allocated. Some blocks are already in use.\n");
        }

        // Prompt to continue
        printf("\nDo you want to enter more files? (1 for Yes / 0 for No): ");
        scanf("%d", &c);
        if (c != 1)
            break;
    }

    return 0;
}
