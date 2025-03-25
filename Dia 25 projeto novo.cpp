#include <stdio.h> //biblioteca de comunicao com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bilbioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
  // Inicio cria��o de vari�veis/string
   char arquivo[40];	
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   // Fim da cria��o de vari�veis/string
  
   printf("digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
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
	
	printf("digite o CPF a ser consultado: "); //Coleta a Informa��a para a consulta
	scanf("%s",cpf); // refere-se a string a ser Consultada
	
	FILE *file; // Coleta o arquivo j� criado 
	file = fopen(cpf,"r"); //coleta o CPF j� cadastrado
	
	if(file == NULL) // Quando n�o encontra o arquivo 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
		while(fgets(conteudo,200, file) != NULL); //Quando ela For ler o arquivo e n�o encontrar
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //Coleta a informa��o cadastrada
		printf("%s", conteudo); //refere-se a string consultada
		printf("\n\n"); // Arquivo  coletado
	}
	
	system("pause");
}

int deletar()
{
	char cpf [40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usu�rio nao se encontra no sitema!.\n");
		system("pause");
	}
	
}



int main ()
    {
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); // Respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
    	printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
  	    printf("Escolha a op��o desejada do menu\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - Sair do sistema\n\n");
	    printf("op��o: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls"); // Respoins�vel por limpar a tela
	    
	    switch(opcao) //Inicio da sele��o do menu
	   {
	     	case 1:
	   	    registro(); //Chamada das fun��es para registro	
		    break;
		    
		    case 2:
		    consulta(); // Chamada das fun��es para consultas
		    break;
		
		    case 3:
		    deletar(); // Chamada das fun��es para deletar
		    break;
		    
		    
		    case 4:
		    printf("Obrigado por utilizar o sitema!\n");
		    return 0;
		    break;
		
		    default:
		   	printf("Essa op��o n�o est� disponivel!\n");
		system("pause");
		break;
	    } // Fim da Sel��o
    
	}   	
}	    
	
	
