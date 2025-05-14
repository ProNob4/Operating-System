#include <stdio.h>
int main() {
    int i, n, bt[10], wt[10] = {0}, tat[10], time = 0, tq;
    int remaining[10], done;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        remaining[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    do {
        done = 1;
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;
                if (remaining[i] > tq) {
                    time += tq;
                    remaining[i] -= tq;
                } else {
                    time += remaining[i];
                    wt[i] = time - bt[i];
                    remaining[i] = 0;
                }
            }
        }
    } while (!done);

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    float avg_wt = 0, avg_tat = 0;
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat / n);
    return 0;
}
