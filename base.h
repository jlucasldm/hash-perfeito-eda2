#ifndef BASE_H
#define BASE_H

//célula da tabela de primeiro nível
typedef struct{
    int mtab;          //quadrado da quantidade de registros
    int a;          //coeficiente do hash
    int b;          //coeficiente do hash
} Celula;

//Função responsável por criar a tabela de nível um. Recebe um valor m, tamanho de registros, 
int criaArquivoNivelUm(int m, int p, int a_global, int b_global);

int hash(int a, int b, int p, int m, int k);

#endif //BASE_H
