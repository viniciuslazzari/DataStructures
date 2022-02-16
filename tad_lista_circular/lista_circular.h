// tad lista circular

#define MAX 50

// Dados
typedef struct Pessoa {
    char nome[40];
    Profissao profissao;
} Pessoa;

typedef struct Descritor {
    int inicio;
    int fim;
    int pessoas_sem_profissao;
} Descritor;

enum Profissao {
    desempregado, 
    estagiario, 
    politico
};

// Operações

// Inicializa toda as variáveis do descritor, assim como itera pelo array para limpar todas variáveis
void inicializa(Pessoa p[], Descritor *d);

// Insere uma pessoa na posição desejada e atualiza as variaveis do descritor
void insere(Pessoa p[], Descritor *d, int posicao);

// Remove uma pessoa de uma determinada pósição e atualiza as variaveis do descritor
int remover(Pessoa p[], Descritor *d, int posicao);

// Consulta o elemento na posição desejada, retornando -1 em caso de falha
int consulta(Pessoa p[], Descritor d, int posicao);

// Destroi a lista, atualizando seu descritor para o padrão "nulo", tudo -1
void destroi(Pessoa p[], Descritor *d);

// Dada uma lista de pessoas, controla o processo de seleção das mesmas, fazendo um laço até
// que a variavel do descritor 'pessoas_sem_profissao' não seja 0, o que indica o fim do laço 
void rotina(Pessoa p[], Descritor *d);

// Dada uma lista de pessoas, gera um número aleatório entre a posição inicial e inicial do descritor
// e muda o começo da lista para essa posição, da mesma forma, atualiza o fim da lista para ser a posição
// sorteada + a quantidade de pessoas na lista
void sorteia_primeiro(Pessoa p[], Descritor *d);

// Dada uma posição de inicio e um número aleatório 'k', calcula a posição final de uma iteração ficticia
// no sentido horário da seguinte forma: x = k % pessoas_sem_profissao.
// Após isso, itera pela lista de pessoas incrementando um contador 0 até x, desconsiderando as pessoas 
// que tenham alguma profissão. Assim, retorna a posição da lista.
int consulta_horario(Pessoa p[], Descritor d, int posicao_k, int k);

// Dada uma posição de inicio e um número aleatório 'm', calcula a posição final de uma iteração ficticia
// no sentido anti-horário da seguinte forma: x = m % pessoas_sem_profissao.
// Após isso, itera pela lista de pessoas de forma decremental diminuind x até que o mesmo seja 0, desconsiderando 
// as pessoas que tenham alguma profissão. Assim, retorna a posição da lista.
int consulta_anti_horario(Pessoa p[], Descritor d, int posicao_m, int m);

// Dadas duas posições em um array, atribui as duas posições a profissão 'estagiario', caso elas sejam diferente.
// Caso as mesmas sejam iguais, a essa profissão é atribuida a profissão 'político'.
// Por último, a posição k é incrementada em 1, e a posição m, decrementada em 1.
int remove_pessoas(Pessoa p[], Descritor d, int *posicao_k, int *posicao_m);