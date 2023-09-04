#include "main.h"

/**
 * append_text_to_file - append text at the end of a file
 * @filename: filename
 * @text_content: added contents.
 *
 * Return: 1 if the file exists. -1 if the fails does not exist
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fs;
	int nletters;
	int rwr;

	if (!filename)
		return (-1);

	fs = open(filename, O_WRONLY | O_APPEND);

	if (fs == -1)
		return (-1);

	if (text_content)
	{
		for (nletters = 0; text_content[nletters]; nletters++)
			;

		rwr = write(fs, text_content, nletters);

		if (rwr == -1)
			return (-1);
	}

	close(fs);

	return (1);
}
