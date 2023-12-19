#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "factor.h"

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: 0 on success, otherwise EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file_ptr;
	size_t buffer_size = 0;
	ssize_t line_size;
	char *buffer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factor <filename>\n");
		exit(EXIT_FAILURE);
	}

	file_ptr = fopen(argv[1], "r");
	if (file_ptr == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((line_size = getline(&buffer, &buffer_size, file_ptr)) != -1)
	{
		factorize(buffer);
	}

	free(buffer);
	fclose(file_ptr);

	return (0);
}
