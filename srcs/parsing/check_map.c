void	check_map(t_game *game)
{
    // les murs : map doit etre entouree de 1
// il doit y avoir 1 joueur, ni plus ni moins
//pas de caractere autre que : 1 P 
// F ou C mauvaise donnee?
//so basically you see a very big room, with a wall around it (the values 1), a small room inside it (the values 2), a few pilars (the values 3), and a corridor with a room (the values 4)
}

// a revoir ci-dessous:
void	check_keys(t_game *game, int i, int j)
{
	char	c;

	c = game->map[i][j];
	if (!(find_me(c, "P01EC\n")))
		error("Error\nInput wrong characters! Please check again!\n", game);
	if (c == 'C')
		game->nb_c += 1;
	if (c == 'E')
		game->nb_e += 1;
	if (c == 'P')
		game->nb_p += 1;
}

void	check_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_height)
	{
		if ((ft_strlen(game->map[i]) - 1) != game->map_width)
			error("Error\nMap is not rectangle\n", game);
		j = 0;
		while (game->map[i][j + 1])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			check_keys(game, i, j);
			check_walls(game->map[i][j], i, game->map_height, game);
			check_walls_h(game->map[i][j], j, game->map_width, game);
			j++;
		}
		i++;
	}
	if (game->nb_e < 1 || game->nb_p != 1)
		error("Error\nMap error: wrong number of P, C or E\n", game);
}