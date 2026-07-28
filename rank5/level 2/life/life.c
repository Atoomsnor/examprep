#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool **alloc_map(int width, int heigth)
{
	bool **new = calloc(heigth + 1, sizeof(bool *));
	for (int i = 0; i < heigth + 1; i++)
		new[i] = calloc(width + 1, sizeof(bool));
	return (new);
}

void print_map(bool **map, int width, int heigth)
{
	for (int y = 0; y < heigth; y++)
	{
		for (int x = 0; x < width; x++)
		{
			
			if (map[y][x] == true)
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

void write_to_map(bool **map, int width, int heigth)
{
	char buf[1028];

	int n = read(STDIN_FILENO, buf, 1028);
	int pen = false;
	int	x = 0;
	int	y = 0;

	for (int i = 0; i < n; i++)
	{
		if (buf[i] == 'w')
			y--;
		else if (buf[i] == 's')
			y++;
		else if (buf[i] == 'a')
			x--;
		else if (buf[i] == 'd')
			x++;
		else if (buf[i] == 'x')
			pen = !pen;
		if (pen && x >= 0 && x < width && y >= 0 && y < heigth)
			map[y][x] = true;
	}
}

int	count_around(bool **map, int x, int y)
{
	int count = 0;
	if (y > 0 && x > 0 && map[y - 1][x - 1] == true)
		count++;
	if (x > 0 && map[y][x - 1] == true)
		count++;
	if (x > 0 && map[y + 1][x - 1] == true)
		count++;
	if (y > 0 && map[y - 1][x] == true)
		count++;
	if (map[y + 1][x] == true)
		count++;
	if (y > 0 && map[y - 1][x + 1] == true)
		count++;
	if (map[y][x + 1] == true)
		count++;
	if (map[y + 1][x + 1] == true)
		count++;
	return (count);
}

bool **next_gen(bool **map, int width, int heigth)
{
	bool **next = alloc_map(width, heigth);

	for (int y = 0; y < heigth; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int	count = count_around(map, x, y);
			if (count == 3)
				next[y][x] = true;
			else if (count == 2 && map[y][x])
				next[y][x] = true;
		}
	}
	return (next);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);

	int	width = atoi(argv[1]);
	int	heigth = atoi(argv[2]);
	int	iter = atoi(argv[3]);

	// (void)iter;

	bool **map = alloc_map(width, heigth);
	// char buf[1028];
	// read(STDIN_FILENO, buf, 1028);
	write_to_map(map, width, heigth);
	while (iter-- > 0)
		map = next_gen(map, width, heigth);
	print_map(map, width, heigth);
	

	return (0);
}