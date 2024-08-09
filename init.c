#include <stdio.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      board[i][j] = ' ';
    }
  }
}

void displayBoard(char board[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf(" %c ", board[i][j]);
      if (j < SIZE - 1) {
        printf("|");
      }
    }
    printf("\n");
    if (i < SIZE - 1)
      printf("---|---|---\n");
  }
}

void playerInput(char board[SIZE][SIZE], char character) {
  int row, cols;
  while (1) {
    printf("Choose cols and rows that you want to put your %c: \n", character);
    scanf("%d %d", &row, &cols);

    if (row >= 0 && row < SIZE && cols >= 0 && cols < SIZE &&
        board[row][cols] == ' ') {
      board[row][cols] = character;
      break;
    } else {
      printf("Move is not valid try again");
    }
  }
}

int checkWin(char board[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&
        board[i][0] != ' ')
      return 1;
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&
        board[0][i] != ' ')
      return 1;
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] &&
      board[0][0] != ' ')
    return 1;
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] &&
      board[0][2] != ' ')
    return 1;
  return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (board[i][j] == ' ')
        return 0;
    }
  }
  return 1;
}

int main() {
  char currentCharacter = 'X';
  char board[SIZE][SIZE];
  initializeBoard(board);

  while (1) {
    displayBoard(board);
    playerInput(board, currentCharacter);

    if (checkWin(board)) {
      displayBoard(board);
      printf("Player %c wins!\n", currentCharacter);
      break;
    }
    if (checkDraw(board)) {
      displayBoard(board);
      printf("It's a draw!\n");
      break;
    }
    currentCharacter = (currentCharacter == 'X') ? 'O' : 'X';
  }

  return 0;
}
