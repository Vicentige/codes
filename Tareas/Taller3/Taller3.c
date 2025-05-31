#include <stdio.h>
#define MAX 8
int separar_rut(int, int []);
int multi(int[], int );

int main()  {  
    int rut, suma, rut_digitos[MAX];
    char digito_verificador;
    
    // Ingresar rut
    printf("Ingrese el rut sin digito verificador: ");
    scanf("%d", &rut);

    printf("Ingrese el digito verificador: ");
    scanf(" %c", &digito_verificador);

    separar_rut(rut, rut_digitos);
    suma = multi(rut_digitos, MAX);
    printf("Suma: %d", suma);
    return 0;
} 

int separar_rut(int rut, int rut_digitos[]) {
    for (int i = 0; i < MAX; i++) {
        rut_digitos[i] = rut % 10;
        rut /= 10;
    }
}

int multi(int rut_digitos[], int n) {
    int suma = 0, multiplicador = 2;
    for (int i = 0; i < n; i++) {
        suma += rut_digitos[i] * multiplicador;
        multiplicador++;
        if (multiplicador > 7) multiplicador = 2;
    }
    return suma;
}