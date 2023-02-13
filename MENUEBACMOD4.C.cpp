#include <stdio.h> // biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço de memória 
#include <locale.h> // biblioteca de alocaçãp de linguaguem por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar as usuários no sistema 
{
	// Início da criação das variáveis/strings 
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // Final da criação de variáveis/strings
    
    printf("Digite o CPF a ser cadastrado: "); // Coletando informção do usuário
    scanf("%s", cpf); // %s refere-se as string/ vai ser armazenado dentro da string
    
    strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
    
    FILE *file; // Cria o arquivo
    file = fopen(arquivo, "w"); // Cria o arquivo
    fprintf(file, cpf); // Salva o valor da variável 
    fclose(file); // Fecha o arquivo 
    
    file = fopen(arquivo,"a"); // Abrindo o aquivo/ "a" atualizar/incluir informação
    fprintf(file, ","); // Está sendo salvo dentro do arquivo 
    fclose(file); // Fechar o arquivo
    
    printf("Digite o nome a ser cadastrado: "); // Coletando infomações do usuário
    scanf("%s", nome); // Vai ser armazenado dentro da string
    
    file = fopen(arquivo, "a"); // Abrindo o arquivo
    fprintf(file, nome); // Está sendo salvo dentro do arquivo
    fclose(file); // Fechar arquivo 
   
    file = fopen(arquivo,"a"); // Abrindo o arquivo 
    fprintf(file, ","); // Está sendo salvo dentro do arquivo 
    fclose(file); // Fechar arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // Coletando informações do usuário 
    scanf("%s", sobrenome); // Armazenando dentro da string 
    
    file = fopen(arquivo, "a"); // Abrindo o arquivo 
    fprintf(file, sobrenome); // Salvando informação dentro do arquivo 
    fclose(file); // Fechar arquivo 
    
    file = fopen(arquivo,"a"); // Abrindo arquivo 
    fprintf(file, ","); // Salvando informação dentro do arquivo
    fclose(file); // Fechar arquivo 
    
    printf("Digite o cargo a ser cadastrado: "); // Coletando informações do usuário
    scanf("%s", cargo); // Armazenando dentro da string 
    
    file = fopen(arquivo, "a"); // Abrir arquivo
    fprintf(file, cargo); // Salvando informação dentro do arquivo
    fclose(file); // Fechar arquivo
    
    system("pause"); // Responsável por pausar a tela 
    
    
}


int consulta()
{
	setlocale(LC_ALL, "portuguese"); // Definindo linguaguem 
	
	char cpf[40];
	char conteudo[200];
	
	 printf("Digite o CPF a ser consultado: "); // Coletando informações do usuário
	 scanf("%s", cpf); // Armazenado dentro da string 
	 
	 FILE *file;
	 file = fopen(cpf, "r");
	 
	 if(file== NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado.\n"); // Passando informação para o usuário
	}
	
   	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		fclose(file);
	}
	
	    system("pause"); // Responsável por pausar a tela 
	
}



int deletar()
{ 
   char cpf[40];
   
   printf("Digite o CPF do usuário a ser deletado: "); // Coletando informações do usuário
   scanf("%s", cpf); // Armazenando dentro da string
   
   remove(cpf);
   
   
   FILE *file;
   file = fopen(cpf,"r");
   
   
   if(file == NULL)
   {
   	  printf("Usuário deletado com suceso!\n"); // Passando informação para o usuário 
   	  system("pause"); // Responsável por pausar a tela 
   }
   

}


int main()
{
	int opcao=0; // Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // Responsável por limpar a tela 
		
		setlocale(LC_ALL, "portuguese"); // Definindo linguaguem
		
		
		printf("### Cartório da EBAC ###\n\n"); // Início do menu 
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registro de nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistma\n\n");
		printf("Opção:");
		scanf("%d", &opcao); // armazenando a escolha do usuário 
		
		system("cls"); // Responsável por limpar a tela 
		
		switch(opcao) // Início da seleção do menu
		
		{  
		  case 1:
		  registro(); // Chamada de funções
		  break;
		  
		  case 2:
		  consulta(); // Chamada de funcões 
		  break;
		  
		  case 3:
		  deletar(); // Chamada de funções 
		  break;
		  
		  case 4:
		  printf("Obrigado por ultilizar o sistema!\n");
		  return 0;
		  break; 
		  
		  
		  default:
		  	printf("Esta opção não está disponível!\n"); 
	        system("pause");
	        break; // Fim da seleção
		  	
		
			
		}
		
	
	
	}
 
}
