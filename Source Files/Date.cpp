#include<iostream>
#include "Date.h"

using namespace std;

//--------------------------------------------------------------------------------------------------
// Descri��o_: Fun��o que configura o cin para ler uma vari�vel do tipo Data na formata��o dd/mm/aa.
// Entrada___: in -> representa o cin;
//			   dat -> Representa a vari�vel do tipo Data a ser lida.
// Sa�da_____: istream&.
//--------------------------------------------------------------------------------------------------
istream& operator>>(istream& in, Data& dat) {
	in >> dat.dia;	
	in.ignore();	// Ignora a '/' digitada entre o n�mero do dia e do m�s
	in >> dat.mes;
	in.ignore();	// Ignora a '/' digitada entre o n�mero do m�s e do ano
	in >> dat.ano;
	return in;
}

//----------------------------------------------------------------------------------------------
// Descri��o_: Fun��o que configura o cout para exibir uma vari�vel Data na formata��o dd/mm/aa.
// Entrada___: out -> representa o cin;
//			   dat -> Representa a vari�vel do tipo Data a ser exibida.
// Sa�da_____: ostream&.
//----------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, Data& dat) {
	out << dat.dia << "/" << dat.mes << "/" << dat.ano;
	return out;
}
