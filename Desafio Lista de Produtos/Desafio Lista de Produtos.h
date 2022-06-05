struct produto {
    int cod;
    char descricao[61];
    char fornecedor[61];
    double preco;
    int quantidadeEstoque;

};
typedef struct produto Produto;

void inicializar(Produto* p[], int tam);

void adcionar(Produto* p[], int pos);

void listarTodos(Produto* p[], int pos);

void encontrar(Produto* p[], int proc, int pos);

void comprar(Produto* p[], int proc, int pos);

void vender(Produto* p[], int proc, int pos);

void atualizar(Produto* p[], int proc, int pos);

