/**
 * @file game.c 
 * @brief contains the essential functions to play the game and chack if any player wins 
 * @author Aymen Benabderrahmane
 * @version 1.0
 * @date 6 janvier 2020
 */

/**
 * fonction qui teste à partir d'une case (i,j), s'il y a quatre pions
 * du même joueur alignés sur les côtés et les deux diagonales dont la case 
 * \param struct la matrice
 * \param int le point i de la case
 * \param int le point j de la case
 * \return un booleen qui teste s'il y a 4 points ou non
 * */

int check_winner(struct matrix_t m, int i, int j){

if(check_line(m, i, j) || check_column(m, i,j)
    || checkDiagoAsc(m, i, j) || checkDiagoDesc(m, i, j))
{
    return 1;
}

return 0;

}


int check_line(struct matrix_t m, int i, int j)
{
    char pawn; /** color */
    int k;
    int l;

    /** test s'il y a 4 sur la même ligne **/

    pawn = m.data[i][j];
    k = i-1;

    while (k>=0 && m.data[i][k]==pawn)
    {
        k--;
    }

    k = k+1;

    l = i+1;

    while (l<m.ncol && m.data[i][l] == pawn )
    {
        l++;
    }
    l= l-1;

    /* si les 4 couleurs sont alignées */

    if (l-k+1 >=4)
    {
        return 1;
    }


    return 0;

}


int check_column(struct matrix_t m, int i, int j)
{
    char pawn; /** color */
    int k;
    int l;

    /** test s'il y a 4 sur la même ligne **/

    pawn = m.data[i][j];
    k = j-1;

    while (k>=0 && m.data[j][k]==pawn)
    {
        k--;
    }

    k = k+1;

    l = j+1;

    while (l<m.nrow && m.data[l][j] == pawn )
    {
        l++;
    }
    l= l-1;

    /* si les 4 couleurs sont alignées */

    if (l-k+1 >=4)
    {
        return 1;
    }



    return 0;

}

int checkDiagoAsc(struct matrix_t m, int i, int j){


    char pawn; /** color */
    int k;
    int l;

    pawn = m.data[i][j];

     // ascendingDiagonalCheck 
    for (int i=3; i<m.ncol; i++){
        for (int j=0; j<m.nrow-3; j++){
            if (m.data[i][j] == pawn && m.data[i-1][j+1] == pawn
                 && m.data[i-2][j+2] == pawn 
                 && m.data[i-3][j+3] == pawn)
                return 1;
        }
    }

    return 0;
}


int checkDiagoDesc(struct matrix_t m, int i, int j){


    char pawn; /** color */
    int k;
    int l;

    pawn = m.data[i][j];

    // descendingDiagonalCheck
    for (int i=3; i<m.ncol; i++){
        for (int j=3; j<m.nrow; j++){
            if (m.data[i][j] == pawn && m.data[i-1][j-1] == pawn 
                && m.data[i-2][j-2] == pawn && m.data[i-3][j-3] == pawn)
                return 1;
        }

        return 0;
    }

}

/**
 * fonction qui effectue un tour de jeu pour un des deux joueurs
 * \param matrix_t le plateau du jeu
 * \param int le joueur 
 * \return void
 * */

void player(struct matrix_t m, int player){

    int col;
    char color;

    if(player == "1")
    {
        color = "Red";
    }
    else
    {
        color = "Yellow";
    }

    printf("Joueur : %d - A toi de jouer\n", player);
    printf("Choissisez la colonne de 1 à %d:  \n ", m.ncol);

    scanf("Colonne: %d", &col);


    int row =0;
    if(m.data[row][col])
    {   
        printf("Cette colonne est remplie\n");
        return;
    }
    while(m.data[row][col] == 0)
    {
        row++;
    }

    m.data[row-1][col] = color;


}