#include "matrix.h"

int main(void){
    struct matrix_t mat;

    char colonne[] = "0101011";

    mat = alloc(6, 7);

    display_matrix(mat);

    mat.data[0] = colonne;

    display_matrix(mat);

    init_matrix(&mat);

    display_matrix(mat);

    return 0;
}