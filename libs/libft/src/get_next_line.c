#include "get_next_line.h"
#include <stdio.h>

/*
static unsigned int	indexof(char c, char *s)
{
	unsigned int	i;

	i = ft_strlen(s) - 1;
	while (s[i] != c)
		i--;
	return (i);
}

static unsigned int	ln_cnt(char *s)
{
	unsigned int	c;

	c = 0;
	while (*s)
	{
		if (*s == '\n')
			c++;
		s++;
	}
	return (c);
}
*/
static char			*process(char *buff, char ***tmp)
{
	static char		*tmp2 = NULL;
	char			*tmp3;
	char			*line;

	tmp3 = NULL;
	line = NULL;
	if (tmp2 == NULL)
		tmp2 = ft_strdup((const char *)buff);
	else
	{
		tmp3 = tmp2;
		tmp2 = ft_strjoin((char const *)tmp3, (char const *)buff);
		ft_strdel(&tmp3);
	}
	if (ft_strchr((const char *)buff, '\n') != NULL)
	{
		*tmp = ft_strsplit((char const *)tmp2, '\n');
		line = ft_strtrim(*tmp[0]);
//		int cnt = ln_cnt(tmp2);
//		int g = indexof('\n', buff);
		ft_strdel(&tmp2);
//		if (buff[++g] != '\0')
//		{
			//ft_putendl("brah");
			//ft_putendl(*tmp[cnt - 1]);
//			tmp2 = ft_strdup((char const *)*tmp[cnt - 1]);
//			ft_strdel(&(*tmp[cnt - 1]));
//		}
		return (line);
	}
	return (NULL);
}

static int				get_new_line(char **line, int fd, char ***tmp)
{
	int					size;
	char				*buff;
	
	buff = ft_strnew(BUFF_SIZE);
	size = 0;
	while ((size = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[size] = '\0';
		if ((*line = process(buff, tmp)) != NULL)
		{
			ft_strdel(&buff);
			return (1);
		}
		ft_strclr(buff);
	}
	ft_strdel(&buff);
	return (size);
}

int						get_next_line(const int fd, char **line)
{
	static char			**tmp = NULL;
	static unsigned int	c = 1;
//	static unsigned int c2 = 1;
	int					status;

	status = 0;
//	if (*line != NULL)
//		ft_strdel(line);
	if (tmp != NULL)
	{
		if (tmp[c] != NULL)
			*line = ft_strtrim((const char *)tmp[c++]);
		//ft_strdel(&tmp[c++]);
		else
			ft_arrdel(&tmp);
	}
	else
	{
		c = 1;
		status = get_new_line(line, fd, &tmp);
		//ft_putendl("gosh");
		return (status);
	}
	return (1);
}
