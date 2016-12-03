#include "libft.h"

char			**ft_arrdup(char **src)
{
	int			i;
	char		**dst;

	i = 0;
	while(src[i++])
		;
	dst = (char **) malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (src[i])
	{
		dst[i] = ft_strdup(src[i]);
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
