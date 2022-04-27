const int PRIMOS[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 
                    29, 31, 37, 41, 43, 47, 53, 59, 
                    61, 67, 71, 73, 39, 83, 89, 97, 101};

//declaração do registro
typedef struct{   
    int chave;
    char nome[20];
    int idade;
} Dados;

typedef struct{
    int ocupado; //controle de vazio (0), atualmente ocupado por dado (1), vazio mas já ocupado uma vez (2)
    
} Registro;