#include "cub3d.h"

char **copy_map(t_parser parser, int y)
 {
    char    **map;
    int     i;

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
		// printf("mapa???: %s\n", *scene.map);
         if (scene.map[y][x] == '\0')
         {
             x = 0;
             y++;
         }
         else
         {  // revisar esta funcion
			 // no hay nada en el mapa, porque???
             if (check_space(scene.map, x, y, parser->letter_player) == 1)
                 return (1);
         }
		//  printf("%s", scene.map[y][x]);
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

void	delete_enter(char **map)
{
	int	i;

	i = 0;
	while (map != NULL && map[i] != NULL)
	{
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
}