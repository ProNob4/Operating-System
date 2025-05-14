#include <stdio.h>
#include <stdbool.h>

int main() {
    int n = 5; // Number of processes
    int m = 3; // Number of resource types

    int alloc[5][3] = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    int request[5][3] = { {0, 0, 0}, {1, 0, 2}, {6, 0, 0}, {0, 1, 1}, {4, 3, 1} };
    int avail[3] = {1, 0, 0}; // Current available resources

    bool finish[5] = {false, false, false, false, false};
    int work[3];
    for (int i = 0; i < m; i++) work[i] = avail[i];

    int count = 0;

    while (count < n) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (request[i][j] > work[j])
                        break;
                }

                if (j == m) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }

        if (!found) {
            break;
        }
    }

    int deadlocked = 0;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            printf("Process P%d is in deadlock.\n", i);
            deadlocked = 1;
        }
    }

    if (!deadlocked) {
        printf("No deadlock detected. All processes can finish.\n");
    }

    return 0;
}
