// tad lista encadeada

#define MAX 40

typedef struct Produto {
    int codigo;
    char nome[MAX];
    float preco;
} Produto;

typedef struct No {
    Produto produto;
    struct No* proximo;
} No;

// operacoes

// inicializa uma nova lista encadeada
No* inicializa(void);

// insere um produto na lista mantendo uma ordem por código
No* insere_produto(No* pont_lista, Produto produto);

// imprime todos os produtos da lista
void imprime(No* pont_lista);
