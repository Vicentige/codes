/*
*autores: Gonzalo Fuenzalida Pérez,Vicente González
*Seccion 2 INF
*/
#include <stdio.h>
#include <string.h>

void lee_original(char *, int *);
void inicializa_alfabeto(char *);
void codificar(char *, char *, char *, int);
void segunda_etapa(char *, char *, int);
void primera_etapa(char *, char *, int);
void graba_mensaje(char *);


int main(){
    char original[100];
    char alfabeto[100];
    char codificado[100];
    int N;

    lee_original(original, &N);
    inicializa_alfabeto(alfabeto);
    codificar(original, codificado, alfabeto, N);
    graba_mensaje(codificado);
    return 0;
}
void lee_original(char *original, int *n){
    int i = 0;
    *n = 0;
    FILE *file = fopen("codificado.txt", "r");
    fgets(original, 100, file);
    
    fclose(file);

    original[strcspn(original, "\n")] = '\0';

    while (original[i] >= '0' && original[i] <= '9') { 
        *n = (*n) * 10 + (original[i] - '0');
        i++;
    }

        for (i = 0; i < (strlen(original)); i++){
        printf("%c", original[i]);
    }

    printf("Numero n: %d\n", *n);
}

void inicializa_alfabeto(char *alfabeto){
    int i, k = 0;   

    for (i = 1; i < 27; i++) { //obtiene el abecedario ingles, del alfabeto ACSII
        alfabeto[i] = 'A' + k;
        k++;
    }
    k++;
    alfabeto[27] = ' ';
    for (i = 28; i < 38; i++) {
        alfabeto[i] = '0' + (k - 27);
        k++;
    }


   //alfabeto[37] = '9'; //Agrega algunos simbolos al alfabeto
    alfabeto[38] = '!';
    alfabeto[39] = ',';
    alfabeto[40] = '.';
    alfabeto[41] = ':';
    alfabeto[42] = ';';
    alfabeto[43] = '?';
    alfabeto[44] = '-';
    alfabeto[45] = '+';
    alfabeto[46] = '*';
    alfabeto[47] = '/';
    alfabeto[48] = '\0';


    /*printf("\nAlfabeto:");
    for (i = 0; i < 48; i++) { //Imprime el alfabeto
        printf("%c", alfabeto[i]);
    }*/
}

void codificar(char *original, char *codificado, char *alfabeto, int n){
    int i = 0, contador = 0;
    strcpy(codificado, original);
    segunda_etapa(codificado, original, n);
    primera_etapa(codificado, original, n);

}
//primera codificacion
void primera_etapa(char *codificado, char *original, int n){
    int i = 0, j, z, k = n, contador = 0;
    char alfabeto[100];
    inicializa_alfabeto(alfabeto);
    while (original[i] >= '0' && original[i] <= '9'){ //Cuenta las posiciones que usa el numero n dentro del array
        contador++;
        i++;
    }
    if (n > 47){
        k = n % 47;        
    }
        
    for (i = contador + 1; i < strlen(original); i++){
        for (j = 1; j < (strlen(alfabeto)); j++){
            if (codificado[i] == alfabeto[j] && (j % 2 == 0)){
                z = j + k;
                if (z > 48) {
                    z = z - 47;
                }
                codificado[i] = alfabeto[z];
                break;
            }
        }
    }
    printf("\nMensaje descodificado: ");
    for (i = 0; i < (strlen(codificado)); i++){
        printf("%c", codificado[i]);
    }
}

void segunda_etapa(char *codificado, char *original, int n){//segunda codificacion
    int i = 0, j, z, k = n, contador = 0;
    char alfabeto[100];
    inicializa_alfabeto(alfabeto);

    while (original[i] >= '0' && original[i] <= '9'){ //Cuenta las posiciones que usa el numero n dentro del array
        contador++;
        i++;
    }
    if (n > 47) {
        k = n % 47;        
    }
    
    for (i = contador + 1; i < strlen(codificado) + 2; i++){
        for (j = 1; j < 49; j ++){
            if (original[i] == alfabeto[j]){
                z = j + k;
                if (z > 48){
                    z = z - 47;
                }
                codificado[i] = alfabeto[z];
                break;
            }
        }
    }

    printf("\nMensaje descodificado segunda vez: ");
    for (i = 0; i < (strlen(codificado)); i++){
        printf("%c", codificado[i]);
    }
}

void graba_mensaje(char *codificado){
    FILE *file = fopen("descodificado.txt", "w");
    if (file == NULL){
        printf("Error al abrir el archivo para escribir.\n");
    }
    fputs(codificado, file);
    fclose(file);
}