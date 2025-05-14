#include <stdio.h>
int main() {
    int bt1[10], bt2[10], n1, n2, i;
    printf("Enter number of System (high priority) processes: ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Burst time for System P%d: ", i+1);
        scanf("%d", &bt1[i]);
    }

    printf("Enter number of User (low priority) processes: ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Burst time for User P%d: ", i+1);
        scanf("%d", &bt2[i]);
    }

    printf("\nExecuting System Queue (FCFS):\n");
    for (i = 0; i < n1; i++)
        printf("System Process P%d executed for %d units\n", i + 1, bt1[i]);

    printf("\nExecuting User Queue (FCFS):\n");
    for (i = 0; i < n2; i++)
        printf("User Process P%d executed for %d units\n", i + 1, bt2[i]);

    return 0;
}
