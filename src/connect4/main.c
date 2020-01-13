#include "game.h"

/**
 * @file game.c 
 * @brief The main of the game
 * @author Aymen Benabderrahmane
 * @version 1.0
 * @date 6 janvier 2020
 */

int main(){
    int player = 0;

    struct matrix_t mat;
   
    /* Matrix allocation */
    mat = alloc(6, 7);
    init_matrix(&mat);
    
    

    printf("===== Bienvenue dans notre magnifique jeu Connect 4======\n");

    
    while(mat.ncol>0)
    { 
        display_matrix(mat);  
        player =(player%2)+1;
        play(mat, player);

    }

    printf("Le joueur %d a gagné", player);
    

    return 0;
}