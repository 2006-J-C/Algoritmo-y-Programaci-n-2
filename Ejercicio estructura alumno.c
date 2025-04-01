#include <stdio.h>
#include <stdlib.h>

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
        perror("Error al abrir el archivo para escribir");
        return 1;
    }
    fwrite(alumnos, sizeof(Alumno), 3, file);
    fclose(file);

    file = fopen("alumnos.dat", "rb");
    if (file == NULL) {
        perror("Error al abrir el archivo para leer");
        return 1;
    }
    
    Alumno alumnosLeidos[3];
    fread(alumnosLeidos, sizeof(Alumno), 3, file);
    fclose(file);

    // Mostrar los datos leídos
    printf("Datos de los alumnos:\n");
    for (int i = 0; i < 3; i++) {
        printf("Nombre: %s, Edad: %d, Promedio: %.2f\n", alumnosLeidos[i].nombre, alumnosLeidos[i].edad, alumnosLeidos[i].promedio);
    }

    return 0;
}
