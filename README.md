Shared Memory Based Data Exchange System
1. Project Overview
The Shared Memory Based Data Exchange System is a C programming project that demonstrates Inter-Process Communication (IPC) in Linux using System V shared memory.
The project allows a parent process to send a message to a child process and receive a reply from the child through a common shared memory region.
2. Objectives
- To understand Inter-Process Communication (IPC).
- To create and manage shared memory in Linux.
- To create a child process using the fork() system call.
- To implement two-way message exchange between parent and child processes.
- To coordinate communication using status flags.
- To release shared memory resources after communication.
3. Technologies Used
- Programming Language: C
- Operating System: Linux / Ubuntu
- Compiler: GCC
- Build Tool: GNU Make
- IPC Mechanism: System V Shared Memory
4. Project Structure
Shared_Memory_IPC_Project/
├── main.c
├── shared.h
├── Makefile
└── README.md
File Descriptions
- main.c: Contains the main program logic, process creation, message exchange, and cleanup.
- shared.h: Defines the SharedData structure, message buffers, and communication flags.
- Makefile: Automates compilation and provides build and cleanup commands.
- README.md: Contains project documentation, setup instructions, and execution details.
5. Libraries and Header Files
- stdio.h: Input, output, and error reporting.
- string.h: String operations.
- sys/ipc.h: IPC constants and definitions.
- sys/shm.h: Shared memory operations.
- sys/wait.h: Waiting for child process termination.
- unistd.h: Process creation using fork() and other system interfaces.
- sched.h: Provides sched_yield() for yielding processor time while waiting.
- shared.h: Custom header defining the shared data structure.
6. Working Principle
1. The program creates a shared memory segment using shmget().
2. The segment is attached using shmat().
3. The parent enters its name and a message for the child.
4. The fork() system call creates a child process.
5. The parent writes the message into shared memory and signals that it is ready.
6. The child reads and displays the parent's message.
7. The child enters a reply and writes it into the shared memory buffer.
8. The child signals that the reply is ready.
9. The parent reads and displays the reply.
10. The parent waits for the child to terminate and removes the shared memory segment.
7. Important System Calls
Function  |  Purpose
shmget()  |  Creates a shared memory segment.
shmat()  |  Attaches shared memory to a process.
fork()  |  Creates a child process.
sched_yield()  |  Yields processor time while waiting.
waitpid()  |  Waits for the child process to terminate.
shmdt()  |  Detaches shared memory.
shmctl()  |  Controls shared memory and requests its removal.
8. Requirements
- Linux or Ubuntu, including a working Ubuntu installation under WSL.
- GCC compiler.
- GNU Make.
- Terminal access.
Install the required tools on Ubuntu:
sudo apt update
sudo apt install build-essential
9. Compilation and Execution
Open the terminal in the project directory.
Compile the program:
make
Run the executable:
./shared_memory
To remove the compiled executable:
make clean
Alternatively, compile directly:
gcc -Wall -Wextra -std=c11 main.c -o shared_memory
./shared_memory
10. Sample Output
Enter parent name: Sai
Enter message for child: Hello child!

Child received: Hello child!
Enter reply from child: Hello parent!
Parent received: Hello parent!
Communication completed!
The parent sends a message, the child reads it and replies, and the parent displays the reply.
11. Advantages
- Supports fast communication between processes.
- Allows processes to access a common memory region.
- Demonstrates two-way message exchange.
- Reduces the need to pass messages through intermediate communication channels.
- Helps understand Linux process management and IPC system calls.
12. Limitations
- Shared memory requires synchronization to prevent race conditions.
- The current implementation uses simple status flags for demonstration.
- The flags are notrobust synchronization primitives and should be replaced with process-shared semaphores or equivalent mechanisms in production systems.
- The demonstration is designed for a parent and one child process.
13. Applications
Shared memory can be useful in:
- Multimedia and image processing.
- High-performance data exchange.
- Scientific computing.
- Operating system IPC demonstrations.
- Applications that process large amounts of shared data.
14. Conclusion
The Shared Memory Based Data Exchange System demonstrates Inter-Process Communication using System V shared memory in Linux. It allows a parent process and a child process to exchange messages in both directions through a shared memory segment. The project illustrates process creation, shared memory management, basic synchronization, and resource cleanup.
15. Future Enhancements
- Implement process-shared semaphores for reliable synchronization.
- Support multiple child processes.
- Add message history and timestamps.
- Add error handling for all input and resource-management failures.
- Extend the system to exchange structured data instead of plain text.
- 
