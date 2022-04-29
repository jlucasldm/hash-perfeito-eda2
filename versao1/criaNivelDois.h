#include<stdio.h>
#include<stdlib.h>

int criaNivelDois(int m) {
	FILE *f;
	FILE *fniveldois;
	Celula c;
	char filename[3];
	
	if (!(f = fopen("dados","r"))) {
		printf ("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

	fseek (f, 0, SEEK_SET);
	
	for (int i = 0; i < m; i++) {
		
		fread (&c, sizeof (Celula), 1, f);

        if(c.mtab > 0){
			sprintf(filename, "%d", i);
			if (!(fniveldois = fopen(filename,"w+"))){
				printf ("Erro na criacao do arquivo \"%s\".", filename);
				exit(-1);
			}

			Registro r;
			r.ocupado = 0;

			for(int j = 0; j < c.mtab * c.mtab; j++){
				fwrite (&r, sizeof(Registro), 1, fniveldois);
			}
			fclose(fniveldois);
        }
	}
	
	fclose(f);
	return 1;
}
	  
