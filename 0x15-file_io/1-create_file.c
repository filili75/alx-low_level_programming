#include "main.h"

/**
 * create_file - creates a files
 * @filename: filename
 * @text_content: contents writed in the file.
 *
 * Return: 1 success -1  fails.
 */
int create_file(const char *filename, char *text_content)
{
	int fs, nletters, rwr;

	if (!filename)
		return (-1);

	fs = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fs == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nletters = 0; text_content[nletters]; nletters++)
		;

	rwr = write(fs, text_content, nletters);

	if (rwr == -1)
		return (-1);

	close(fs);

	return (1);
}
