#include <stdio.h>
#include <stdlib.h>  // for exit()

int main() {
    int f[50], p, i, j, k, a, st, len, c;

    // Initialize all blocks to 0 (unallocated)
    for(i = 0; i < 50; i++)
        f[i] = 0;

    printf("Enter how many blocks are already allocated: ");
    scanf("%d", &p);

    printf("Enter the block numbers that are already allocated:\n");
    for(i = 0; i < p; i++) {
        scanf("%d", &a);
        if (a >= 0 && a < 50)
            f[a] = 1;
        else
            printf("Invalid block number: %d. Skipping.\n", a);
    }

X:
    printf("\nEnter the starting block and the length of the file: ");
    scanf("%d%d", &st, &len);

    if (st < 0 || st + len > 50) {
        printf("Invalid range. Try again.\n");
        goto X;
    }

    k = len;
    for(j = st; j < st + len; j++) {
        if(f[j] == 0) {
            f[j] = 1;
            printf("%d -> Allocated\n", j);
        } else {
            printf("%d -> Already Allocated. Skipping.\n", j);
            k++;
        }
    }

    printf("\nDo you want to enter another file? (Yes = 1 / No = 0): ");
    scanf("%d", &c);

    if (c == 1)
        goto X;
    else
        return 0;
}

