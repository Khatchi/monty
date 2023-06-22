#include "monty.h"

/**
 * main - the monty program interpreter
 * @argc: the no of arguments
 * @argv: the location of the monty file
 * Return: returns 0 on success
 * Description: a func that prints the monty code
 */

int main(int argc, char *argv[])
{
	bus_t bus = {NULL, NULL, NULL, 0};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	bus.file = fopen(argv[1], "r");

	if (!bus.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&bus.content, &bus.size, bus.file) != -1)
	{
		bus.counter++;

		if (bus.content[0] != '\n')
		{
			execute(bus.content, &bus.stack, bus.counter, bus.file);
		}
	}
	free(bus.content);
	fclose(bus.file);

	return (0);
}
