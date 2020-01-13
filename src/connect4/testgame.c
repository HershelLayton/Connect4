/**
 * @file game.c 
 * @brief The folder test our game
 * @author Aymen Benabderrahmane
 * @version 1.0
 * @date 6 janvier 2020


int main(){

    printf("===== Bienvenue dans notre jeu magnifique Connect 4======\n");

    int player = 1;

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


    return 0;
}
*/