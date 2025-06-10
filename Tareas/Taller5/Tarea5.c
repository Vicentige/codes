#include <stdio.h>
#include <string.h>

#define MAX 31

FILE *archivo;
void mostrarNombres(void);
void agregarNombres(void);

int main(){

    
    agregarNombres();
    mostrarNombres();


    return 0;
}

void agregarNombres(void){
    int i = -1;
    char verif;
    char nombres[MAX];
    
    archivo = fopen("archivo.dat","w");
    
    while(i < 0){
        printf("Ingrese su nombre(maximo 30 letras): ");
        fgets(nombres, 31, stdin);
        fprintf(archivo, "%s",nombres);
        printf("Desea ingresar otro nombre(s/n): ");
        scanf("%c",&verif);
        getchar();

        if (verif != 's'){
            i += 3;
        }
        
    }
    fclose(archivo);
}

void mostrarNombres(void){
    char nombres[MAX];
    int i = 1;
    archivo = fopen("archivo.dat","r");
    printf("Los nombres ingresados son: \n");
    while(fgets(nombres,31,archivo)){
        printf("%s",nombres);
        
    }

}
