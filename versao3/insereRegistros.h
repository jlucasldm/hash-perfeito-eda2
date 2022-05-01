#include<stdio.h>
#include<stdlib.h>

int insereRegistros(int m) {
    FILE *fnivelum;
    FILE *fniveldois;
	Registro r;
    Celula c;
    char filename[3];
    fnivelum = fopen("nivelUm", "r+");

	for (int i=0; i < m; i++) {
        scanf("%d\n", &r.dado.chave);
        //fgets(r.dado.nome, 20, stdin);
        scanf("%[^\n]%*c", r.dado.nome);
        scanf("%d", &r.dado.idade);
        r.hash = hash(a, b, p, m, r.dado.chave);
        r.ocupado = 1;
        

        // if (i == 0){
        //     int j = 0;
        //     p = PRIMOS[0];
        //     while (p <= r.dado.chave){
        //         j++;
        //         p = PRIMOS[j];
        //     }
        // }


        //criando so arquivos individuais
        sprintf(filename, "%d", r.hash);
        fniveldois = fopen(filename, "r+");

	    if(fniveldois == NULL){
		    if (!(fniveldois = fopen(filename,"w+"))){
			    printf ("Erro na criacao do arquivo \"%s\".", filename);
			    exit(-1);
		    }   
        }

        fseek(fnivelum, (r.hash) * sizeof(Celula), SEEK_SET);
        fread(&c, sizeof(Celula), 1, fnivelum);
        
        fseek(fniveldois, c.mtab * sizeof(Registro), SEEK_SET);
        fwrite (&r, sizeof(Registro), 1, fniveldois);

        c.mtab += 1;
        fseek(fnivelum, (r.hash) * sizeof(Celula), SEEK_SET);
        fwrite(&c, sizeof(Celula), 1, fnivelum);

        fclose(fniveldois);

	}

    fseek(fnivelum, 0, SEEK_SET);
    for(int i = 0; i < m; i++){
        fread(&c, sizeof(Celula), 1, fnivelum);
        if(c.mtab > 0){
            sprintf(filename, "%d", i);
            realocaRegistros(filename, c.mtab, c.a, c.b, c);
        }
    }

    fclose(fnivelum);

    return 1;
}
	  
