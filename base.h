#ifndef BASE_H
#define BASE_H

//célula da tabela de primeiro nível
typedef struct{
    int mtab;          //quadrado da quantidade de registros
    int a;          //coeficiente do hash
    int b;          //coeficiente do hash
} Celula;

int criaArquivoNivelUm(int m);

int hash(int a, int b, int p, int m, int k);

#endif //BASE_H
