#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


bool **alloc_map(int y, int x)
{
	bool **map = calloc(y + 1, sizeof(bool *));
	for (int i = 0; i < y + 1; i++)
		map[i] = calloc(x + 1, sizeof(bool));
	return (map);
}

void print_map(bool **map, int y, int x)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (map[i][j] == true)
				putchar('0');
			else if (map[i][j] == false)
				putchar(' ');
		}
		putchar('\n');
	}
}

bool **write_to_map(bool **map, int heigth, int width, char *buf)
{
	int y = 0, x = 0;
	bool pen = false;
	for (int i = 0; buf[i]; i++)
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
		else if (buf[i] == '\n')
			return (map);
		else
			return (false);
		if (y < 0 || y > heigth || x < 0 || x > width)
			return (false);
		if (pen)
			map[y][x] = true;
	}
	return (map);
}

int count_around(bool **map, int y, int x)
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

bool **it_game(bool **map, int y, int x)
{
	bool **new_map = alloc_map(y, x);
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			int count = count_around(map, i, j);
			if (count == 3)
				new_map[i][j] = true;
			else if (count == 2 && map[i][j])
				new_map[i][j] = true;
		}
	}
	return (new_map);
}

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	int x = atoi(argv[1]), y = atoi(argv[2]), it = atoi(argv[3]);
	bool **map = alloc_map(y, x);
	char buf[1028];
	read(STDIN_FILENO, buf, 1028);
	map = write_to_map(map, y, x, buf);
	if (!map)
		return (1);
	for (int i = 0; i < it; i++)
		map = it_game(map, y, x);
	print_map(map, y, x);
	return (0);
}