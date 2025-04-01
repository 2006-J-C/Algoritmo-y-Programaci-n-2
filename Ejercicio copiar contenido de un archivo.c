#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *origen = fopen("origen.txt", "r");
    char j;
    if (origen == NULL) {
        perror("El archivo origen no existe");
        return 1;
    }

    FILE *copia = fopen("copia.txt", "w");
    if (copia == NULL) {
        perror("Error al crear el archivo copia");
        fclose(copia);
        return 1;
    }

    
    while ((j = fgetc(origen)) != EOF) {
        fputc(j, copia);
    }

    return 0;
}