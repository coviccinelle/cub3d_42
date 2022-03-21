int	move_player(int next_x, int next_y, t_game *game)
{
	if ((game->map[next_y][next_x]) == '1' ||
			((game->map[next_y][next_x] == 'E')
			&& (game->player.collectibles < game->total_collectibles)))
		return (0);
	winning_winner_looser(next_x, next_y, game);
	game->player.orientation_x = next_x - game->player.curr_x;
	game->player.orientation_y = next_y - game->player.curr_y;
	game->player.curr_x = next_x;
	game->player.curr_y = next_y;
	game->map[game->player.curr_y][game->player.curr_x] = 'P';
	game->player.n_moves++;
	printf("Number of moves : %d\n", game->player.n_moves);
	game->map[game->player.prev_y][game->player.prev_x] = '0';
	game->player.prev_x = game->player.curr_x;
	game->player.prev_y = game->player.curr_y;
	return (0);
}

int	handle_player_moves(int keysym, t_game *game)
{
	if (keysym == ESC)
		exit_game(game);
	if ((keysym == UP) || (keysym == UP_W))
		move_player(game->player.curr_x, game->player.curr_y - 1, game);
	else if ((keysym == DOWN) || (keysym == DOWN_S))
		move_player(game->player.curr_x, game->player.curr_y + 1, game);
	else if ((keysym == LEFT) || (keysym == LEFT_A))
		move_player(game->player.curr_x - 1, game->player.curr_y, game);
	else if ((keysym == RIGHT) || (keysym == RIGHT_D))
		move_player(game->player.curr_x + 1, game->player.curr_y, game);
	return (0);
}