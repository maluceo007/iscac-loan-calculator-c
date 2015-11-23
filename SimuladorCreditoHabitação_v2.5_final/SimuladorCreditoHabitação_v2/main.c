#include <stdio.h>
#include "estruturas.h"

/******************************************/
/*Samuel Anjos nº 13305                  */
/*Luis Camilo nº13987					*/
/***************************************/


int main (){
	
	/* colocar a cor da letra como branco*/
	system("color F");
	/* cabeça das listas  */
	struct listaFuncionarios *funcionariosHead = NULL;
	struct listaClientes *clientesHead = NULL;
	struct listaSimulacoes *simulacoesHead = NULL;
	/* utilizador que realizou o login com acesso*/
	struct listaFuncionarios *utilizador;
	/* carrega lista de funcionarios */
	funcionariosHead = carregaFuncionarios(funcionariosHead);
	/* valida login do utilizador */
	utilizador = loginFuncionarios(funcionariosHead);
	/* carrega lista de clientes*/
	clientesHead = carregaClientes(clientesHead);
	/* se utilizador for administrativo */
	if (utilizador->funcionarios.cargo == ADMINISTRATIVO ){
		menuAdministrativos(utilizador,funcionariosHead,clientesHead,simulacoesHead);
	}//outro utilizador
	else{
		menuFuncionario(utilizador, clientesHead,simulacoesHead);
	}
	
}// fim função