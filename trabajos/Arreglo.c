#include <stdio.h>
#define MAX 100

int main(){
    int numeros[MAX], num, i = 0;
    FILE *archivo;
    archivo = fopen("numeros.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");    
    }
    while(i < 10){
        if (fscanf(archivo, "%d",&num) == 1){
            numeros[i] = num;
            i++;
        }
        
    }
    
    fclose(archivo);
    return 0;
}
