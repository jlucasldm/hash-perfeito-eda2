#include<stdio.h>
#include<stdlib.h>

int criaArquivoTemporario(int m) {
    FILE *ftemp;
    FILE *fnivelum;

    fnivelum = fopen("dados", "r+");
	
	if (!(ftemp = fopen("temp","w+"))){
			printf ("Erro na criacao do arquivo \"temp\".");
			exit(-1);
		}

	Registro r;
    Celula c;
    int a = 3;
    int b = 42;

	for (int i=0; i < m; i++) {
        scanf("%d", &r.dado.chave);
        scanf("%s", &r.dado.nome);
        scanf("%d", &r.dado.idade);

        // if (i == 0){
        //     int j = 0;
        //     p = PRIMOS[0];
        //     while (p <= r.dado.chave){
        //         j++;
        //         p = PRIMOS[j];
        //     }
        // }

        p = 101;

        r.hash = hash(a, b, p, m, r.dado.chave);
        fwrite (&r, sizeof(Registro), 1, ftemp);

	    fseek(fnivelum, (r.hash) * sizeof(Celula), SEEK_SET);
        fread(&c, sizeof(Celula), 1, fnivelum);
        c.mtab += 1;
        fseek(fnivelum, (r.hash) * sizeof(Celula), SEEK_SET);
        fwrite(&c, sizeof(Celula), 1, fnivelum);
	}
			
	fclose(ftemp);
    fclose(fnivelum);

    return 1;
}
	  
