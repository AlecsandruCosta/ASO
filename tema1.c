#include <stdio.h>
#include <stdlib.h>

/*
 * - sz: string zero-terminated
 * - p: pointer
 * - f: file / handle
 */

int main() {
    char szPath[260];
    char szBuffer[1024];
    FILE* pFile = NULL;

    printf("Introduceti calea relativa a fisierului: ");
    
    if (scanf("%259s", szPath) != 1) {
        printf("Eroare la citirea caii.\n");
        return 1;
    }

    pFile = fopen(szPath, "r");

    if (pFile == NULL) {
        perror("Eroare");
        printf("Fisierul '%s' nu a putut fi gasit.\n", szPath);
        return 1;
    }

    printf("\n--- Continutul Fisierului ---\n\n");

    while (fgets(szBuffer, sizeof(szBuffer), pFile) != NULL) {
        printf("%s", szBuffer);
    }

    printf("\n\n--- Sfarsit Document ---\n");
    fclose(pFile);

    return 0;
}