struct matrix_t {
    char **data; /*!< The concrete matrix data. */
    int nrow; /*!< Number of rows */
    int ncol; /*!< Number of columns */
};

struct matrix_t alloc(int, int);
void init_matrix(struct matrix_t);
void display_matrix(struct matrix_t);