/**
 * @file testmatrix.c
 * @brief Enables the user to test libmatrix library functions.
 * @author Majd BUTTY
 * @version 1.0
 * @date 6 janvier 2020 
 */


#include "matrix.h"

int main(void){
    struct matrix_t mat;
    char colonne[] = "0101011";

    /* Matrix allocation */
    mat = alloc(6, 7);
    display_matrix(mat);

    /* Modify matrix data */
    mat.data[0] = colonne;
    display_matrix(mat);

    /* Matrix initialization */
    init_matrix(&mat);
    display_matrix(mat);

    return 0;
}