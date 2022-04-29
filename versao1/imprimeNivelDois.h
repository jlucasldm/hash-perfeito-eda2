#include<stdio.h>
#include<stdlib.h>

int imprimeNivelDois(int m) {
	FILE *f;
    FILE *fniveldois;
	Celula c;
    Registro r;
    char filename[3];
	
	if (!(f = fopen("dados","r"))) {
		printf ("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	fseek (f, 0, SEEK_SET);
	printf("impressao de segundo bnivel\n");

	for (int i=0; i < m; i++) {
		fread (&c, sizeof (Celula), 1, f);

        if(c.mtab > 0){
            printf("---posicao %d---\n", i);

            sprintf(filename, "%d", i);
	        if (!(fniveldois = fopen(filename,"r"))) {
		    printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
		    exit(-1);
	        }

	        fseek (fniveldois, 0, SEEK_SET);
            for(int j = 0; j < c.mtab * c.mtab; j ++){
                fread (&r, sizeof (Registro), 1, fniveldois);
                if(r.ocupado == 0){
                    printf("%d: *\n", j);
                }   
            }

        }
	}
	
	fclose(f);
	return 1;
}
	  
