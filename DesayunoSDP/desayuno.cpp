
#include <stdio.h>
#include <windows.h>

DWORD WINAPI prepararCafe(LPVOID arg) {
    printf("Preparando cafe...\n");
    Sleep(3000);
    printf("Cafe preparado.\n");
    return 0;
}

DWORD WINAPI tostarPan(LPVOID arg) {
    printf("Tostando pan...\n");
    Sleep(2000);
    printf("Pan tostado.\n");
    return 0;
}

DWORD WINAPI calentarLeche(LPVOID arg) {
    printf("Calentando leche...\n");
    Sleep(4000);
    printf("Leche caliente.\n");
    return 0;
}

int main() {
    HANDLE hilos[3];

    printf("Comenzando desayuno...\n");

    hilos[0] = CreateThread(NULL, 0, prepararCafe, NULL, 0, NULL);
    hilos[1] = CreateThread(NULL, 0, tostarPan, NULL, 0, NULL);
    hilos[2] = CreateThread(NULL, 0, calentarLeche, NULL, 0, NULL);

    if (hilos[0] == NULL || hilos[1] == NULL || hilos[2] == NULL) {
        printf("Error al crear los hilos.\n");
        return 1;
    }

    WaitForMultipleObjects(3, hilos, TRUE, INFINITE);

    printf("Desayuno listo!\n");

    for (int i = 0; i < 3; i++) {
        CloseHandle(hilos[i]);
    }

    return 0;
}
