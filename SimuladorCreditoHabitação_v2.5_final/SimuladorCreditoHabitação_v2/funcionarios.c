
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"

/******************************************/
/*Samuel Anjos n� 13305                  */
/*Luis Camilo n�13987					*/
/******************************************/

/* 
*	adiciona o novo funcionario 
*/
struct listaFuncionarios * adicionarFuncionario ( struct listaFuncionarios * head){

	struct listaFuncionarios *current;
	current = (struct listaFuncionarios*) malloc (sizeof(struct listaFuncionarios));
	
	/* verificar se � o primeiro node, se for criar o funcionario */
	if (head == NULL)
		head = menuCriaNovoFuncionario();

	else{
		/* ir at� ao ultimo node */
		current = head;
		while (current->next != NULL)
			current = current->next;

		/* criar novo node */
		
		current->next = menuCriaNovoFuncionario();
	}

	return head;

}// fim fun��o

/*
*	imprime a lista de funcionarios
*/
struct listaFuncionarios * imprimeFuncionarios(struct listaFuncionarios * head){

	struct listaFuncionarios * current;

	/* verificar se a lista tem nodes */
	if (head == NULL){
		printf("%61s", " "); printf("N�o existem funcionarios!\n");
	}

	current = head;

	while (current != NULL){
		/* imprime node */
		printFuncionario(current);
		/* proximo node */
		current = current->next;
	}
	printf("\n");
	alteraCorTexto(8);
	printf("%0s\n", "-------------------------------------------------------------\n");
	alteraCorTexto(15);
	system("pause");

	return head;

}// fim fun��o

/*
*	imprime no ecra um node
*/
void printFuncionario(struct listaFuncionarios * current){

	printf("\n");
	alteraCorTexto(8);
	printf("%0s\n", "-------------------------------------------------------------\n");
	alteraCorTexto(15);
	printf("Nome proprio:%s", current->funcionarios.dadosPessoais.nomeProprio);
	printf("\nApelido:%s", current->funcionarios.dadosPessoais.apelido);
	printf("\nNif:%d", current->funcionarios.dadosPessoais.nif);
	printf("\nTelefone:%d", current->funcionarios.dadosPessoais.telefone);
	printf("\nCargo:%d", current->funcionarios.cargo);
	printf("\nUsername para aceder o sistema:%s", current->funcionarios.username);
	printf("\nPassword para aceder o sistema:%s\n", current->funcionarios.password);

}// fim fun��o
/*
*	editar o funcionarios atravez do seu nif
*/
void editarFuncionario(struct listaFuncionarios * head){
	
	/* campo pelo qual pretendemos pesquisa a lista ligada */
	int nif;
	/* struct que pretendemos para  editar */
	struct listaFuncionarios * funcionarioPretendido;
	/* perguntar ao utilizador qual o nif do funcionario */
	printf("%61s", " "); printf("Introduza o nif do funcionario:");
	scanf ("%d", &nif);
	fflush(stdin);
	
	/* funcionario pretendido para editar */
	funcionarioPretendido = procuraNodeFuncionario (head, &nif);
	/* funcionario existe*/
	if (funcionarioPretendido!=NULL)
		/* editar funcionario */
		menuEditarFuncionario(funcionarioPretendido);

	else{
		printf("%61s", " "); 
		alteraCorTexto(12); printf("Esse funcionario nao exite.\n"); alteraCorTexto(15);
	}
	system("pause");

}// fim fun��o

/* 
*	procura um node na lista ligada por nif 
*/
struct listaFuncionarios * procuraNodeFuncionario( struct listaFuncionarios * head , int *nif ){

	struct listaFuncionarios * current;

	current = head;
	/* traversa a lista */
	while (current != NULL){
		if (current->funcionarios.dadosPessoais.nif == *nif)
			return current;
		/* avan�a para o proximo node */
		current = current->next;
	}

	return NULL;

}// fim fun��o

/*
*	fun��o para procurar o utilizador por username e password na lista ligada
*/
struct listaFuncionarios * procuraFuncionarioLogin(struct listaFuncionarios * head, char * username, char * password){

	struct listaFuncionarios * utilizador;

	utilizador = head;
	/* traversa a lista */
	while (utilizador != NULL){
		if ((strcmp(utilizador->funcionarios.username, username) == 0) && (strcmp(utilizador->funcionarios.password, password) == 0))
			return utilizador;
		/* avan�a para o proximo node */
		utilizador = utilizador->next;
	}
	
	return utilizador = NULL;
		
}// fim fun��o


/*
*	pede ao utilizador o nif do funcionario que deseja apagar do sistema
*/
struct listaFuncionarios * apagaFuncionario(struct listaFuncionarios * head){
	/* campo pelo qual pretendemos pesquisa a lista ligada */
	int nif;
	/* struct que pretendemos para  editar */
	struct listaFuncionarios * funcionarioPretendido;
	/* perguntar ao utilizador qual o nif do funcionario */
	printf("%61s", " "); printf("Introduza o nif do funcionario:");
	scanf ("%d", &nif);
	fflush(stdin);

	/* funcionario pretendido para apagar */
	funcionarioPretendido = procuraNodeFuncionario (head, &nif);
	/* funcionario existe*/
	if (funcionarioPretendido != NULL){
		/*apagar funcionario da lista */
		head = removerFuncionario(head, funcionarioPretendido);

		printf("%61s", " "); 
		alteraCorTexto(10); printf("O funcionario foi apagado com sucesso!\n"); alteraCorTexto(15);

	}/* funcionario n�o exite*/
	else{
		printf("%61s", " ");
		alteraCorTexto(12); printf("Esse funcionario nao exist.\n"); alteraCorTexto(15);
	}
	system("pause");

	return head;
}// fim fun��o

/* 
*	remover a cabe�a da lista ligada 
*/
struct listaFuncionarios* deleteHeadFuncionario(struct listaFuncionarios*head){
	struct listaFuncionarios * primeiro = head;	

	//struct funcionario * primeiro = head;
	head = head->next;
	
	/* confirmar que exite mais que um node */
	if (primeiro == head)
		head = NULL;

	primeiro = NULL;
	free (primeiro);

	return head;
}//fim fun��o
/*
*	remover o ultimo node da lista ligada
*/
struct listaFuncionarios * deleteUltimoFuncionario (struct listaFuncionarios * head){
	struct listaFuncionarios * current = head;
	struct listaFuncionarios * ultimo = NULL;

	/* transversar a lista at� ao penultimo */
	while ( current->next != NULL){
		ultimo = current ;
		current = current->next;
	}

	if (ultimo != NULL)
		ultimo->next = NULL;
		
	free(current);

	return head;

}// fim fun��o

/* 
*	remove qualque node 
*/
struct listaFuncionarios * removerFuncionario(struct listaFuncionarios *head, struct listaFuncionarios *current){
	struct listaFuncionarios * temp = head;

	if (current == NULL)
		return NULL;

	/*se o node � o primeiro */
	if (current == head){
		//return head;
		return deleteHeadFuncionario(head);
	}

	/*se o node � o ultimo */
	if (current->next == NULL)
		return deleteUltimoFuncionario (head);

	/*se o node � no meio da lista ligada */	
	while (temp != NULL){
		if (temp->next == current)
			break;
		temp = temp->next;
	}
		
	struct listaFuncionarios * temp2 = temp->next;
	temp->next = temp2->next;
	temp2->next = NULL;
	free (temp2);	
	
	return head;

}//fim fun��o

/* 
*	grava funcionarios no ficheiro binario 
*/
void escreveFuncionarios ( struct listaFuncionarios * head){
	FILE *fp;
	struct listaFuncionarios *current; 
	/* chama a fun��o para abri o ficheiro */
	fp = abreFicheiroBinario ("funcionarios.dat", "wb");
	
	current = head;
	/* escreve no ficheiro um node de cada vez da lista */
	while (current != NULL){
		fwrite (current, sizeof (struct listaFuncionarios),1, fp);
		current = current->next;
	}

	fclose (fp);

}// fim fun��o

/* 
*	fun��o para liebertar a lista de memoria 
*/
void libertaLista(struct listaFuncionarios *head){
	struct listaFuncionarios *temp, *current = head;

	while (current != NULL){
		temp = current->next;
		free(current);  // liberta o node
		current = temp;
	}
}// fim fun��o

/* 
*	carregamento de funcionarios de ficheiro binarios 
*/
struct listaFuncionarios * carregaFuncionarios (struct listaFuncionarios * head){

	FILE *fp;
	struct listaFuncionarios  *temp;
	struct listaFuncionarios *current ; 
	
	fp = abreFicheiroBinario ( "funcionarios.dat" , "rb");
	
	/* percorre o ficheio at� ao fim */
	while ( !feof(fp)){
		//current = (struct funcionario *) malloc (sizeof (struct funcionario));
		if ((current = (struct listaFuncionarios *) malloc (sizeof (struct listaFuncionarios)))==NULL){
			printf("Erro: reservad de memoria carrega funcionarios.");
			exit (1);
		}
		/* devolve 0 qunado n�o tem sucesso */
		if (fread (current, sizeof(struct listaFuncionarios),1 , fp)>0){
			
			current->next = NULL;
			temp = head;
			
			/* preencher o primeiro node */
			if (head == NULL){
				head = current;
			}
			/* preencher o resto dos nodes */
			else{
				
				while (temp->next != NULL)					
					temp = temp->next;
				
				temp->next = current;	
			}	
				
		}// fim if
	} // fim while

	fclose (fp);

	return head;
}// fim fun��o

/*
* fun��o para realizar o login in e saber quem � o utilizador
*/

struct listaFuncionarios * loginFuncionarios(struct  listaFuncionarios * head){
	char username[20];
	char password[10];

	struct listaFuncionarios * utilizador =NULL;

	while (utilizador == NULL){

		menuLogin(username, password);
		utilizador = procuraFuncionarioLogin(head, username, password);

	}

	return utilizador;
}// fim fun��o




