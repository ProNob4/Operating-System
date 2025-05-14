#include <stdio.h>
#define MAX 10

int main() {
    int i, j, n, time, remain, flag = 0, ts;
    int at[MAX], bt[MAX], rt[MAX], wt[MAX], tat[MAX];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;

    for (i = 0; i < n; i++) {
        printf("Arrival time of P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("\nProcess\tWaiting Time\tTurnaround Time\n");
    for (time = 0, i = 0; remain != 0;) {
        int smallest = -1;
        for (j = 0; j < n; j++) {
            if (at[j] <= time && rt[j] > 0 && (smallest == -1 || rt[j] < rt[smallest]))
                smallest = j;
        }

        if (smallest == -1) {
            time++;
            continue;
        }

        rt[smallest]--;
        if (rt[smallest] == 0) {
            remain--;
            int end = time + 1;
            wt[smallest] = end - at[smallest] - bt[smallest];
            tat[smallest] = end - at[smallest];
            avg_wt += wt[smallest];
            avg_tat += tat[smallest];
            printf("P%d\t%d\t\t%d\n", smallest+1, wt[smallest], tat[smallest]);
        }
        time++;
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat/n);
    return 0;
}
