#include <iostream>
#include "Color.h"

using namespace std;

//---------------------------------------------------------------------------------------------------------
// Descrição_: Função que alinha o texto centralizando-o em um espaço e exibe o texto e o espaço coloridos. 
// Entrada___: texto[] -> Texto a ser alinhado/centralizado e colorido;
//			   corTexto -> Cor que o texto será exibido;
// 			   corFundo -> Cor que o espaço ao redor do texto e o fundo do texto irá receber; 
// 			   espacos -> Espaço a ser adicionado à direita e à esquerda do texto.
// Saída_____: Sem retorno.
//---------------------------------------------------------------------------------------------------------
void exibirVetCharAlinhadoColorido(const char texto[], unsigned corTexto, unsigned corFundo, int espacos) {
	colorir(corTexto, corFundo);			// Colore o texto e o espaço com as cores definidas pelo usuário.
	cout.width(espacos);					// Insere espaços antes do texto.
	cout << texto;
	cout.width(espacos-strlen(texto)+3);	// Insere espaços após o texto para centralizar.
	descolorir();							// Retorna a cor do texto e do fundo para a original do prompt de comando.
}

//--------------------------------------------------------------
// Descrição_: Função que exibe o texto e o fundo coloridos.
// Entrada___: texto[] -> Texto a ser colorido;
//			   corTexto -> Cor que o texto será exibido;
// 			   corFundo -> Cor que o fundo do texto irá receber; 
// Saída_____: Sem retorno.
//--------------------------------------------------------------
void exibirVetCharColorido(const char texto[], unsigned corTexto, unsigned corFundo) {
	colorir(corTexto, corFundo);
	cout << texto;
	descolorir();
}

//-----------------------------------------------------------------------------
// Descrição_: Função que alinha um número double à direita e o exibe colorido. 
// Entrada___: numero -> Número que será alinhado e exibido colorido;
//			   corNumero -> Cor que o número será exibido;
// 			   corFundo -> Cor que fundo do número irá receber; 
// 			   espacos -> Espaço que o número pode ocupar.
// Saída_____: Sem retorno.
//-----------------------------------------------------------------------------
void exibirFloatAlinhadoColorido(float numero, unsigned corNumero, unsigned corFundo, int espacos) {
	colorir(corNumero, corFundo); 
	cout << right;			// Alinha o número à direita.
	cout.width(espacos);	// Determina a quantidade de espaço que o número pode ocupar.
	cout << numero;
	descolorir();
}

//-------------------------------------------------------------------------------------------------------------------
// Descrição_: Função que alinha um número inteiro centralizando-o em um espaço e exibe o número e o espaço coloridos  
// Entrada___: numero -> Número que será alinhado e colorido;
//			   corNumero -> Cor que o número será exibido;
// 			   corFundo -> Cor que fundo do número e o espaço ao redor irá receber; 
// 			   espacos -> Espaço a ser adicionado à direita e à esquerda do número.
// Saída_____: Sem retorno.
//-------------------------------------------------------------------------------------------------------------------
void exibirIntAlinhadoColorido(int numero, unsigned corNumero, unsigned corFundo, int espacos) {
	colorir(corNumero, corFundo); 
	cout.width(espacos);		// Adiciona espaços à esquerda do número.
	cout << numero;
	cout.width(espacos + 1);	// Permite centralizar o número no espaço pintado ao adicionar espaços à esquerda.
	descolorir();
}

//------------------------------------------------------------------------------------------
// Descrição_: Função que substitui as letras minúsculas por suas maiúsculas correspondentes 
// Entrada___: nome[] -> Palavra a ser analisada para deixar suas letras maiúsculas;
// Saída_____: Sem retorno.
//------------------------------------------------------------------------------------------
void deixarTickerMaiusculo(char nome[]) {
	for (int i = 0; i < 4; i++) {							 // Todo Ticker tem 4 caracteres, a partir desse 'for' todos são analisados
		if (nome[i] >= 97 && nome[i] <= 122) nome[i] -= 32;	 // Na tabela ASCII a letra maiúscula correpondente a minúscula é 32 unidades menor 
															 // Se a letra for minúscula, é substituida pelo caractere maiúsculo
	}
}

//-----------------------------------------------------------------------
// Descrição_: Função que exibe um caractere em laço para fazer uma linha 
// Entrada___: carac -> Caractere a ser exibido;
//			   tam -> Tamanho da linha a ser formada;
//			   corLinha -> Cor que o caractere será exibido em laço;
//			   corFundo -> Cor do fundo da linha;
// Saída_____: Sem retorno.
//-----------------------------------------------------------------------
void exibirLinhaColorida(const char carac, unsigned tam, unsigned corLinha, unsigned corfundo) {
	char caractere[2] = { carac, '\0' }; // Como a função 'exibirVetCharColorido()' só aceita vetor de caractere, aqui o caracter
										 // é transformado em uma String (vetor de caractere com um caractere nulo)
	while(--tam) {
		exibirVetCharColorido(caractere, corLinha, corfundo); // Exibe o caractere colorido 
	}
}

//------------------------------------------------------------
// Descrição_: Função que exibe o caractere espaço em loop.   
// Entrada___: qntEspacos -> Número de espaços a ser exibidos;
// Saída_____: Sem retorno.
//------------------------------------------------------------
void escreverEspacos(int qntEspacos) {
	if (qntEspacos > 0) {
		while (--qntEspacos) {
			cout << ' ';
		}
	}
}

