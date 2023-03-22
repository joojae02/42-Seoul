#include <stdio.h>

int	dup_check(int board[6][6], int row, int col, int n)
{
	int i;
	
	i = 0;
	while(++i < 5)
		if (board[i][col] == n)
			return (0);
	i = 0;
	while(++i < 5)
		if (board[row][i] == n)
			return (0);
	return (1);
}
int	inc_check (int board[6][6])
{
	int i;
	int j;
	int l;
	int check;
	int tmp;

	i = 0;
	j = 0;
	while (++j < 5)
	{
		l = board[0][j];
		i = 1;
		check = 1;
		tmp =  board[i][j];
		while (++i < 5)
		{
			if (tmp < board[i][j])
			{
				check += 1;
				tmp = board[i][j];
			}
		}
		if (check != l)
			return (0);
	}
	while (--j > 0)
	{
		l = board[5][j];
		i = 4;
		check = 1;
		tmp =  board[i][j];
		while (--i > 0)
		{
			if (tmp < board[i][j])
			{
				check += 1;
				tmp = board[i][j];
			}
		}
		if (check != l)
			return (0);
	}
	i = 0;
	while (++i < 5)
	{
		l = board[i][0];
		j = 1;
		check = 1;
		tmp =  board[i][j];
		while (++j < 5)
		{
			if (tmp < board[i][j])
			{
				check += 1;
				tmp = board[i][j];
			}
		}
		if (check != l)
			return (0);
	}
	while (--i > 0)
	{
		l = board[i][5];
		j = 4;
		check = 1;
		tmp =  board[i][j];
		while (--j > 0)
		{
			if (tmp < board[i][j])
			{
				check += 1;
				tmp = board[i][j];
			}
		}
		if (check != l)
			return (0);
	}
	return (1);
}

void	dfs(int board[6][6], int row, int col)
{
	int i;
	if (row == 5)
	{
		if (inc_check(board))
			for (int i = 1; i< 5; i++)
			{
				for (int j = 1; j < 5; j++)
					printf("%d ", board[i][j]);
				printf("\n");
			}
		return ;
	}
	if (col == 5)
	{
		dfs(board, row + 1, 1);
		return ;
	}
	if (board[row][col] != 0)
		dfs(board, row, col + 1);
	else
	{	
		i = 0;
		while (++i < 5)
		{
			if (dup_check(board, row, col, i))
			{
				board[row][col] = i;
				dfs(board, row, col + 1);
			}
		}
		board[row][col] = 0;
	}
}
int main(void)
{
	int board[6][6] = {{0, 4, 2, 1, 3, 0},
						{3, 0, 0, 0, 0, 2},
						{2, 0, 0, 0, 0, 2},
						{2, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 0, 3},
						{0, 1, 2, 2, 2, 0}};

	for (int i = 1; i< 5; i++)
	{
		for (int j = 1; j < 5; j++)
 		printf("%d, ", board[i][j]);
	 	printf("\n");
	}
	//dfs(board, 1, 1);
}


void set_base(char board[][6], int i, int j)
{
	j = 0;
	while (++j <= 4)
	{
		i = 0;
		if (board[0][j] == 1)
			board[1][j] = 4;
		else if (board[0][j] == 4)
			while (++i <= 4)
				board[j][i] = i;
		i = 0;
		if (board[j][0] == 1)
			board[j][1] = 4;
		else if (board[j][0] == 4)
			while (++i <= 4)
				board[j][i] = i;
	}
	j = 0;
	while (++j < 5)
	{
		i = 5;
		if (board[5][j] == 1)
			board[4][j] = 4;
		else if (board[5][j] == 4)
			while (--i >= 1)
				board[j][i] = i;
		i = 5;
		if (board[j][5] == 1)
			board[j][4] = 4;
		else if (board[j][5] == 4)
			while (--i >= 1)
				board[j][i] = i;
	}
}
