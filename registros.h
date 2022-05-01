#ifndef REGISTROS_H
#define REGISTROS_H

//declaração do registro
typedef struct{
    int chave;
    char nome[20];
    int idade;
} Dados;

typedef struct{
    int ocupado;
    int hash;
    Dados dado;
} Registro;

int insereRegistros(int m, int *a, int *b, int *p);

int realocaRegistros(char filename[3], int tamanho, int a, int b, int p, int id_celula);

int consultaRegistro(int chave, int a, int b, int p);

#endif //REGISTROS_H
