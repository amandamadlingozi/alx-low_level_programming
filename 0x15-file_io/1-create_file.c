#include "main.h"

/**
 * create_file - Create a new file and write text to it
 * @filename: The name of the file to create or overwrite
 * @text_content: The text to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_status;

	size_t text_len = 0;

	if (filename == NULL)
		return (-1);

	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[text_len] != '\0')
			text_len++;
		write_status = write(file_descriptor, text_content, text_len);
		if (write_status == -1 || (size_t)write_status != text_len)
		{
			close(file_descriptor);
			return (-1);
		}
	}

	close(file_descriptor);
	return (1);
}

