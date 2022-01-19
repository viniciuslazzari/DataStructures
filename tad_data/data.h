// tad data (dd/mm/aaaa)

// tipo de dado
struct data
{
    int dia;
    int mes;
    int ano;
};

typedef struct data Data;

// operações

// lê uma data
void le_data(Data *data);

// valida uma data
int valida_data(Data data);

// imprime uma data
void imprime_data(Data data);

// calcula quantos dias existem entre duas datas
int calcula_dias(Data data1, Data data2);

// calcula a data da pascoa em um determinado ano
Data calcula_pascoa(int ano);
