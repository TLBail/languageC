#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    
    printf("salut a tous");
    /*
    int nb1 = 2;
    //scanf("donne un chiffre", &nb1);
    printf("nb1 vaut : %d", nb1);
    while(1){
        printf("BANANE \n");
    }
    */
   srand(time(NULL));
   while(1){      
    double nb = (rand() % (30 - 5 + 1) ) + 5;
    printf("nb : %f\n", nb);

   }
    return 0;
}