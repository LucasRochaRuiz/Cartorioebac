#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int limpaTela(void)
{
	printf("\033[H\033[J"); // Sequência ANSI para limpar a tela
}

int pausaTela(void) 
{
    printf("Pressione Enter para continuar...");
    getchar(); // Aguarda o usuário pressionar Enter
}

//As funções acima, são pra substituir system("pause") e "cls", pq o antivirus tava enchendo o saco com isso.

int registro(void)
{
	//Criando as Strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Salva o cpf na string e no database
	printf("Digite o CPF a ser cadastrado: \n\n"); 
	scanf("%s", cpf);
	strcpy(arquivo, cpf);
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file, cpf);
	fclose(file);
	
	//Poem ", ". Uma virgula e um espaço para separar os dados.
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	//Salva o nome na string e no database
	printf("\nDigite o NOME a ser cadastrado: \n\n");
	scanf("%s", nome);	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	//Salva o sobrenome na string e no database
	printf("\nDigite o SOBRENOME a ser cadastrado: \n\n");
	scanf("%s", sobrenome);	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	//Salva o cargo na string e no database
	printf("\nDigite o CARGO a ser cadastrado: \n\n");
	scanf("%s", cargo);	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
}

int consultar(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: \n\n");
	scanf("%s", cpf);
	getchar(); 
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nO usuário não se encontra no sistema.\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nOs dados são: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	pausaTela();
	fclose(file);
}

int deletar(void)
{   
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado: \n\n");
    scanf("%s", cpf);
    getchar();
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if (file == NULL)
    {
    	printf("\nO usuário não se encontra no sistema.\n\n");
    	pausaTela();
	}
}

int main(void)
{	
	int opcao = 0;
	//int laco = 1;
	char senha[10];
	setlocale(LC_ALL, "Portuguese");
	
	do
	{
		limpaTela();
		
		printf("### Cartório da Ebac ###\n\n");
		printf("\nDigite a senha:  ");
		scanf("%s", senha);
		
		if (strcmp(senha, "admin") != 0)
		{
			printf("\n\n--- Senha incorreta ---\n\n");
			pausaTela();
		}
	}
	while (strcmp(senha, "admin") != 0);
	
	while (1)
	{	
		limpaTela();	
		
		setlocale(LC_ALL, "Portuguese");
		
		printf("### Cartório da Ebac ###\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n\n");
		printf("\t2 - Consultar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do programa\n");
		printf("\nOpção:  ");
		
		scanf("%d", &opcao);
		limpaTela();
		
		switch (opcao)
		{
			case 1:
				registro();
				break;
			case 2:
				consultar();
				break;
			case 3:
				deletar();
				break;
			case 4:
				printf("Obrigado por usar o programa!\n");
				return 0;
				break;
			default:
				printf("\nOpção invalida. Escolha entre as 3 opções disponiveis no menu.\n\n");
				pausaTela();
				break;
		}
	}
}


