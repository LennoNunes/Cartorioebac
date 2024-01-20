#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings 

int registro() //Função responsavel por cadastrar no sistema
	{
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		//Inicio da criação de variaveis:
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//Final da criação de variaveis:
	
		printf("### Registrar usuários: ###\n\n");
	
		FILE *file; //Cria o arquivo
		file = fopen(arquivo, "w"); //"W" comando para criar coisa nova
		fclose(file); //Fechamento do arquivo 
	
		printf("Digite o CPF a ser cadastrado: "); //responsavel por mostrar na tela
		scanf("%s", cpf); //"%s" comando para digitar uma string
		
		strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
		file = fopen(arquivo, "a"); //Abertura do arquivo
		fprintf(file, "CPF do usuário: "); //Salva no aquivo o texto entre aspas
		fprintf(file,cpf); //Salva o valor da variavel
		fclose(file); //Fechar o arquivo
	
		file = fopen(arquivo, "a"); //"A" comando para atualizar um arquivo
		fprintf(file,"\nNome do usuário: "); //Salva no aquivo o texto entre aspas
		fclose(file);
	
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
	
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,"\nSobrenome do usuário: "); //Salva no aquivo o texto entre aspas
		fclose(file);
	
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s",sobrenome);
	
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
	
		file = fopen(arquivo, "a");
		fprintf(file,"\nCargo do usuário: "); //Salva no aquivo o texto entre aspas
		fclose(file);
	
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s",cargo);
	
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		printf("\n");
		
		system("pause");
	}

int consulta() //Função a ser chamada
	{
		setlocale(LC_ALL, "Portuguese"); //Desfinindo linguagem
		
		//inicio da criação das variaveis
		char cpf[40];
		char informacao[200];
		//final da criação das variaveis
		
		printf("### Consultar usuários: ###\n\n");
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
			{
				printf("\nNão foi possivel encontrar, usuário não localizado!.");
			}
		else
			{
				printf("\nInformações do CPF consultado: \n\n");
			}	
			
				
		while(fgets(informacao, 200, file) != NULL)		
			{
				printf("%s", informacao);
			}
			
		printf("\n\n");	
		system("pause");
		
		fclose(file);	
	}

int deletar() //Função a ser chamada
	{
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		//Inicio das variaveis
		char cpf[40];
		//Final das variaveis
		
		printf("### Deletar usuários: ###\n\n");
		
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s",cpf);
		
		printf("\n");
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
			{
				printf("Usuário não encontrado no sistema!.\n\n");
				system("pause");
			}
		else
			{
				fclose(file);
				remove(cpf);
				printf("Usuário foi deletado com sucesso!.\n\n");
				system("pause");
			}
	}

int main()// Função Menu
	{	
		//Inicio da variaveis
		int opcao=0; 
		int laco=1;
		//Fim da variaveis
		
		for(laco=1;laco=1;) //Operador de repetição
			{
				system("cls"); //Limpar a tela
			
				setlocale(LC_ALL, "Portuguese"); //Desfinindo a linguagem
			
				//Inicio do menu
				printf("### Cartorio da EBAC ###\n\n"); 
				printf("Escolha a opção desejada do meno:\n\n");
				printf("\t1 - Registrar usuários\n");
				printf("\t2 - Consultar usuários\n");
				printf("\t3 - Deletar usuários\n"); 
				printf("\t4 - Sair do sistema\n\n");
				printf("Opção: "); 
				//Final do menu
			
				//"\n" = Pular uma linha 
				//"\t" = Espaçamento de primeira linha
				
				//"%d" = Escolha
			
				scanf("%d", &opcao); //Armazenando a escolha do usuario
			
				system("cls"); //Limpar a tela
				
				
				switch(opcao) //Inicio da seleção
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
							printf("Essa opção não está disponivel!\n\n");
							system("pause");
						break;	
					} //Fim da seleção
				
			}
	}
	

