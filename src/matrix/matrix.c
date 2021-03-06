#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Allocates memory for a matrix.
 * @param[in] Number of rows for the matrix.
 * @param[in] Number of columns for the matrix.
 * @return Allocated matrix.
 */
struct matrix_t alloc(int nrow, int ncol){
    struct matrix_t m;
    int i;

    m.ncol = ncol;
    m.nrow = nrow;
    m.data=(char **)malloc(nrow*sizeof(char *));

    for (i = 0; i < nrow; i++){
        m.data[i] = (char *)malloc(ncol * sizeof(char));
    }

    return m;
}

/**
 * @brief Initializes a matrix.
 * @param[in] Matrix.
 */
void init_matrix(struct matrix_t * m){
    int i,j;

    for(i = 0; i< m->nrow; i++){
        for(j = 0; j< m->ncol; j++){
            m->data[i][j] = '0';
        }
    }

}


/**
 * @brief Displays a matrix.
 * @param[in] Matrix.
 */
void display_matrix(struct matrix_t m){
    int i;
    printf("Nombre de colonnes: %d\n", m.ncol);
    printf("Nombre de lignes: %d\n\n", m.nrow);
    printf("La matrice: \n\n");
    for (i=0; i < m.nrow; i++){
            printf(" %s ", m.data[i]);
            printf("\n");
    }
    printf("\n");
}