#include <stdio.h>
#include <string.h> 

int registro ()//função responsavel por cadastrar os usuarios no sistema
{
    //inicio criação de variaves/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
     //final da criação de variaves/string
    
    printf ("Digite o CPF a ser cadastrado: ");//coletando informação do usuario
    scanf("%s", cpf);//%s refere se a string
    
    strcpy(arquivo, cpf);//responsavel por copiar os valores da string 
    
    FILE *file;//cria arquivo
    file = fopen(arquivo, "w");//cria arquivo "w" significa escrever
    fprintf(file,cpf);//salvo o valor da variavel 
    fclose(file);//fecha o arquivo
    
    file = fopen (arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen (arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrdo: ");
    scanf("%s", sobrenome); 
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
     file = fopen (arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadasrado: ");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}

int consulta ()
{
     char cpf[40];
     char conteudo[200];
     
     printf("Digite o CPF a ser consultado: ");
     scanf("%s", cpf);
     
     FILE *file;
     file = fopen(cpf, "r");
     
     if(file == NULL)
     {
         printf("Não foi possível abrir o arquivo, não foi localizado!\n");
         
     }
     
     while(fgets(conteudo, 200, file) != NULL)
     {
         printf("\nEssas são as informações do usuário: ");
         printf("%s", conteudo);
         printf("\n\n");
     }
     
     system("pause");
}

int deletar ()
{
    char cpf[40];
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
        printf("O usuário não se encontra no sistema");
        system ("pause");
    }
    
}



int main()
   {
    int opcao=0;
    int laco=1;
    
    for(laco=1;laco=1;)
    {
        
      printf("### Cartóio da EBAC###\n\n");//inicio do menu
      printf("Escolha a opção desejada no menu:\n\n");
      printf("\t1 - Registrar nomes\n");
      printf("\t2 - Consultar nomes\n");
      printf("\t3 - Deletar nomes\n\n");
      printf("opção: ");//fim do menu
    
    scanf("%d" , &opcao);//armazenando a escolha do usuario
    
     system("cls");//responsavel por limpar a tela
    
    switch(opcao)//inicio da seleção
    {
        case 1:
        registro();//chamada de funções
        break;
        
         case 2:
       consulta();
        break;
        
         case 3:
       deletar();
        break;
        
        default: 
        printf("Essa opção não está disponível!\n");
        system("pause");
        break;
    }//fim da seleção
    
    }
    return 0;
}
