#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

struct pedido
{
    char namePed[100];
    char CPF[100];
    char numPed[100];
    char qtdPed[100];
    char valorped[100];
    int cod;
}logP[100];

struct cadastro
{
    char CPF[100];
    char telefone[100];
    char nome[100];
    char endereco[100];
    char data[100];
    int vazio,cod;
    struct pedido clientePed;

}log[100];

int verifica_pos(void);
int verifica_cod( int cod );
int opt;
void cadastroP(int cod,int pos);
void list();
void cadastroPedido();
void consultaCod (void);
void excluirCliente (void);

int main(void){ 

	setlocale(LC_ALL,"portuguese");

    int i,Opcao,OpcaoCliente,posicao,retorno;
    int codaux;
    do
    {
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Sobre clientes\n");
        printf("3 - Atualizar Cliente\n");
        printf("4 - Deletar Cliente\n");
        printf("5 - Cadastrar Pedido\n");
        printf("6 - Atualizar Pedido\n");
        printf("7 - Deletar Pedido\n");
        printf("8 - Sair\n");
        printf("\nSelecione uma opção: ");
        scanf("%d", &Opcao);
        
        getchar();
        
        if (Opcao == 1)
        {
            printf("Voce selecionou a opcao 1 - Cadastrar Novo Cliente\n");
            posicao=verifica_pos();

                if ( posicao != -1 )
                {

                    printf("\nEntre com um codigo de 1 a 100 para seu cadastro: \n");
                    scanf("%d",&codaux);fflush(stdin);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        cadastroP( codaux, posicao );
                    else{
                        printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
                        getchar();
                        system("cls");
                        main();
                    }

                }
                else
                    printf("\nImpossível realizar mais cadastros!\n");

                break;

        }
        else if (Opcao == 2)
        {
            system("cls");
            do{
            printf("Voce selecionou a opção: Sobre Clientes\n\n");
            printf("1 - Procurar cliente por codigo\n");
            printf("2 - Listar todos os clientes\n");
            printf("3 - Voltar ao menu\n");
            printf("Selecione uma opção: ");
            scanf("%d", &OpcaoCliente);
            getchar();
                 if(OpcaoCliente == 1){
                    consultaCod();
                }
                else if(OpcaoCliente == 2){
                    list();
                }
                else if(OpcaoCliente == 3){
                    printf("Voce optou por voltar ao menu, pressione ENTER para continuar");
                    getchar();
                    system("cls");
                }
                else
                    printf("Opção Inválida\n\n");
    }while(OpcaoCliente =!3 || OpcaoCliente > 3 || OpcaoCliente < 0 || OpcaoCliente == 0);
        }
        else if (Opcao == 3)
        {
            printf("Voce selecionou a opção: Atualizar Cliente\n");
        }
        else if (Opcao == 4)
        {
            printf("Voce selecionou a opção: Deletar Cliente\n");
            excluirCliente();
        }
        else if (Opcao == 5)
        {
            printf("Voce selecionou a opção: Cadastrar Pedido\n");
            cadastroPedido();
        }
        else if (Opcao == 6)
        {
            printf("Voce selecionou a opção: Atualizar Pedido\n");
        }
        else if (Opcao == 7)
        {
            printf("Voce selecionou a opção: Deletar Pedido\n");
        }
        else if (Opcao == 8)
        {
            printf("Voce selecionou a opção: Sair\n");
        }
        else{
            printf("Opção inválida, favor pressione enter para voltar ao menu principal");
            getchar();
            system("cls");
        }
        }    while (Opcao != 8 || Opcao < 8);

}
 
void list(){ 
    int i,j;
    for(i=0;i<100;i++){
        if(log[i].cod!=NULL){
            printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", log[i].cod,log[i].nome,log[i].CPF,log[i].endereco,log[i].telefone);
    }
}
    printf("Pressione enter para volta ao menu principal");
    getchar();
    system("cls");

} 

void cadastroP(int cod, int pos){ 
    int i;
    do{
    pos = verifica_pos();
    log[pos].cod = cod;
        printf("\nDigite seu nome: ");
        gets(log[pos].nome);
        printf("\nDigite seu CPF: ");
        gets(log[pos].CPF);
        printf("\nDigite seu Endereco: ");
        gets(log[pos].endereco);
        printf("\nDigite seu Telefone: ");
        gets(log[pos].telefone);
        log[pos].vazio = 1;
        opt ==1;
        getchar();
    }while(opt==1);
    system("cls");
    main();

} 

int verifica_pos( void )
{
    int cont = 0;

    while ( cont <= 100 )
    {

        if ( log[cont].vazio == 0 )
            return(cont);

        cont++;

    }

    return(-1);

}

int verifica_cod( int cod )
{
    int cont = 0;

    while ( cont <= 100 )
    {
        if ( log[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);

}

void cadastroPedido(){ 
    system("cls");
    int i;
    int Option;
    int OpcaoPedido;
    char nomeCad[100];
    printf("\nDigite seu nome como esta no cadastro: ");
    gets(nomeCad);
    for(i=0;i<100;i++){
            if(strcmp(log[i].nome, nomeCad)==0){
                do{
                printf("\nEscolha o seu pedido: ");
                printf("\n1- Sanduba esperto");
                printf("\n2- Ceasar Salad");
                printf("\n3- Raviolli\n:");
                scanf("%d", &OpcaoPedido);
                if(OpcaoPedido == 1){
                    strcpy(log[i].clientePed.namePed, "Sanduba esperto");
                    printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.",log[i].clientePed.namePed);
                    printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    scanf("%d", &Option);
                    i++;
                }
                else if(OpcaoPedido == 2){
                    strcpy(log[i].clientePed.namePed, "Ceasar Salad");
                    printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.", log[i].clientePed.namePed);
                    printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    scanf("%d", &Option);
                    i++;
                   }
                   else if(OpcaoPedido == 3){
                    strcpy(log[i].clientePed.namePed, "Raviolli");
                    printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.", log[i].clientePed.namePed);
                    printf("\nPressione 1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    scanf("%d", &Option);
                    i++;
                }
    }while(Option == 1);
    system("cls");


}
}
}

void consultaCod (void)
{
    int cont = 0, cod;

    printf("\nEntre com o codigo\n");
    scanf("%d",&cod);
    fflush(stdin);
    system("cls");

    while ( cont <= 100 )
    {

        if (log[cont].cod==cod)
        {
            if (log[cont].vazio==1)
            {

                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", log[cont].cod,log[cont].nome,log[cont].CPF,log[cont].endereco,log[cont].telefone);


                system ("pause");

                system("cls");

                break;

            }
        }

        cont++;

        if ( cont > 100 ){
            printf("\nCodigo nao encontrado, pressione enter para volar ao menu principal\n");
            getchar();
            system("cls");
        }

    }
}

void excluirCliente(void)
{
    int cod, cont = 0;
    char resp;
    printf("\nEntre com o codigo do registro que deseja excluir: \n");
    scanf("%d", &cod );

    while ( cont <= 100 )
    {

        if ( log[cont].cod == cod )
        {

            if (log[cont].vazio == 1 )
            {
                printf("\nCodigo: %d \nNome: %s\nCPF: %s\nEndereco: %s\nTelefone: %s\n\n", log[cont].cod,log[cont].nome,log[cont].CPF,log[cont].endereco,log[cont].telefone);
                getchar();
                printf("\nDeseja realmente exlucir? s/n: ");
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    log[cont].vazio=0;
                    log[cont].cod = NULL;
                    printf("\nExclusão feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusão cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 100 )
            printf("\nCodigo nao encontrado\n");

    }

    system("pause");
    system("cls");

}
