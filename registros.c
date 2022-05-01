#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "base.h"
#include "registros.h"

const int PRIMOS[] = {2, 3, 5, 7, 11, 13, 17, 19, 23,
                      29, 31, 37, 41, 43, 47, 53, 59,
                      61, 67, 71, 73, 39, 83, 89, 97, 101};

int insereRegistros(int m, int a, int b, int p) {
    FILE *fnivelum;
    FILE *fniveldois;
    Registro r;
    Celula c;
    char filename[3];
    fnivelum = fopen("nivelUm", "r+b");

    for (int i=0; i < m; i++) {
        scanf("%d\n", &r.dado.chave);
        //fgets(r.dado.nome, 20, stdin);
        scanf("%[^\n]%*c", r.dado.nome);
        scanf("%d", &r.dado.idade);
        r.hash = hash(a, b, p, m, r.dado.chave);
        r.ocupado = 1;


        // if (i == 0){
        //     int j = 0;
        //     p = PRIMOS[0];
        //     while (p <= r.dado.chave){
        //         j++;
        //         p = PRIMOS[j];
        //     }
        // }


        //criando so arquivos individuais
        sprintf(filename, "%d", r.hash);
        fniveldois = fopen(filename, "r+b");

        if(fniveldois == NULL){
            if (!(fniveldois = fopen(filename,"w+b"))){
                printf ("Erro na criacao do arquivo \"%s\".", filename);
                exit(-1);
            }
        }

        fseek(fnivelum, (r.hash) * sizeof(Celula), SEEK_SET);
        fread(&c, sizeof(Celula), 1, fnivelum);

        fseek(fniveldois, c.mtab * sizeof(Registro), SEEK_SET);
        fwrite (&r, sizeof(Registro), 1, fniveldois);

        c.mtab += 1;
        fseek(fnivelum, (r.hash) * sizeof(Celula), SEEK_SET);
        fwrite(&c, sizeof(Celula), 1, fnivelum);

        fclose(fniveldois);

    }

    fseek(fnivelum, 0, SEEK_SET);
    for(int i = 0; i < m; i++){
        fread(&c, sizeof(Celula), 1, fnivelum);
        if(c.mtab > 0){
            sprintf(filename, "%d", i);
            realocaRegistros(filename, c.mtab, c.a, c.b, p, c);
        }
    }

    fclose(fnivelum);

    return 1;
}

int realocaRegistros(char filename[3], int tamanho, int a, int b, int p, Celula c){
    FILE *f;
    FILE *falocado;

    if(tamanho == 1){
        c.a = 0;
        c.b = 0;
    }

    char filenameAlocado[10] = "";
    strcat(filenameAlocado, filename);
    strcat(filenameAlocado, "aloc");

    if (!(f = fopen(filename,"r+b"))) {
        printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
        exit(-1);
    }

    falocado = fopen(filenameAlocado,"w+b");

    Registro r;
    Registro raux;
    Registro rconsulta;
    r.ocupado = 0;
    int pos;

    for(int i = 0; i < (tamanho*tamanho); i++){
        fwrite (&r, sizeof(Registro), 1, falocado);
    }


    fseek(falocado, 0, SEEK_SET);
    fseek(f, 0, SEEK_SET);


    for(int i = 0; i < tamanho; i++){
        fread (&raux, sizeof(Registro), 1, f);
        pos = hash(a, b, p, tamanho*tamanho, raux.dado.chave);

        fseek(falocado, (pos) * sizeof(Registro), SEEK_SET);
        fread(&rconsulta, sizeof(Registro), 1, falocado);
        fseek(falocado, 0, SEEK_SET);

        if (rconsulta.ocupado == 0){
            fseek(falocado, (pos) * sizeof(Registro), SEEK_SET);
            fwrite (&raux, sizeof(Registro), 1, falocado);
            fseek(falocado, 0, SEEK_SET);
        }else if(rconsulta.ocupado == 1){
            c.a = (rand() % 102) + 1;
            c.b = rand() % 101;
            i = 0;
        }
    }

    fclose(f);
    fclose(falocado);
    return 1;
}

int consultaRegistro(int chave, int a, int b, int p){
    FILE *fnivelum;
    FILE *fniveldois;
    Celula c;
    Registro r;

    if (!(fnivelum = fopen("nivelUm","r"))) {
        printf ("Erro na abertura do arquivo \"nivelUm\" - Programa abortado\n");
        exit(-1);
    }

    fseek(fnivelum, 0, SEEK_END);
    int m = ftell(fnivelum)/sizeof(Celula);
    int hash_secundario;

    int posicao_primaria = hash(a, b, p, m, chave);
    fseek(fnivelum, posicao_primaria * sizeof(Celula), SEEK_SET);
    fread(&c, sizeof(Celula), 1, fnivelum);

    char filename[10] = "";
    sprintf(filename, "%d", posicao_primaria);
    strcat(filename, "aloc");

    if (!(fniveldois = fopen(filename,"r"))) {
        printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
        exit(-1);
    }

    int posicao_secundaria = hash(c.a, c.b, p, c.mtab*c.mtab, chave);
    fseek(fniveldois, posicao_secundaria*sizeof(Registro), SEEK_SET);
    fread(&r, sizeof(Registro), 1, fniveldois);

    if(r.dado.chave == chave){
        printf("chave: %d\n", r.dado.chave);
        printf("%s\n", r.dado.nome);
        printf("%d\n", r.dado.idade);
    }else{
        printf("chave nao encontrada: %d\n", chave);
    }

    fclose(fnivelum);
    fclose(fniveldois);
}