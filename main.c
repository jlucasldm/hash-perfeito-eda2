#include <stdio.h>

#include "base.h"
#include "impressao.h"
#include "registros.h"

int p = 101;
int a = 3;
int b = 42;

int main(){
    char entrada;
    int m;
    int c;
    int indice;
    FILE *f;
    scanf("%c", &entrada);

    f = fopen("nivelUm", "r+b");
    if(f != NULL){
        fseek(f, -3*sizeof(int), SEEK_END);
        fread(&p, sizeof(int), 1, f);
        fread(&a, sizeof(int), 1, f);
        fread(&b, sizeof(int), 1, f);
    }

    while (entrada != 'e'){
        switch (entrada){
        case 'i':
            scanf("%d", &m);
            insereRegistros(m, &a, &b, &p);
            printf("estrutura de hashing perfeito criada\n");
            break;

        case 'c':
            scanf("%d", &c);
            consultaRegistro(c, a, b, p);
            break;

        case 'p':
            imprimeNivelUm(a, b, p);
            break;

        case 's':
            scanf("%d", &indice);
            imprimeNivelDois(indice, p);
            break;

        case 'h':
            imprimeNivelUm(a, b, p);
            imprimeTodosNiveisDois(p);
            break;

        case 'n':
            printf("%d\n", p * (p-1));
            break;

        default:
            break;
        }

        scanf("%c", &entrada);
    }

    return 0;
}