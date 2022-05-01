#include <stdio.h>
#include "tiposArquivo.h"
#include "imprimeNivelUm.h"
#include "criaArquivoNivelUm.h"
#include "imprimeNivelDois.h"
#include "realocaRegistros.h"
#include "insereRegistros.h"
#include "consultaRegistro.h"
#include "imprimeTodosNiveisDois.h"


int main(){
    char entrada;
    int m;
    int c;
    int indice;
    scanf("%c", &entrada);

    while (entrada != 'e'){
        switch (entrada){
        case 'i':
            scanf("%d", &m);
            criaArquivoNivelUm(m);
            insereRegistros(m);
            break;

        case 'c':
            scanf("%d", &c);
            consultaRegistro(c);
            break;

        case 'p':
            imprimeNivelUm(m);
            break;

        case 's':
            scanf("%d", &indice);
            imprimeNivelDois(indice);
            break;

        case 'h':
            imprimeNivelUm(m);
            imprimeTodosNiveisDois();
            break;

        case 'n':
            printf("%d", p * (p-1));
            break;

        default:
            break;
        }

        scanf("%c", &entrada);
    }

    return 0;
}