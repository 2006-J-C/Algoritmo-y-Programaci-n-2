#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[20];
    int edad;
    float promedio;
} Alumno;

int main() {
    Alumno alumnos[3] = {
        {"Jhonzo", 19, 20},
        {"Maria", 18, 11},
        {"Jose", 24, 15}
    };

    FILE *file = fopen("alumnos.dat", "wb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    fwrite(alumnos, sizeof(Alumno), 3, file);
    fclose(file);

    file = fopen("alumnos.dat", "rb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char nombreBuscado[20];
    printf("Ingrese el nombre del alumno a buscar: ");
    scanf("%19s", nombreBuscado);

    Alumno alumnoBuscado;
    int encontrado = 0;

    while (fread(&alumnoBuscado, sizeof(Alumno), 1, file)) {
        if (strcmp(alumnoBuscado.nombre, nombreBuscado) == 0) {
            printf("Alumno encontrado:\n");
            printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", alumnoBuscado.nombre, alumnoBuscado.edad, alumnoBuscado.promedio);
            encontrado = 1;
            break; 
            
        }
    }

    if (!encontrado) {
        printf("Alumno con nombre '%s' no encontrado.\n", nombreBuscado);
    }

    fclose(file);
    return 0;
}