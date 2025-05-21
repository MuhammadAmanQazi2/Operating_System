#include <stdio.h>
#include <stdlib.h>  // Needed for exit()

void main() {
    int b[20], l[20], n, i, pa, s, a, d;

    printf("\nProgram for segmentation");
    printf("\nEnter the number of segments: ");
    scanf("%d", &n);

    printf("\nEnter the base address and limit register:\n");
    for (i = 0; i < n; i++) {
        printf("Segment %d base: ", i);
        scanf("%d", &b[i]);
        printf("Segment %d limit: ", i);
        scanf("%d", &l[i]);
    }

    printf("\nEnter the segment number: ");
    scanf("%d", &s);

    printf("Enter the logical address (offset): ");
    scanf("%d", &d);

    if (s < n) {
        if (d < l[s]) {
            pa = b[s] + d;
            a = b[s];
            printf("\n\tSeg#\tBaseAddr\tPhysicalAddr\n");
            printf("\t%d\t%d\t\t%d\n", s, a, pa);
        } else {
            printf("\nOffset exceeds segment limit.\n");
        }
    } else {
        printf("\nInvalid segment number.\n");
    }
}
