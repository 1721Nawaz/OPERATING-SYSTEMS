
#include <stdio.h>

struct Process {
    int burstTime;
    int priority;
};

void priorityScheduling(struct Process processes[], int n) {
    int waitingTime[n], turnaroundTime[n];
    int i;
    float totalWaitingTime = 0, totalTurnaroundTime = 0;

    waitingTime[0] = 0;

    for (i = 1; i < n; i++) {
        waitingTime[i] = processes[i - 1].burstTime + waitingTime[i - 1];
        totalWaitingTime += waitingTime[i];
    }

    for (i = 0; i < n; i++) {
        turnaroundTime[i] = processes[i].burstTime + waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].burstTime, processes[i].priority,
               waitingTime[i], turnaroundTime[i]);
    }


    float avgWaitingTime = totalWaitingTime / n;
    float avgTurnaroundTime = totalTurnaroundTime / n;

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}

int main() {

    struct Process processes[] = {
        {30, 2},
        {5, 1},
        {12, 3}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    priorityScheduling(processes, n);

    return 0;
}

