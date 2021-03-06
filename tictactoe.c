/* Program name : Tictactoe.c */
#include<stdio.h>

#define LINE printf("+---+---+---+\n")


int main(void)
{
    int turn;
    int player, winner, choice, row, col, line;
    char board[3][3] = { {'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'},
                       };
    player = 0;
    winner = 0; 
    choice = 0;
    row = 0;
    col = 0;
    line = 0;

    /* draw board */
    for (turn = 0; turn < 9 && winner == 0; turn++){
      printf("\n\n");
      LINE;
      printf("| %c | %c | %c |\n", 
               board[0][0], board[0][1], board[0][2] );
      LINE;
      printf("| %c | %c | %c |\n", 
               board[1][0], board[1][1], board[1][2] );
      LINE;
      printf("| %c | %c | %c |\n", 
               board[2][0], board[2][1], board[2][2] );
      LINE;

      player = (turn % 2) + 1; /* select player */

      /* player selection */
      do {
        printf("\nPlay %d, enter your go %c: ", 
                        player, (player == 1) ? 'X' : 'O');
        scanf("%d", &choice); 

        row = --choice / 3;
        col = choice % 3;

      }while(choice < 0 || choice > 9 || board[row][col] > '9');
      /* insert player symbol */
      board[row][col] = (player == 1) ? 'X' : 'O'; 

      /* check for winner */
      if ((board[0][0] == board[1][1] &&
           board[0][0] == board[2][2]) || 
          (board[0][2] == board[1][1] &&
           board[0][2] == board[2][0])) {
        winner = player;
      }else{
        /* check row and col for winner */
        for ( line = 0; line < 2; line ++){
          if ((board[line][0] == board[line][1] &&
               board[line][1] == board[line][2]) ||
              (board[0][line] == board[1][line] &&
               board[0][line] == board[2][line])) {
            winner = player;          
          }/* end if check line */
        }/* end for loop check line */
      }/* end else check for winner */
    } /* end for loop turn */

    /* game over, show final board */
    printf("\n\n");
    LINE;
    printf("| %c | %c | %c |\n", 
               board[0][0], board[0][1], board[0][2] );
    LINE;
    printf("| %c | %c | %c |\n", 
               board[1][0], board[1][1], board[1][2] );
    LINE;
    printf("| %c | %c | %c |\n", 
               board[2][0], board[2][1], board[2][2] );
    LINE;

    if (winner == 0) {
      printf("\nHow boring, it is a draw\n");
    }
    else {
      printf("\nPLAYER %d YOU ARE THE WINNER!\n\n", winner);
    }

    return 0;
} /* end main function */