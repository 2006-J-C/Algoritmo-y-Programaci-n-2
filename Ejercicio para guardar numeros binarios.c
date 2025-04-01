#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero = 19;

    FILE *file = fopen("numero.bin", "wb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    fwrite(&numero, sizeof(int), 1, file);
    fclose(file);

    
    file = fopen("numero.bin", "rb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    int numeroLeido;
    fread(&numeroLeido, sizeof(int), 1, file);
    fclose(file);

    printf("Número leido es: %d\n", numeroLeido);

    return 0;
}