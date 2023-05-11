#include <stdio.h>

void set_base1(int board[][6]);
void set_base2(int board[][6]);

int main(void)
{
	int board[6][6] = {{0, 4, 2, 1, 3, 0},
						{3, 0, 0, 0, 0, 2},
						{2, 0, 0, 0, 0, 2},
						{2, 0, 0, 0, 0, 1},
						{1, 0, 0, 0, 0, 3},
						{0, 1, 2, 2, 2, 0}};
	set_base1(board);
	set_base2(board);
	for (int i = 1; i< 5; i++)
	{
		for (int j = 1; j < 5; j++)
 		printf("%d, ", board[i][j]);
	 	printf("\n");
	}
	//dfs(board, 1, 1);
}


void set_base2(int board[][6])
{
	int	i;
	int	j;

	j = 0;
	while (++j < 5)
	{
		i = 5;
		if (board[5][j] == 1)
			board[4][j] = 4;
		else if (board[5][j] == 4)
			while (--i >= 1)
				board[i][j] = i;
		i = 5;
		if (board[j][5] == 1)
			board[j][4] = 4;
		else if (board[j][5] == 4)
			while (--i >= 1)
				board[j][i] = i;
	}
}

void set_base1(int board[][6])
{
	int	i;
	int	j;

	j = 0;
	while (++j <= 4)
	{
		i = 0;
		if (board[0][j] == 1)
			board[1][j] = 4;
		else if (board[0][j] == 4)
			while (++i <= 4)
				board[i][j] = i;
		i = 0;
		if (board[j][0] == 1)
			board[j][1] = 4;
		else if (board[j][0] == 4)
			while (++i <= 4)
				board[j][i] = i;
	}
}
