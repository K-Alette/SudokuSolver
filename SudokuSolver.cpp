//backtracking sudoku solver
//Kodi Lein
#include <iostream>
#include "Solve.h" //include header file that contains class "solve"
#include "Print.h" //include header file that contains class "print"
using namespace std;

int main() //driver
{
    int grid[N][N] = { {0, 0, 0, 0, 8, 0, 0, 4, 0},  //sudoku board
                      {0, 0, 0, 0, 0, 5, 0, 0, 0},
                      {8, 0, 0, 0, 0, 0, 0, 0, 3},
                      {1, 0, 0, 0, 0, 0, 0, 9, 0},
                      {0, 0, 7, 2, 4, 0, 0, 0, 5},
                      {0, 8, 9, 0, 5, 0, 7, 3, 0},
                      {0, 0, 0, 0, 0, 7, 0, 0, 0},
                      {0, 2, 0, 8, 0, 0, 0, 0, 0},
                      {4, 9, 5, 0, 6, 0, 2, 8, 0} };
    solve s; //calls class "solve"
    print p; //calls class "print"
    if (s.SolveSudoku(grid) == true) //solves sudoku puzzle
        p.PrintBoard(grid);    //prints solved board
    else
        cout << "There is no solution." << endl; //this will print if board is unsolvable

    return 0;
}