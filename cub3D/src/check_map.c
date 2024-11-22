#include <cub3d.h>

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