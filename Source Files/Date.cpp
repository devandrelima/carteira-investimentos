#include<iostream>
#include "Date.h"

using namespace std;

//--------------------------------------------------------------------------------------------------
// Descrição_: Função que configura o cin para ler uma variável do tipo Data na formatação dd/mm/aa.
// Entrada___: in -> representa o cin;
//			   dat -> Representa a variável do tipo Data a ser lida.
// Saída_____: istream&.
//--------------------------------------------------------------------------------------------------
istream& operator>>(istream& in, Data& dat) {
	in >> dat.dia;	
	in.ignore();	// Ignora a '/' digitada entre o número do dia e do mês
	in >> dat.mes;
	in.ignore();	// Ignora a '/' digitada entre o número do mês e do ano
	in >> dat.ano;
	return in;
}

//----------------------------------------------------------------------------------------------
// Descrição_: Função que configura o cout para exibir uma variável Data na formatação dd/mm/aa.
// Entrada___: out -> representa o cin;
//			   dat -> Representa a variável do tipo Data a ser exibida.
// Saída_____: ostream&.
//----------------------------------------------------------------------------------------------
ostream& operator<<(ostream& out, Data& dat) {
	out << dat.dia << "/" << dat.mes << "/" << dat.ano;
	return out;
}
