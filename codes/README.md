1# Shared Memory Based Data Exchange System

A small Linux C project demonstrating inter-process communication (IPC) using System V shared memory.

## Files
- `main.c` — creates shared memory, forks a child, exchanges a message, and cleans up.
- `shared.h` — defines the shared data structure.
- `Makefile` — builds, runs, and cleans the program.

## Requirements
- Linux or Ubuntu (native Linux or WSL with a working Ubuntu installation)
- GCC and Make

Install tools on Ubuntu:
```bash
sudo apt update
sudo apt install build-essential
```

## Build and run
From this folder:
```bash
make
./shared_memory
```
Or compile directly:
```bash
gcc -Wall -Wextra -std=c11 main.c -o shared_memory
./shared_memory
```

Expected output:
```text
Child received: Hello from the parent process!
Parent: message exchange completed.
```

## How it works
1. `shmget()` creates a shared memory segment.
2. `shmat()` attaches it to the process address space.
3. `fork()` creates a child process that inherits the attachment.
4. Parent writes a message and sets `ready = 1`.
5. Child waits until the message is ready, prints it, then sets `ready = 2`.
6. Parent waits for the child to finish.
7. `shmdt()` detaches the segment and `shmctl(..., IPC_RMID, ...)` removes it.
