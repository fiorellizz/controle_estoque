#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "main.h"
#include "funcoes.c"

int main(){
    
    setlocale(LC_ALL,"Portuguese");

    //tentar criar variaveis nas funções
    int count = 0, escolha, idbusca, login = 0, count2 = 0, conta;
    char excluiDados, alterarDados;

    abertura();

    do{ //criar uma função para verificar se o numero digitado foi correto
        printf("[1] Entrar\n");
        printf("[2] Criar\n");
        printf("Digite sua escolha: ");
        fflush(stdin);
        scanf("%d", &conta);
        system("cls");

        if (conta == 1){
            entrarConta(b, count2, &login);
            if (login == 0){
                printf("Dados invalidos!\nFavor inserir novamente!\n");
                system("pause");
            } else {
                system("cls");
            }
        }
        else if (conta == 2){
            if (count2 < MAX){
                criarConta(b, &count2);
                printf("Conta criada com sucesso!\n");
                system("pause");
            } else {
                printf("Limite de contas atingidos!\n\n");
                system("pause");
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
                system("pause");
            } else {
                printf("Limite de cadastros atingidos!\n\n");
                system("pause");
            }
            break;

        case 2:
            listarProdutos(count);
            system("pause");
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
                system("pause");
            } else {
                printf("\nExclusao Cancelada!\n");
                system("pause");
            }
            break;

        default:
            break;
        }
        
    } while (escolha != 0);

    return 0;
}