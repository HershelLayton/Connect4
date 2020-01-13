#include "game.h"

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

        if(check_line(m, i, j) || check_column(m, i,j))
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
    k = j-1;

    while (k>=0 && m.data[i][k]==pawn)
    {
        k--;
    }

    k = k+1;

    l = j+1;

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
    k = i-1;

    while (k>=0 && m.data[k][j]==pawn)
    {
        k--;
    }

    k = k+1;

    l = i+1;

    while (l<m.nrow && m.data[l][j] == pawn )
    {
        l++;
    }
    l= l-1;

    /* si les 4 couleurs sont aliv o i d   p l a y ( s t r u c t    m a t r i x _ t   m,    i n t    p l a y e r )gnées */

    if (l-k+1 >=4)
    {
        return 1;
    }



    return 0;

}
/*
int checkDiagoAsc(struct matrix_t m, int i, int j){


    char pawn; 
    int k;
    int l;
    int cpt1;
    int cpt2;

    pawn = m.data[i][j];

     
    for (cpt1=3; cpt1<m.ncol; cpt1++){
        for ( cpt2=0; cpt2<m.nrow-3; cpt2++){
            if (m.data[cpt1][cpt2] == pawn && m.data[cpt1-1][cpt2+1] == pawn
                 && m.data[cpt1-2][cpt2+2] == pawn 
                 && m.data[cpt1-3][cpt2+3] == pawn)
                return 1;
        }
    }

    return 0;
}


int checkDiagoDesc(struct matrix_t m, int i, int j){


    char pawn; 
    int k;
    int l;
    int cpt1;
    int cpt2;

    pawn = m.data[i][j];

    for (cpt1=3; cpt1<m.ncol; cpt1++){
        for (cpt2=3; cpt2<m.nrow; cpt2++){
            if (m.data[cpt1][cpt2] == pawn && m.data[cpt1-1][cpt2-1] == pawn 
                && m.data[cpt1-2][cpt2-2] == pawn && m.data[cpt1-3][cpt2-3] == pawn)
                return 1;
        }

    }
    return 0;

}*/

/**
 * fonction qui effectue un tour de jeu pour un des deux joueurs
 * \param matrix_t le plateau du jeu
 * \param int le joueur 
 * \return void
 * */

void play(struct matrix_t m, int player){

    int col;
    char color;
    int row =0;

    if(player == 1)
    {
        color = 'R';
    }
    else
    {
        color = 'Y';
    }

    printf("Joueur : %d -> A toi de jouer!\n", player);
    printf("Choissisez la colonne de 1 à %d:  \n ", m.ncol);

    scanf("%d", &col);
    
    col--;

    if(m.data[row][col] != '0')
    {   
        printf("Cette colonne est remplie\n");
        play(m,player);
        return;
    }
    while(row < m.nrow && m.data[row][col] == '0' )
    {
        row++;
        
    }
    printf("%c\n",m.data[row-1][col]);

    m.data[row-1][col] = color;

    if (check_winner(m, row-1, col))
    {
        m.ncol = 0;
    }


}