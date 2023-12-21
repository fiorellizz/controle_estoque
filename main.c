#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

Produto a[MAX];

void abertura(){

    printf("BEM VINDO AO PAINEL DE CONTROLE DE ESTOQUE!\n");
    printf("Para ter acesso ao painel ENTRE na sua conta ou CRIE uma!\n\n");
}

void painel(){

    printf("[1] Cadastrar");
    printf("\n[2] Listar");
    printf("\n[3] Buscar");
    printf("\n[4] Alterar");
    printf("\n[5] Excluir");
    printf("\n[0] Sair");
    printf("\nDigite a opção escolhida: ");
}

void cadastrar(int *indice){
    
    a[(*indice)].id = 1;
    for (int i = 0; i < (*indice); i++){
        if (a[(*indice)].id == a[i].id){
            a[(*indice)].id++;
        }    
    }

    a[(*indice)].status = 1;
    printf("Digite o nome do produto: ");
    fflush(stdin);
    fgets(a[(*indice)].nome, sizeof(a[(*indice)].nome), stdin);
    a[(*indice)].nome[strcspn(a[(*indice)].nome, "\n")] = '\0';
    printf("Digite a quantidade do produto: ");
    fflush(stdin);
    scanf("%d", &a[(*indice)].quantidade);
    printf("Digite o lote do produto: ");
    fflush(stdin);
    scanf("%d", &a[(*indice)].lote);

    (*indice)++;
}

void listarTodos(int indice){

    if (indice == 0){
        printf("\nNenhum registro encontrado!");
    } else {
        for (int i = 0; i < indice; i++){
            printf("Id: %d", a[i].id);
            printf("\nNome: %s", a[i].nome);
            printf("\nQuantidade: %d", a[i].quantidade);
            printf("\nLote: %d", a[i].lote);
            if (a[i].status == 1){
                printf("\nStatus: Ativado\n");
            } else {
                printf("\nStatus: Desativado\n");
            }
            printf("\n");
        }
    }
}

void listarProdutos(int indice){
    
    int escolha;
    if (indice == 0){
        printf("Nenhum registro encontrado!\n");
    } else {
        printf("1 - Ativados \n2 - Desativados \n3 - Todos \n");
        fflush(stdin);
        printf("Digite opção desejada: ");
        fflush(stdin);
        scanf("%d", &escolha);
        fflush(stdin);
        switch (escolha){
        case 1:
            for (int i = 0; i < indice; i++){
                if (a[i].status == 1){
                    printf("Id: %d", a[i].id);
                    printf("\nNome: %s", a[i].nome);
                    printf("\nQuantidade: %d", a[i].quantidade);
                    printf("\nLote: %d", a[i].lote);
                    printf("\nStatus: %d\n", a[i].status);
                    printf("\n");
                }
            }
            break;
        case 2:
            for (int i = 0; i < indice; i++){
                if (a[i].status == 0){
                    printf("Id: %d", a[i].id);
                    printf("\nNome: %s", a[i].nome);
                    printf("\nQuantidade: %d", a[i].quantidade);
                    printf("\nLote: %d", a[i].lote);
                    printf("\nStatus: %d\n", a[i].status);
                    printf("\n");
                }
            }
            break;
        case 3:
            listarTodos(indice);
            break;
        }
    }
}

void buscar(int indice, int idbusca){
    
    int encontrado = 0;
    for (int i = 0; i < indice; i++){
        if (idbusca == a[i].id){
            printf("Id: %d", a[i].id);
            printf("\nNome: %s", a[i].nome);
            printf("\nQuantidade: %d", a[i].quantidade);
            printf("\nLote: %d\n", a[i].lote);
            printf("\n");
            encontrado++;
        }
    }
    if (encontrado == 0){
        printf("\nNenhum produto encontrado no estoque!\n\n");
    }
}

void alterar(int indice, int idbusca){
    
    int escolha;
    for (int i = 0; i < indice; i++){
        if (idbusca == a[i].id){
            printf("Id: %d", a[i].id);
            printf("\nNome: %s", a[i].nome);
            printf("\nQuantidade: %d", a[i].quantidade);
            printf("\nLote: %d", a[i].lote);
            if (a[i].status == 1){
                printf("\nStatus: Ativado");
            } else {
                printf("\nStatus: Desativado");
            }
            printf("\n\n");
            printf("1 - Alterar Nome \n2 - Alterar Quantidade \n3 - Alterar Status \n4 - Alterar Lote \n5 - Alterar Todos \n");
            fflush(stdin);
            printf("Digite a opção desejada: ");
            fflush(stdin);
            scanf("%d", &escolha);
            fflush(stdin);
            if (escolha == 1){
                printf("Digite o novo nome: ");
                fgets(a[i].nome, sizeof(a[i].nome), stdin);
                a[indice].nome[strcspn(a[indice].nome, "\n")] = '\0';
                fflush(stdin);
            } else if (escolha == 2){
                printf("Digite a nova quantidade:");
                scanf("%d", &a[i].quantidade);
                fflush(stdin);
            } else if (escolha == 3){
                printf("Digite o novo status (0 ou 1): ");
                scanf("%d", &a[i].status);
                fflush(stdin);
            } else if (escolha == 4){
                printf("Digite o novo lote: ");
                scanf("%d", &a[i].lote);
                fflush(stdin);
            } else if (escolha == 5){
                printf("Digite o novo nome: ");
                fgets(a[i].nome, sizeof(a[i].nome), stdin);
                a[indice].nome[strcspn(a[indice].nome, "\n")] = '\0';
                printf("Digite a nova quantidade:");
                scanf("%d", &a[i].quantidade);
                printf("Digite o novo status (0 ou 1): ");
                scanf("%d", &a[i].status);
                printf("Digite o novo lote: ");
                scanf("%d", &a[i].lote);
                fflush(stdin);
            } else {
                printf("Opção invalida!\n");
            }
            printf("Digite qualquer tecla para voltar ao menu...");
            getch();
            system("cls");
            return;
        }
    }
}

void excluir(int indice, int idbusca){
    for (int i = 0; i < indice; i++){
        if (idbusca == a[i].id){
            for (int j = i; j < indice - 1; j++){
                a[j] = a[j + 1];
            }
            return;
        }
    }
    printf("Registro não encontrado!\n");
}

void criarConta(Usuario b[], int *count2){
    printf("Digite um nome de usuario para sua conta: ");
    fflush(stdin);
    fgets(b[*count2].bancoUsuario, sizeof(b[*count2].bancoUsuario), stdin);
    printf("Digite uma senha para sua conta: ");
    fflush(stdin);
    fgets(b[*count2].bancoSenha, sizeof(b[*count2].bancoSenha), stdin);

    (*count2)++;
}

void entrarConta(Usuario b[], int totalContas, int *login){
    int entrarContas = 0;

    printf("Digite seu usuario: ");
    fflush(stdin);
    fgets(b[entrarContas].usuario, sizeof(b[entrarContas].usuario), stdin);
    printf("Digite sua senha: ");
    fflush(stdin);
    fgets(b[entrarContas].senha, sizeof(b[entrarContas].senha), stdin);

    for (int i = 0; i < totalContas; i++){
        if (strcmp(b[entrarContas].usuario, b[i].bancoUsuario) == 0 && strcmp(b[entrarContas].senha, b[i].bancoSenha) == 0){
            *login = 1;
        }
    }
}

int main()
{
    
    Usuario b[MAX];
    int count = 0, escolha, idbusca, login = 0, count2 = 0, conta;
    char excluiDados, alterarDados;

    abertura();

    do{
        printf("[1] Entrar\n");
        printf("[2] Criar\n");
        printf("Digite a opção escolhida: ");
        fflush(stdin);
        scanf("%d", &conta);
        system("cls");

        if (conta == 1){
            entrarConta(b, count2, &login);
            if (login == 0){
                printf("Dados inválidos!\nFavor inserir novamente!\n");
                printf("Digite qualquer tecla para voltar ao menu...");
                getch();
                system("cls");
            } else {
                system("cls");
            }
        }
        else if (conta == 2){
            if (count2 < MAX){
                criarConta(b, &count2);
                printf("Conta criada com sucesso!\n");
                printf("Digite qualquer tecla para voltar ao menu...");
                getch();
                system("cls");
            } else {
                printf("Limite de contas atingidos!\n\n");
                printf("Digite qualquer tecla para voltar ao menu...");
                getch();
                system("cls");
            }
        }

    } while (login == 0);

    do{
        painel();
        scanf("%d", &escolha);
        system("cls");

        switch (escolha){
        case 1:
            if (count < MAX){
                cadastrar(&count);
                printf("Cadastro realizado com sucesso!\n");
                printf("Digite qualquer tecla para voltar ao menu...");
                getch();
                system("cls");
            } else {
                printf("Limite de cadastros atingidos!\n\n");
                printf("Digite qualquer tecla para voltar ao menu...");
                getch();
                system("cls");
            }
            break;

        case 2:
            listarProdutos(count);
            printf("Digite qualquer tecla para voltar ao menu...");
            getch();
            system("cls");
            break;

        case 3:
            printf("Digite o id do produto que quer buscar: ");
            fflush(stdin);
            scanf("%d", &idbusca);
            buscar(count, idbusca);
            break;

        case 4:
            listarTodos(count);
            printf("Digite o id que deseja alterar: ");
            fflush(stdin);
            scanf("%d", &idbusca);
            printf("Deseja realmente alterar (s / n)?\n");
            fflush(stdin);
            scanf("%c", &alterarDados);
            system("cls");
            if (alterarDados == 's'){
                alterar(count, idbusca);
            } else {
                printf("Alteração Cancelada!");
            }
            break;

        case 5:
            listarTodos(count);
            printf("Digite o id que deseja excluir: ");
            fflush(stdin);
            scanf("%d", &idbusca);
            printf("Deseja realmente excluir (s / n)?\n");
            fflush(stdin);
            scanf("%c", &excluiDados);
            if (excluiDados == 's'){
                excluir(count, idbusca);
                count--;
                printf("\nExcluido com sucesso!\n");
                printf("Digite qualquer tecla para voltar ao menu...");
                getch();
                system("cls");
            } else {
                printf("\nExclusao Cancelada!\n");
                printf("Digite qualquer tecla para voltar ao menu...");
                getch();
                system("cls");
            }
            break;

        default:
            break;
        }
        
    } while (escolha != 0);

    return 0;
}