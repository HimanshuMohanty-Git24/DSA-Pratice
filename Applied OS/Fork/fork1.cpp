#include <windows.h>
#include <iostream>
#include <process.h>

void displayProcessInfo(const char* message) {
    DWORD pid = GetCurrentProcessId();       // Get current process ID
    DWORD ppid = GetCurrentProcessId();      // On Windows, you can't directly get the parent ID like in Unix.
    std::cout << message << " - PID: " << pid << ", PPID: " << ppid << std::endl;
}

void displayProcessTable() {
    // This function simulates the process table; actual implementation is more complex.
    std::cout << "Displaying process table (simulated):" << std::endl;
    std::cout << "PID\tPPID" << std::endl;
    std::cout << GetCurrentProcessId() << "\t" << GetCurrentProcessId() << std::endl;
}

int main() {
    std::cout << "Before CreateProcess:" << std::endl;
    displayProcessTable();

    // Create a new process
    PROCESS_INFORMATION processInfo;
    ZeroMemory(&processInfo, sizeof(processInfo));
    STARTUPINFO startupInfo;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);

    // Command to execute
    const char* command = "cmd.exe /C echo Hello from the child process!";

    if (CreateProcess(NULL, // No module name (use command line)
                      (LPSTR)command, // Command line
                      NULL, // Process handle not inheritable
                      NULL, // Thread handle not inheritable
                      FALSE, // Set handle inheritance to FALSE
                      0, // No creation flags
                      NULL, // Use parent's environment block
                      NULL, // Use parent's starting directory 
                      &startupInfo, // Pointer to STARTUPINFO structure
                      &processInfo) // Pointer to PROCESS_INFORMATION structure
    ) {
        // Successfully created the child process
        displayProcessInfo("Child process");

        // Wait until child process exits
        WaitForSingleObject(processInfo.hProcess, INFINITE);

        // Close process and thread handles
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
    } else {
        std::cerr << "CreateProcess failed!" << std::endl;
        return 1;
    }

    std::cout << "After CreateProcess:" << std::endl;
    displayProcessTable();

    return 0;
}
