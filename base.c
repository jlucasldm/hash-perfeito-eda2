#include<stdio.h>
#include<stdlib.h>

#include "base.h"

int criaArquivoNivelUm(int m) {
	FILE *f;
	
	f = fopen("nivelUm", "r+b");

	if(f == NULL){
		if (!(f = fopen("nivelUm","w+b"))){
			printf ("Erro na criacao do arquivo \"nivelUm\".");
			exit(-1);
		}

		Celula c;
		c.mtab = 0;

		for (int i = 0; i < m; i++) {
			if(i == 0 || i == 5){
				c.a = 0;
				c.b = 0;
			}else if(i == 2){
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

/*
p = primo maior que todas as possíveis chaves
a = coeficiente pertencente ao intervalo [1, p-1]
b = coeficiente pertencente ao intervalo [0, p-1]
m = quantidade de chaves, posições de distruibuição de chaves
k = chave
*/
int hash(int a, int b, int p, int m, int k){
    return (((a*k + b) % p) % m);
}
	  
