#define _WIN32_WINNT 0x0500

#include <Windows.h>
#include <TlHelp32.h>
#include <stdio.h>
#include <string.h>

int main() {

    HANDLE hJobObject = CreateJobObject(NULL, NULL);

    STARTUPINFO si_1;
    PROCESS_INFORMATION pi_1;
    DWORD CreationFlags = NORMAL_PRIORITY_CLASS;
    memset(&si_1, 0, sizeof(STARTUPINFO));
    si_1.cb = sizeof(si_1);
    si_1.lpTitle = "First";
    CreateProcess(NULL, "branch1.exe", NULL, NULL, FALSE, CreationFlags, NULL, NULL, &si_1, &pi_1);
    AssignProcessToJobObject(hJobObject, pi_1.hProcess); 

    STARTUPINFO si_2;
    PROCESS_INFORMATION pi_2;
    CreationFlags=NORMAL_PRIORITY_CLASS;
    memset(&si_2, 0, sizeof(STARTUPINFO));
    si_2.cb = sizeof(si_2);
    si_2.lpTitle  = "Second";
    CreateProcess(NULL, "branch2.exe", NULL, NULL, FALSE, CreationFlags, NULL, NULL, &si_2, &pi_2);
    AssignProcessToJobObject(hJobObject, pi_2.hProcess); 

    for (int i = 1; i < 16; i++) {

        Sleep(1100);
        if (i == 7) {

            if (TerminateProcess(pi_1.hProcess, 0)) {
                printf("%d. Process branch1.exe killed successfull!\n", i);
            }
            else {
                printf("%d. Can't kill branch1.exe process...\n", i);
            }
        } 
        else if (i == 11) {

            if (TerminateJobObject(hJobObject, 0)) {
                printf("%d. Process vse killed successfull!\n", i);
            }
            else {
                printf("%d. Can't kill vse process...\n", i);
            }
        }
        printf("%d. Parent\n", i);
    }

    CloseHandle(hJobObject);
    system("pause");

    return 0;
}