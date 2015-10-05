#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNKNOWN 0
#define ONGOING (1<<0)
#define STALEMATE (1<<1)
#define X_WON (1<<2)
#define O_WON (1<<3)
#define INVALID (1<<4)

static int isValidPlay_(char play);
static int checkState_(char board[3][3]);
static int checkRow_(char board[3][3], int row);
static int checkColumn_(char board[3][3], int column);
static int checkDiagonal_(char board[3][3], int diagonal);
static int checkStateFrom3Pos_(char pos1, char pos2, char pos3);
static void printBoard_(char board[3][3]);
static const char *stateName_(int state);

int main(int argc, char *argv[]) {
	char board[3][3];
	int i;
	int j;
	int state = UNKNOWN;

	if (argc != 10) {
		printf("Invalid parameters! Usage:\n");
		printf("ttt b11 b12 b13 b21 b22 b23 b31 b32 b33\n");
		printf("Where bij indicates the board position at i-row and "
								 "j-column,\n");
		printf("being either X or O. Use _ for empty positions.\n");
		printf("As suggestions, one could invoke the command with line "
		      "breaks, using the \\ character at the end of a line.\n");
		exit(1);
	}

	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 3; ++j) {
			board[i][j] = argv[i*3 + j + 1][0];
			if (!isValidPlay_(board[i][j])) {
				state = INVALID;
			}
		}
	}

	if (state != INVALID) {
		state = checkState_(board);
	}

	printf("Tic Tac Toe board\n");
	printBoard_(board);
	printf("state is %s.\n", stateName_(state));

	return 0;
}

static int isValidPlay_(char play) {
	int rc = (NULL != strchr("XO_", play));
	return rc;
}

static int checkState_(char board[3][3]) {
	int state = UNKNOWN;
	int i;

	for(i = 0; i < 3; ++i) {
		state |= checkRow_(board, i);
		state |= checkColumn_(board, i);
	}

	for(i = 0; i < 2; ++i) {
		state |= checkDiagonal_(board, i);
	}

	if (state & INVALID) {
		state = INVALID;
	} else if (state & X_WON) {
		state = X_WON;
	} else if (state & O_WON) {
		state = O_WON;
	} else if (state & ONGOING) {
		state = ONGOING;
	} else {
		state = STALEMATE;
	}

	return state;
}

static int checkRow_(char board[3][3], int row) {
	int state;
	char pos1 = board[row][0];
	char pos2 = board[row][1];
	char pos3 = board[row][2];

	state = checkStateFrom3Pos_(pos1, pos2, pos3);
	return state;
}

static int checkColumn_(char board[3][3], int column) {
	int state;
	char pos1 = board[0][column];
	char pos2 = board[1][column];
	char pos3 = board[2][column];

	state = checkStateFrom3Pos_(pos1, pos2, pos3);
	return state;
}

static int checkDiagonal_(char board[3][3], int diagonal) {
	int state;
	char pos1 = board[0][0];
	char pos2 = board[1][1];
	char pos3 = board[2][2];
	if (1 == diagonal) {
		pos1 = board[0][2];
		pos3 = board[2][0];
	}

	state = checkStateFrom3Pos_(pos1, pos2, pos3);
	return state;
}

static int checkStateFrom3Pos_(char pos1, char pos2, char pos3) {
	int state = UNKNOWN;

	if (pos1 == pos2 && pos2 == pos3) {
		if ('X' == pos1) {
			state = X_WON;
		} else if ('O' == pos1) {
			state = O_WON;
		} else {
			state = ONGOING;
		}
	} else if ('_' == pos1 || '_' == pos2 || '_' == pos3) {
		state = ONGOING;
	}

	return state;
}

static void printBoard_(char board[3][3]) {
	printf("%c|%c|%c\n", board[0][0], board[0][1], board[0][2]);
	printf("-----\n");
	printf("%c|%c|%c\n", board[1][0], board[1][1], board[1][2]);
	printf("-----\n");
	printf("%c|%c|%c\n", board[2][0], board[2][1], board[2][2]);
}

static const char *stateName_(int state) {
	const char *stateName;

	switch(state) {
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
		case UNKNOWN:
		default:
			stateName = "unknown";
			break;
	}

	return stateName;
}

