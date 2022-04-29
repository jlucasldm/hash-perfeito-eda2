#include "consultaRegistro.h"

int realocaRegistros(char filename[3], int tamanho, int a, int b){
    FILE *f;

    if (!(f = fopen(filename,"r+"))) {
	    printf ("Erro na abertura do arquivo \"%s\" - Programa abortado\n", filename);
	    exit(-1);
	}
    
    fseek(f, tamanho * sizeof(Registro), SEEK_SET);
    
    Registro r;
    Registro raux;
    Registro rconsulta;
    r.ocupado = 0;
    int pos;

    for(int i = 0; i < (tamanho*tamanho) - tamanho; i++){
        fwrite (&r, sizeof(Registro), 1, f);
    }

    fseek(f, 0, SEEK_SET);

    // for(int i = 0; i < tamanho; i++){
    //     printf("%d: ", i);
    //     fread (&raux, sizeof(Registro), 1, f);
    //     printf("chave: %d ", raux.dado.chave);
    //     pos = hash(a, b, p, tamanho*tamanho, raux.dado.chave);
    //     printf("pos: %d\n", pos);

    //     fseek(f, i * sizeof(Registro), SEEK_SET);
    //     fwrite (&r, sizeof(Registro), 1, f);
        
    //     fseek(f, (pos) * sizeof(Registro), SEEK_SET);
    //     fread(&rconsulta, sizeof(Registro), 1, f);
	    
    //     if (rconsulta.ocupado == 0){
    //         fseek(f, (pos) * sizeof(Registro), SEEK_SET);
    //         fwrite (&raux, sizeof(Registro), 1, f);
    //         fseek(f, (i+1) * sizeof(Registro), SEEK_SET);
	//     }else if(rconsulta.ocupado == 1){
	// 	    printf("ocupado\n");
	//     }
    // }

    fclose(f);
    return 1;
}