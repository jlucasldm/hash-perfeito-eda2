#include<stdio.h>
#include<stdlib.h>

int criaNivelDois(int m) {
	FILE *ftemp;
    FILE *fnivelum;
	FILE *fniveldois;
	Celula c;
    Registro r;
    int pos;
    int alocado = 0;
	char filename[3];
	
	if (!(ftemp = fopen("temp","r"))) {
		printf ("Erro na abertura do arquivo \"temp\" - Programa abortado\n");
		exit(-1);
	}

    if (!(fnivelum = fopen("dados","r"))) {
		printf ("Erro na abertura do arquivo \"dados\" - Programa abortado\n");
		exit(-1);
	}

    // sprintf(filename, "%d", r.hash);
    // if (!(fniveldois = fopen(filename,"r"))) {
	// 	printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
	// 	exit(-1);
	// }

	fseek (ftemp, 0, SEEK_SET);
    fseek (fnivelum, 0, SEEK_SET);
    fseek (fniveldois, 0, SEEK_SET);

	for (int i = 0; i < m; i++) {
		fread (&c, sizeof (Celula), 1, fnivelum);

        if(c.mtab > 0){
            while(alocado < c.mtab){
                fread (&r, sizeof (Registro), 1, temp);
                if(!consultaRegistro(hash(c.a, c.b, p, c.mtab * c.mtab ,r.dado.chave), fniveldois)){
                    fseek(fniveldois, hash(c.a, c.b, p, c.mtab * c.mtab ,r.dado.chave) * sizeof(Registro), SEEK_SET);
                    fwrite (&r, sizeof(Registro), 1, fniveldois);
                    fseek (fniveldois, 0, SEEK_SET);
                    alocado += 1;
                }
            }
        }

        

        
	}
	
	fclose(f);
	return 1;
}
	  
