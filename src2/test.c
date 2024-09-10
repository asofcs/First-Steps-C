#include <stdio.h>
#include <stdlib.h>


#define PLAYER2SYMB 'o'
#define PLAYER1SYMB 'x'


char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; // board to fill
int player = 1; // player number
int choice = 0; // position to fill


void clrscr(); // clear screen
int checkForWin(); // checks for winners
void drawBoard();  // draw the complete board for each player turn
void markBoard(char mark);  // update board and check for invalid choice



int main(void)
{
    char mark = ' ';
    int winFlag = -1;
    
    do
    {
        /* draw board*/
        drawBoard();
        
        /*change turns*/
        player = (player % 2) ? 1 : 2;
        
        printf("Player %d, enter a number(1-9. 1-(0,0); 9-(2,2)): ", player);
        scanf("%d", &choice);
        
        /*set the correct character based on player turn*/
        mark = (player == 1) ? PLAYER1SYMB : PLAYER2SYMB;
        
        /*fill board*/
        markBoard(mark);
        
        /*check winner*/
        winFlag = checkForWin();
        
        player++;    
        
    }while (winFlag == -1);
    
    drawBoard();
    
    if (winFlag == 1)
    {
        player = player -1;
        printf(" \n\n\tPlayer %d win \n\n ", player);
    }
    else
    {
        printf(" \n\n\tGame Draw \n\n ");
    }
    return 0;
}


/*
 *CLEAR SCREEN 
 */
void clrscr()
{
    system("clear"); // UNIX: "clear"; POSIX: "cls"
}

/*
 *DISPLAY BOARD 
 */
void drawBoard()
{
    /*clear screen*/
    clrscr();
    
    /*display board*/
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (%c)  -  Player 2 (%c)\n\n\n", PLAYER1SYMB, PLAYER2SYMB);
    printf("  %c    %c    %c \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c    %c    %c \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c    %c    %c \n", board[2][0], board[2][1], board[2][2]);
}

/*
 *FILL/MARK POSITION IN THE BOARD
 */
void markBoard(char mark)
{        
    /*Fill first position*/
    if ((choice == 1) && (board[0][0] == ' '))
    {
        board[0][0] = mark;
    }
    
    /*Fill second position*/
    else if ((choice == 2) && (board[0][1] == ' '))
    {
        board[0][1] = mark;
    }
    
    /*Fill third position*/
    else if ((choice == 3) && (board[0][2] == ' '))
    {
        board[0][2] = mark;
    }
    
    /*Fill fourth position*/
    else if ((choice == 4) && (board[1][0] == ' '))
    {
        board[1][0] = mark;
    }
    
    /*Fill fifth position*/
    else if ((choice == 5) && (board[1][1] == ' '))
    {
        board[1][1] = mark;
    }
    
    /*Fill sixth position*/
    else if ((choice == 6) && (board[1][2] == ' '))
    {
        board[1][2] = mark;
    }
    
    /*Fill seventh position*/
    else if ((choice == 7) && (board[2][0] == ' '))
    {
        board[2][0] = mark;
    }
    
    /*Fill eighth position*/
    else if ((choice == 8) && (board[2][1] == ' '))
    {
        board[2][1] = mark;
    }
    
    /*Fill ninth position*/
    else if ((choice == 9) && (board[2][2] == ' '))
    {
        board[2][2] = mark;
    }
    
    else
    {
        /*Force current player if invalid move, and read another value.*/
        printf("Invalid move!");
        player--;
        getchar();
    }
    
}

/*
 *CHECK FOR WINNER OR FULL SQUARE 
 * 0: FULL SQUARE BUT NOT ANY WINNER
 * 1: WINNER FOUND
 * -1: OTHER
 */

int checkForWin()
{
    int returnVal = -1;
    int counterFilled = 0;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                counterFilled = counterFilled +1;
            }
        }
    }
    
    /*Validate diagonals*/
    if ((board[0][0] != ' ') && (board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))
    {
        returnVal = 1;
    }
    
    else if ((board[2][0] != ' ') && (board[2][0] == board[1][1]) && (board[2][0] == board[0][2]))
    {
        returnVal = 1;
    }
    
    /*Validate horizontal lines*/
    else if ((board[0][0] != ' ') && (board[0][0] == board[0][1]) && (board[0][0] == board[0][2]))
    {
        returnVal = 1;
    }
    
    else if ((board[1][0] != ' ') && (board[1][0] == board[1][1]) && (board[1][0] == board[1][2]))
    {
        returnVal = 1;
    }
    
    else if ((board[2][0] != ' ') && (board[2][0] == board[2][1]) && (board[2][0] == board[2][2]))
    {
        returnVal = 1;
    }
    
    /*Validate vertical lines*/
    else if ((board[0][0] != ' ') && (board[0][0] == board[1][0]) && (board[0][0] == board[2][0]))
    {
        returnVal = 1;
    }
    
    else if ((board[0][1] != ' ') && (board[0][1] == board[1][1]) && (board[0][1] == board[2][1]))
    {
        returnVal = 1;
    }
    
    else if ((board[0][2] != ' ') && (board[0][2] == board[1][2]) && (board[0][2] == board[2][2]))
    {
        returnVal = 1;
    }
    
    /*Validate full square*/
    else if (counterFilled == 9)
    {
        returnVal = 0;
    }
    
    return returnVal;
}
