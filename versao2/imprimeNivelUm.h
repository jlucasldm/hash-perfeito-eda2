#include<stdio.h>
#include<stdlib.h>

int imprimeNivelUm(int m) {
	FILE *f;
	Celula c;
	
	if (!(f = fopen("nivelUm","r"))) {
		printf ("Erro na abertura do arquivo \"nivelUm\" - Programa abortado\n");
		exit(-1);
	}

	fseek (f, 0, SEEK_SET);
	
	for (int i=0; i < m; i++) {
        printf("%d: ", i);
		
		fread (&c, sizeof (Celula), 1, f);
        if(c.mtab == 0){
            printf("*\n");
        }else{
            printf("m: %d\ta: %d\tb: %d\n", c.mtab, c.a, c.b);
        }
	}

	fclose(f);
	return 1;
}
	  
