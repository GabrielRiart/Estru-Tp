#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CANTIDAD_ESTUDIANTES 15

typedef struct {
    char codigo[10];
    char nombre[50];
    char carrera[50];
    int puntaje;
    char estado[20];
} Estudiante;


// Calculo para saber si está aplazado o no
void calcularEstado(int puntaje, char estado[]) {
    if (puntaje >= 60) {
        strcpy(estado, "Aprobado");
    } else {
        strcpy(estado, "Reprobado");
    }
}


// Confirmar puntaje correcto
int validarPuntaje(int puntaje) {
    return puntaje >= 0 && puntaje <= 100;
}


// Imprimir un estudiante específico
void imprimirEstudiante(Estudiante estudiante) {
    printf(
        "Codigo: %s | Nombre: %s | Carrera: %s | Puntaje: %d | Estado: %s\n",
        estudiante.codigo,
        estudiante.nombre,
        estudiante.carrera,
        estudiante.puntaje,
        estudiante.estado
    );
}


// Listado de estudiantes completo
void mostrarEstudiantes(Estudiante estudiantes[], int cantidad) {
    if (cantidad == 0) {
        printf("Error: la lista de estudiantes esta vacia.\n");
        return;
    }

    printf("\nLISTA DE ESTUDIANTES\n");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < cantidad; i++) {
        imprimirEstudiante(estudiantes[i]);
    }
}


// Calculo del promedio general de los estudiantes
double calcularPromedio(Estudiante estudiantes[], int cantidad) {
    if (cantidad == 0) {
        printf("Error: no se puede calcular el promedio de una lista vacia.\n");
        return 0;
    }

    int suma = 0;

    for (int i = 0; i < cantidad; i++) {
        suma += estudiantes[i].puntaje;
    }

    return (double) suma / cantidad;
}


// Cuantos estan aplazados y cuantos aprobados
void contarEstados(Estudiante estudiantes[], int cantidad, int *aprobados, int *reprobados) {
    *aprobados = 0;
    *reprobados = 0;

    for (int i = 0; i < cantidad; i++) {
        if (strcmp(estudiantes[i].estado, "Aprobado") == 0) {
            (*aprobados)++;
        } else {
            (*reprobados)++;
        }
    }
}


// Buscar estudiante especifico
int buscarPorCodigo(Estudiante estudiantes[], int cantidad, char codigo[]) {
    for (int i = 0; i < cantidad; i++) {
        if (strcmp(estudiantes[i].codigo, codigo) == 0) {
            return i;
        }
    }

    return -1;
}


// Top de los estudiantes
void ordenarPorPuntaje(Estudiante estudiantes[], int cantidad) {
    // Ordenamiento burbuja manual de mayor a menor
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (estudiantes[j].puntaje < estudiantes[j + 1].puntaje) {
                Estudiante aux = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = aux;
            }
        }
    }
}


// Mejor estudiante
int obtenerMayorPuntaje(Estudiante estudiantes[], int cantidad) {
    if (cantidad == 0) {
        return -1;
    }

    int posicionMayor = 0;

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].puntaje > estudiantes[posicionMayor].puntaje) {
            posicionMayor = i;
        }
    }

    return posicionMayor;
}


// Peor estudiante
int obtenerMenorPuntaje(Estudiante estudiantes[], int cantidad) {
    if (cantidad == 0) {
        return -1;
    }

    int posicionMenor = 0;

    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].puntaje < estudiantes[posicionMenor].puntaje) {
            posicionMenor = i;
        }
    }

    return posicionMenor;
}


// Pausa del programa
void pausar() {
    printf("\nPresione Enter para continuar...");
    getchar();
}


// Mostrar menu
void mostrarMenu() {
    printf("\nSeleccione una opcion:\n");
    printf("1. Mostrar estudiantes\n");
    printf("2. Calcular promedio\n");
    printf("3. Contar quien paso y quien no\n");
    printf("4. Buscar por codigo\n");
    printf("5. Ordenar por puntaje\n");
    printf("6. Obtener mayor puntaje\n");
    printf("7. Obtener menor puntaje\n");
    printf("8. Validar puntaje\n");
    printf("9. Salir\n");
    printf("Opcion: ");
}


// Programa principal
int main() {
    Estudiante estudiantes[CANTIDAD_ESTUDIANTES] = {
        {"E001", "Ana Lopez", "Informatica", 85, ""},
        {"E002", "Carlos Gomez", "Informatica", 58, ""},
        {"E003", "Maria Torres", "Electronica", 92, ""},
        {"E004", "Jose Martinez", "Informatica", 47, ""},
        {"E005", "Lucia Fernandez", "Civil", 76, ""},
        {"E006", "Pedro Gonzalez", "Electronica", 63, ""},
        {"E007", "Sofia Benitez", "Informatica", 99, ""},
        {"E008", "Miguel Ruiz", "Civil", 34, ""},
        {"E009", "Laura Caceres", "Informatica", 68, ""},
        {"E010", "Diego Pereira", "Electronica", 55, ""},
        {"E011", "Valeria Acosta", "Civil", 81, ""},
        {"E012", "Fernando Rojas", "Informatica", 40, ""},
        {"E013", "Camila Duarte", "Electronica", 73, ""},
        {"E014", "Rodrigo Sosa", "Civil", 61, ""},
        {"E015", "Elena Franco", "Informatica", 89, ""}
    };

    int cantidad = CANTIDAD_ESTUDIANTES;

    // Calcular automaticamente el estado y validar puntajes
    for (int i = 0; i < cantidad; i++) {
        if (validarPuntaje(estudiantes[i].puntaje)) {
            calcularEstado(estudiantes[i].puntaje, estudiantes[i].estado);
        } else {
            strcpy(estudiantes[i].estado, "Puntaje invalido");
        }
    }

    int salir = 0;
    char opcion[10];

    while (!salir) {
        mostrarMenu();

        fgets(opcion, sizeof(opcion), stdin);
        opcion[strcspn(opcion, "\n")] = '\0';

        if (strcmp(opcion, "1") == 0) {
            mostrarEstudiantes(estudiantes, cantidad);
            pausar();

        } else if (strcmp(opcion, "2") == 0) {
            double promedio = calcularPromedio(estudiantes, cantidad);
            printf("\nPromedio general: %.2f\n", promedio);
            pausar();

        } else if (strcmp(opcion, "3") == 0) {
            int aprobados, reprobados;

            contarEstados(estudiantes, cantidad, &aprobados, &reprobados);

            printf("\nCantidad de aprobados: %d\n", aprobados);
            printf("Cantidad de reprobados: %d\n", reprobados);
            pausar();

        } else if (strcmp(opcion, "4") == 0) {
            char codigoBuscado[10];

            printf("\nBUSQUEDA DE ESTUDIANTE POR CODIGO\n");
            printf("Ingrese el codigo del estudiante: ");

            fgets(codigoBuscado, sizeof(codigoBuscado), stdin);
            codigoBuscado[strcspn(codigoBuscado, "\n")] = '\0';

            int posicion = buscarPorCodigo(estudiantes, cantidad, codigoBuscado);

            if (posicion != -1) {
                printf("Estudiante encontrado:\n");
                imprimirEstudiante(estudiantes[posicion]);
            } else {
                printf("Error: no existe un estudiante con el codigo %s\n", codigoBuscado);
            }

            pausar();

        } else if (strcmp(opcion, "5") == 0) {
            printf("\nESTUDIANTES ORDENADOS POR PUNTAJE DE MAYOR A MENOR\n");

            ordenarPorPuntaje(estudiantes, cantidad);
            mostrarEstudiantes(estudiantes, cantidad);

            pausar();

        } else if (strcmp(opcion, "6") == 0) {
            printf("\nESTUDIANTE CON MAYOR PUNTAJE\n");

            int posicionMayor = obtenerMayorPuntaje(estudiantes, cantidad);

            if (posicionMayor != -1) {
                imprimirEstudiante(estudiantes[posicionMayor]);
            } else {
                printf("No se encontro ningun estudiante.\n");
            }

            pausar();

        } else if (strcmp(opcion, "7") == 0) {
            printf("\nESTUDIANTE CON MENOR PUNTAJE\n");

            int posicionMenor = obtenerMenorPuntaje(estudiantes, cantidad);

            if (posicionMenor != -1) {
                imprimirEstudiante(estudiantes[posicionMenor]);
            } else {
                printf("No se encontro ningun estudiante.\n");
            }

            pausar();

        } else if (strcmp(opcion, "8") == 0) {
            char entrada[20];
            int puntajePrueba;

            printf("\nVALIDACION DE PUNTAJE\n");
            printf("Ingrese un puntaje para validar: ");

            fgets(entrada, sizeof(entrada), stdin);

            if (sscanf(entrada, "%d", &puntajePrueba) == 1) {
                if (validarPuntaje(puntajePrueba)) {
                    printf("El puntaje %d es valido.\n", puntajePrueba);
                } else {
                    printf("Error: el puntaje %d esta fuera del rango permitido.\n", puntajePrueba);
                }
            } else {
                printf("Error: debe ingresar un numero entero.\n");
            }

            pausar();

        } else if (strcmp(opcion, "9") == 0) {
            printf("Saliendo del programa...\n");
            salir = 1;

        } else {
            printf("Opcion invalida.\n");
            pausar();
        }
    }

    return 0;
}