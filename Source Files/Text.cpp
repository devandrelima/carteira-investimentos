#include <iostream>
#include "Color.h"

using namespace std;

//---------------------------------------------------------------------------------------------------------
// Descri��o_: Fun��o que alinha o texto centralizando-o em um espa�o e exibe o texto e o espa�o coloridos. 
// Entrada___: texto[] -> Texto a ser alinhado/centralizado e colorido;
//			   corTexto -> Cor que o texto ser� exibido;
// 			   corFundo -> Cor que o espa�o ao redor do texto e o fundo do texto ir� receber; 
// 			   espacos -> Espa�o a ser adicionado � direita e � esquerda do texto.
// Sa�da_____: Sem retorno.
//---------------------------------------------------------------------------------------------------------
void exibirVetCharAlinhadoColorido(const char texto[], unsigned corTexto, unsigned corFundo, int espacos) {
	colorir(corTexto, corFundo);			// Colore o texto e o espa�o com as cores definidas pelo usu�rio.
	cout.width(espacos);					// Insere espa�os antes do texto.
	cout << texto;
	cout.width(espacos-strlen(texto)+3);	// Insere espa�os ap�s o texto para centralizar.
	descolorir();							// Retorna a cor do texto e do fundo para a original do prompt de comando.
}

//--------------------------------------------------------------
// Descri��o_: Fun��o que exibe o texto e o fundo coloridos.
// Entrada___: texto[] -> Texto a ser colorido;
//			   corTexto -> Cor que o texto ser� exibido;
// 			   corFundo -> Cor que o fundo do texto ir� receber; 
// Sa�da_____: Sem retorno.
//--------------------------------------------------------------
void exibirVetCharColorido(const char texto[], unsigned corTexto, unsigned corFundo) {
	colorir(corTexto, corFundo);
	cout << texto;
	descolorir();
}

//-----------------------------------------------------------------------------
// Descri��o_: Fun��o que alinha um n�mero double � direita e o exibe colorido. 
// Entrada___: numero -> N�mero que ser� alinhado e exibido colorido;
//			   corNumero -> Cor que o n�mero ser� exibido;
// 			   corFundo -> Cor que fundo do n�mero ir� receber; 
// 			   espacos -> Espa�o que o n�mero pode ocupar.
// Sa�da_____: Sem retorno.
//-----------------------------------------------------------------------------
void exibirFloatAlinhadoColorido(float numero, unsigned corNumero, unsigned corFundo, int espacos) {
	colorir(corNumero, corFundo); 
	cout << right;			// Alinha o n�mero � direita.
	cout.width(espacos);	// Determina a quantidade de espa�o que o n�mero pode ocupar.
	cout << numero;
	descolorir();
}

//-------------------------------------------------------------------------------------------------------------------
// Descri��o_: Fun��o que alinha um n�mero inteiro centralizando-o em um espa�o e exibe o n�mero e o espa�o coloridos  
// Entrada___: numero -> N�mero que ser� alinhado e colorido;
//			   corNumero -> Cor que o n�mero ser� exibido;
// 			   corFundo -> Cor que fundo do n�mero e o espa�o ao redor ir� receber; 
// 			   espacos -> Espa�o a ser adicionado � direita e � esquerda do n�mero.
// Sa�da_____: Sem retorno.
//-------------------------------------------------------------------------------------------------------------------
void exibirIntAlinhadoColorido(int numero, unsigned corNumero, unsigned corFundo, int espacos) {
	colorir(corNumero, corFundo); 
	cout.width(espacos);		// Adiciona espa�os � esquerda do n�mero.
	cout << numero;
	cout.width(espacos + 1);	// Permite centralizar o n�mero no espa�o pintado ao adicionar espa�os � esquerda.
	descolorir();
}

//------------------------------------------------------------------------------------------
// Descri��o_: Fun��o que substitui as letras min�sculas por suas mai�sculas correspondentes 
// Entrada___: nome[] -> Palavra a ser analisada para deixar suas letras mai�sculas;
// Sa�da_____: Sem retorno.
//------------------------------------------------------------------------------------------
void deixarTickerMaiusculo(char nome[]) {
	for (int i = 0; i < 4; i++) {							 // Todo Ticker tem 4 caracteres, a partir desse 'for' todos s�o analisados
		if (nome[i] >= 97 && nome[i] <= 122) nome[i] -= 32;	 // Na tabela ASCII a letra mai�scula correpondente a min�scula � 32 unidades menor 
															 // Se a letra for min�scula, � substituida pelo caractere mai�sculo
	}
}

//-----------------------------------------------------------------------
// Descri��o_: Fun��o que exibe um caractere em la�o para fazer uma linha 
// Entrada___: carac -> Caractere a ser exibido;
//			   tam -> Tamanho da linha a ser formada;
//			   corLinha -> Cor que o caractere ser� exibido em la�o;
//			   corFundo -> Cor do fundo da linha;
// Sa�da_____: Sem retorno.
//-----------------------------------------------------------------------
void exibirLinhaColorida(const char carac, unsigned tam, unsigned corLinha, unsigned corfundo) {
	char caractere[2] = { carac, '\0' }; // Como a fun��o 'exibirVetCharColorido()' s� aceita vetor de caractere, aqui o caracter
										 // � transformado em uma String (vetor de caractere com um caractere nulo)
	while(--tam) {
		exibirVetCharColorido(caractere, corLinha, corfundo); // Exibe o caractere colorido 
	}
}

//------------------------------------------------------------
// Descri��o_: Fun��o que exibe o caractere espa�o em loop.   
// Entrada___: qntEspacos -> N�mero de espa�os a ser exibidos;
// Sa�da_____: Sem retorno.
//------------------------------------------------------------
void escreverEspacos(int qntEspacos) {
	if (qntEspacos > 0) {
		while (--qntEspacos) {
			cout << ' ';
		}
	}
}

