
#ifndef SHARED_H
#define SHARED_H

#define MESSAGE_SIZE 256

typedef struct {
    volatile int ready;
    volatile int reply_ready;
    char message[MESSAGE_SIZE];
    char reply[MESSAGE_SIZE];
} SharedData;

#endif

