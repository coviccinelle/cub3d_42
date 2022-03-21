#include "cub3d.h"

int	ft_find(char c, const char *str)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while (str[i])
			i++;
		return (i);
	}
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i] != c)
	{
		if (s[i] != '\0')
			return (0);
		i++;
	}
	return (&s[i]);
}

void	view_tab(char **s)
{
	if (s)
	{
		while (*s)
		{
			printf("%s\n", *s);
			s++;
		}
	}
}
