#include <iostream>
#include "Color.h"
using namespace std;

//-----------------------------------------------
// Descrição_: Função que muda a cor do texto.
// Entrada___: corTexto -> define a cor do texto;
//			   corFundo -> define a cor do fundo.
// Saída_____: Sem retorno.
//-----------------------------------------------
void colorir(unsigned corTexto, unsigned corFundo) {
	cout << "\033[0;" << corTexto << ";" << corFundo + 10 << "m"; //Código que muda a cor do texto e do fundo conforme os números inseridos.
}

//-----------------------------------------------------------------------------------------------
// Descrição_: Função que retorna a cor do texto e do fundo para a original do prompt de comando.
// Entrada___: Sem parâmetros.
// Saída_____: Sem retorno.
//-----------------------------------------------------------------------------------------------
void descolorir() {
	cout << "\033[m";	//Código que muda a cor do texto e do fundo para a original do prompt de comando.
}