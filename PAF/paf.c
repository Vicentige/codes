/*
*autores: Gonzalo Fuenzalida Pérez,Vicente González
*Seccion 2 INF
*/
#include <stdio.h>
#include <string.h>

void lee_original(char *, int *);
void inicializa_alfabeto(char *);
void codificar(char *, char *, char *, int);
void graba_mensaje(char *);

int main(){
    char original[100];
    char alfabeto[100];
    char codificado[100];
    int N;

    lee_original(original, &N);
    inicializa_alfabeto(alfabeto);
    codificar(original, codificado, alfabeto, N);
    //graba_mensaje(codificado);
    return 0;
}

void lee_original(char *original, int *n){
    int i = 0;
    *n = 0;
    FILE *file = fopen("original.txt", "r");
    fgets(original, 100, file);
    fclose(file);

    original[strcspn(original, "\n")] = '\0';
    //printf("Mensaje original:%s\n", original);

    while (original[i] >= '0' && original[i] <= '9') { 
        *n = (*n) * 10 + (original[i] - '0');
        i++;
    }

    printf("Numero n: %d\n", *n);
}

void inicializa_alfabeto(char *alfabeto){
    int i;
    

    for (i = 0; i < 26; i++) { //obtiene el abecedario ingles, del alfabeto ACSII
        alfabeto[i] = 'A' + i;
    }
    alfabeto[26] = ' ';
    for (i = 27; i < 37; i++) {
        alfabeto[i] = '0' + (i - 27);
    }

    alfabeto[37] = '!';
    alfabeto[38] = ',';
    alfabeto[39] = '.';
    alfabeto[40] = ':';
    alfabeto[41] = ';';
    alfabeto[42] = '?';
    alfabeto[43] = '-';
    alfabeto[44] = '+';
    alfabeto[45] = '*';
    alfabeto[46] = '/';
    alfabeto[47] = '\0';
}

void codificar(char *original, char *codificado, char *alfabeto, int n){
    int i = 0;
    void primera_etapa(char *, char *, int);
    void segunda_etapa(char *, char *, int);

    
    strcpy(codificado, original);
    
    primera_etapa(codificado, alfabeto, n);
    segunda_etapa(codificado, alfabeto, n);


}

void primera_etapa(char *codificado, char *alfabeto, int n){//primera codificacion
    int i = 0, j, z, k = n, contador = 0;

    while (codificado[i] >= '0' && codificado[i] <= '9') { //Cuenta las posiciones que usa el numero n dentro del array
        contador++;
        i++;
    }

    if (n > 47) {
        k = n % 47;        
    }
    

    
    for (i = contador + 1; i < strlen(codificado); i++) {
        for (j = 0; j < (strlen(alfabeto)); j++) {
            if (codificado[i] == alfabeto[j]) {
                z = j - k;
                while (z < 0) {
                    z = z + 47;
                }
                codificado[i] = alfabeto[z];
                break;
            }
        }
    }

    printf("Mensaje codificado: ");
    for (i = 0; i < (strlen(codificado)); i++) {
        printf("%c", codificado[i]);
    }
}

void segunda_etapa(char *codificado, char *alfabeto, int n){//segunda codificacion
    int i = 0, j, z, k = n, contador = 0;

    while (codificado[i] >= '0' && codificado[i] <= '9') { //Cuenta las posiciones que usa el numero n dentro del array
        contador++;
        i++;
    }
    if (n > 47) {
        k = n % 47;        
    }
    
    for (i = contador + 1; i < strlen(codificado) + 2; i++) {
        for (j = 0; j < 47; j += 2) {
            if (codificado[i] == alfabeto[j] && (j % 2 == 0)) {
                z = j - k;
                if (z < 0){
                    z = z + 47;
                }
                codificado[i] = alfabeto[z];
                break;
            }
        }
    }

    printf("\nMensaje codificado segunda vez: ");
    for (i = 0; i < (strlen(codificado)); i++) {
        printf("%c", codificado[i]);
    }
}