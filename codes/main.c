
#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sched.h>
#include "shared.h"

int main() {
    int id = shmget(IPC_PRIVATE, sizeof(SharedData), IPC_CREAT | 0600);
    if (id == -1) { perror("shmget"); return 1; }

    SharedData *d = shmat(id, NULL, 0);
    if (d == (void *)-1) { perror("shmat"); shmctl(id, IPC_RMID, NULL); return 1; }

    d->ready = 0;
    d->reply_ready = 0;

    char name[50];
    printf("Enter parent name: ");
    fflush(stdout);
    if (!fgets(name, sizeof(name), stdin)) return 1;
    name[strcspn(name, "\n")] = '\0';

    printf("Enter message for child: ");
    fflush(stdout);
    if (!fgets(d->message, MESSAGE_SIZE, stdin)) return 1;
    d->message[strcspn(d->message, "\n")] = '\0';

    pid_t pid = fork();

    if (pid == -1) { perror("fork"); shmdt(d); shmctl(id, IPC_RMID, NULL); return 1; }

    if (pid == 0) {
        while (d->ready != 1) sched_yield();
        printf("\nChild received: %s\n", d->message);

        printf("Enter reply from child: ");
        fflush(stdout);
        if (!fgets(d->reply, MESSAGE_SIZE, stdin))
            d->reply[0] = '\0';
        d->reply[strcspn(d->reply, "\n")] = '\0';

        d->reply_ready = 1;
        shmdt(d);
        _exit(0);
    } else {
        d->ready = 1;
        while (d->reply_ready != 1) sched_yield();

        printf("Parent received: %s\n", d->reply);
        printf("Communication completed!\n");

        waitpid(pid, NULL, 0);
    }

    shmdt(d);
    shmctl(id, IPC_RMID, NULL);
    return 0;
}
