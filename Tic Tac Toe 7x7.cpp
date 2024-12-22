//Tic Tac Toe game made by Kuro201.
//For practice, if you found any bugs, feel free to tell me!
// default is 7x7 grid, 5 same letters to win
// This should work no matter the size of grid and the same letters to win 
#include <iostream>
#include <string>
#include <Windows.h>

const int boardWidth = 7;
const int boardHeight = 7;
const int numberOfLetterToWin = 5;

void boardMiddleAndBotton() {
    for (int i = 1; i <= (boardWidth * 5 - boardWidth + 1); i++) {
        std::cout << "-";
    }
}

void board(char board[7][7]) {
    std::cout << " " << " " << " " << " ";
    for (int i = 0; i < boardWidth; i++) {
        std::cout << i << " " << " " << " ";
    } // show the X-coordinate shows in the TOP

    std::cout << '\n';
    std::cout << " " << " ";

    for (int i = 1; i <= (boardWidth * 5 - boardWidth + 1); i++) {
        std::cout << "-";
    } // This is the TOP of the board

    std::cout << '\n';

    for (int i = 0; i < boardHeight; i++) {
        std::cout << i << " "; // show the Y-coordinate shows in the middle part
        std::cout << "| "; // every start of the row
        for (int j = 0; j < boardWidth; j++) {
            std::cout << board[i][j] << " | "; // after the start of the row
        }
        std::cout << '\n' << " " << " " << std::string((boardWidth * 5 - boardWidth + 1), '-') << '\n';
    }// middle and bottom of the board  --------------

}

bool CheckWin(char board[7][7], char player) {
    int parallelCheck = 0; // this will check like this -> (+1, 0)
    int verticalCheck = 0;// this will check like this -> (0, +1)
    int diagonalCheck1 = 0; // this will check like this -> \. (0,0) (1,1) (2,2)... (+1,+1)
    int diagonalCheck2 = 0; // this will check like this -> /. (6,0) (5,1) (4,2)... (-1,+1)
    int i = 0; // use in parallelCheck, verticalCheck
    int j = 0; // use in parallelCheck, verticalCheck
    int a = 0; // use in diagonalCheck1, diagonalCheck2
    int b = 0; // use in diagonalCheck1, diagonalCheck2

    for (i = 0; i <= boardHeight; i++) {
        parallelCheck = 0; // if no this. when (0,4)(0,5)(0,6)(1,0)(1,1) it will count win
       
        for (j = 0; j < boardWidth + 1; j++) {
            if (board[i][j] == player) {
                parallelCheck++;
            }
            else if (board[i][j] != player)
            {
                parallelCheck = 0;
            }
            if (parallelCheck == numberOfLetterToWin) {
                //   std::cout << "parallelwin" << '\n';
                return true;
            }

            if (board[j][i] == player) {
                verticalCheck++;
            }
            else if (board[j][i] != player)
            {
                verticalCheck = 0;
            }
            if (verticalCheck == numberOfLetterToWin) {
                //   std::cout << "verticalwin" << '\n';
                return true;
            }

        }
    }

    for (i = 0; i <= boardHeight; i++) {
        for (j = 0; j <= boardWidth; j++) {
            a = i; b = j;
            diagonalCheck1 = 0;// if no this, when there are 2 diagonal, diagonal check will count them together
            if (board[i][j] == player) {
                for (int k = 0; k < boardHeight * boardWidth; k++) {
                    a++; b++;
                    if (board[a][b] == player) {
                        diagonalCheck1++;
                    }
                    else if (board[a][b] != player) {
                        break;
                    }
                }
            }
            else {
                diagonalCheck1 = 0;
            }
            if (diagonalCheck1 == numberOfLetterToWin - 1) {
                //   std::cout << "diagonal1win" << '\n';
                return true;
            }
        }
    }

    for (i = 0; i <= boardHeight; i++) {
        for (j = 0; j <= boardWidth; j++) {
            a = i; b = j;
            diagonalCheck2 = 0;// if no this, when there are 2 diagonal, diagonal check will count them together
            if (board[i][j] == player) {
                for (int k = 0; k < boardHeight * boardWidth; k++) {
                    a--; b++;
                    if (board[a][b] == player) {
                        diagonalCheck2++;
                    }
                    else if (board[a][b] != player) {
                        break;
                    }
                }
            }
            else {
                diagonalCheck2 = 0;
            }
            if (diagonalCheck2 == numberOfLetterToWin - 1) {
                //   std::cout << "diagonal2win" << '\n';
                return true;
            }
        }
    }
    return false;
}

bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

int main()
{
    char boards[boardWidth][boardHeight];
    for (int i = 0; i < boardHeight; i++) {
        for (int j = 0; j < boardWidth; j++) {
            boards[i][j] = ' ';
        }
    }
    int row, column;
    char player = 'X';
    int turn;
    std::cout << "This is a " << boardWidth << "x" << boardHeight
        << " Tic Tac Toe game made by Kuro201." << '\n';
    std::cout << "Create a horizontal, vertical, or diagonal line consisting of"
        << numberOfLetterToWin << " same letters to win!";
    std::cout << '\n' << '\n';
    for (int turn = 1; turn <= (boardWidth * boardHeight); turn++) {
        board(boards);
        std::cout << "\n";
        while (true) {
            std::cout << "Player " << player << "'s turn" << '\n';
            std::cout << "select the row(0-6):";
            std::cin >> row;
            if (hasUnextractedInput()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "not integer, again:";
                std::cin >> row;
            }
            std::cout << "select the column(0-6):";
            std::cin >> column;
            if (hasUnextractedInput()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "not integer, again:";
                std::cin >> column;
            }
            std::cout << '\n';
            if (row < 0 || row > boardWidth || column < 0 || column > boardHeight || boards[row][column] != ' ') {
                std::cout << "invalid move, again" << '\n';
            }
            else break;
        }
        player = (player == 'X') ? 'O' : 'X';
        boards[row][column] = player;
        system("cls");

        if (CheckWin(boards, player)) {
            board(boards);
            std::cout << "Player " << player << " won!" << '\n';
            std::cout << "Can't believe this shit coding work";
            break;
        }
        if (turn == (boardWidth * boardHeight) && !CheckWin(boards, 'X') && !CheckWin(boards, 'O')) {
            board(boards);
            std::cout << "It's a draw!\n";
        }
    }
}


