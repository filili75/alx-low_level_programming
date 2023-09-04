#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. It fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fs;
	ssize_t nrs, nwr;
	char *buf;

	if (!filename)
		return (0);

	fs = open(filename, O_RDONLY);

	if (fs == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrs = read(fs, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrs);

	close(fs);

	free(buf);

	return (nwr);
}
