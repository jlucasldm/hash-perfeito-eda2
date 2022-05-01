#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int imprimeNivelDois(int indice) {
	FILE *fnivelum;
    FILE *fniveldois;
	Celula c;
    Registro r;
    char filename[10];
	
	if (!(fnivelum = fopen("nivelUm","r"))) {
		printf ("Erro na abertura do arquivo \"nivelUm\" - Programa abortado\n");
		exit(-1);
	}

	fseek(fnivelum, 0, SEEK_SET);
	fseek(fnivelum, indice * sizeof(Celula), SEEK_SET);
	fread(&c, sizeof(Celula), 1, fnivelum);

	printf("hashing perfeiro: segundo nivel - indice: %d\n", indice);
	printf("tamanho da tabela: %d\n", c.mtab * c.mtab);
	printf("parametro a: %d\n", c.a);
	printf("parametro b: %d\n", c.b);
	printf("numero primo: %d\n", p);

    sprintf(filename, "%d", indice);
	strcat(filename, "aloc");
	if (!(fniveldois = fopen(filename,"r"))) {
		printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
		exit(-1);
	}

	fseek (fniveldois, 0, SEEK_SET);
    for(int j = 0; j < c.mtab * c.mtab; j ++){
    	fread (&r, sizeof (Registro), 1, fniveldois);
		if(r.ocupado != 0){
			printf("%d: ", j);
			printf("%d\n", r.dado.chave);
		}
    }
	
	fclose(fnivelum);
	fclose(fniveldois);
	return 1;
}
	  
