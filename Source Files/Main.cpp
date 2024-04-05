#include <iostream>
#include "Color.h"
#include "Date.h"
#include "Stock.h"
#include "Text.h"

using namespace std;

int main() {
	float investAportRendi[3];
	float investimentos[21];
	float rendimentos[21];
	float acumulados[21];
	int reguaGrafico[21];
	int qntEmpresas;
	char grafico[21][21] = { {0},{0} };

	system("chcp 1252 > nul");  // Formata os caracteres para acentuação.
	
	exibirVetCharAlinhadoColorido("Carteira de Ações", preto, verde,int(strlen("Carteira de Ações"))+1);	// Exibe  o texto preto e o fundo verde 
																											// com 1 espaçamento de cada lado.
	exibirVetCharColorido("\n\nQuantidade de Empresas: ", verde, preto);	// Exibe o texto na cor verde em um fundo preto.
	cin >> qntEmpresas;
	Empresa* empresas = new Empresa[qntEmpresas];	// Cria um vetor dinâmico de empresas do tamanho que o 
													// usuário desejar cadastrar.

	// ***************************************************************************************************************
	// Tela de Preenchimento dos dados das empresas
	for (int i = 0; i < qntEmpresas; i++) {
		cout << endl;
		exibirLinhaColorida('-', 20, verde, preto);	// Exibe uma linha com 20 caracteres na cor verde com fundo preto.

		exibirVetCharColorido("\nEmpresa: ", ciano, preto);
		cin.ignore();					 
		cin.getline(empresas[i].nome,50); 

		exibirVetCharColorido("Ticker: ", ciano, preto);
		cin >> empresas[i].ticker;
		deixarTickerMaiusculo(empresas[i].ticker);

		exibirVetCharColorido("Transações: ", ciano, preto);
		cin >> empresas[i].qntTransacoes;
		empresas[i].transacoes = new Transacoes[empresas[i].qntTransacoes];	// Cria um vetor de transações para
																			// cada transação realizada
																			// de cada empresa.
	}
	// **************************************************************************************************************

	// *****************************************************************************************************
	// Tela de Preenchimento das transações de cada empresa:
	cout << endl;
	exibirVetCharAlinhadoColorido("Transações Realizadas", preto, verde, int(strlen("Transações Realizadas"))+1);
	cout << endl << endl;

	for (int i = 0; i < qntEmpresas; i++) {
		// Exibe o Nome da Empresa e o Ticker:
		exibirVetCharColorido(empresas[i].nome, verde, preto);
		exibirVetCharColorido(" - ", verde, preto);
		exibirVetCharColorido(empresas[i].ticker, verde, preto);
		cout << endl << endl;

		// Guarda os dados de cada transação no vetor dinâmico referente a cada empresa:
		for (int j = 0; j < empresas[i].qntTransacoes; j++) {
			exibirVetCharColorido("Data: ", ciano, preto);
			cin >> empresas[i].transacoes[j].data;
			exibirVetCharColorido("Quantidade: ", ciano, preto);
			cin >> empresas[i].transacoes[j].quantidadeAcoes;
			exibirVetCharColorido("Preço: ", ciano, preto);
			cin >> empresas[i].transacoes[j].preco;
			cout << endl;
		}
	}
	// *****************************************************************************************************

	// *********************************************************
	// Tela Resumo da Carteira 
	investAportRendi[0] = resumoCarteira(empresas, qntEmpresas);
	// *********************************************************

	cout << endl << endl;
	exibirVetCharColorido("Aporte Anual R$ ", ciano, preto);
	cin >> investAportRendi[1];		// Guarda a informação no vetor para enviar para a Rentabilidade a Carteira.
	exibirVetCharColorido("Rendimento anual esperado:    %\b\b\b\b", ciano, preto);
	cin >> investAportRendi[2];		// Guarda a informação no vetor para enviar para a Rentabilidade a Carteira.
	
	// ****************************************************************************************************
	// Tela Rentabilidade da Carteira 
	rentabilidadeCarteira(investAportRendi, investimentos, rendimentos, acumulados, reguaGrafico, grafico);
	// ****************************************************************************************************

	for (int i = 0; i < qntEmpresas; i++) 
		delete[] empresas[i].transacoes;	// Deleta os vetores dinâmicos das transações de cada empresa.

	delete[] empresas;						// Deleta o vetor dinâmico de empresas.
	
	return 0;
}