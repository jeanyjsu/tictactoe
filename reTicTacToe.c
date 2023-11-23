//reTicTacToe.c
//This is a small Tic Tac Toe game where the user will be against computer.
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

//initializing the tictactoe grids to be ' ', by looping through row and col.  
void initialTicGrid(char grid[3][3])
{
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			grid[row][col] = ' ';
		}
	}
}

//prints the tic tac toe grid by looping throught the row abd col, with the symbol(X, O, or  ).
void displayTicGrid(char grid[3][3])
{
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			if(col > 0)
			{
				printf("|");
			}
			printf(" %c ", grid[row][col]);
		}
		printf("\n");

        	if(row < 2)
        	{
                	printf("---|---|---\n");
        	}
	}
}

//checks if the coordination provided is within the grid, and if they are still empty. 
int moveValid(char grid[3][3], int x, int y)
{
	int isValid = 0;
	if(x >= 0 && x < 3 && y >= 0 && y < 3 && grid[x][y] == ' ')
	{
		isValid = 1;
	}
	return isValid;
}

//mark the empty grid of the particular coordinate with the symbol based on whose turn it is(X or O)
void markGrid(char grid[3][3], int x, int y, char player)
{
	grid[x][y] = player;
}

//checks if there is a winner, the if statement checks horizonal, vertial and both directions of
//diagonal win condition. 
bool bingo(char grid[3][3], char player)
{
	for(int i = 0; i < 3; i++)
	{
		if((grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
		|| (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
		|| (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
		|| (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player))
		{
			return true;
		}
	}
	return false;
}

//check for no winners by looping through the grids to look for any remaining empty spaces
bool draw(char grid[3][3])
{
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			if(grid[row][col] == ' ')
			{
				return false;
			}
		}
	}
	return true; 
}

//generates the coordination for the computer to mark on the grid automatically by utilizing 
//the rand() range from 0 to 2. It will keep regenerate the coordinates until the move is valid
//by using the moveValid() defined above. 
//Then mark the grid with the computer symbol(O) while also printing the coordination.
void computerMove(char grid[3][3], char computer)
{
	int x, y;

	do
	{
		x = rand()%3;
		y = rand()%3;
	}
	while(!moveValid(grid, x, y));

	markGrid(grid, x, y, computer);
	printf("Computer's move: %d, %d\n", x, y);
}

int main()
{
    char userName[25];
    char grid[3][3];
	int x, y;

	printf("*****************************************\n");
	printf("Tic Tac Toe\n");
	printf("COMP 2131 -Winter 2023\n");
	printf("You will be playing against the computer\n");
	printf("*****************************************\n");
	printf(" \n");
    printf("What is your name?\n");
	//setting the maximum number of characters for the userName to 25
    scanf("%24s", userName);
    printf("Hello %s ... Let's have fun!!! You = X | Computer = O\n", userName);

    initialTicGrid(grid);

	//using the do...while loop so the game continues till either a winner is determined or a draw 
	do
	{
		displayTicGrid(grid);

		printf("Enter X,Y coordinates for your move: ");
		scanf("%d,%d", &x, &y);

		if(moveValid(grid, x, y))
		{
			markGrid(grid, x, y, 'X');

			//chech for winner or draw
			if(bingo(grid, 'X'))
			{
				printf("********\n");
				printf("You win!\n");
				printf("********\n");
				displayTicGrid(grid);
				break;
			}
			else if(draw(grid))
			{
				printf("*************\n");
				printf("It's a draw!\n");
				printf("*************\n");
				displayTicGrid(grid);
				break;
			}
		}
		else
		{
			printf("Please make sure your coordination is within the grid, and the spot is empty.\n");
			continue;
		}

		computerMove(grid, 'O');
		
		if(bingo(grid, 'O'))
		{
			printf("*************\n");
			printf("Computer win!\n");
			printf("*************\n");
			displayTicGrid(grid);
			break; 
		}
		else if(draw(grid))
		{
			printf("************\n");
			printf("It's a draw!\n");
			printf("************\n");
			displayTicGrid(grid);
			break;
		}
	}while(!draw(grid)|| !bingo(grid, 'X') || !bingo(grid, 'O'));
}

