#include <stdio.h>
#include <stdlib.h>
#define T 500
#include "Desafio lista de produtos.h"

int main(){
    int pos = 0;
    int codProc = 0;
    int compra = 0;
    int venda = 0;
    Produto* vet_produtos[T];
    int opc = 0;
    inicializar(vet_produtos, T);
    do{
        printf("Lista de Produtos \n");
        printf("-------------------- \n");
        printf("1. Cadastrar Produto \n");
        printf("2. Encontrar Produto \n");
        printf("3. Atualizar Produto \n");
        printf("4. Listar todos os Produtos \n");
        printf("5. Comprar \n");
        printf("6. Vender \n");
        printf("9. Sair \n");
        printf("Digite sua opcao: \n");
        scanf("%d", &opc);
        switch(opc){
            case 1:
                adicionar(vet_produtos, pos);
                pos++;
                break;
            case 2:
                printf("Digite o codigo a ser encontrado: \n");
                scanf("%d", &codProc);
                encontrar(vet_produtos, codProc, pos);
                break;
            case 3:
                printf("Digite o codigo do produto a ser atualizado: \n");
                scanf("%d", &codProc);
                atualizar(vet_produtos, codProc, pos);
                break;
            case 4:
                listarTodos(vet_produtos, pos);
                break;
            case 5:
                printf("Digite o codigo do produto a ser comprado: \n");
                scanf("%d", &codProc);
                comprar(vet_produtos, codProc, pos);
                break;
            case 6:
                printf("Digite o codigo do produto a ser vendido: \n");
                scanf("%d", &codProc);
                vender(vet_produtos, codProc, pos);
                break;
            case 9:
                printf("Fim do programa \n");
                break;
            default:
                printf("Opção inválida \n");
        }
        system ("pause");
        system ("cls");
    }while(opc!=9);
    return 0;
}

