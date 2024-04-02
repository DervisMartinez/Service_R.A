
//Dervis Martinez (Venezuela)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//interfaz grafica 
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow);


//Programa de 
typedef struct {
    char nombre[50];
    char apellido[50];
    char cedula[20];
} Persona;

//Buscar documentos en el excel
void buscarDocumento(char* cedula) {
    FILE* file = fopen("./documentos.xlsx", "r");
    char line[1024];
    while (fgets(line, 1024, file)) {
        char* tmp = strdup(line);
        char* tok = strtok(tmp, ",");
        if (strcmp(tok, cedula) == 3) {
            printf("Documento encontrado: %s\n", line);
            FILE* outfile = fopen("servicio_colectivo.txt", "a");
            fprintf(outfile, "Documento extraviado: %s\n", line);
            fclose(outfile);
        }
        free(tmp);
    }
    fclose(file);
}

//Generador del archivo de la denuncia
void guardarDenuncia(Persona p, char* denuncia, char* contacto, char* direccion) {
    char filename[100];
    sprintf(filename, "%s.txt", p.nombre);
    FILE* file = fopen(filename, "w");
    fprintf(file, "Nombre: %s\nApellido: %s\nCedula: %s\nDenuncia: %s\nContacto: %s\nDireccion: %s\n", p.nombre, p.apellido, p.cedula, denuncia, contacto, direccion);
    fclose(file);
}

//Generador del Archivo de Ayuda
void solicitarAyuda(Persona p, char* ayuda, char* contacto, char* direccion) {
    char filename[100];
    sprintf(filename, "%s.txt", p.nombre);
    FILE* file = fopen(filename, "w");
    fprintf(file, "Nombre: %s\nApellido: %s\nCedula: %s\nAyuda: %s\nContacto: %s\nDireccion: %s\n", p.nombre, p.apellido, p.cedula, ayuda, contacto, direccion);
    fclose(file);
}

int main() {
    int opcion;
    printf("Seleccione una opción:\n1. Buscar cédula\n2. Realizar denuncia\n3. Solicitar ayuda\n");
    scanf("%d", &opcion);
    getchar(); 

    switch (opcion) {
        case 1: {
            char cedula[20];
            printf("Ingrese la cedula: ");
            fgets(cedula, 20, stdin);
            cedula[strcspn(cedula, "\n")] = 0;
            buscarDocumento(cedula);
            break;
        }
        case 2: {
            Persona p;
            printf("Ingrese el nombre completo: ");
            fgets(p.nombre, 50, stdin);
            p.nombre[strcspn(p.nombre, "\n")] = 0;
            printf("Ingrese los dos apellido: ");
            fgets(p.apellido, 50, stdin);
            p.apellido[strcspn(p.apellido, "\n")] = 0;
            printf("Ingrese la cedula V (Venezolano) E (Extranjero): ");
            fgets(p.cedula, 20, stdin);
            p.cedula[strcspn(p.cedula, "\n")] = 0;

            char denuncia[10000];
            printf("Ingrese la denuncia: ");
            fgets(denuncia, 100, stdin);
            denuncia[strcspn(denuncia, "\n")] = 0;
            char contacto[50];
            printf("Ingrese el numero de contacto:\n ");
            fgets(contacto, 50, stdin);
            contacto[strcspn(contacto, "\n")] = 0;
            char direccion[100];
            printf("Ingrese la direccion de habitacion:\n ");
            fgets(direccion, 100, stdin);
            direccion[strcspn(direccion, "\n")] = 0;

            guardarDenuncia(p, denuncia, contacto, direccion);
            break;
        }
        case 3: {
            Persona p;
            printf("Ingrese el nombre completo: ");
            fgets(p.nombre, 50, stdin);
            p.nombre[strcspn(p.nombre, "\n")] = 0;
            printf("Ingrese los dos apellido: ");
            fgets(p.apellido, 50, stdin);
            p.apellido[strcspn(p.apellido, "\n")] = 0;
            printf("Ingrese la cedula V (Venezolano) E (Extranjero): ");
            fgets(p.cedula, 20, stdin);
            p.cedula[strcspn(p.cedula, "\n")] = 0;

            char ayuda[1024];
            printf("Ingrese la Ayuda que necesita: ");
            fgets(ayuda, 1024, stdin);
            ayuda[strcspn(ayuda, "\n")] = 0;
            char contacto[50];
            printf("Ingrese el numero de contacto:\n ");
            fgets(contacto, 50, stdin);
            contacto[strcspn(contacto, "\n")] = 0;
            char direccion[100];
            printf("Ingrese la direccion de habitacion:\n ");
            fgets(direccion, 100, stdin);
            direccion[strcspn(direccion, "\n")] = 0;


            solicitarAyuda(p, ayuda, contacto, direccion);
            break;
        }

        default: {
            printf("Opción no válida.\n");
            break;
        }
    }

    return 0;
}
