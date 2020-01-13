#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int check_winner(struct matrix_t m, int i, int j);
int check_line(struct matrix_t m, int i, int j);
int check_column(struct matrix_t m, int i, int j);
int checkDiagoAsc(struct matrix_t m, int i, int j);
int checkDiagoDesc(struct matrix_t m, int i, int j);
void play(struct matrix_t m, int player);

