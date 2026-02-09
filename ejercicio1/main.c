#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Opcion {
    Si,
    No
};

enum Opcion DeseaEvaluarOtraPersona() {
    char respuesta;
    printf("\nDesea evaluar otra persona? (S/N): ");
    scanf(" %c", &respuesta);

    if (respuesta == 'S' || respuesta == 's') {
        return Si;
    }

    return No;
};

int LeerEdadDePersona() {
    char buffer[10];
    char *lastPosition;

    strcpy(buffer,"");

    printf("\nDigite a edad: ");
    scanf("%s", buffer);

    const long value = strtol(buffer, &lastPosition, 10);
    return (int)value;
}

int LeerCredencial() {
    char buffer[10];
    char *lastPosition;

    strcpy(buffer,"");

    printf("\nDigite su credencial: ");
    scanf("%s", buffer);

    const long value = strtol(buffer, &lastPosition, 10);
    return (int)value;
}

void ReportarAccesoDenegado() {
    printf("\nAcceso Denegado");
}

void ReportarAccesoConcedido() {
    printf("\nAcceso Concedido");
}

int main(void) {
    enum Opcion opcion = Si;

    // el ciclo sirve para controlar el programa principal
    do {
        int edad = LeerEdadDePersona();
        if (edad < 18) {
            ReportarAccesoDenegado();
        } else {
            const int CREDENCIAL_VALIDA = 12345;
            int credencial = LeerCredencial();

            if (credencial == CREDENCIAL_VALIDA) {
                ReportarAccesoConcedido();
            } else {
                ReportarAccesoDenegado();
            }
        }
    } while (DeseaEvaluarOtraPersona() == Si);

    return 0;
}
