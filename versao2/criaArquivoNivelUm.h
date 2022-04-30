#include<stdio.h>
#include<stdlib.h>

int criaArquivoNivelUm(int m) {
	FILE *f;
	
	f = fopen("nivelUm", "r+");

	if(f == NULL){
		if (!(f = fopen("nivelUm","w+"))){
			printf ("Erro na criacao do arquivo \"nivelUm\".");
			exit(-1);
		}

		Celula c;
		c.mtab = 0;

		for (int i = 0; i < m; i++) {
			if(i == 2){
				c.a = 10;
				c.b = 18;
			}else if(i == 7){
				c.a = 23;
				c.b = 88;
			}else{
				c.a = (rand() % 102) + 1;
				c.b = rand() % 101;
			}
			fwrite (&c, sizeof(Celula), 1, f);
		}
			
		fclose(f);
	}

    return 1;
}
	  
