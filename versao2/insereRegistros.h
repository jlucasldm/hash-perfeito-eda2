#include<stdio.h>
#include<stdlib.h>

int insereRegistros(int m) {
    FILE *fnivelum;
    FILE *fniveldois;
	Registro r;
    Celula c;
    int a = 3;
    int b = 42;
    p = 101;
    char filename[3];

    Registro raux;
    Registro rvazio;
    rvazio.ocupado = 0;

    fnivelum = fopen("nivelUm", "r+");

	for (int i=0; i < m; i++) {
        scanf("%d", &r.dado.chave);
        scanf("%s", &r.dado.nome);
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

        printf("-----------arquivo %s---------------\n", filename);

        fseek(fnivelum, (r.hash) * sizeof(Celula), SEEK_SET);
        fread(&c, sizeof(Celula), 1, fnivelum);
        
        //insercao sequencial
        // fseek(fniveldois, c.mtab * sizeof(Registro), SEEK_SET);
        // fwrite (&r, sizeof(Registro), 1, fniveldois);

        c.mtab += 1;
        fseek(fnivelum, (r.hash) * sizeof(Celula), SEEK_SET);
        fwrite(&c, sizeof(Celula), 1, fnivelum);

        r.hash = hash(c.a, c.b, p, c.mtab * c.mtab , r.dado.chave);
        for(int j = 0; j < c.mtab * c.mtab; j++){
            fread(&raux, sizeof(Registro), 1, fniveldois);
            //printf("hash: %d\n", r.hash);

            //se nao nulo e a posicao esta vazia
            if(c.mtab == 1){
                printf("inserindo %d: em %d\n", r.dado.chave, r.hash);
                fseek(fniveldois, 0, SEEK_SET);
                fwrite(&r, sizeof(Registro), 1, fniveldois);
                fseek(fniveldois, (j+1) * sizeof(Registro), SEEK_SET);

            }else if(raux.ocupado != 0){
                printf("realocando raux chave %d hash antigo: %d\t", raux.dado.chave, raux.hash);
                raux.hash = hash(c.a, c.b, p, c.mtab * c.mtab , raux.dado.chave);
                printf("hash novo: %d\n", raux.hash);
                fseek(fniveldois, raux.hash * sizeof(Registro), SEEK_SET);
                fwrite(&raux, sizeof(Registro), 1, fniveldois);
                fseek(fniveldois, (j+1) * sizeof(Registro), SEEK_SET);

                if(r.hash == j){
                    printf("inserindo %d: em %d\n", r.dado.chave, r.hash);
                    fseek(fniveldois, j * sizeof(Registro), SEEK_SET);
                    fwrite(&r, sizeof(Registro), 1, fniveldois);
                    fseek(fniveldois, (j+1) * sizeof(Registro), SEEK_SET);
                }else if(raux.hash != j){
                    printf("escrevendo vazio na posicao %d\n", j);
                    fseek(fniveldois, j * sizeof(Registro), SEEK_SET);
                    fwrite(&rvazio, sizeof(Registro), 1, fniveldois);
                    fseek(fniveldois, (j+1) * sizeof(Registro), SEEK_SET);
                }
            }
            
        }

        fclose(fniveldois);

	}
    fclose(fnivelum);

    return 1;
}
	  
