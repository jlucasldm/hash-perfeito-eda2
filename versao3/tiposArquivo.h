const int PRIMOS[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 
                    29, 31, 37, 41, 43, 47, 53, 59, 
                    61, 67, 71, 73, 39, 83, 89, 97, 101};

int p = 101;
int a = 3;
int b = 42;
int cadeias = 0;
int cadeias_m;

//declaração do registro
typedef struct{   
    int chave;
    char nome[20];
    int idade;
} Dados;

typedef struct{
    int ocupado;
    int hash;
    Dados dado;
} Registro;

//célula da tabela de primeiro nível
typedef struct{
    int mtab;          //quadrado da quantidade de registros
    int a;          //coeficiente do hash
    int b;          //coeficiente do hash
    int endereco_segundo_nivel;
} Celula;


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