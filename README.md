# ShellSpawn

ShellSpawn is a simple shell program designed to execute various commands in a child process. The shell prompt (`cmd>`) waits for the user to input a command, upon which the parent process spawns a child to execute the given command. 

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Error Handling](#error-handling)

## Features

- Simple shell interface with the prompt `cmd>`.
- Execution of user commands in a child process.
- Proper error handling for system calls.
- Ability to handle multiple commands sequentially.

## Installation

1. Clone the repository:
git clone https://github.com/spicy/ShellSpawn.git

2. Navigate to the directory:
cd ShellSpawn

3. Compile the program (assuming a generic compile command; replace with actual instructions):
make all

## Usage

1. Start the ShellSpawn program:
./shell

2. At the `cmd>` prompt, enter your desired command:
cmd> ls

3. To exit the shell, simply type:
cmd> exit

## Error Handling

All system calls are rigorously error-checked. Specifically, the `fork()`, `execlp()`, and `wait()` functions are monitored for any errors during their execution. If any of these functions return `-1`, the program will terminate and provide an appropriate error message.

Example:

if (pid < 0) {
perror("fork");
exit(-1);
}
