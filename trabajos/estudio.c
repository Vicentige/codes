#include<stdio.h>

int main() {
    int f, c, valor, matriz[10][10];
    valor = 0;

    for(f = 0; f < 10; f++){
        for(c = 0; c < 10; c++){
            matriz[f][c] = 0;
        }
        
    }

    for(f = 0; f < 2; f++){
        for(c = 0; c < 2; c++){
            printf("valor:\t");
            scanf("%d",&valor);
            matriz[f][c] = valor;
        }

    }
    for(f = 0; f < 10; f++){
        for(c = 0; c < 10; c++){
            printf("%d  ",matriz[f][c]);
            

        }
        printf("\n");
    }


}