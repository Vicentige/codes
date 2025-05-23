#include <stdio.h>

int main(){ 
    int C, i,CN;
    float promedio, P, mayor, menor, My, Mn, desviacion, suma_diferencias, N;
    double d;
    printf("Bienvenido al programa de notas\n");
     float notas[C]; //almacenar las notas
    menor = 7;
    mayor = 1;
    i = 0;
    N = 0;
    P = 0;
    suma_diferencias = 0;

    while(i < C ){
        
        printf("ingresa una nota del 1 al 7, o ingresa un 0 para finalizar:\n");        
        scanf("%f", &N);
        printf("Ingresaste un: %f\n", N);
        if(N < 1 || N > 7 == true){
            if (N == 0){
                C = C - 2; //resta 1 al C
                break; //resta 1 al C      
            }
            printf("No es una nota valida\n");
            continue;    
        }
        if (N >= 1 || N <= 7 ){
            C = C + 1; //Suma 1 al C
        }
        if (N >= mayor){
            mayor = N;
        }
        
        if (N <= menor && N != 0){
            menor = N;  
        }

        P = P + N;
        notas[i] = N; // Almacena la nota
        i++;// Suma 1 al i  
    }
    promedio = P / C;
    // Cálculo de la suma de las diferencias al cuadrado
    for(i = 0; i < C; i++){
        suma_diferencias += (notas[i] - promedio) * (notas[i] - promedio);

    }
    // Cálculo de la desviación estándar
    desviacion = (suma_diferencias / C);
    d = 0;
    while ((d * d) < desviacion){
        d = d + 0.00000001;
    }
    printf("El promedio es: %f\nEl numero menor es: %f\nEl numero mayor es: %f\nLa cantidad de notas son: %d\nLa desviacion estandar es: %f\n", promedio, menor, mayor, C, d);
    return 0;    // Fin del programa
}    
    

   