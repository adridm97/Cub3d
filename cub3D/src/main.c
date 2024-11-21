 #include "../include/cub3d.h"
 #include "get_next_line.h"

 #include <string.h>
 #include <stdlib.h>

 // size_t ft_strlen(const char *str)
 // {
 //     size_t len = 0;
 //     while (str[len] != '\0')
 //     {
 //         len++;
 //     }
 //     return len;
 // }
int count_args(char **check_line)
 {
	 int i;

	 i = 0;
	 while (check_line[i] != NULL)
		 i++;
	 return (i);
 }

 int	cont_words(char *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			cont++;
		else if ((i != 0) && (s[i - 1] == c && s[i] != c))
			cont++;
		i++;
	}
	return (cont);
}

int	ft_delimiter(char *s, int pos, char c)
{
	while (s[pos] == c)
	{
		pos++;
	}
	return (pos);
}

int	cont_letter(char *s, int pos, char c)
{
	int	cont;

	cont = 0;
	pos = ft_delimiter(s, pos, c);
	while (s[pos] != '\0' && s[pos] != c)
	{
		cont++;
		pos++;
	}
	return (cont);
}

char	**ft_free_mat(char **mat, int i)
{
	int		j;

	j = 0;
	while (i > j)
	{
		free(mat[j]);
		j++;
	}
	free(mat);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		pos;
	char	**mat;
	int		words;
	int		j;

	i = -1;
	pos = 0;
	words = cont_words((char *)s, c);
	mat = malloc(sizeof(char *) * (words + 1));
	if (!mat)
		return (0);
	while (++i < words)
	{
		j = 0;
		mat[i] = malloc(sizeof(char) * (cont_letter((char *)s, pos, c) + 1));
		if (!mat[i])
			return (ft_free_mat(mat, i));
		pos = ft_delimiter((char *)s, pos, c);
		while (s[pos] != c && s[pos] != '\0')
			mat[i][j++] = s[pos++];
		mat[i][j] = '\0';
	}
	mat[i] = NULL;
	return (mat);
}

 void    error_param(char *msg, char **map)
 {
     if (map)
         free(map);
     if (ft_strlen(msg) != 0)
         write(1, msg, ft_strlen(msg));
     exit(1);
 }

 int ft_strcmp(const char *s1, const char *s2)
 {
     size_t  i;

     i = 0;
     while (s1[i] != '\0' && s2[i] != '\0')
     {
         if (s1[i] != s2[i])
             return ((unsigned char)s1[i] - (unsigned char)s2[i]);
         i++;
     }
     return ((unsigned char)s1[i] - (unsigned char)s2[i]);
 }

 char    *ft_strcpy(char *s1, char *s2)
 {
     int i;

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

 int ft_contains_cub(char *str)
 {
     int len;

     len = ft_strlen(str);
     if (len < 4)
         return 0;
     return (ft_strcmp(str + len - 4, ".cub") == 0);
 }


 int initialize_map(t_map *map)
 {
     map->grid = NULL;
     map->height = 0;
     map->width = 0;
     map->nexit = 0;
     map->ncoins = 0;
     return (1);
 }

 void    ft_exit(char *str, int ex)
 {
     int len;

     len = ft_strlen(str);
     if (len > 0)
         write(1, str, len);
     exit(ex);
 }

 void trim_first(char *s1, char *s2, int *start)
 {
     int i;
     int j;

     i = 0;
     while (s1[i] != '\0')
     {
         j = 0;
         while (s2[j] != '\0')
         {
             if (s1[i] == s2[j])
                 break ;
             j++;
         }
         if (s2[j] == '\0')
            break ;
         i++;
    }
     *start = i;
 }

 void trim_last(char *s1, char *s2, int *end)
 {
     int i;
     int j;

     i = ft_strlen(s1) - 1;
     while (i >= 0)
     {
         j = 0;
         while (s2[j] != '\0')
         {
             if (s1[i] == s2[j])
                 break ;
             j++;
         }
         if (s2[j] == '\0')
             break ;
         i--;
     }
     *end = i;
 }

 char *ft_strtrim(char const *s1, char const *s2)
 {
     char    *new;
     int     start;
     int     end;
     int     len;
     int     i;

     if (!s1)
         return (NULL);
     if (!s2)
         return (strdup(""));
     i = 0;
     trim_first((char *)s1, (char *)s2, &start);
     trim_last((char *)s1, (char *)s2, &end);
     if (start > end)
         return (strdup(""));
     len = end - start;
     new = malloc(sizeof(char) * (len + 1));
     if (!new)
         return (NULL);
     while (start < end)
         new[i++] = s1[start++];
     new[i] = '\0';
     return (new);
 }

 void    *ft_memcpy(void *dest, const void *src, size_t n)
 {
     unsigned char   *byte_src;
     unsigned char   *byte_dest;
     size_t          i;

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


 // int add_to_map(t_map *map, char *line)
 // {
 //  if (strncmp(line, "NO ", 3) == 0)
 //      return parse_texture(&map-north_texture, line);
 //  else if (strncmp(line, "SO ", 3) == 0)
 //      return parse_texture(&map-south_texture, line);
 //  else if (strncmp(line, "WE ", 3) == 0)
 //      return parse_texture(&map-west_texture, line);
 //  else if (strncmp(line, "EA ", 3) == 0)
 //      return parse_texture(&map-east_texture, line);
 //  else if (strncmp(line, "F ", 2) == 0)
 //      return parse_color(&map-floor, line);
 //  else if (strncmp(line, "C ", 2) == 0)
 //      return parse_color(&map-ceiling, line);
 //  // else if (line[0] == '1' || line[0] == '0')
 //  //  return add_line_to_map(map, line);
 //  // else if (line[0] == ' ')
 //  //  return 1;
 //  return 0;
 // }

 // int  add_to_map(t_map *map, char *line)
 // {
 //  int     line_length;
 //  char    **new_grid;
 //     int i;

 //     i = 0;
 //  line_length = ft_strlen(line);

 //  while (i < line_length) {
 //         if (line[i] == ' ' || line[i] == '\t') {
 //             line[i] = '-1';
 //         }
 //         i++;
 //     }
 //  if (map-height == 0)
 //      map-width = line_length;
 //     else if (line_length  map-width)
 //         map-width = line_length;
 //  new_grid = malloc((map-height + 1) * sizeof(char *));
 //  if (new_grid == NULL)
 //      return (0);
 //  i = 0;
 //  while (i < map-height)
 //  {
 //      new_grid[i] = map-grid[i];
 //      i++;
 //  }
 //  free(map-grid);
 //  map-grid = new_grid;
 //  map-grid[map-height] = malloc(map-width + 1);
 //  if (map-grid[map-height] == NULL)
 //      return (0);
 //  i = 0;
 //     while (i < map-width)
 //     {
 //         if (i < line_length)
 //             map-grid[map-height][i] = line[i];
 //         else
 //             map-grid[map-height][i] = ' ';
 //      i++;
 //     }
 //     map-grid[map-height][map-width] = '\0';
 //  map-height++;

 //  print_map(map);
 //  return (1);
 // }

 void    free_map(t_map *map)
 {
     int i;

     i = 0;
     while (i < map->height)
     {
         free(map->grid[i]);
         i++;
     }
     free(map->grid);
 }

 // void add_line_to_map(t_map *map, char *line)
 // {
 //  if (!add_to_map(map, line))
 //  {
 //      ft_exit("Error al añadir línea al mapa", 1);
 //      free(line);
 //      free_map(map);
 //  }
 //  free(line);
 // }

 void    initialize_copy(t_map *copy, t_map *original)
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

 // t_map    *copy_map(t_map *original)
 // {
 //  t_map   *copy;
 //  int     i;

 //  copy = malloc(sizeof(t_map));
 //  initialize_copy(copy, original);
 //  i = 0;
 //  while (i < copy-height)
 //  {
 //      copy-grid[i] = malloc(sizeof(char) * (copy-width + 1));
 //      if (copy-grid[i] == NULL)
 //      {
 //          free(copy-grid);
 //          free(copy);
 //          exit(1);
 //      }
 //      ft_strcpy(copy-grid[i], original-grid[i]);
 //      i++;
 //  }
 //  return (copy);
 // }

 // t_map    *check_map(int fd, t_map *map)
 // {
 //  char    *line;
 //  size_t  first_map_width;
 //  t_map   *map_valid;

 //  if (!initialize_map(map))
 //      ft_exit("Error inicializando el mapa.", 1);
 //  first_map_width = 0;
 //  while (1)
 //  {
 //      line = get_next_line(fd);
 //      if (!line)
 //          break ;
 //      add_line_to_map(map, line);
 //  }
 //  // printf(*map-grid);
 //  map_valid = copy_map(map);
 //  // if (validate_map(map))
 //  //  return (map_valid);
 //  return (NULL);
 // }

 // t_map    *check_param(int argc, char *argv[], t_map *map)
 // {
 //  int fd;

 //  if (argc != 2)
 //      error_param("Incorrect parameters", NULL);
 //  fd = open(argv[1], O_RDONLY);
 //  if (fd == -1)
 //      error_param("Error in file", NULL);
 //  if (!ft_contains_cub(argv[1]))
 //      error_param("File format not correct", NULL);
 //  return (check_map(fd, map));
 // }
 // int  validate_map(t_map *map)
 // {
 //  // int      player_count;
 //  // int      coin_count;
 //  t_game  game;

 //  // player_count = 0;
 //  // coin_count = 0;
 //  game.coins = 0;
 //  game.nplayer = 0;
 //  verify_walls(map);
 //  caracter_map(map, &game);
 //  game.ncollect = game.coins;
 //  if (map-nexit != 1 || game.nplayer != 1 || game.coins == 0)
 //      ft_exit("Error\n", 1);
 //  flood_fill(map, map-x, map-y);
 //  if (map-nexit < 1 || map-nexit  1 || map-ncoins != game.coins)
 //      ft_exit("Error\n", 1);
 //  return (1);
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

 char **check_file(char *str)
 {
     char    **new;
     int     i;
     int     fd;

     fd = 0;
     i  = -1;
     if (count_line(str) == 0)
         return (NULL);
     new = malloc(sizeof(char *) * (count_line(str) + 1));
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

 void parser_init(t_parser *parser, char *str)
 {
     parser->elem.qtt.no = 0;
     parser->elem.qtt.so = 0;
     parser->elem.qtt.we = 0;
     parser->elem.qtt.ea = 0;
     parser->elem.qtt.f = 0;
     parser->elem.qtt.c = 0;
     parser->elem.qtt.is_zero = 0;
     parser->elem.qtt.door = 0;
     parser->elem.no = NULL;
     parser->elem.so = NULL;
     parser->elem.we = NULL;
     parser->elem.ea = NULL;
     parser->elem.f = NULL;
     parser->elem.c = NULL;
     parser->rowsfile = 0;
     parser->colsx = 0;
     parser->rowsy = 0;
     parser->file = check_file(str);
 }

 void    free_parser(t_parser *parser)
 {
     int y;

     y = 0;
     while (parser && parser->file && parser->file[y])
     {
         free(parser->file[y]);
         y++;
     }
     free(parser->file);
     // ft_free_game_elements(parser);
 }

 void    free_scene(t_parser *parser, t_scene *scene)
 {
     // free_mlx(scene);
     free_parser(parser);
 }

 void    free_data(t_parser *parser, t_data *data, t_scene *scene)
 {
     int y;

     y = 0;
     while (data && data->map && data->map[y])
     {
         free(data->map[y]);
         y++;
     }
     free(data->map);
     free_scene(parser, scene);
 }

 void    ft_free_game(char **check_line)
 {
     int i;

     i = 0;
     while (check_line[i] != NULL)
     {
         free(check_line[i]);
         i++;
    }
     free(check_line);
 }

 int check_rgb_nums(char **sp)
 {
     int i;
     int j;
     int num;

     i = 0;
     j = 0;
     while (sp[i] != NULL)
     {
        num = atoi(sp[i]);    
         if (num < 0 || num > 255)
             return (1);
         i++;
     }
     return (0);
 }

 int convert_hexa(char **sp_f, char **sp_c, t_scene *scene)
 {
     int i;
     int j;
     int num;
     int num2;
     int num3;

     i = 0;
     j = 0;
     num = 0;
     num2 = 0;
     num3 = 0;
    //  while (sp_f[i] != NULL)
    //  {
         num = atoi(sp_f[0]);
         num2 = atoi(sp_f[1]);
         num3 = atoi(sp_f[2]);
         scene->fcolor = (num << 16) | (num2 << 8) | num3;
        //  i++;
    //  }
    //  while (sp_c[j] != NULL)
    //  {
         num = atoi(sp_c[0]);
         num2 = atoi(sp_c[1]);
         num3 = atoi(sp_c[2]);
         scene->ccolor = (num << 16) | (num2 << 8) | num3;
         j++;
    //  }
     return (0);
 }

 int check_f_c(t_parser *parser, t_scene *scene)
 {
  char **sp_f;
  char **sp_c;

  sp_f = ft_split(parser->elem.f, ',');
  sp_c = ft_split(parser->elem.c, ',');
  if (count_args(sp_f) != 3 || count_args(sp_c) != 3)
      return (free(sp_f), free(sp_c), 1);
  else
  {
      if (check_rgb_nums(sp_f) == 0 && check_rgb_nums(sp_c) == 0)
      {
          if (convert_hexa(sp_f, sp_c, scene) == 1)
              return (ft_free_game(sp_f), ft_free_game(sp_c), 0);
      }
      else
         return (ft_free_game(sp_f), ft_free_game(sp_c), 1);
  }
  ft_free_game(sp_f);
  ft_free_game(sp_c);
  return (0);
 }


int check_is_valid(char **check_line)
{
    int i;
    int x;
    int found;

    i = 0;
    x = 0;
    found = 0;
    while (check_line && check_line[i] != NULL)
    {
        x = 0;
        while (check_line[i][x] != '\0')
        {
            if (strchr("01 \nNSWE", check_line[i][x]) == NULL)
                return (1);
            if (strchr("NSWE", check_line[i][x]) != NULL)
                found = 1;
            x++;
        }
        i++;
    }
    return (0);
}


int check_elem1(char **check_line, t_parser *parser)
{
    if (ft_strcmp(check_line[0], "EA") == 0)
    {
        if (parser->elem.ea == NULL)
            parser->elem.ea = strdup(check_line[1]);
        parser->elem.qtt.ea++;
    }
    else if (ft_strcmp(check_line[0], "F") == 0)
    {
        if (parser->elem.f == NULL)
            parser->elem.f = strdup(check_line[1]);
        parser->elem.qtt.f++;
    }
    else if (ft_strcmp(check_line[0], "C") == 0)
    {
        if (parser->elem.c == NULL)
            parser->elem.c = strdup(check_line[1]);
        parser->elem.qtt.c++;
    }
    else
        return (check_is_valid(check_line));
    return (0);
}

int check_elem(char **check_line, t_parser *parser)
{
	if (ft_strcmp(check_line[0], "NO") == 0)
    {
        if (parser->elem.no == NULL)
            parser->elem.no = strdup(check_line[1]);
        parser->elem.qtt.no++;
    }
    else if (ft_strcmp(check_line[0], "SO") == 0)
    {
        if (parser->elem.so == NULL)
            parser->elem.so = strdup(check_line[1]);
        parser->elem.qtt.so++;
    }
    else if (ft_strcmp(check_line[0], "WE") == 0)
    {
        if (parser->elem.we == NULL)
            parser->elem.we = strdup(check_line[1]);
        parser->elem.qtt.we++;
    }
    else
        return (check_elem1(check_line, parser));
    return (0);
}

int check_nums(char *str, t_parser *parser)
{
    if (str != NULL)
    {
        if (str[0] != '1')
        {
            parser->elem.qtt.is_zero++;
            return (free(str), 1);
        }
    }
    free(str);
    return (0);
}

 int do_it(t_parser *parser, char *str)
 {
	char **check_line;
	int count;

	check_line = ft_split(str, ' ');
	count = count_args(check_line);
	if (count == 2)
	{
		if (check_elem(check_line, parser) == 1)
			return (1);
	}
    else
    {
        check_nums(ft_strtrim(check_line[0], " "), parser);
    }
    // hacer un free de check_line
	return (0);
 }

// int check_f_c(t_parser *parser, t_scene *scene)
// {
//     char **sp_f;
//     char **sp_c;

//     sp_f = ft_split(parser->elem.f, ',');
//     sp_c = ft_split(parser->elem.c, ',');
//     if (count_args(sp_f) != 3 || count_args(sp_c) != 3)
//         return (free(sp_f), free(sp_c), 1);
//     else
//     {
//         if (check_nums(sp_f[0], parser) == 0 && check_nums(sp_c[0], parser) == 0)
//         {
//             if (1)
//                 return (free(sp_f), free(sp_c), 0);
//         }
//         else
//             return (free(sp_f), free(sp_c), 1);
//     }
//     free(sp_f);
//     free(sp_c);
//     return (0);
// }

 int check_elements(t_parser *parser, t_scene *scene)
 {
     int y;

     y = 0;
     while (parser->file[y] != NULL)
     {
         if (strcmp(parser->file[y], "\n") == 0)
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

 char **copy_map(t_parser parser, int y)
 {
    char **map;
    int i;

    i = 0;
    if (y == 0)
        return (NULL);
    map = malloc(sizeof(char *) * (parser.rowsfile - y + 1));
    if (!map)
         return (NULL);
     while (parser.file[y] != NULL)
     {
         map[i] = strdup(parser.file[y]);
         y++;
         i++;
     }
     map[i] = NULL;
     return (map);
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
        y++;
        free(trimed);
     }
     free(trimed);
     data->map = copy_map(*parser, y);
     return (0);
 }

 // checking if the map its valid or not

 int is_player(char **map, int x, int y)
 {
     if (map[y][x] == 'N' || map[y][x] == 'S' ||
         map[y][x] == 'W' || map[y][x] == 'E')
         return (1);
     return (0);
 }

 t_point init_pos(void)
 {
     t_point pos;
     pos.x = -1;
     pos.y = 0;
     return (pos);
 }

 int check_player(char **map, t_parser *parser)
 {
     int     count;
     t_point pos;

     count = 0;
     pos = init_pos();
     while (map != NULL && map[pos.y] != NULL)
     {
         if (map[pos.y][++pos.x] == '\0')
         {
            pos.x = -1;
            pos.y++;
         }
         else
         {
             if (is_player(map, pos.x, pos.y))
             {
                 parser->letter_player = map[pos.y][pos.x];
                 count++;
             }
         }
     }
     if (count != 1)
         return (1);
     return (0);
 }


 int check_space(char **map, int x, int y, char letter_player)
 {
     if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != ' '
        && map[y][x] != letter_player && map[y][x] != '\0' && map[y][x] != '\n')
         return (1);
     if ((map[y][x] == '0' || map[y][x] == letter_player) && y == 0)
         return (1);
     if ((map[y][x] == '0' || map[y][x] == letter_player) && (map[y -1][x] == ' '
        || map[y + 1][x] == ' '))
         return (1);
     if ((map[y][x] == '0' || map[y][x] == letter_player) && map[y + 1] == NULL)
         return (1);
     if ((map[y][x] == '0' || map[y][x] == letter_player) &&
         (map[y][x + 1] == ' ' || map[y][x + 1] == '\0'))
         return (1);
     if ((map[y][x] == '0' || map[y][x] == letter_player) &&
         map[y][x - 1] == ' ')
         return (1);
     return (0);
 }

 int check_map(t_parser *parser, t_scene scene)
 {
    int y;
    int x;

     y = 0;
     x = 0;
     if (check_player(scene.map, parser) == 1)
         return (1);
     while (scene.map != NULL && scene.map[y] != NULL)
     {
         if (scene.map[y][x] == '\0')
         {
             x = 0;
             y++;
         }
         else
         {
             if (check_space(scene.map, x, y, parser->letter_player) == 1)
                 return (1);
         }
         x++;
     }
     return (0);
 }

void calc_x_y(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (data->map[i] != NULL)
    {
        j = 0;
        while (data->map[i][j] != '\0')
            j++;
        i++;
    }
    data->rowsy = i;
    data->colsx = j;
}

void    delete_enter(char **map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i] != NULL)
    {
        j = 0;
        while (map[i][j] != '\0')
        {
            if (map[i][j] == '\n')
                map[i][j] = '\0';
            j++;
        }
        i++;
    }
}

size_t strlcpy(char *dst, const char *src, size_t dstsize)
{
    const char *s = src;
    size_t n = dstsize;

    if (n != 0 && --n != 0)
    {
        do {
            if ((*dst++ = *s++) == 0)
                break;
        } while (--n != 0);
    }

    if (n == 0)
    {
        if (dstsize != 0)
            *dst = '\0';
        while (*s++)
            ;
    }

    return (s - src - 1);
}

char **padding_map(char **map, int *rows, int *cols)
{
    char    **new_map;
    int     i;

    delete_enter(map);
    *rows += 10 * 2;
    *cols += 10 * 2;
    new_map = malloc(sizeof(char *) * (*rows + 1));
    if (!new_map)
        return (NULL);
    i = 0;
    while (i < *rows)
    {
        new_map[i] = malloc(sizeof(char) * (*cols + 1));
        if (!new_map[i])
            return (ft_free_game(new_map), NULL);
        memset(new_map[i], ' ', *cols + 1);
        if (i >= 10 && i < *rows - 10)
            strlcpy(new_map[i] + 10 - 2, map[i - 10], *cols + 1);
        new_map[i][*cols] = '\0';
        i++;
    }
    new_map[i] = NULL;
    return (new_map);
}

 void set_scene(t_scene *scene, t_parser parser, t_data *data)
 {
    calc_x_y(data);
    scene->rows = parser.rowsy;
    scene->cols = parser.colsx;
    scene->width = 1920;
    scene->height = 1080;
    // cubrir el mapa para protegerlo para el raycasting
    // esta mal, en el mapa se queda solo espacios blancos y ya no verifica bien lo siguiente !!!
    scene->map = padding_map(data->map, &scene->rows, &scene->cols);
    // scene->player = set_player(scene->map);
    // set_mlx(scene, parser, &data);
    if (scene->map == NULL)
    {
        free_data(&parser, data, scene);
        // mlx_destroy_window(scene->mlx, scene->win);
        exit(0);
    }
    // set_scene_image(scene, parser, *data);
 }

 int main(int argc, char *argv[])
 {
     t_data data;
     t_parser parser;
     t_scene scene;
     // t_keys keys;
     if (argc != 2)
         return (write(2, "Bad arguments\n", 14), 2);
     parser_init(&parser, argv[1]);
     if (parser.file == NULL)
         return (free_parser(&parser), 1);
     if (check_elements(&parser, &scene))
         return (write(2, "Error file\n", 11), free_parser(&parser), 1);
     if (init_map(&data, &parser))
         return (write(2, "Error map\n", 10), free_data(&parser, &data,
 &scene), 1);
     set_scene(&scene, parser, &data);
     if (check_map(&parser, scene))
     {
         write(2, "Error map\n", 10);
        free_data(&parser, &data, &scene);
         exit(1);
     }
     // inicializacion de keys
     // funcion que escucha los movimientos
     // mlx_loop_hook(scene.mlx, &loop, &data);
     // mlx_loop(scene.mlx);
     // t_cub3d  game;
     // t_map    map;
     // t_map    *map_pars;

     // map_pars = check_param(argc, argv, &map);
     // if (!map_pars)
     // {
     //     printf("Error: No se pudo inicializar el juego.\n");
     //     return (1);
     // }
 }
