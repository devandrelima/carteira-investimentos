#include <iostream>
#include "Color.h"
using namespace std;

//-----------------------------------------------
// Descri��o_: Fun��o que muda a cor do texto.
// Entrada___: corTexto -> define a cor do texto;
//			   corFundo -> define a cor do fundo.
// Sa�da_____: Sem retorno.
//-----------------------------------------------
void colorir(unsigned corTexto, unsigned corFundo) {
	cout << "\033[0;" << corTexto << ";" << corFundo + 10 << "m"; //C�digo que muda a cor do texto e do fundo conforme os n�meros inseridos.
}

//-----------------------------------------------------------------------------------------------
// Descri��o_: Fun��o que retorna a cor do texto e do fundo para a original do prompt de comando.
// Entrada___: Sem par�metros.
// Sa�da_____: Sem retorno.
//-----------------------------------------------------------------------------------------------
void descolorir() {
	cout << "\033[m";	//C�digo que muda a cor do texto e do fundo para a original do prompt de comando.
}