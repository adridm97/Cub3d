#include "../include/cub3d.h"
#include "get_next_line.h"

#include <string.h> 

// size_t ft_strlen(const char *str)
// {
//     size_t len = 0;
//     while (str[len] != '\0')
//     {
//         len++;
//     }
//     return len;
// }

void	error_param(char *msg, char **map)
{
	if (map)
		free(map);
	if (ft_strlen(msg) != 0)
		write(1, msg, ft_strlen(msg));
	exit(1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
    if (s1 == NULL || s2 == NULL)
        return NULL;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	ft_contains_cub(char *str)
{
	int	len;

	len = ft_strlen(str);
    if (len < 4)
        return 0;
	return (ft_strcmp(str + len - 4, ".cub") == 0);
}


int	initialize_map(t_map *map)
{
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	map->nexit = 0;
	map->ncoins = 0;
	return (1);
}

void	ft_exit(char *str, int ex)
{
	int	len;

	len = ft_strlen(str);
	if (len > 0)
		write(1, str, len);
	exit(ex);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*byte_src;
	unsigned char	*byte_dest;
	size_t			i;

	byte_src = (unsigned char *)src;
	byte_dest = (unsigned char *)dest;
	i = 0;
	if (src == 0 && dest == 0)
		return (NULL);
	while (i < n)
	{
		byte_dest[i] = byte_src[i];
		i++;
	}
	return (dest);
}

void *ft_realloc(void *ptr, size_t new_size)
{
    void *new_ptr;

    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
        return NULL;

    if (ptr != NULL)
    {
	
        ft_memcpy(new_ptr, ptr, new_size);
        free(ptr);
    }

    return new_ptr;
}

void print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->height)
	{
		printf("%s\n", map->grid[i]);
		i++;
	}
}


int add_to_map(t_map *map, char *line)
{
	if (strncmp(line, "NO ", 3) == 0)
		return parse_texture(&map->north_texture, line);
	else if (strncmp(line, "SO ", 3) == 0)
		return parse_texture(&map->south_texture, line);
	else if (strncmp(line, "WE ", 3) == 0)
		return parse_texture(&map->west_texture, line);
	else if (strncmp(line, "EA ", 3) == 0)
		return parse_texture(&map->east_texture, line);
	else if (strncmp(line, "F ", 2) == 0)
		return parse_color(&map->floor, line);
	else if (strncmp(line, "C ", 2) == 0)
		return parse_color(&map->ceiling, line);
	// else if (line[0] == '1' || line[0] == '0')
	// 	return add_line_to_map(map, line);
	// else if (line[0] == ' ')
	// 	return 1;
	return 0;
}

// int	add_to_map(t_map *map, char *line)
// {
// 	int		line_length;
// 	char	**new_grid;
//     int i;

//     i = 0;
// 	line_length = ft_strlen(line);
	
// 	while (i < line_length) {
//         if (line[i] == ' ' || line[i] == '\t') {
//             line[i] = '-1';
//         }
//         i++;
//     }
// 	if (map->height == 0)
// 		map->width = line_length;
//     else if (line_length > map->width)
//         map->width = line_length;
// 	new_grid = malloc((map->height + 1) * sizeof(char *));
// 	if (new_grid == NULL)
// 		return (0);
// 	i = 0;
// 	while (i < map->height)
// 	{
// 		new_grid[i] = map->grid[i];
// 		i++;
// 	}
// 	free(map->grid);
// 	map->grid = new_grid;
// 	map->grid[map->height] = malloc(map->width + 1);
// 	if (map->grid[map->height] == NULL)
// 		return (0);
// 	i = 0;
//     while (i < map->width)
//     {
//         if (i < line_length)
//             map->grid[map->height][i] = line[i];
//         else
//             map->grid[map->height][i] = ' ';
// 		i++;
//     }
//     map->grid[map->height][map->width] = '\0';
// 	map->height++;

// 	print_map(map);
// 	return (1);
// }

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
}

void	add_line_to_map(t_map *map, char *line)
{
	if (!add_to_map(map, line))
	{
		ft_exit("Error al añadir línea al mapa", 1);
		free(line);
		free_map(map);
	}
	free(line);
}

void	initialize_copy(t_map *copy, t_map *original)
{
	if (copy == NULL)
		exit(1);
	copy->width = original->width;
	copy->height = original->height;
	copy->grid = malloc(sizeof(char *) * copy->height);
	if (copy->grid == NULL)
	{
		free(copy);
		exit(1);
	}
}

t_map	*copy_map(t_map *original)
{
	t_map	*copy;
	int		i;

	copy = malloc(sizeof(t_map));
	initialize_copy(copy, original);
	i = 0;
	while (i < copy->height)
	{
		copy->grid[i] = malloc(sizeof(char) * (copy->width + 1));
		if (copy->grid[i] == NULL)
		{
			free(copy->grid);
			free(copy);
			exit(1);
		}
		ft_strcpy(copy->grid[i], original->grid[i]);
		i++;
	}
	return (copy);
}

t_map	*check_map(int fd, t_map *map)
{
	char	*line;
	size_t	first_map_width;
	t_map	*map_valid;

	if (!initialize_map(map))
		ft_exit("Error inicializando el mapa.", 1);
	first_map_width = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		add_line_to_map(map, line);
	}
	// printf(*map->grid);
	map_valid = copy_map(map);
	// if (validate_map(map))
	// 	return (map_valid);
	return (NULL);
}

t_map	*check_param(int argc, char *argv[], t_map *map)
{
	int	fd;

	if (argc != 2)
		error_param("Incorrect parameters", NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_param("Error in file", NULL);
	if (!ft_contains_cub(argv[1]))
		error_param("File format not correct", NULL);
	return (check_map(fd, map));
}
// int	validate_map(t_map *map)
// {
// 	// int		player_count;
// 	// int		coin_count;
// 	t_game	game;

// 	// player_count = 0;
// 	// coin_count = 0;
// 	game.coins = 0;
// 	game.nplayer = 0;
// 	verify_walls(map);
// 	caracter_map(map, &game);
// 	game.ncollect = game.coins;
// 	if (map->nexit != 1 || game.nplayer != 1 || game.coins == 0)
// 		ft_exit("Error\n", 1);
// 	flood_fill(map, map->x, map->y);
// 	if (map->nexit < 1 || map->nexit > 1 || map->ncoins != game.coins)
// 		ft_exit("Error\n", 1);
// 	return (1);
// }


int count_line(char *str)
{
	char *new;
	int fd;
	int i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: No se pudo abrir el archivo.\n");
		return (0);
	}
	new = get_next_line(fd);
	while (new != NULL)
	{
		i++;
		free(new);
		new = get_next_line(fd);
	}
	free(new);
	close(fd);
	return (i);
}

// empezar a validar el  mapa

int check_f_c(t_parser *parser, t_scene *scene)
{
	char **sp_f;
	char **sp_c;

	sp_f = ft_split(parser->elem.f, ',');
	sp_c = ft_split(parser->elem.c, ',');
	if (ft_strlen(sp_f) != 3 || ft_strlen(sp_c) != 3)
		return (free(sp_f), free(sp_c), 1);
	else
	{
		if (check_rgb_nums(sp_f) == 0 && check_rbg_nums(sp_c) == 0)
		{
			if (convert_hexa(sp_f, sp_c, scene) == 1)
				return (ft_free(sp_f), ft_free(sp_c), 0);
		}
		else
			return (ft_free(sp_f), ft_free(sp_c), 1);
	}
	ft_free(sp_f);
	ft_free(sp_c);
	return (0);
}

int check_elements(t_parser *parser, t_scene *scene)
{
	int y;

	y = 0;
	while (parser->file[y] != NULL)
	{
		if (ft_strcmp(parser->file[y], "\n") == 0)
			y++;
		else
		{
			if (do_it(parser, parser->file[y]) == -1)
				return (-1);
			y++;
		}
	}
	if (parser->elem.qtt.no != 1 || parser->elem.qtt.so != 1 ||
		parser->elem.qtt.we != 1 || parser->elem.qtt.ea != 1 ||
		parser->elem.qtt.f != 1 || parser->elem.qtt.c != 1 ||
		parser->elem.qtt.is_zero != 0)
		return (1);
	if (check_f_c(parser, scene) == 1)
		return (1);
	return (0);
}

int ft_rowsfile(char **file)
{
	int i;

	i = 0;
	while (file[i] != NULL)
		i++;
	return (i);
}

char *ft_strtrim()
{
	
}

int init_map(t_data *data, t_parser *parser)
{
	int y;
	char *trimed;

	y = 0;
	parser->rowsfile = ft_rowsfile(parser->file);
	while (parser->file[y] != NULL)
	{
		trimed = ft_strtrim(parser->file[y], " ");
		if (trimed[0] == '1')
			break ;
		free(trimed);
	}
	free(trimed);
	data->map = copy_map(*parser, y);
	return (0);
}

char **check_file(char *str)
{
	char	*new;
	int		i;
	int		fd;

	fd = 0;
	i -1;
	if (count_line(str) == 0)
		return (NULL);
	new = malloc(sizeof(char *) * count_line(str) + 1);
	if (!new)
		return (NULL);
	if (!ft_contains_cub(str))
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (free(new), printf("error\n"), NULL);
	new[++i] = get_next_line(fd);
	while (new[i++] != NULL)
		new[i] = get_next_line(fd);
	close(fd);
	return (new);
}


int	main(int argc, char *argv[])
{
    // t_cub3d	game;
    t_map    map;
    t_map    *map_pars;

    map_pars = check_param(argc, argv, &map);
    if (!map_pars)
    {
        printf("Error: No se pudo inicializar el juego.\n");
        return (1);
    }
}