using namespace std;
class print
{
public:
    void PrintBoard(int grid[N][N]) //prints solved sudoku in 9x9 grid
    {
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
                cout << grid[row][col] << " ";
            cout << endl;
        }
    }
};