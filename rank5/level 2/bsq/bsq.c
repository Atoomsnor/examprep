#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
	int		width;
	int		heigth;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	read_map(FILE *f, t_map *map)
{
	char	*line;
	size_t	cap;
	int		i;

	if (fscanf(f, "%d %c %c %c", &map->heigth, &map->empty,
			&map->obstacle, &map->full) != 4)
		return (-1);
	line = NULL;
	cap = 0;
	getline(&line, &cap, f);
	free(line);
	map->grid = calloc(map->heigth, sizeof(char *));
	i = 0;
	while (i < map->heigth)
	{
		line = NULL;
		cap = 0;
		if (getline(&line, &cap, f) < 0)
			return (-1);
		line[ft_strlen(line) - 1] = '\0';
		if (i == 0)
			map->width = ft_strlen(line);
		map->grid[i] = line;
		i++;
	}
	return (0);
}

int	min3(int a, int b, int c)
{
	if (b < a)
		a = b;
	if (c < a)
		a = c;
	return (a);
}

void	solve_map(t_map *map)
{
	int	**dist;
	int	best;
	int	by;
	int	bx;
	int	y;
	int	x;

	dist = calloc(map->heigth, sizeof(int *));
	for (y = 0; y < map->heigth; y++)
		dist[y] = calloc(map->width, sizeof(int));
	best = 0;
	by = 0;
	bx = 0;
	for (y = 0; y < map->heigth; y++)
	{
		for (x = 0; x < map->width; x++)
		{
			if (map->grid[y][x] == map->obstacle)
				dist[y][x] = 0;
			else if (y == 0 || x == 0)
				dist[y][x] = 1;
			else
				dist[y][x] = min3(dist[y - 1][x], dist[y][x - 1],
						dist[y - 1][x - 1]) + 1;
			if (dist[y][x] > best)
			{
				best = dist[y][x];
				by = y;
				bx = x;
			}
		}
	}
	for (y = by - best + 1; y <= by; y++)
		for (x = bx - best + 1; x <= bx; x++)
			map->grid[y][x] = map->full;
}

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->heigth)
	{
		fprintf(stdout, "%s\n", map->grid[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	FILE	*f;
	t_map	map;
	int		i;

	i = 1;
	while (i < argc || argc == 1)
	{
		f = argc == 1 ? stdin : fopen(argv[i], "r");
		if (!f || read_map(f, &map) < 0)
			fprintf(stderr, "map error\n");
		else
		{
			solve_map(&map);
			print_map(&map);
		}
		fprintf(stdout, "\n");
		if (argc == 1)
			break;
		i++;
	}
	return (0);
}