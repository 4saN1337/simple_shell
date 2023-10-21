#include "shell.h"

#define MAX_COMMAND_LENGTH 256

void write_string(const char *str) {
    write(STDOUT_FILENO, str, strlen(str));
}

void execute_command(char *command) {
    char *args[MAX_COMMAND_LENGTH];
    int arg_count = 0;

    char *token = strtok(command, " ");
    while (token != NULL) {
        args[arg_count] = token;
        arg_count++;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    if (arg_count > 0) {
        pid_t child_pid = fork();
        if (child_pid == 0) {
            execvp(args[0], args);
            _exit(1);
        } else if (child_pid > 0) {
            int status;
            waitpid(child_pid, &status, 0);
        }
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        write_string("Enter a command (or 'exit' to quit): ");
        if (fgets(command, sizeof(command), stdin) == NULL) {
            break;
        }

        size_t cmd_len = strlen(command);
        if (cmd_len > 0 && command[cmd_len - 1] == '\n') {
            command[cmd_len - 1] = '\0';
        }

        if (strcmp(command, "exit") == 0) {
            write_string("Exiting the shell...\n");
            break;
        } else {
            execute_command(command);
        }
    }

    return 0;
}
