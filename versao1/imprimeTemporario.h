#include<stdio.h>
#include<stdlib.h>

int imprimeTemporario(int m) {
	FILE *f;
	Registro r;
	
	if (!(f = fopen("temp","r"))) {
		printf ("Erro na abertura do arquivo \"temp\" - Programa abortado\n");
		exit(-1);
	}

	fseek (f, 0, SEEK_SET);
	
	for (int i=0; i < m; i++) {
        printf("%d: ", i);
		
		fread (&r, sizeof (Registro), 1, f);
        printf("chave: %d \tnome: %s \t idade: %d \t hash: %d\n", r.dado.chave, r.dado.nome, r.dado.idade, r.hash);
	}
	
	fclose(f);
	return 1;
}
	  
