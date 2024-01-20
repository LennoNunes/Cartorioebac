#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings 

int registro() //Fun��o responsavel por cadastrar no sistema
	{
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		//Inicio da cria��o de variaveis:
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//Final da cria��o de variaveis:
	
		printf("### Registrar usu�rios: ###\n\n");
	
		FILE *file; //Cria o arquivo
		file = fopen(arquivo, "w"); //"W" comando para criar coisa nova
		fclose(file); //Fechamento do arquivo 
	
		printf("Digite o CPF a ser cadastrado: "); //responsavel por mostrar na tela
		scanf("%s", cpf); //"%s" comando para digitar uma string
		
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
		file = fopen(arquivo, "a"); //Abertura do arquivo
		fprintf(file, "CPF do usu�rio: "); //Salva no aquivo o texto entre aspas
		fprintf(file,cpf); //Salva o valor da variavel
		fclose(file); //Fechar o arquivo
	
		file = fopen(arquivo, "a"); //"A" comando para atualizar um arquivo
		fprintf(file,"\nNome do usu�rio: "); //Salva no aquivo o texto entre aspas
		fclose(file);
	
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
	
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,"\nSobrenome do usu�rio: "); //Salva no aquivo o texto entre aspas
		fclose(file);
	
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,"\nCargo do usu�rio: "); //Salva no aquivo o texto entre aspas
		fclose(file);
	
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
	
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		printf("\n");
		
		system("pause");
	}

int consulta() //Fun��o a ser chamada
	{
		setlocale(LC_ALL, "Portuguese"); //Desfinindo linguagem
		
		//inicio da cria��o das variaveis
		char cpf[40];
		char informacao[200];
		//final da cria��o das variaveis
		
		printf("### Consultar usu�rios: ###\n\n");
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
			{
				printf("\nN�o foi possivel encontrar, usu�rio n�o localizado!.");
			}
		else
			{
				printf("\nInforma��es do CPF consultado: \n\n");
			}	
			
				
		while(fgets(informacao, 200, file) != NULL)		
			{
				printf("%s", informacao);
			}
			
		printf("\n\n");	
		system("pause");
		
		fclose(file);	
	}

int deletar() //Fun��o a ser chamada
	{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//Inicio das variaveis
		char cpf[40];
		//Final das variaveis
		
		printf("### Deletar usu�rios: ###\n\n");
		
		printf("Digite o CPF do usu�rio a ser deletado: ");
		scanf("%s",cpf);
		
		printf("\n");
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
			{
				printf("Usu�rio n�o encontrado no sistema!.\n\n");
				system("pause");
			}
		else
			{
				fclose(file);
				remove(cpf);
				printf("Usu�rio foi deletado com sucesso!.\n\n");
				system("pause");
			}
	}

int main()// Fun��o Menu
	{	
		//Inicio da variaveis
		int opcao=0; 
		int laco=1;
		//Fim da variaveis
		
		for(laco=1;laco=1;) //Operador de repeti��o
			{
				system("cls"); //Limpar a tela
			
				setlocale(LC_ALL, "Portuguese"); //Desfinindo a linguagem
			
				//Inicio do menu
				printf("### Cartorio da EBAC ###\n\n"); 
				printf("Escolha a op��o desejada do meno:\n\n");
				printf("\t1 - Registrar usu�rios\n");
				printf("\t2 - Consultar usu�rios\n");
				printf("\t3 - Deletar usu�rios\n"); 
				printf("\t4 - Sair do sistema\n\n");
				printf("Op��o: "); 
				//Final do menu
			
				//"\n" = Pular uma linha 
				//"\t" = Espa�amento de primeira linha
				
				//"%d" = Escolha
			
				scanf("%d", &opcao); //Armazenando a escolha do usuario
			
				system("cls"); //Limpar a tela
				
				
				switch(opcao) //Inicio da sele��o
					{
						case 1: //Chamada do registro
							registro();
						break;
						
						case 2:
							consulta();
						break;
						
						case 3:	
							deletar();
						break;
						
						case 4:
							printf("Obrigado por usar o sistema!\n");
							return 0;
						break;
						
						default:
							printf("Essa op��o n�o est� disponivel!\n\n");
							system("pause");
						break;	
					} //Fim da sele��o
				
			}
	}
	

