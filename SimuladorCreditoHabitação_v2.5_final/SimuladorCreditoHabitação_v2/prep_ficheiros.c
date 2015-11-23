#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "estruturas.h"

/******************************************/
/*Samuel Anjos nº 13305                  */
/*Luis Camilo nº13987					*/
/***************************************/

FILE * abreFicheiroBinario (char * nomeFicheiro , char *permissao){
	FILE *fp;	
	char backup[60]="./backup/backup_";
	char data [25];
	
	/* confirmar se ficheiro esta fechado */
	if (fp = fopen (nomeFicheiro , "r"))
		fclose(fp);
	
	/* faz backup do ficheiro antes de gravar */
	if (strcmp(permissao, "wb") == 0){

		/* função para adquirir a data do sistema */
		buscaData(data);
	
		/* concatonação de strings */
		strcat (backup, data );	

		/* back up do ficherio */
		rename (nomeFicheiro , strcat (backup, nomeFicheiro));
	}

	if ((fp = fopen(nomeFicheiro, permissao))== NULL){
		printf ("Erro na abertura do ficheiro %s", nomeFicheiro );
		exit (1);
	}
	
	return fp;

}// fim função

/*
*	função que coloca a data do sistema numa string
*/
void buscaData(char * data){
	time_t  rawtime;
	struct tm * infotime;
	//char  * data = (char *) malloc (25*sizeof(char));

	/* adquiri data e hora do sistema para colocar no ficheiro backup */
	time (&rawtime);
	infotime = localtime (&rawtime);
	strftime (data,25,"%Y-%m-%d_%H%M%S_",infotime);
	

}// fim função

/*
*	função que valida que apenas sao introduzidos caracteres numericos e com o tamanho de 9 no nif
*/
int validaNumInteiros(int x){
	int tamanho=0;

	/* para apanhara erros com numeros de nove digitos negativos */
	if (x < 0)
		return 0;

	while (x != 0){

		x /= 10;
		tamanho ++;
	}
	
	return tamanho;

}// fim função

/*
*	função que valida que apenas sao introduzidos caracteres alfanumericos no campo nome e outros
*/
int validaLetras(char *palavra){

	int flag = 1;
	while (*palavra)
	{
		if (*palavra != ' ')
			if ((*palavra < 'A') || (*palavra > 'Z'))
				if ((*palavra < 'a') || (*palavra > 'z'))
					flag = 0;


		*palavra++;
	}
	return flag;
}// fim função

/*
*	função que valida que a data foi introduzida de forma valida
*/
int validaData(int dia, int mes, int ano)
{
	if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os numeros sao validos
	{
		if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
		{
			return 1;
		}
		if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
		{
			return 1;
		}
		if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
		{
			return 1;
		}
		if ((dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}// fim função
