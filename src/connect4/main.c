#include "../../include/game.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * @file game.c 
 * @brief The main of the game
 * @author Aymen Benabderrahmane
 * @version 1.0
 * @date 6 janvier 2020
 */

int main(){

    int player = 1;

    struct matrix_t mat;
   
    /* Matrix allocation */
    mat = alloc(6, 7);
    init_matrix(&mat);
    display_matrix(mat);
    

    printf("===== Bienvenue dans notre magnifique jeu  Connect 4======\n");

    /*
    while(check_winner(m, i, j))
    {
        player(m, player);

        if(player == 1){
            player = 2;
        }
        else{
            player = 1;    
        }
    }
    */

    return 0;
}