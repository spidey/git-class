#include <stdio.h>
#include <stdlib.h>


#define ONGOING 0
#define STALEMATE 1
#define X_WON 2
#define O_WON 3
#define INVALID 4


static int checkState_(char board[3][3]);
static void printBoard_(char board[3][3]);
static const char *stateName_(int state);



/*----------------------------------------------------------------------------*/
int
main(int argc, char *argv[])
{
	char board[3][3];
	int i;
	int j;
	int state;

	if (argc != 10)
	{
		printf("Invalid parameters! Usage:\n");
		printf("ttt b11 b12 b13 b21 b22 b23 b31 b32 b33\n");
		printf("Where bij indicates the board position at i-row and "
								 "j-column,\n");
		printf("being either X or O. Use _ for empty positions.\n");
		printf("As suggestions, one could invoke the command with line "
		      "breaks, using the \\ character at the end of a line.\n");
		exit(1);
	}

	for(i = 0; i < 3; ++i)
	{
		for(j = 0; j < 3; ++j)
		{
			board[i][j] = argv[i*3 + j][0];
		}
	}

	state = checkState_(board);
	printf("Tic Tac Toe board\n");
	printBoard_(board);
	printf("state is %s.\n", stateName_(state));

	return 0;
}



/*----------------------------------------------------------------------------*/
static int
checkState_(char board[3][3])
{
	(void)board;
	return INVALID;
}



/*----------------------------------------------------------------------------*/
static void
printBoard_(char board[3][3])
{
	printf("%c|%c|%c\n", board[0][0], board[0][1], board[0][2]);
	printf("-----\n");
	printf("%c|%c|%c\n", board[1][0], board[1][1], board[1][2]);
	printf("-----\n");
	printf("%c|%c|%c\n", board[2][0], board[2][1], board[2][2]);
}



/*----------------------------------------------------------------------------*/
static const char *
stateName_(int state)
{
	const char *stateName;

	switch(state)
	{
		case ONGOING:
			stateName = "on going";
			break;
		case STALEMATE:
			stateName = "stalemate";
			break;
		case X_WON:
			stateName = "won by X";
			break;
		case O_WON:
			stateName = "won by O";
			break;
		case INVALID:
			stateName = "invalid";
			break;
		default:
			stateName = "unknown";
			break;
	}

	return stateName;
}

