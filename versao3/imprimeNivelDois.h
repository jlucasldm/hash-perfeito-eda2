#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int imprimeNivelDois(int m) {
	FILE *fnivelum;
    FILE *fniveldois;
	Celula c;
    Registro r;
    char filename[10];
	
	if (!(fnivelum = fopen("nivelUm","r"))) {
		printf ("Erro na abertura do arquivo \"nivelUm\" - Programa abortado\n");
		exit(-1);
	}

	fseek (fnivelum, 0, SEEK_SET);
	printf("impressao de segundo nivel\n");

	for (int i=0; i < m; i++) {
		fread (&c, sizeof (Celula), 1, fnivelum);

        if(c.mtab > 0){
            printf("---posicao %d---\n", i);

            sprintf(filename, "%d", i);
			strcat(filename, "aloc");
	        if (!(fniveldois = fopen(filename,"r"))) {
		    printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
		    exit(-1);
	        }

	        fseek (fniveldois, 0, SEEK_SET);
            for(int j = 0; j < c.mtab * c.mtab; j ++){
                fread (&r, sizeof (Registro), 1, fniveldois);
				if(r.ocupado != 0){
					printf("chave: %d \tnome: %s \t idade: %d \t hash: %d\n", r.dado.chave, r.dado.nome, r.dado.idade, r.hash);
				}else{
					printf("*\n");
				}
            }

        }
	}
	
	fclose(fnivelum);
	fclose(fniveldois);
	return 1;
}
	  
