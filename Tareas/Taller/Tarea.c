#include <stdio.h>

int main(){ 
    int i = 0, C = 0, No_valida;
    float promedio, P, mayor, menor, desviacion, suma_diferencias, N;
    double d;
    float notas[10000]; // Este es un tamaño fijo de 100 notas como maximo par almacenar las notas 

    printf("Bienvenido al programa de notas\n");
    menor = 7;
    mayor = 1;
    P = 0;
    suma_diferencias = 0;
    
    while(1){
       
        if(i >= 10000){
            printf("Se ha alcanzado el limite de notas.\n");
            break;
        }

        printf("Ingresa una nota del 1 al 7, o ingresa un 0 para finalizar:");
        scanf("%f", &N);

        if(N == 0){
            break;
        }

        if(N < 1 || N > 7){
            printf("NO ES UNA NOTA VALIDA\n");
            continue;
        }

        printf("Ingresaste un: %f\n", N);

        if (N > mayor){ 
            mayor = N;
        }
        if (N < menor){
            menor = N;
        }

        P += N;
        notas[i] = N;
        i++;
    }

    C = i; // Cantidad de notas válidas

    if(C == 0){
        printf("No se ingresaron notas válidas.\n");
        return 0;
    }

    promedio = P / C;

    for(i = 0; i < C; i++){
        suma_diferencias += (notas[i] - promedio) * (notas[i] - promedio);
    }

    desviacion = suma_diferencias / C;

    // Aproximación de la raíz cuadrada
    d = 0;

    while ((d * d) < desviacion){
        d = d + 0.00000001;
    }

    printf("\nEl promedio es: %.2f\n\nEl numero menor es: %.2f\n\nEl numero mayor es: %.2f\n\nLa cantidad de notas son: %d\n\nLa desviacion estandar es: %.3f\n\n", promedio, menor, mayor, C, d);
    return 0;
}