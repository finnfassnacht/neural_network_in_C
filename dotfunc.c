
// this is code for my function that can multiply matrixes and also always works without fail (ever)
#include <stdio.h>
// function to multiply matrixes
void dotproduct(int rowsone, int columnsone,int matrixone[rowsone][columnsone], int rowstwo, int columnstwo, int matrixtwo[rowstwo][columnstwo],int resmatrix[rowsone][columnstwo]){
    // loop trough rows of matrix one
     for (int ra = 0; ra < rowsone; ra++){
        // loop trough columns of matrix two
            for (int cb = 0; cb < columnstwo; cb++){
                // one element in the matrix consists of two calculations
                int cres = 0;
                for (int ca= 0; ca < columnsone; ca++){
                    // multiply each element of the row with each element of the column
                    int res = (matrixone[ra][ca] * matrixtwo[ca][cb]);
                    cres += res;
                }
                // make the new matrix
                resmatrix[ra][cb] = cres;
            }
    }
}
// function to transpose a matrix
// tranpose flips rows and columns
void transpose(int rows, int columns,int matrix[rows][columns],int trnmatrix[columns][rows]){
    for (int c = 0; c < columns; c++){
        for (int r = 0; r < rows; r++){
            trnmatrix[c][r] = matrix[r][c];
        }
    }
}
// print out a matrix 
void matrix_display(int rows, int columns, int matrix[rows][columns]){
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < columns; c++){
            printf(" %i ",matrix[r][c]);
        }
        printf("\n");
    }
}
int main(){
    /*
    Matrix one
        3  4 
        7  2 
        5  9 
    rows:3 columns:2
    */
    int matrixone[][2] = {{3,4},{7,2},{5,9}};
    int rowsone = sizeof(matrixone) / sizeof(matrixone[0]); // 3
    int columnsone = sizeof(matrixone[0]) / sizeof(matrixone[0][0]); // 2

    /*
    Matrix two
        3  1  5 
        6  9  7 
    rows:2 columns:3
    */

    int matrixtwo[][3] = {{3,1,5},{6,9,7}};
    int rowstwo = sizeof(matrixtwo) / sizeof(matrixtwo[0]); // 2
    int columnstwo = sizeof(matrixtwo[0]) / sizeof(matrixtwo[0][0]); // 3 

    // Matrix one * Matrix two (dot product)

    // define the rows and columns for the resulting matrix
    int resmatrix[rowsone][columnstwo] = {};
    // pass rows, columns for both matrixes, resmatrix will be changed by the matrix
    dotproduct(rowsone, columnsone, matrixone, rowstwo, columnstwo, matrixtwo, resmatrix);
    // display (print) the calculated matrix
    matrix_display(rowsone,columnstwo,resmatrix);

    // Transpose a Matrix
    int tran_matrix[columnstwo][rowsone] = {}; 
    // pass columns and rows of the new matrix, tran_matrix will be changed by the funcion
    transpose(columnstwo,rowsone,resmatrix,tran_matrix);
    printf("\nTransposed: \n");
    // display matrix
    matrix_display(columnstwo,rowsone,tran_matrix);

    return 0;
}