void    ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

size_t  ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int     ft_strcmp(char *s, char *t)
{
	while (*s && (*s == *t))
	{
		s++;
		t++;
	}
	return (*s - *t);
}

void	exit_error_fd(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	exit (0);
}

int	ft_strcmp_end(char *s, char *t)
{
	if (ft_strlen(s) < ft_strlen(t))
		return (0);
	return (0 == ft_strcmp(&s[ft_strlen(s) - ft_strlen(t)], t));
}