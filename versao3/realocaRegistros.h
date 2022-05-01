#include "consultaRegistro.h"
#include <string.h>

int realocaRegistros(char filename[3], int tamanho, int a, int b){
    FILE *f;
    FILE *falocado;
    
    char filenameAlocado[10] = "";
    strcat(filenameAlocado, filename);
    strcat(filenameAlocado, "aloc");

    if (!(f = fopen(filename,"r+"))) {
	    printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
	    exit(-1);
	}

    falocado = fopen(filenameAlocado,"w+");
    
    Registro r;
    Registro raux;
    Registro rconsulta;
    r.ocupado = 0;
    int pos;

    for(int i = 0; i < (tamanho*tamanho); i++){
        fwrite (&r, sizeof(Registro), 1, falocado);
    }


    fseek(falocado, 0, SEEK_SET);
    fseek(f, 0, SEEK_SET);


    for(int i = 0; i < tamanho; i++){
        printf("%d: ", i);
        fread (&raux, sizeof(Registro), 1, f);
        printf("chave: %d ", raux.dado.chave);
        pos = hash(a, b, p, tamanho*tamanho, raux.dado.chave);
        printf("pos: %d\n", pos);
        
        fseek(falocado, (pos) * sizeof(Registro), SEEK_SET);
        fread(&rconsulta, sizeof(Registro), 1, falocado);
        fseek(falocado, 0, SEEK_SET);
	    
        if (rconsulta.ocupado == 0){
            fseek(falocado, (pos) * sizeof(Registro), SEEK_SET);
            fwrite (&raux, sizeof(Registro), 1, falocado);
            fseek(falocado, 0, SEEK_SET);
	    }else if(rconsulta.ocupado == 1){
		    printf("ocupado\n");
	    }
    }

    fclose(f);
    fclose(falocado);
    return 1;
}