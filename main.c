#include <stdio.h>
#include "tiposArquivo.h"

int main(){
    char entrada;
    scanf("%c", &entrada);

    while (entrada != 'e'){
        switch (entrada){
        case 'i':
            printf("insere registro\n");
            break;

        case 'c':
            printf("consulta registro\n");
            break;

        case 'p':
            printf("imprime primeiro nivel da estrutura de hashing\n");
            break;

        case 's':
            printf("imprime segundo nivel da estrutura de hashing\n");
            break;

        case 'h':
            printf("imprime estrutura global\n");
            break;

        case 'n':
            printf("cardinalidade do conjunto de funções de hashing universal\n");
            break;

        default:
            break;
        }

        scanf("%c", &entrada);
    }

    return 0;
}