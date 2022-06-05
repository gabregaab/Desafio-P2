#include <stdio.h>
#include <stdlib.h>
#include "Desafio lista de produtos.h"

void inicializar(Produto* p[], int tam){
    for(int i=0; i<tam; i++){
        p[i] = NULL;
    }
}

void adicionar(Produto* p[], int pos){
    p[pos] = (Produto*)malloc(sizeof(struct produto));
    fflush(stdin);
    printf("Digite a descricao do produto: \n");
    scanf("%[^\n]", p[pos]->descricao);
    fflush(stdin);
    printf("Digite o codigo do produto: \n");
    scanf("%d", &p[pos]->cod);
    fflush(stdin);
    printf("Digite o fornecedor: \n");
    scanf("%[^\n]", p[pos]->fornecedor);
    fflush(stdin);
    printf("Digite o preco do produto: \n");
    scanf("%lf", &p[pos]->preco);
    fflush(stdin);
    printf("Digite a quantidade de estoque: \n");
    scanf("%d", &p[pos]->quantidadeEstoque);
    printf("Produto adicionado com sucesso \n");
}
void listarTodos(Produto* p[], int pos){
    for(int i=0; i<pos; i++){
        printf("Dados do Cadastro: %d \n", i+1 );
        printf("Produto: %s \n", p[i]->descricao);
        printf("Codigo do produto: %d \n", p[i]->cod);
        printf("Fornecedor: %s \n", p[i]->fornecedor);
        printf("Preco: R$%.2lf \n", p[i]->preco);
        printf("Quantidade em estoque: %d \n", p[i]->quantidadeEstoque);
        printf("--------------------------------------\n");
    }
}

void encontrar(Produto* p[], int proc, int pos){
    for(int i=0; i<pos; i++){
        if(proc== p[i]->cod){
        printf("Dados do Cadastro: %d \n", i+1 );
        printf("Produto: %s \n", p[i]->descricao);
        printf("Codigo do produto: %d \n", p[i]->cod);
        printf("Fornecedor: %s \n", p[i]->fornecedor);
        printf("Preco: R$%.2lf \n", p[i]->preco);
        printf("Quantidade em estoque: %d \n", p[i]->quantidadeEstoque);
        printf("--------------------------------------\n");
            return;
        }
    }
    printf("Registro nao encontrado \n");
    return;
}

void atualizar(Produto* p[], int proc, int pos){
    int resp = 0;
    for(int i=0; i<pos; i++){
        if(proc== p[i]->cod){
            printf("Atualizar Registro: %d \n", i+1 );
            printf("Atualizar a descricao? [0] nao, [1] sim\n");
            scanf("%d", &resp);
            if(resp){
                    fflush(stdin);
                printf("Descricao: %s \n", p[i]->descricao);
                printf("Digite a nova descricao: \n");
                scanf("%[^\n]", p[i]->descricao);
                printf("Descricao Atualizada com sucesso \n");
            }
            printf("Atualizar o fornecedor? [0] nao, [1] sim\n");
            scanf("%d", &resp);
            if(resp){
                    fflush(stdin);
                printf("Fornecedor: %s \n", p[i]->fornecedor);
                printf("Digite o novo fornecedor: \n");
                scanf("%[^\n]", p[i]->fornecedor);
                printf("Fornecedor Atualizado com sucesso \n");
            }
            printf("Atualizar o preco? [0] nao, [1] sim\n");
            scanf("%d", &resp);
            if(resp){
                    fflush(stdin);
                printf("preco atual: R$%.2lf \n", p[i]->preco);
                printf("Digite o novo preco: \n");
                scanf("%lf", &p[i]->preco);
                printf("Preco Atualizado com sucesso \n");
            }
            printf("Atualizar a Quantidade em estoque? [0] nao, [1] sim\n");
            scanf("%d", &resp);
            if(resp){
                    fflush(stdin);
                printf("Quantidade em estoque: %d \n", p[i]->quantidadeEstoque);
                printf("Digite a nova quantidade em estoque: \n");
                scanf("%d", &p[i]->quantidadeEstoque);
            }
            printf("Qauntidade Atualizada com sucesso \n");
            return;
        }
    }
    printf("Registro não encontrado \n");
}
void comprar(Produto* p[], int proc, int pos){
        for(int i=0; i<pos; i++){
        int compra = 0;
        if(proc== p[i]->cod){
                fflush(stdin);
                printf("Dados do Cadastro: %d \n", i+1 );
                printf("Produto: %s \n", p[i]->descricao);
                printf("Codigo do produto: %d \n", p[i]->cod);
                printf("Fornecedor: %s \n", p[i]->fornecedor);
                printf("Preco: R$%.2lf \n\n", p[i]->preco);
                printf("Digite a quantidade comprada: \n");
                scanf("%d", &compra);
                p[i]-> quantidadeEstoque += compra;
            }
            printf("Valor total da Venda R$%.2lf\n", p[i]->preco * compra );
            printf("Compra concluida! \n");
            printf("Quantidade atualizada em estoque: %d \n", p[i]->quantidadeEstoque);
            return;

        }
}
void vender(Produto* p[], int proc, int pos){
        for(int i=0; i<pos; i++){
        int venda = 0;
        if(proc== p[i]->cod){
                fflush(stdin);
                printf("Dados do Cadastro: %d \n", i+1 );
                printf("Produto: %s \n", p[i]->descricao);
                printf("Codigo do produto: %d \n", p[i]->cod);
                printf("Fornecedor: %s \n", p[i]->fornecedor);
                printf("Preco: R$%.2lf \n\n", p[i]->preco);
                printf("Digite a quantidade vendida: \n");
                scanf("%d", &venda);
                if(p[i]-> quantidadeEstoque > venda){
                    p[i]-> quantidadeEstoque -= venda;
                    printf("Valor total da Venda R$%.2lf", p[i]->preco * venda );
                    printf("Venda concluida! \n");
                    printf("Quantidade atualizada em estoque: %d \n", p[i]->quantidadeEstoque);
                    return;
                }else{
                printf("Nao ha Estoque suficiente para esta venda\n");
                printf("Quantidade atualizada em estoque: %d \n", p[i]->quantidadeEstoque);
                }
            }

            return;

        }
}


