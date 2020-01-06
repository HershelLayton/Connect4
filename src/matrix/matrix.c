#include "matrix.h"

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

void init_matrix(struct matrix_t m){

}

void display_matrix(struct matrix_t m){
    
}