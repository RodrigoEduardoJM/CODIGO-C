# CODIGO-C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarMatricula(char matricula[]) {
    return strlen(matricula) == 7;
}

int validarContrasena(char contrasena[]) {
    int tieneLetra = 0, tieneNumero = 0;
    for (int i = 0; contrasena[i] != '\0'; i++) {
        if (isalpha(contrasena[i])) tieneLetra = 1;
        if (isdigit(contrasena[i])) tieneNumero = 1;
    }
    return tieneLetra && tieneNumero;
}

// Imprimir el menu de la cafeteria
void imprimirMenu() {
    printf("\n--- Menu de la Cafeteria ---\n");
    printf("1. Reb. Pizza  $20\n");
    printf("2. Hot-Dog    $20\n");
    printf("3. Vaso con fruta  $18\n");
    printf("4. Hamburguesa   $30\n");
}

// Calificar la cafeteria
void calificarCafeteria() {
    int suma = 0, calificacion;
    for (int i = 1; i <= 5; i++) {
        do {
            printf("Pregunta #%d (1-5): ", i);
            scanf("%d", &calificacion);
            if (calificacion < 1 || calificacion > 5) {
                printf("Por favor, ingresa un numero entre 1 y 5.\n");
            }
        } while (calificacion < 1 || calificacion > 5);
        suma += calificacion;
    }
    float promedio = suma / 5.0;
    printf("Calificacion promedio: %.2f\n", promedio);
}

void dejarComentario() {
    char comentario[200];
    printf("¿Que comentario te gustaria dejarnos?: ");
    getchar();
    fgets(comentario, sizeof(comentario), stdin);
    printf("Gracias por tu comentario: %s\n", comentario);
}

void gestionarSaldo() {
    float saldo = 100.0;
    int opcion;
    printf("\n1. Consultar mi saldo\n2. Utilizar mi saldo\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &opcion);
    
    if (opcion == 1) {
        printf("Tu saldo actual es: $%.2f\n", saldo);
    } else if (opcion == 2) {
        float gasto;
        printf("¿Cuánto deseas gastar?: ");
        scanf("%f", &gasto);
        if (gasto > saldo) {
            printf("Saldo insuficiente.\n");
        } else {
            saldo -= gasto;
            printf("Transacción realizada. Nuevo saldo: $%.2f\n", saldo);
        }
    } else {
        printf("Opción inválida.\n");
    }
}

void rankingCafeterias() {
    printf("\n--- Ranking de cafeterias ---\n");
    printf("1. FIME\n2. FACPYA\n3. FARQ\n");
}

void gestionarCuenta() {
    int opcion;
    printf("\n1. Salir de la cuenta\n2. Reportar un error\n3. Q&A\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Saliendo de la cuenta...\n");
            exit(0);
        case 2:
            printf("Escribenos tu problema.Trataremos de solucionarlo a la brevedad.\n");
			printf("Reporte de error enviado.\n");
            break;
        case 3:
            printf("Preguntas y respuestas frecuentes.\n");
            printf("1.-¿Como puedo recargar saldo?");
            printf("2.-¿Como puedo utilizar mi saldo?");
            printf("3.-¿En que puedo gastar mi saldo?");
            break;
        default:
            printf("Opcion invalida.\n");
    }
}

// Funcion principal
int main() {
    char matricula[10], contrasena[50];
    
    printf("Ingresa tu matricula: ");
    scanf("%s", matricula);
    if (!validarMatricula(matricula)) {
        printf("Matricula invalida.\n");
        return 0;
    }
    
    printf("Ingresa tu contraseña(Debe contener al menos un numero y una letra): ");
    scanf("%s", contrasena);
    if (!validarContrasena(contrasena)) {
        printf("Contraseña invalida.\n");
        return 0;
    }

    int opcionFacultad, opcionSubmenu;
    
    while (1) {
        printf("\n--- Selecciona una opcion ---\n");
        printf("1. FIME\n2. FACPYA\n3. FARQ\n4. Consultar/utilizar saldo\n5. Ranking de cafeterias\n6. Cuenta\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcionFacultad);

        if (opcionFacultad >= 1 && opcionFacultad <= 3) {
            printf("\n1. Menu de la Cafeteria\n2. Calificar la cafeteria\n3. Dejar un comentario\n");
            printf("Selecciona una opcion: ");
            scanf("%d", &opcionSubmenu);

            if (opcionSubmenu == 1) {
                imprimirMenu();
            } else if (opcionSubmenu == 2) {
                printf("\n--- Calificar la Cafeteria ---\n");
                printf("#1-Califica la comodidad de la cafeteria (1-5): \n\t");
                printf("#2-Califica la calidad de la comida (1-5): \n\t");
                printf("#3-Califica los precios de la cafeteria (1-5): \n\t");
                printf("#4-Califica el servicio al cliente de la cafeteria (1-5): \n\t");
                printf("#5-Califica la limpieza de la cafeteria (1-5): \n\t");
                calificarCafeteria();
            } else if (opcionSubmenu == 3) {
                dejarComentario();
            } else {
                printf("Opcion invalida.\n");
            }
        } else if (opcionFacultad == 4) {
            gestionarSaldo();
        } else if (opcionFacultad == 5) {
            rankingCafeterias();
        } else if (opcionFacultad == 6) {
            gestionarCuenta();
        } else {
            printf("Opcion invalida.\n");
        }
    }

    return 0;
}
