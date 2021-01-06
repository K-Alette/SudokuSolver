class solve
{
private:
#define UNASSIGNED 0 //empty cells have value of 0
#define N 9          //help define grid size as 9x9

public:
    bool FindUnassigned(int grid[N][N], int& row, int& col) //checks for any unassigned values
    {
        for (row = 0; row < N; row++)
            for (col = 0; col < N; col++)
                if (grid[row][col] == UNASSIGNED)
                    return true;                         //returns true if unassigned values exist
        return false;                                    //returns false if all cells assigned
    }
    bool RowCheck(int grid[N][N], int row, int num) //checks if number assigned to cell is in row
    {
        for (int col = 0; col < N; col++)
            if (grid[row][col] == num)
                return true; 
        return false;
    }
    bool ColumnCheck(int grid[N][N], int col, int num) //checks if number assigned to cell is in column
    {
        for (int row = 0; row < N; row++)
            if (grid[row][col] == num)
                return true;
        return false;
    }
    bool BoxCheck(int grid[N][N], int boxStartRow, int boxStartCol, int num) //checks if number assigned to cell is in 3x3 box
    {
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (grid[row + boxStartRow][col + boxStartCol] == num)
                    return true;
        return false;
    }
    bool CanAssign(int grid[N][N], int row, int col, int num)  //checks if number assigned to cell is present in row, column, or 3x3 box
    {                                                          //consolidates 3 above functions into one for "SolveSudoku" function
        return !RowCheck(grid, row, num) &&
            !ColumnCheck(grid, col, num) &&
            !BoxCheck(grid, row - row % 3, col - col % 3, num) && grid[row][col] == UNASSIGNED;
    }
    bool SolveSudoku(int grid[N][N]) //takes 9x9 grid and attempts to assign value to each cell
                                     //that will yield successful sudoku solve
    {
        int row, col;

        if (!FindUnassigned(grid, row, col)) //checks if there are any unassigned (empty) cells
            return true;                     //will print orignal board if already completed

        for (int num = 1; num <= 9; num++)  //only int 1-9 accepted
        {
            if (CanAssign(grid, row, col, num)) //checks if assignment can be made
            {
                grid[row][col] = num;   //int 1-9 will be tentatively assigned to cell

                if (SolveSudoku(grid))  //if assignment successful, will return true
                    return true;

                grid[row][col] = UNASSIGNED;
            }
        }
        return false;    //program will backtrack if assignment unsuccessful
    }
};