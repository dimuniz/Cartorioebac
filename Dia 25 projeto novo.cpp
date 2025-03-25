#include <stdio.h> //biblioteca de comunicao com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bilbioteca de alocaçóes de texto por regiáo
#include <string.h> //biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
  // Inicio criação de variáveis/string
   char arquivo[40];	
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   // Fim da criação de variáveis/string
  
   printf("digite o CPF a ser cadastrado: "); // Coletando informação do usuário
   scanf("%s", cpf); //%s Refere-se a string 

   strcpy(arquivo, cpf); //Responsavel por copiar os valore das string

   FILE *file; //cria o arquivo
   file = fopen(arquivo,"w"); // cria o arquivo e o "W" significa escrever
   fprintf(file,cpf); //salvo o valor da variavel
   fclose(file); // fecha o arquivo
   
   file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: ");
   scanf("%s",1,nome);
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo, "a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: ");
   scanf("%s",cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause");
     
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: "); //Coleta a Informaçõa para a consulta
	scanf("%s",cpf); // refere-se a string a ser Consultada
	
	FILE *file; // Coleta o arquivo já criado 
	file = fopen(cpf,"r"); //coleta o CPF já cadastrado
	
	if(file == NULL) // Quando não encontra o arquivo 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
		while(fgets(conteudo,200, file) != NULL); //Quando ela For ler o arquivo e não encontrar
	{
		printf("\nEssas são as informações do usuário: "); //Coleta a informação cadastrada
		printf("%s", conteudo); //refere-se a string consultada
		printf("\n\n"); // Arquivo  coletado
	}
	
	system("pause");
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usuário nao se encontra no sitema!.\n");
		system("pause");
	}
	
}



int main ()
    {
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); // Responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
    	printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
  	    printf("Escolha a opção desejada do menu\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("opção: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls"); // Respoinsável por limpar a tela
	    
	    switch(opcao) //Inicio da seleção do menu
	   {
	     	case 1:
	   	    registro(); //Chamada das funções para registro	
		    break;
		    
		    case 2:
		    consulta(); // Chamada das funções para consultas
		    break;
		
		    case 3:
		    deletar(); // Chamada das funções para deletar
		    break;
		    
		    
		    case 4:
		    printf("Obrigado por utilizar o sitema!\n");
		    return 0;
		    break;
		
		    default:
		   	printf("Essa opção não está disponivel!\n");
		system("pause");
		break;
	    } // Fim da Selção
    
	}   	
}	    
	
	
