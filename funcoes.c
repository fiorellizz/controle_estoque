#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "main.h"

void abertura(){
    system("cls");
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
    printf("\nDigite sua escolha: ");
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

void listarProdutos(int indice){ //quando listar apenas ativados ou desativados e não tiver produtos no estoque não aparece nada falando que não tem produto

    int escolha;
    if (indice == 0){
        printf("Nenhum registro encontrado!\n");
    } else {
        printf("1 - Ativados \n2 - Desativados \n3 - Todos \n");
        fflush(stdin);
        printf("Digite sua escolha: ");
        fflush(stdin);
        scanf("%d", &escolha);
        fflush(stdin);
        system("cls");
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
            printf("Digite sua escolha: ");
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
                printf("Digite o novo status (0 para DESATIVADO) ou (1 para ATIVADO): ");
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
                printf("Opcao invalida!\n");
            }
            printf("Dados alterados com sucesso!\n");
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
    printf("Digite um usuario: ");
    fflush(stdin);
    fgets(b[*count2].bancoUsuario, sizeof(b[*count2].bancoUsuario), stdin);
    printf("Digite uma senha: ");
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