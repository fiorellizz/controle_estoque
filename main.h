#define MAX 3

typedef struct{

    char nome[20];
    int quantidade, lote, id, status;

} Produto;

typedef struct{

    char usuario[50], senha[50], bancoUsuario[50], bancoSenha[50];

} Usuario;

typedef struct{

    char bancoUsuario[50], bancoSenha[50];

} DadosPrivados;

void abertura();
void painel();
void cadastrar(int *indice);
void listarTodos(int indice);
void listarProdutos(int indice);
void buscar(int indice, int idbusca);
void alterar(int indice, int idbusca);
void excluir(int indice, int idbusca);
void entrarConta(Usuario b[], int totalContas, int *login);
void criarConta(Usuario b[], int *count2);