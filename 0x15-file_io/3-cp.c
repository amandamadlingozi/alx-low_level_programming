#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUFFER_SIZE 1024

int copy_file(const char *source, const char *destination);
void display_usage_error(const char *program_name);
void display_read_error(const char *file_name);
void display_write_error(const char *file_name);
void display_close_error(int fd_value);

int main(int argc, char *argv[])
{
if (argc != 3)
{
display_usage_error(argv[0]);
return (97);
}

int result = copy_file(argv[1], argv[2);

return (result);
}

int copy_file(const char *source, const char *destination)
{
int fd_from, fd_to;
char buffer[BUFFER_SIZE];
ssize_t bytes_read, bytes_written;

fd_from = open(source, O_RDONLY);
if (fd_from == -1)
{
display_read_error(source);
return (98);
}

fd_to = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
display_write_error(destination);
close(fd_from);
return (99);
}

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1)
{
display_write_error(destination);
close(fd_from);
close(fd_to);
return (99);
}
}

if (bytes_read == -1)
{
display_read_error(source);
close(fd_from);
close(fd_to);
return (98);
}

if (close(fd_from) == -1 || close(fd_to) == -1)
{
display_close_error(fd_from);
return (100);
}

return (0);
}

void display_usage_error(const char *program_name)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", program_name);
}

void display_read_error(const char *file_name)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_name);
}

void display_write_error(const char *file_name)
{
dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_name);
}

void display_close_error(int fd_value)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_value);
}
