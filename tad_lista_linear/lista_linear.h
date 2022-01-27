// tad lista linear

#define MAX 10

typedef struct T_Produto {
    int cod;
    char nome[40];
    float preco;
} TProduto;

int inicio, fim, maximo;

void inicializa(TProduto t[], int *inicio, int *fim);
void insere(TProduto t[], int *inicio, int *fim, int posicao);
int remover(TProduto t[], int *inicio, int *fim, int posicao);
int consulta(TProduto t[], int inicio, int fim, int posicao);
void destroi(int *inicio, int *fim);
