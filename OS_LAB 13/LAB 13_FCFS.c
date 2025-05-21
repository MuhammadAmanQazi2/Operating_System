#include <stdio.h>
#include <conio.h> // Only needed if you're using getch()

int main() {
    int t[20], n, i, tohm[20], tot = 0;
    float avhm;

    printf("Enter the number of tracks: ");
    scanf("%d", &n);

    printf("Enter the tracks to be traversed:\n");
    for(i = 2; i < n+2; i++) {
        scanf("%d", &t[i]);
    }

    for(i = 1; i < n + 1; i++) {
        tohm[i] = t[i + 1] - t[i];
        if(tohm[i] < 0)
            tohm[i] = -tohm[i];
        tot += tohm[i];
    }

    avhm = (float) tot / (n - 1);

    printf("\nTracks Traversed\tDifference between tracks\n");
    for(i = 0; i < n - 1; i++) {
        printf("%d -> %d\t\t\t%d\n", t[i], t[i + 1], tohm[i]);
    }

    printf("\nTotal head movement = %d", tot);
    printf("\nAverage head movement = %.2f\n", avhm);


    getch();
}

