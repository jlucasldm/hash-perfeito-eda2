#include <stdio.h>
#include "tiposArquivo.h"
#include "imprimeNivelUm.h"
#include "criaArquivoNivelUm.h"
#include "imprimeNivelDois.h"
#include "insereRegistros.h"
#include "realocaRegistros.h"

int main(){
    char entrada;
    scanf("%c", &entrada);

    if(entrada == 'i'){
        printf("insere registro\n");
        int m;
        scanf("%d", &m);
        criaArquivoNivelUm(m);            
        imprimeNivelUm(m);
        insereRegistros(m);
        imprimeNivelUm(m);
        // imprimeNivelDois(m);
        realocaRegistros("0aloc", 1, 0, 0);
        realocaRegistros("2aloc", 3, 10, 18);
        realocaRegistros("5aloc", 1, 0, 0);
        realocaRegistros("7aloc", 4, 23, 88);
        imprimeNivelDois(m);
    }

    // while (entrada != 'e'){
    //     switch (entrada){
    //     case 'i':
    //         printf("insere registro\n");
    //         int m;
    //         scanf("%d", &m);
    //         criaArquivoNivelUm(m);
    //         imprimeNivelUm(m);
    //         criaArquivoTemporario(m);
    //         imprimeNivelUm(m);
    //         imprimeTemporario(m);
    //         criaNivelDois(m);
    //         imprimeNivelUm(m);
    //         imprimeNivelDois(m);
    //         break;

    //     case 'c':
    //         printf("consulta registro\n");
    //         break;

    //     case 'p':
    //         printf("imprime primeiro nivel da estrutura de hashing\n");
    //         break;

    //     case 's':
    //         printf("imprime segundo nivel da estrutura de hashing\n");
    //         break;

    //     case 'h':
    //         printf("imprime estrutura global\n");
    //         break;

    //     case 'n':
    //         printf("cardinalidade do conjunto de funções de hashing universal\n");
    //         break;

    //     default:
    //         break;
    //     }

    //     scanf("%c", &entrada);
    // }

    return 0;
}