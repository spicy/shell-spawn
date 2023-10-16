#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{
    // The command buffer
    string cmdBuff;

    // The ID of the child process
    pid_t pid;

    // Keep running until the user typed "exit"
    do
    {
        // Prompt the user to enter the command
        cerr << "cmd> ";
        getline(cin, cmdBuff);

        // Exit if the user enters "exit"
        if (cmdBuff == "exit")
            break;

        // Create a child process
        pid = fork();

        // Error check to make sure the child was successfully created
        if (pid < 0)
        {
            perror("fork");
            return -1;
        }

        // If I am the child
        if (pid == 0)
        {
            if (execlp(cmdBuff.c_str(), cmdBuff.c_str(), NULL) == -1)
            {
                perror("execlp");
                exit(1);
            }
        }
        // If I am the parent
        else
        {
            int status;
            if (wait(&status) == -1)
            {
                perror("wait");
                return -1;
            }
        }
    }
    while (true); // loop will break when cmdBuff is "exit"

    return 0;
}
