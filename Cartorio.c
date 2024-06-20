#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsavel por cuidar das string


int cadastro() //Função responsavel por cadastrar os usuários no sistema
{
	
	setlocale(LC_ALL,"Portuguese"); //seleciona o idioma	
	
	//Inicio da criação de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação das variaveis/strings
	
	printf("Digite o CPF para cadastrar: ");//Coletando informações do usuario
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
		printf("Aquivo não foi localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//Buscando arquivo
	{
		printf("\nEssas são as informações do usuário: CPF: ");
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
	
		printf("Usuário deletado com sucesso!\n\n");
		system("pause");
	
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
	
		printf("Esse usuário não possuí cadastro no sistema. \n");
		system("pause");
		
		
	}
	
}

int main()
{
	
	int opcao=0; //Definindo variáveis
	int x=1; //definindo a variavel x para comando de repetição
	
	for(x=1; x=1;)//Dando comando de repetir
	{
		
		system("cls"); //limpando a tela após uma ação
		
	
		setlocale(LC_ALL,"Portuguese"); //seleciona o idioma
	
	
		printf("\tRegistro de alunos da EBAC\n\n");
		printf("Selecione uma Opção:\n\n"); //Inicio do sistema
		printf("\t1 - Cadastrar Aluno\n");
		printf("\t2 - Consultar Aluno\n");
		printf("\t3 - Excluir Usuarios\n\n\n"); 
		printf("Opção: "); //fim do sistema
	
		scanf("%d", &opcao); //armazem de escolha do usuario
	
		system("cls"); //limpando a tela
		
			switch(opcao) //Opções das escolhas
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
				printf("Opção indisponivel no momento, volte e selecione uma das opções disponiveis no sistema\n");
			system("pause");
			break; //fim das opções de escolhas
		}
     
	 }
	
	
}
