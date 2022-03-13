
#include<iostream>


/**

 * Generates a 2D Array of the dimensions entered as input.
 * @param[in] r number of rows of the matrix.
 * @param[in] c number of columns of the matrix.
 @return double pointer pointing to the 2D array that is generated with the elements entered by the user.

*/

int** generate2DArray(int r, int c){

    int** arr = new int*[r];
    for(int i=0; i<r; i++)
    {
        arr[i] = new int[c];
        for(int j=0; j<c; j++)
        {
            std::cout << "A[" << i+1 << "][" << j+1 << "]=";
            std::cin >> arr[i][j];
        }

    }
    return arr;
}


/**

 * Generates the 2D transposed matrix of the matrix entered as input.
 * @param[in] original_arr double pointer pointing to the matrix to be transposed.
 * @param[in] r number of rows of the matrix to be transposed.
 * @param[in] c number of columns of the matrix to be transposed.
 @return double pointer pointing to the transposed matrix.

*/
int** generate2DTransposedArray(int** original_arr, int r, int c)
{

    int** transposed_array = new int*[c];
    for(int i=0; i<c; i++)
    {
        transposed_array[i] = new int[r];
        for(int j=0; j<r; j++)
        {
            transposed_array[i][j] = original_arr[j][i];
        }

    }
    return transposed_array;

}

/**

 * Generates a 1D array with the elements of the original matrix.
 * @param[in] original_arr double pointer pointing to the original matrix.
 * @param[in] r number of rows of the original matrix.
 * @param[in] c number of columns of the original matrix.
 @return pointer pointing to 1D array containing the elements of the original matrix.

*/

int * generate1DArray(int** original_arr, int r, int c)
{
    int* monod_array= new int[r*c];
    int z= 0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            monod_array[z] = original_arr[i][j];
            z+=1;
        }

    }
    return monod_array;
}

/**

 * Prints a 2D array.
 * @param[in] arr double pointer pointing to the array that is going to be printed.
 * @param[in] r number of rows of the matrix to be printed.
 * @param[in] c number of columns of the matrix to be printed.
 * @param[in] transposed boolean variable to print either the original matrix or the transposed matrix.

*/


void print2DArray(int** arr, int r, int c, bool transposed){
    if (transposed==true)
    {
        for (int i=0; i<c;i++)
        {
            for (int j=0; j<r; j++)
            {
                std::cout << arr[i][j]<< " ";
            }
            std::cout << std::endl;
        }
    }
    else
    {
        for (int i=0; i<r;i++)
        {
            for (int j=0; j<c; j++)
            {
                std::cout << arr[i][j]<< " ";
            }
            std::cout << std::endl;
        }

    }

}

/**

 * Prints a 1D array.
 * @param[in] oned_arr pointer pointing to the one dimensional array that is going to be printed.
 * @param[in] r number of rows of the original matrix.
 * @param[in] c number of columns of the original matrix

*/


void print1DArray(int* oned_arr, int r, int c)
{
    for (int i=0; i<r*c; i++)
    {
        std::cout <<oned_arr[i]<<"  ";
    }
}

int main()
{
    int r,c;
    bool transposed;
    std::cout << "Enter the number of rows of the array"<<std::endl;
    std::cin>> r;
    std::cout << "Enter the number of columns of the array"<<std::endl;
    std::cin >> c;
    while (r >= 8 || c >= 8)
    {
        std::cout << "Matrix dimensions must be less than 8."<<std::endl;
        std::cout << "Enter the number of rows of the array"<<std::endl;
        std::cin>> r;
        std::cout << "Enter the number of columns of the array"<<std::endl;
        std::cin >> c;
    }
    int** original_arr;
    int** transposed_arr;
    int* oned_array;
    original_arr= generate2DArray(r,c);
    transposed_arr= generate2DTransposedArray(original_arr,r,c);
    oned_array= generate1DArray(original_arr,r,c);
    std::cout << "Original Matrix"<<std::endl;
    print2DArray(original_arr,r,c, transposed= false);
    std::cout << "Transposed Matrix"<<std::endl;
    print2DArray(transposed_arr,r,c,transposed=true);
    std::cout << "1D Array"<<std::endl;
    print1DArray(oned_array,r,c);

    return 0;

}
