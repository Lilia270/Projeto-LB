#include <stdio.h>
#define MAX_PEDIDOS 100

struct pedido {
    char nome_cliente[50];
    char opcoes_lanches_comida[50];
    char opcoes_lanches_bebida[50];
    int quantidade_comida;
    int quantidade_bebida;
    int codigo_pedido;
    float valor_pedido;
    float valor_pedido_comida;
    float valor_pedido_bebida;
    char forma_de_pagamento[50];
    
}; 


// cadastrar pedido
void cadastrar_pedido(struct pedido pedidos[], int *num_pedidos) {
    struct pedido novo_pedido;


    // cadastrar os dados do cliente
    printf("==========BEM VINDO A LANCHONETE FELIZ==========\n");
    printf("\n");
    printf("\nDigite o nome do cliente: ");
    scanf("%s", novo_pedido.nome_cliente);
    printf("\n");
    
   
  
    printf("\n=============CARDÁPIO==========\n");
    printf("\n 1-Hamburguer --------- R$ 10,00\n");
    printf("\n 2-Cachorro quente ---------- R$ 12,00\n");
    printf("\n 3-Pastel ------------ R$ 7,00\n");
    printf("\n 4-Macarronada --------- R$ 14,00\n");
    printf("\n 5-Pizza ----------- R$ 20,00\n");
    printf("\n==============================\n");
  
   
    printf("\n Digite qual lanche será escolhida pelo cliente nas opçoes acima:\n");
    scanf("%s", novo_pedido.opcoes_lanches_comida);
    printf("\nAdicionada com sucesso!\n");

    printf("Digite o valor do lanche do cliente:");
    scanf("%f",&novo_pedido.valor_pedido_comida );

    printf("\n=============BEBIDAS==========\n");
    printf("\n 6-Refrigerante--------- R$ 10,00\n");
    printf("\n 7-Jarra de suco(todos os sabores) ---------- R$ 12,00\n");
    printf("\n 8-Agua ------------ R$ 5,00\n");
    printf("\n==============================\n");
    printf("\n Digite qual bebida será escolhida pelo cliente nas opçoes acima:\n");
    scanf("%s", novo_pedido.opcoes_lanches_bebida);
    printf("\nAdicionada com sucesso!\n");

   printf("\nDigite o valor da bebida do cliente:\n");
   scanf("%f",&novo_pedido.valor_pedido_bebida );


  
    printf("\nDigite a quantidade do lanche do cliente:");
    scanf("%d",&novo_pedido.quantidade_comida);
   
    
    printf("\nDigite a quantidade da bebida da bebida:");
    scanf("%d",&novo_pedido.quantidade_bebida);
    
    
    printf("Digite o código do pedido do cliente(0 a 100): ");
    scanf("%d", &novo_pedido.codigo_pedido);

    printf("\nDigite a forma de pagamento que o cliente deseja pagar o pedido:\n");
    printf("\n1-Pix\n");
    printf("\n2-Débito\n");
    printf("\n3-Crédito\n");
    scanf("%s", novo_pedido.forma_de_pagamento);
  

    //adicionar o novo pedido no ponteiro pedidos
    pedidos[*num_pedidos] = novo_pedido;
    
    (*num_pedidos)++;

    // calculo da compra
    pedidos->valor_pedido= pedidos->valor_pedido_comida*pedidos->quantidade_comida + pedidos->valor_pedido_bebida * pedidos->quantidade_bebida;

  novo_pedido.valor_pedido=novo_pedido.valor_pedido_comida*novo_pedido.quantidade_comida + novo_pedido.valor_pedido_bebida * novo_pedido.quantidade_bebida;


    //salvando o pedido em arquivo
    FILE *arquivo =fopen("pedidoslanchonete.txt", "a");
    fprintf(arquivo," Nome do cliente:%s,Lanche:%s,Bebida:%s,Quantidade lanche:%d,Quantidade bebida:%d,Valor:%f, Forma de Pagamento:%s \n ", novo_pedido.nome_cliente, novo_pedido.opcoes_lanches_comida,         novo_pedido.opcoes_lanches_bebida, novo_pedido.quantidade_comida, novo_pedido.quantidade_bebida, novo_pedido.valor_pedido, novo_pedido.forma_de_pagamento);
  fclose(arquivo);


    printf("\n\n");
    printf("\n=============DADOS DO PEDIDO===================\n");
    printf("Nome do cliente: %s \n", novo_pedido.nome_cliente);
    printf("Código do pedido: %d \n",novo_pedido.codigo_pedido);
    printf("Lanche escolhido: %s \n", novo_pedido.opcoes_lanches_comida);
    printf("Bebida escolhida: %s \n", novo_pedido.opcoes_lanches_bebida);
    printf("Forma de Pagamento:%s \n", novo_pedido.forma_de_pagamento);
    printf("Valor total: %f \n", novo_pedido.valor_pedido);
    printf("=================================================");
    
    printf("\nPedido cadastrado com sucesso!\n"); 
    
}



//alteracao de pedido
void alterar_pedido(struct pedido pedidos[], int num_pedidos) {
    int codigo, indice, i;
    
    printf("\nDigite o código do pedido que deseja alterar: ");
    scanf("%d", &codigo);
    
    for (i = 0; i < num_pedidos; i++) {
        if (pedidos[i].codigo_pedido == codigo) {
            indice = i;
            break;
        }
    }
    
    if (i == num_pedidos) {
         printf("\nO codigo esta invalido!\n");
    } else {
        printf("\nO seu pedido foi encontrado!\n");
        printf("Nome do cliente: %s\n", pedidos[indice].nome_cliente);
        printf("Código do pedido: %d\n", pedidos[indice].codigo_pedido);
        printf("\nLanche: %s \n", pedidos[indice].opcoes_lanches_comida);
        printf("\nBebida: %s \n",pedidos[indice].opcoes_lanches_bebida);
        printf("\nQuantidade da comida: %d \n", pedidos[indice].quantidade_comida);
        printf("\nQuantidade da bebida: %d \n", pedidos[indice].quantidade_bebida);
        printf("Forma de Pagamento: %s\n", pedidos[indice].forma_de_pagamento);
        printf("Valor do pedido: %.2f\n", pedidos[indice].valor_pedido);
      
        
        //alteracao//
            printf("\n");
            printf("\nDigite o novo lanche que deseja:\n");
            printf("\n=============CARDÁPIO==========\n");
            printf("\n1-Hamburguer --------- R$ 10,00\n");
            printf("\n2-Cachorro quente ---------- R$ 12,00\n");
            printf("\n3-Pastel ------------ R$ 7,00\n");
            printf("\n4-Macarronada --------- R$ 14,00\n");
            printf("\n5-Pizza ----------- R$ 20,00\n");
            scanf("%s", pedidos[indice].opcoes_lanches_comida);


            printf("\nDigite o novo valor do pedido: ");
            scanf("%f", &pedidos[indice].valor_pedido_comida);


            printf("\nDigite a nova bebida que deseja:\n");
            printf("\n=============BEBIDAS==========\n");
            printf("\n 6-Refrigerante--------- R$ 10,00\n");
            printf("\n 7-Jarra de suco(todos os sabores) ---------- R$ 12,00\n");
            printf("\n 8-Agua ------------ R$ 5,00\n");
            printf("\n==============================\n");
            scanf("%s", pedidos[indice].opcoes_lanches_bebida);
              
            printf("\nDigite o novo valor do pedido: ");
            scanf("%f", &pedidos[indice].valor_pedido_bebida);
  
            printf("\nDigite a nova quantidade de comida que deseja:\n");
            scanf("%d",&pedidos[indice].quantidade_comida);
              
            
            printf("\nDigite a nova quantidade de bebida que deseja:\n");
            scanf("%d", &pedidos[indice].quantidade_bebida);

            printf("\nDigite a nova forma de pagamento\n");
             printf("\n1-Pix\n");
             printf("\n2-Débito\n");
             printf("\n3-Crédito\n");
             scanf("%s",pedidos[indice].forma_de_pagamento);
      
        
        
            printf("\nPedido alterado com sucesso!\n");
        
    }
}

void excluir_pedido(struct pedido pedidos[], int *num_pedidos) {
    int codigo, indice, i;
    
    printf("\nDigite o código do pedido que deseja excluir: ");
    scanf("%d", &codigo);
    
    for (i = 0; i < *num_pedidos; i++) {
        if (pedidos[i].codigo_pedido == codigo) {
            indice = i;
            break;
        }
    }
    
    if (i == *num_pedidos) {
        printf("\nCódigo de pedido inválido!\n");
    } else {
        for (i = indice; i < *num_pedidos-1; i++) {
            pedidos[i] = pedidos[i+1];
        }
        
        (*num_pedidos)--;
        
        printf("\nPedido excluído com sucesso!\n");
    }
}

void exibir_pedidos(struct pedido pedidos[], int num_pedidos) {
    int i;
    
    printf("\nLista de Pedidos:\n");
    
    for (i = 0; i < num_pedidos; i++) {
        printf("%s - Código: %d - Valor: %.2f - Lanche: %s - Bebida: %s - Quantidade Lanche: %d - Quantidade Bebida: %d \n", pedidos[i].nome_cliente, pedidos[i].codigo_pedido, pedidos[i].valor_pedido, pedidos[i].opcoes_lanches_comida, pedidos[i].opcoes_lanches_bebida);
    }
}


void buscar_pedido(struct pedido pedidos[], int num_pedidos){
int codigo;
int i;
printf("Digite o codigo que deseja buscar:");
scanf("%d",&codigo);

for(i = 0; i < num_pedidos; i++){
if(pedidos[i].codigo_pedido == codigo){
printf("Nome do cliente: %s \n", pedidos[i].nome_cliente);
printf("Código do cliente: %d \n",pedidos[i].codigo_pedido);
printf("Opcao de Lanche: %s \n", pedidos[i].opcoes_lanches_comida);
printf("Opcao de Bebida: %s \n", pedidos[i].opcoes_lanches_bebida);
return;
}
}
printf("Pedido não encontrado!");
}

void notafiscalpedido(struct pedido pedidos[],int num_pedidos){
  
  int codigo;
  int i;
  printf("Digite o código do pedido que você deseja emetir a nota fiscal:");
  
  scanf("%d", &codigo);
  for(int i=0; i < num_pedidos; i++){

     if(pedidos[i].codigo_pedido == codigo){
      printf("\n============NOTA FISCAL============\n");
      printf("Nome do cleinte: %s \n",pedidos[i].nome_cliente);
      printf("Lanche escolhido: %s \n", pedidos[i].opcoes_lanches_comida);
      printf("Bebida escolhido: %s \n", pedidos[i].opcoes_lanches_bebida);
      printf("Quantidade do lanche: %d \n", pedidos[i].quantidade_comida);
      printf("Quantidade do bebida: %d \n", pedidos[i].quantidade_bebida);
      printf("Valor do lanche: %f \n", pedidos[i].valor_pedido_comida);
      printf("Valor da bebida: %f \n",pedidos[i].valor_pedido_bebida);
      printf("Valor total do pedido: %f \n", pedidos[i].valor_pedido);
      printf("Forma de Pagamento: %s", pedidos[i].valor_pedido );
      printf("\n============================\n");   
    }
    else{
      printf("Pedido nao encontrado");

    }
      
  }

   
 }

int main() {
    struct pedido pedidos[MAX_PEDIDOS];
    int num_pedidos = 0;
    int opcao;
  float total;
   
   
    do {
        printf("\n----------MENU LANCHONETE FELIZ--------------\n");
        printf("1 - Cadastrar Pedido\n");
        printf("2 - Alterar Pedido\n");
        printf("3 - Excluir Pedido\n");
        printf("4-  Buscar Pedido\n");
        printf("5 - Exibir Pedidos\n");
        printf("6-  Emitir nota fiscal\n");
        printf("0 - Sair\n");
        
        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                cadastrar_pedido(pedidos, &num_pedidos);
                break;
            case 2:
                alterar_pedido(pedidos, num_pedidos);
                break;
            case 3:
                excluir_pedido(pedidos, &num_pedidos);                
                break;
          
            case 4:
                buscar_pedido(pedidos, num_pedidos);
                break;
          
            case 5:
                exibir_pedidos(pedidos, num_pedidos);
                break;
            
            case 6:  
                 notafiscalpedido(pedidos, num_pedidos);
                  break;
            case 0:
                printf("\n Pedido Finalizadp!\n");
                printf("\n Obrigada por visitar a Lanchonete Feliz<3!\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while(opcao != 0);
    
    return 0;
}
