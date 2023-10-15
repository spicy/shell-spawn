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

    // Keep running until the user has typed "exit"
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
            perror("fork has failed");
            return -1;
        }
        
        // If I am the child
        if (pid == 0)
        {
            execlp(cmdBuff.c_str(), cmdBuff.c_str(), NULL);

            perror("execlp failed");
            exit(1);
        }
        // If I am the parent
        else 
        {
            int status;
            wait(&status);
        }
    } 
    while (true); // loop will break when cmdBuff is "exit"

    return 0;    
}
