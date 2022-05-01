#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int imprimeNivelUm(int m) {
	FILE *f;
	FILE *fniveldois;
	char filename[10];
	Registro r;
	Celula c;
	
	if (!(f = fopen("nivelUm","r"))) {
		printf ("Erro na abertura do arquivo \"nivelUm\" - Programa abortado\n");
		exit(-1);
	}

	fseek (f, 0, SEEK_SET);
	
	printf("hashing perfeito: primeiro nivel\n");
	printf("tamanho da tabela: %d\n", m);
	printf("parametro a: %d\n", a);
	printf("parametro b: %d\n", b);
	printf("numero primo: %d\n", p);
	for (int i=0; i < m; i++) {
		fread (&c, sizeof (Celula), 1, f);
        if(c.mtab != 0){
			printf("%d:", i);
            //printf("m: %d\ta: %d\tb: %d\n", c.mtab, c.a, c.b);

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
					printf(" %d", r.dado.chave);
				}
            }
			printf("\n");
        }
	}

	fclose(f);
	return 1;
}
	  
