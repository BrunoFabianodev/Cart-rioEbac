#include <stdio.h> // biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> // biblioteca de aloca��p de linguaguem por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar as usu�rios no sistema 
{
	// In�cio da cria��o das vari�veis/strings 
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da cria��o de vari�veis/strings
    
    printf("Digite o CPF a ser cadastrado: "); // Coletando inform��o do usu�rio
    scanf("%s", cpf); // %s refere-se as string/ vai ser armazenado dentro da string
    
    strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo
    fprintf(file, cpf); // Salva o valor da vari�vel 
    fclose(file); // Fecha o arquivo 
    
    file = fopen(arquivo,"a"); // Abrindo o aquivo/ "a" atualizar/incluir informa��o
    fprintf(file, ","); // Est� sendo salvo dentro do arquivo 
    fclose(file); // Fechar o arquivo
    
    printf("Digite o nome a ser cadastrado: "); // Coletando infoma��es do usu�rio
    scanf("%s", nome); // Vai ser armazenado dentro da string
    
    file = fopen(arquivo, "a"); // Abrindo o arquivo
    fprintf(file, nome); // Est� sendo salvo dentro do arquivo
    fclose(file); // Fechar arquivo 
   
    file = fopen(arquivo,"a"); // Abrindo o arquivo 
    fprintf(file, ","); // Est� sendo salvo dentro do arquivo 
    fclose(file); // Fechar arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // Coletando informa��es do usu�rio 
    scanf("%s", sobrenome); // Armazenando dentro da string 
    
    file = fopen(arquivo, "a"); // Abrindo o arquivo 
    fprintf(file, sobrenome); // Salvando informa��o dentro do arquivo 
    fclose(file); // Fechar arquivo 
    
    file = fopen(arquivo,"a"); // Abrindo arquivo 
    fprintf(file, ","); // Salvando informa��o dentro do arquivo
    fclose(file); // Fechar arquivo 
    
    printf("Digite o cargo a ser cadastrado: "); // Coletando informa��es do usu�rio
    scanf("%s", cargo); // Armazenando dentro da string 
    
    file = fopen(arquivo, "a"); // Abrir arquivo
    fprintf(file, cargo); // Salvando informa��o dentro do arquivo
    fclose(file); // Fechar arquivo
    
    system("pause"); // Respons�vel por pausar a tela 
    
    
}


int consulta()
{
	setlocale(LC_ALL, "portuguese"); // Definindo linguaguem 
	
	char cpf[40];
	char conteudo[200];
	
	 printf("Digite o CPF a ser consultado: "); // Coletando informa��es do usu�rio
	 scanf("%s", cpf); // Armazenado dentro da string 
	 
	 FILE *file;
	 file = fopen(cpf, "r");
	 
	 if(file== NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n"); // Passando informa��o para o usu�rio
	}
	
   	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file);
	}
	
	    system("pause"); // Respons�vel por pausar a tela 
	
}



int deletar()
{ 
   char cpf[40];
   
   printf("Digite o CPF do usu�rio a ser deletado: "); // Coletando informa��es do usu�rio
   scanf("%s", cpf); // Armazenando dentro da string
   
   remove(cpf);
   
   
   FILE *file;
   file = fopen(cpf,"r");
   
   
   if(file == NULL)
   {
   	  printf("Usu�rio deletado com suceso!\n"); // Passando informa��o para o usu�rio 
   	  system("pause"); // Respons�vel por pausar a tela 
   }
   

}


int main()
{
	int opcao=0; // Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // Respons�vel por limpar a tela 
		
		setlocale(LC_ALL, "portuguese"); // Definindo linguaguem
		
		
		printf("### Cart�rio da EBAC ###\n\n"); // In�cio do menu 
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registro de nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistma\n\n");
		printf("Op��o:");
		scanf("%d", &opcao); // armazenando a escolha do usu�rio 
		
		system("cls"); // Respons�vel por limpar a tela 
		
		switch(opcao) // In�cio da sele��o do menu
		
		{  
		  case 1:
		  registro(); // Chamada de fun��es
		  break;
		  
		  case 2:
		  consulta(); // Chamada de func�es 
		  break;
		  
		  case 3:
		  deletar(); // Chamada de fun��es 
		  break;
		  
		  case 4:
		  printf("Obrigado por ultilizar o sistema!\n");
		  return 0;
		  break; 
		  
		  
		  default:
		  	printf("Esta op��o n�o est� dispon�vel!\n"); 
	        system("pause");
	        break; // Fim da sele��o
		  	
		
			
		}
		
	
	
	}
 
}
