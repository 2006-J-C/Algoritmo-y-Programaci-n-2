#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[20];
    float nota;
} Alumno;

int main() {
    Alumno alumnos[3] = {
        {"Jhonzo", 20},
        {"Maria", 11},
        {"Juan", 15}
    };

    FILE *file = fopen("alumnos.bin", "wb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    fwrite(alumnos, sizeof(Alumno), 3, file);
    fclose(file);

    
    file = fopen("alumnos.bin", "rb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    Alumno alumnosLeidos[3];
    fread(alumnosLeidos, sizeof(Alumno), 3, file);
    fclose(file);

    
    for (int i = 0; i < 3; i++) {
        printf("Nombre: %s, Nota: %.2f\n", alumnosLeidos[i].nombre, alumnosLeidos[i].nota);
    }

    return 0;
}