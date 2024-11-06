//
// Created by saver05 on 11/1/24.
//

// Created by saver05 on 11/1/24

#include "kernel/types.h"
#include "user.h"
#include "kernel/pstat.h"

int main(void) {
    struct pstat pstat;
    if (getpinfo(&pstat) < 0) {
        printf("Failed to retrieve process info\n");
        exit(1);
    }

    printf("PID\tTickets\tIn Use\n");
    for (int i = 0; i < NPROC; i++) {
        if (pstat.inuse[i]) {  // Print only active processes
            printf("%d\t%d\t%d\n", pstat.pid[i], pstat.tickets[i], pstat.inuse[i]);
        }
    }

    exit(0);
}
