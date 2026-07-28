#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool **new_map(int w, int h)
{
	bool **new_map = calloc(h + 1, sizeof(bool *));
	for (int i = 0; i < h + 1; i++)
		new_map[i] = calloc(w + 1, sizeof(bool));
	return (new_map);
}

void start_map(bool **map, int w, int h)
{
	int y = 0;
	int x = 0;
	bool pen = false;

	char buf[1028];
	int n = read(0, buf, 1028);

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
		
		if (pen && x >= 0 && y >= 0 && y < h && x < w)
			map[y][x] = true;
	}
}

void	draw_map(bool **map, int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			if (map[y][x] == true)
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}

int	count_around(bool **map, int x, int y)
{
	int count = 0;

	if (y > 0 && x > 0 && map[y - 1][x - 1] == true)
		count++;
	if (y > 0 && map[y - 1][x] == true)
		count++;
	if (y > 0 && map[y - 1][x + 1] == true)
		count++;

	if (x > 0 && map[y][x - 1] == true)
		count++;
	if (map[y][x + 1] == true)
		count++;

	if (x > 0 && map[y + 1][x - 1] == true)
		count++;
	if (map[y + 1][x] == true)
		count++;
	if (map[y + 1][x + 1] == true)
		count++;

	return (count);

}

bool **next_map(bool **map, int w, int h)
{
	bool **next = new_map(w, h);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int count = count_around(map, x, y);
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
	int	w = atoi(argv[1]);
	int	h = atoi(argv[2]);
	int iter = atoi(argv[3]);

	(void)iter;

	bool **map = new_map(w, h);
	start_map(map, w, h);
	
	while (iter-- > 0)
		map = next_map(map, w, h);
	
	draw_map(map, w, h);
}