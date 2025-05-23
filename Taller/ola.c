#include <stdio.h>



int main(){
    int C,i,N_B;
    float promedio,N, P,mayor, menor, My, Mn;
    printf("Indique cuantas notas va a ingresar:\n");
    scanf("%d", &C);
    menor = 7;
    mayor = 1;
    i = 0;
    N = 0;
    P = 0;
    while(i < C ){
        printf("ingresa una nota del 1 al 7, o ingresa un 0 para finalizar:\n");        
        scanf("%f", &N);
        printf("Ingresaste un: %f\n",N);  

        if(N < 1 || N > 7){
            if (N == 0){
                C = C - 1; //resta 1 al C      
            }
            printf("No es una nota valida\n");
            continue;         
        }
        
        if (N >= mayor){
            mayor = N ;
        }
        
        if (N <=menor && N != 0){
            menor = N; 
        }
        
        P = P + N;
        i ++; //suma 1 al i  
        
    }
    
    
    promedio = P/C;
    printf("El promedio es:%f\nEl numero menor es:%f\nEl numero mayor es:%f\nLa cantidad de notas son:%d\n",promedio,menor,mayor,C);
    return 0;
}