#include <stdio.h>

int main() {
    int n, i;
    int arrival[10], burst[10], waiting[10], turnaround[10];
    int total_waiting = 0, total_turnaround = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input Arrival and Burst Times
    for (i = 0; i < n; i++) {
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    // Calculate Waiting Time and Turnaround Time
    waiting[0] = 0; // First process has 0 waiting time
    for (i = 1; i < n; i++) {
        waiting[i] = (arrival[i - 1] + burst[i - 1] + waiting[i - 1]) - arrival[i];
        if (waiting[i] < 0)
            waiting[i] = 0; // No negative waiting time
    }

    for (i = 0; i < n; i++) {
        turnaround[i] = burst[i] + waiting[i];
        total_waiting += waiting[i];
        total_turnaround += turnaround[i];
    }

    // Output
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, arrival[i], burst[i], waiting[i], turnaround[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround / n);

    return 0;
}
