#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//Only runs in linux
void displayProcessInfo(const char* message) {
    pid_t pid = getpid();       // Get current process ID
    pid_t ppid = getppid();     // Get parent process ID
    std::cout << message << " - PID: " << pid << ", PPID: " << ppid << std::endl;
}

void displayProcessTable() {
    // This function is a placeholder for a real process table display.
    // Actual implementation would require system-specific calls or libraries.
    std::cout << "Displaying process table (simulated):" << std::endl;
    std::cout << "PID\tPPID" << std::endl;
    std::cout << getpid() << "\t" << getppid() << std::endl;
}

int main() {
    std::cout << "Before fork:" << std::endl;
    displayProcessTable();

    pid_t pid = fork(); // Create a new process

    if (pid < 0) {
        // Error occurred
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        displayProcessInfo("Child process");
    } else {
        // Parent process
        displayProcessInfo("Parent process");
        wait(NULL); // Wait for child process to finish
    }

    std::cout << "After fork:" << std::endl;
    displayProcessTable();

    return 0;
}
