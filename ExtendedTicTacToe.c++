// Anshika Patel
// The following code is the extension of the tic-tac-toe game with customizable grid size and win condition

#include <iostream>

const int maxSize = 10; // setting the max size of the board 

void printBoard(char board[maxSize][maxSize], int size) { // function to print the board. takes two arguments - one for 2D array which defines the maximum size of the board and size is for the user inputted size of the board 
    // for loop to print the board 
    for (int i = 0; i < size; ++i) { 
        for (int j = 0; j < size; ++j) {
            std::cout << board[i][j]; // printing a 2D board 
            if (j < size - 1) std::cout << " | ";
        }
        std::cout << std::endl; // new line 
    }
}

bool isWin(char board[maxSize][maxSize], char player, int size, int winCondition) { // function to check the winning conditions 
    // arguments are: 2D board with max size, player symbol, size of the grid and the number of arguments needed to win in a given board 

    // checking rows
    for (int i = 0; i < size; ++i) {
        int count = 0;
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == player) { // checking the symbols at [i][j] place 
                count++; // counting the number of arguments 
                if (count >= winCondition) {
                    return true; // checking if the number of symbols in a row is greater than or lesser than the given number by user 
                }
            } else {
                count = 0;
            }
        }
    }

    // checking columns
    for (int j = 0; j < size; ++j) {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (board[i][j] == player) { // checking the symbols at [i][j]
                count++;
                if (count >= winCondition){
                    return true; // checking if the number of symbols in a row is greater than or lesser than the given number by user 
                } 
            } else {
                count = 0;
            }
        }
    }

    return false;
}

bool isBoardFull(char board[maxSize][maxSize], int size) { // function to check if the board is full without any win
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() { // main function 
    // intro function
    std::cout << "\nWelcome to the Tic-Tac-Toe game.\n"
              << "You will get an option to choose for one or two players. Then you will be shown an empty board for the game and you can choose the position you want to play the next turn.\n"
              << "The positions on the board will be shown as numbers.\n";

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "\nLet's start the game:\n";

    while (true) { // outer loop for the "Play Again" feature
        int size; // initializing the size of the board 
        int winCondition; // initializing the number of symbols needed to win the game

        while (true) {
            std::cout << "Enter the size of the grid (e.g. 5 for a 5x5 grid, max 10): ";
            std::cin >> size; // asking the size of board

            if (std::cin.fail() || size > maxSize || size < 3) { // checking if the size entered does not exceed the max size and it is not less than 3 
                std::cin.clear(); // clear the error flag
                std::cin.ignore(10000, '\n'); // discard invalid input
                std::cout << "Invalid grid size. Please enter a valid integer between 3 and " << maxSize << ".\n";
            } else {
                break;
            }
        }

        while (true) {
            std::cout << "Enter the number of consecutive symbols needed to win: ";
            std::cin >> winCondition;

            if (std::cin.fail() || winCondition > size || winCondition < 2) {
                std::cin.clear(); // clear the error flag
                std::cin.ignore(10000, '\n'); // discard invalid input
                std::cout << "Invalid win condition. Please enter a valid integer between 2 and " << size << ".\n";
            } else {
                break;
            }
        }

        char board[maxSize][maxSize]; // initializing 2D board 
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                board[i][j] = ' ';
            }
        }

        char currentPlayer = 'X';
        bool gameWon = false;

        while (true) { // inner game loop
            printBoard(board, size); // printing the board 
            int move; // position of the move 

            while (true) {
                std::cout << "Player " << currentPlayer << ", enter your move (1-" << size * size << "): ";
                std::cin >> move; // asking the user where they want to move

                if (std::cin.fail() || move < 1 || move > size * size) { // checking if the position entered is invalid 
                    std::cin.clear(); // clear the error flag
                    std::cin.ignore(10000, '\n'); // discard invalid input
                    std::cout << "Invalid move. Try again.\n";
                } else {
                    int row = (move - 1) / size; // adjusting the zero indexing by subtracting 1 
                    int col = (move - 1) % size;

                    if (board[row][col] != ' ') {
                        std::cout << "Position already taken. Try again.\n"; // if the user enters a position where there is a X or O already, tell them that the position is already taken
                    } else {
                        board[row][col] = currentPlayer; // if the position is empty, putting the current player's symbol 
                        break;
                    }
                }
            }

            if (isWin(board, currentPlayer, size, winCondition)) { // checking if someone won
                printBoard(board, size); // printing the board
                std::cout << "Player " << currentPlayer << " wins!\n"; // if someone wins, printing who won
                gameWon = true;
                break;
            }

            if (isBoardFull(board, size)) { 
                printBoard(board, size);
                std::cout << "The game is a draw!\n"; // if the board is full and no one won, printing that the game is a draw 
                break;
            }
            
            //switching the player 
            if (currentPlayer == 'X'){
                currentPlayer = 'O';
            }
            else{
                currentPlayer = 'X';
            }
        }

        // asking if the user wants to play again
        std::cout << "Do you want to play again? (yes/no): ";
        std::string playAgain;
        std::cin >> playAgain;
        if (playAgain.compare("yes")) {
            break; 
        }
    }

    return 0;
}
