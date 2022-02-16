// tad lista duplamente encadeada

#define MAX 40

typedef struct TipoInfoNo {
    int codigo;
    char nome[MAX];
    float preco;
} InfoNo;

typedef struct TipoPtNo {
    InfoNo info;
    struct TipoPtNo* anterior;
    struct TipoPtNo* proximo;
} PtNo;

// operacoes

// inicializa uma nova lista duplamente encadeada
PtNo* inicializa(void);

// insere um produto no final da lista
PtNo* insere_produto_final(PtNo* pont_lista, InfoNo produto);

// remove um produto que contenha determinado código da lista
PtNo* remove_produto(PtNo* pont_lista, int codigo);

// imprime todos os produtos da lista
void imprime(PtNo* pont_lista);
