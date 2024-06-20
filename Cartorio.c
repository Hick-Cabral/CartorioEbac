#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca responsavel por cuidar das string


int cadastro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	
	setlocale(LC_ALL,"Portuguese"); //seleciona o idioma	
	
	//Inicio da cria��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o das variaveis/strings
	
	printf("Digite o CPF para cadastrar: ");//Coletando informa��es do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Responsavel por criar um arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo
	fprintf(file,cpf); //Salva o valor da variavel
	fclose(file); //Fecha variavel
	
	file = fopen(arquivo, "a");//abre e atualiza o arquivo
	fprintf(file, ", Nome: ");
	fclose(file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//abre e atualiza o arquivo
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite seu Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", Cargo: ");
	fclose(file);
	
	printf("Digite o cargo a se cadastrar: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //seleciona o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF ao ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Aquivo n�o foi localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Buscando arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio: CPF: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	
	
}

int excluir()
{

	char cpf[40];
	
	printf("Digite o CPF para excluir: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
		printf("Usu�rio deletado com sucesso!\n\n");
		system("pause");
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	
		printf("Esse usu�rio n�o possu� cadastro no sistema. \n");
		system("pause");
		
		
	}
	
}

int main()
{
	
	int opcao=0; //Definindo vari�veis
	int x=1; //definindo a variavel x para comando de repeti��o
	
	for(x=1; x=1;)//Dando comando de repetir
	{
		
		system("cls"); //limpando a tela ap�s uma a��o
		
	
		setlocale(LC_ALL,"Portuguese"); //seleciona o idioma
	
	
		printf("\tRegistro de alunos da EBAC\n\n");
		printf("Selecione uma Op��o:\n\n"); //Inicio do sistema
		printf("\t1 - Cadastrar Aluno\n");
		printf("\t2 - Consultar Aluno\n");
		printf("\t3 - Excluir Usuarios\n\n\n"); 
		printf("Op��o: "); //fim do sistema
	
		scanf("%d", &opcao); //armazem de escolha do usuario
	
		system("cls"); //limpando a tela
		
			switch(opcao) //Op��es das escolhas
		{
			case 1:
			cadastro(); //inicio das escolhas
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				excluir();
			break;
			
			default:
				printf("Op��o indisponivel no momento, volte e selecione uma das op��es disponiveis no sistema\n");
			system("pause");
			break; //fim das op��es de escolhas
		}
     
	 }
	
	
}
