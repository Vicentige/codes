#include <stdio.h>

#define MAX_REGISTROS 100

int main(){
    int Hrs_Totales[MAX_REGISTROS], Min_Totales[MAX_REGISTROS]; // Arreglo para guardar datos
    int cantidad = 0, opcion = 1, dia = 0;
    float descuento = 0, A_pagar[MAX_REGISTROS], Ingreso_diario = 0, Ingreso_mensual = 0;

    while (opcion == 1 && cantidad < MAX_REGISTROS) {
        int h_ing, m_ing, h_sal, m_sal, horas, minutos;
        float T_A_pagar = 0;
        // Ingreso hora de ingreso
        do {
            printf("\nIngrese la hora de ingreso: ");
            scanf("%d", &h_ing);
            if (h_ing < 0 || h_ing > 23)
                printf("\nLa hora ingresada es incorrecta\n");
        } while (h_ing < 0 || h_ing > 23);

        // Ingreso minutos de ingreso
        do {
            printf("\nIngrese los minutos de ingreso: ");
            scanf("%d", &m_ing);
            if (m_ing < 0 || m_ing > 59){
                printf("\nLos minutos ingresados son incorrectos\n");
            }
        } while (m_ing < 0 || m_ing > 59); 

        // Ingreso hora de salida
    
        do {
            printf("\nIngrese la hora de salida: ");
            scanf("%d", &h_sal);
            if (h_sal < h_ing || h_sal > 23){
                printf("\nLa hora de salida es incorrecta\n");
            }
        } while (h_sal < h_ing || h_sal > 23);

        // Ingreso minutos de salida
        do {
            printf("\nIngrese los minutos de salida: ");
            scanf("%d", &m_sal);
            if (h_ing == h_sal) {
                if (m_sal <= m_ing || m_sal > 59) {
                    printf("\nLos minutos de salida son incorrectos\n");
                }
            } else {
                if (m_sal < 0 || m_sal > 59) {
                    printf("\nLos minutos de salida son incorrectos\n");
                }
            }
        } while ((h_ing == h_sal && (m_sal <= m_ing || m_sal > 59)) ||
                 (h_ing != h_sal && (m_sal < 0 || m_sal > 59)));

        printf("\nEs dia domingo? (1=Si, 0=No): ");
        scanf("%d", &dia);

        horas = h_sal - h_ing;
        minutos = m_sal - m_ing;
        if (minutos < 0) {
            minutos += 60;
            horas--;
        }

        Hrs_Totales[cantidad] = horas;
        Min_Totales[cantidad] = minutos;

        // Calcular el total a pagar según reglas
        if (horas == 0 && minutos <= 10) {
            T_A_pagar = 0;
        } else if (horas == 0 && minutos <= 25) {
            T_A_pagar = 3;
        } else if (horas == 0) {
            T_A_pagar = 10;
        } else {
            // Se cobra la primera hora a $10
            T_A_pagar = 10;
            // Si hay minutos extra, se cobra una hora adicional
            int horas_cobradas = horas;
            if (minutos > 0) {
                horas_cobradas++;
            }
            // Ya se cobró la primera hora, restamos 1
            T_A_pagar += (horas_cobradas - 1) * 5;
        }
        // Descuento por domingo
        if (dia == 1) {
            T_A_pagar = T_A_pagar * 0.9;
        }

        A_pagar[cantidad] = T_A_pagar;
        cantidad++;
        Ingreso_diario = Ingreso_diario + T_A_pagar;
        Ingreso_mensual = Ingreso_mensual + T_A_pagar;
        printf("Desea ingresar otro registro (1=Si, 0=No): ");
        scanf("%d", &opcion);
    }
    // Mostrar todos los registros
    printf("\nRegistros ingresados:\n");
    printf("           |--------------------------|-----------------|\n");
    printf("           |       Horas/minutos      |  Total a pagar  |\n");
    for (int i = 0; i < cantidad; i++) {
       
        printf("           |--------------------------|-----------------|\n");
        printf("     %d     |       %02d:%02d              |    $%0.2f       |\n",
        
        i + 1, Hrs_Totales[i], Min_Totales[i], A_pagar[i]);
        printf("           |--------------------------|-----------------|\n");
       
    }
        printf("           |El ingreso diario es:          $%0.2f       |\n",Ingreso_diario);
        printf("           |El ingreso mensual es:         $%0.2f       |\n",Ingreso_mensual);
        printf("           |--------------------------------------------|\n");
    return 0;
}