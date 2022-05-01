#include <stdlib.h>

int consultaRegistro(int chave){
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

    if (!(fniveldois = fopen(filename,"r+"))) {
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