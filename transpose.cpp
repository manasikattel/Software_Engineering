#include <iostream>

using namespace std;

int main()
{
    int rows, columns;

    cout << "Give number of rows and columns of the matrix (should be less than 8):  \n";

    cin >> rows >> columns;

    int mat[rows][columns], mat_t[columns][rows];

    cout << "Give the elements of the matrix";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < rows; i++) // loop 3 times for three lines
    {
        for (int j = 0; j < columns; j++) // loop for the three elements on the line
        {
            cout << mat[i][j] << "  "; // display the current element out of the array
        }
        cout << endl; // when the inner loop is done, go to a new line
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < rows; j++)
            mat_t[i][j] = mat[j][i];

    for (int i = 0; i < rows; i++) // loop 3 times for three lines
    {
        for (int j = 0; j < columns; j++) // loop for the three elements on the line
        {
            cout << mat_t[i][j] << "  "; // display the current element out of the array
        }
        cout << endl; // when the inner loop is done, go to a new line
    }

    return 0;
}