#include <stdio.h>

int main() {
    int i, j, n, t, bu[10], wa[10] = {0}, tat[10] = {0}, ct[10], time = 0;
    float awt = 0, att = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];  // Store original burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &t);

    int done;
    do {
        done = 1;
        for (i = 0; i < n; i++) {
            if (bu[i] > 0) {
                done = 0;
                if (bu[i] > t) {
                    time += t;
                    bu[i] -= t;
                } else {
                    time += bu[i];
                    tat[i] = time;
                    bu[i] = 0;
                }
            }
        }
    } while (!done);

    for (i = 0; i < n; i++) {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, ct[i], wa[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", att / n);

    return 0;
}
