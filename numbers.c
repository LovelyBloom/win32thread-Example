/*
 * numbers.c
 *
 * Starts five threads and gives visible feedback
 * of these threads running by printing a number
 * passed in from the primary thread.
 * Build with the command line: cl numbers.c
 * or use cmake targeting visual studio
 * Note: This program was purposely built
 *       without the multithread run-time library
 *       for demonstration purposes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI ThreadFunc(LPVOID n)
{
    for (int i = 0; i < 10; i++)
        printf("%d%d%d%d%d%d%d%d\n",
               n,n,n,n,
               n,n,n,n);

    return 0;
}

int main(int argc, char* argv[]) {
    HANDLE hThrd;
    DWORD  threadId;

    for (int i = 0; i < 5; i++)
    {
        hThrd = CreateThread(NULL, 0,
                             ThreadFunc,
                             (LPVOID)i,
                             0,
                             &threadId);
        if (hThrd) {
            printf("Thread launched\n");
        }
    }

    // Wait for the threads to complete.
    // We'll see a better way of doing this in Chapter 3
    Sleep(2000);
    return EXIT_SUCCESS;
}



