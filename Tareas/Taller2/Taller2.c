#include <stdio.h>

#define MAX_REGISTROS 100

int main(){
    int i, n, Hrs_ingreso = 0, Min_ingreso = 0, Hrs_salida = 0, Min_salida = 0, precio_hora;
    i = 0;
    n = 0;
    int Hrs_ingreso[MAX_REGISTROS], Min_ingreso[MAX_REGISTROS], Hrs_salida[MAX_REGISTROS], Min_salida[MAX_REGISTROS];
    while(i == 0){
        while(n == 0){
        printf("ingrese la hora de ingreso: ");
        scanf("%d", &Hrs_ingreso);
        if (Hrs_ingreso < 0 || Hrs_ingreso > 23 ){
        printf("La hora ingresada es incorrectos\n");
        } else {
            n = 1; // Salir del bucle si la hora es correcta

        }

    }
    while(n == 1){
        printf("ingrese los minutos de ingreso: ");
        scanf("%d", &Min_ingreso);
        if (Min_ingreso < 0 || Min_ingreso > 59 ){
            printf("Los minutos ingresados son incorrectos\n");
        } else {
            n = 2; // Salir del bucle si los minutos son correctos

        }
    }
    while(n == 2){
        printf("ingrese la hora de salida: ");
        scanf("%d", &Hrs_salida);
        if (Hrs_salida < Hrs_ingreso || Hrs_salida > 23 ){
            printf("La hora ingresada es incorrectos\n");
        } else {
            n = 3; // Salir del bucle si la hora de salida es correcta

        }
    }
    while(n == 3){
        printf("ingrese los minutos de salida: ");
        scanf("%d", &Min_salida);
        if (Min_salida < 0 || Min_salida > 59 ){
            printf("Los minutos ingresados son incorrectos\n");
        } else {
            n = 4; // Salir del bucle si los minutos de salida son correctos

        }
        
    }

    }
    

    
    printf("hora %d, minutos %d\n", Hrs_ingreso, Min_ingreso);
    printf("hora %d, minutos %d\n", Hrs_salida, Min_salida);

    return 0;
}