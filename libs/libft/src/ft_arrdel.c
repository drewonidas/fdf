#include "libft.h"

void		ft_arrdel(char ***arr_ptr)
{
	int		i;
	char	**tmp;

	tmp = *arr_ptr;
	i = 0;
	if (tmp != NULL)
	{
		while (tmp[i] != NULL)
			ft_strdel(&tmp[i++]);
		*arr_ptr = tmp;
		free(*arr_ptr);
		*arr_ptr = NULL;
	}
}
