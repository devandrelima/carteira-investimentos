#include <iostream>
#include "stock.h"
#include "Color.h"
#include "Text.h"

using namespace std;

//-------------------------------------------------------------------------------------------------
// Descri��o_: Fun��o que soma a quantidade total de a��es compradas.
// Entrada___: transacoes -> Ponteiro que acessa a quantidade de a��es compradas em cada transa��o;
//			   qnt -> N�mero de transa��es realizadas pela empresa;
// Sa�da_____: Sem retorno.
//-------------------------------------------------------------------------------------------------
int somarQntAcoes(Transacoes* transacoes, int qnt) {
	int soma = 0;

	while (--qnt > -1) {
		soma += transacoes[qnt].quantidadeAcoes;
	}

	return soma;
}

//------------------------------------------------------------------------------------
// Descri��o_: Fun��o que calcula o pre�o m�dio do total de a��es compradas.
// Entrada___: transacoes -> Ponteiro que acessa os dados de cada transa��o realizada;
//			   totalAcoes -> Quantidade total de a��es compradas pela empresa;
//			   qnt -> N�mero de transa��es realizadas.
// Sa�da_____: float que representa a m�dia calculada na fun��o.
//------------------------------------------------------------------------------------
float calcularPrecoMedio(Transacoes* transacoes, int totalAcoes, int qnt) {
	float precoMedio = 0;

	for (int i = 0; i < qnt; i++) {
		precoMedio += transacoes[i].preco * transacoes[i].quantidadeAcoes;
	}

	return precoMedio / totalAcoes;
}

//-------------------------------------------------------------
// Descri��o_: Fun��o que exibe a tabela do Resumo da Carteira.
// Entrada___: empresas[] -> Vetor das empresas registradas;
//			   tamVetor -> Quantidade de Empresas cadastradas;
// Sa�da_____: Float que representa o total investido.
//-------------------------------------------------------------
float resumoCarteira(Empresa empresas[], int tamVetor) {
	int qntTotalAcoes;
	float precoMedio;
	float investido;
	float totalInvestido = 0;
	const int tamTraco = 69;

	// Exibi��o do Sum�rio da Tabela de Resumo da Carteira:
	exibirVetCharAlinhadoColorido("Resumo da Carteira", preto, verde, 43);	
	cout << endl;
	exibirLinhaColorida('-', tamTraco, ciano, preto);						
	cout << endl;
	exibirVetCharAlinhadoColorido("Empresa", preto, verde, int(strlen("Empresa")) + 1);	// � necess�rio converter o retorno de 'strlen' de forme expl�cita para 
	escreverEspacos(10);																// para n�o dar aviso de perigo de convers�o
	exibirVetCharAlinhadoColorido("Ticker", preto, verde, int(strlen("Ticker")) + 1);
	escreverEspacos(5);
	exibirVetCharAlinhadoColorido("Qtd.", preto, verde, int(strlen("Qtd.")) + 1);		// O +1 representa um espa�o a mais de cada lado do texto para alinhar
	escreverEspacos(5);
	exibirVetCharAlinhadoColorido("Pre�o M�dio", preto, verde, int(strlen("Pre�o M�dio")) + 1);
	escreverEspacos(5);
	exibirVetCharAlinhadoColorido("Investido", preto, verde, int(strlen("Investido")) + 1);
	cout << endl;
	
	// Loop que processa e exibe os dados linha a linha:
	for (int i = 0; i < tamVetor; i++) {					
		qntTotalAcoes = 0;
		precoMedio = 0;
		investido = 0;

		// Exibi��o da coluna 'Empresa':
		cout << empresas[i].nome;
		escreverEspacos(20 - int(strlen(empresas[i].nome)));

		// Exibi��o da coluna 'Ticker':
		cout << empresas[i].ticker;
		escreverEspacos(8);
		
		// Processamento e Exibi��o da coluna 'Qtd.' (quantidade total de transa��es):
		qntTotalAcoes = somarQntAcoes(empresas[i].transacoes,empresas[i].qntTransacoes);
		if (qntTotalAcoes < 100) cout << ' ';				// Para igualar a tabela, n�meros que n�o atingem a centena
		cout << qntTotalAcoes;								// ganham 1 espa�o a mais para compensar.
		escreverEspacos(10);								
		
		// Processamento e Exibi��o da Coluna do 'Pre�o M�dio':
		precoMedio = calcularPrecoMedio(empresas[i].transacoes, qntTotalAcoes, empresas[i].qntTransacoes);
		cout << fixed;
		cout.precision(2);
		cout  << precoMedio;								
		escreverEspacos(12);

		// Processamento e Exibi��o da coluna 'Investido':
		investido = precoMedio * qntTotalAcoes;
		cout << investido;

		totalInvestido += investido;	// A cada loop soma o quanto foi investido para encontrar o total.
		cout << endl;
	}

	// Exibi��o do Rodap� da Tabela com o total investido:
	exibirLinhaColorida('-', tamTraco, ciano, preto);						
	cout << endl;
	colorir(preto, verde);
	cout << " Total Investido";
	escreverEspacos(45);
	exibirFloatAlinhadoColorido(totalInvestido, preto, verde, 8);
	descolorir();

	return totalInvestido;
}

//--------------------------------------------------------------------------------------
// Descri��o_: Fun��o que processa e exibe a tabela de Rentabilidade da Carteira.
// Entrada___: investAportRendi[] -> Vetor que possui o valor do total de investimentos, 
//									 o aporte anual e o rendimento anual;
//			   investimentos[] -> Vetor que ser� preenchido com os resultados dos
//                                c�lculos dos investimentos durante os anos; 
//			   rendimentos[] -> Vetor que ser� preenchido com os resultados dos 
//								c�lculos dos rendimentos durante os anos;
//			   acumulados[] -> Vetor que ser� preenchido com os resultados dos
//							   c�lculos dos acumulados durante os anos;
//			   reguaGrafico[] -> Vetor que ser� preenchido com n�meros que 
//								 far�o uma escala entre 0 e 21;
//			   grafico[21][21] -> Matriz que ser� preenchinda por 0 e 1 
//								  conforme a escala da 'reguaGrafico'.
// Sa�da_____: Sem retorno.
//---------------------------------------------------------------------------------------
void rentabilidadeCarteira(float investAportRendi[], float investimentos[], float rendimentos[], 
						   float acumulados[], int reguaGrafico[], char grafico[21][21]) {

	investimentos[0] = { investAportRendi[0] };
	rendimentos[0] = { 0 };
	acumulados[0] = { investAportRendi[0] };
	
	// Processamento dos dados da Tabela:
	for (int i = 1; i < 21; i++) {
		investimentos[i] = investimentos[i - 1] + investAportRendi[1];									// Calcula e guarda os investimentos do ano 0 at� o 20.
		rendimentos[i] = (investAportRendi[2] / 100.0f) * (acumulados[i - 1] + investAportRendi[1]);	// Calcula e guarda os rendimentos do ano 0 at� o 20.
		acumulados[i] = acumulados[i - 1] + investAportRendi[1] + rendimentos[i];						// Calcula e guarda os acumulados do ano 0 at� o 20.
	}

	// Processamento da escala que ir� servir de base para o gr�fico:
	for (int i = 0; i < 21; i++) {
		reguaGrafico[i] = (int)((acumulados[i] / acumulados[20]) * 21);		// Fornece uma escala que pode ir de 0 at� 21
	}

	// Processamento do Gr�fico:
	for (int i = 0, j = 0, coluna = 0; i < 21; i++) {
		j = reguaGrafico[i]; 

		if (j == 21) j = 20;		// Os vetores s� v�o at� o indice 20, por isso � necess�rio.
									// fazer esse tratamento com o n�mero 21.
		
		coluna = j;					// Indice da coluna que come�ar� a substituir por 1, regredindo at� a coluna 0.
									
		do {						// Caso j� seja a coluna 0 o programa substitui por 1 e parte para o pr�ximo loop no 'for'.
			grafico[i][coluna] = 1;	// Substitui os zeros por 1 (onde ser� colocado o caractere). A quantidade de n�meros 'um' 
									// em uma linha equivalem ao valor de j+1
		} while (coluna--);
	}

	/* Exemplo de como ser� guardado na matriz:
	j = 0	100000000000000000000
	j = 0	100000000000000000000
	j = 0	100000000000000000000
	j = 1	110000000000000000000
	j = 1	110000000000000000000
	j = 1	110000000000000000000
	j = 2	111000000000000000000  Ex: O 'do while' acima substitui o '0' por '1' na coluna 2 e regride at� a coluna 0 substituindo os zeros por uns.  
	j = 2	111000000000000000000
	j = 3	111100000000000000000
	j = 3	111100000000000000000
	j = ...	.
	j = ...	.
	j = ...	.
	*/

	// Exibi��o do Sum�rio da Tabela:
	cout << endl;
	exibirVetCharAlinhadoColorido("Rentabilidade da Carteira", preto, verde, int(strlen("Rentabilidade da Carteira")) + 31);			
	cout << endl;

	const int tamTraco = 88;
	exibirLinhaColorida('-', tamTraco, ciano, preto);										
	cout << endl;
	
	exibirVetCharAlinhadoColorido("Ano", preto, verde, int(strlen("Ano")) + 1);
	exibirVetCharAlinhadoColorido("Investimento", preto, verde, int(strlen("Investimento")) + 1);
	exibirVetCharAlinhadoColorido("Rendimento", preto, verde, int(strlen("Rendimento")) + 1);
	exibirVetCharAlinhadoColorido("Acumulado", preto, verde, int(strlen("Acumulado")) + 1);
	exibirVetCharAlinhadoColorido("Gr�fico", preto, verde, 26);		

	// Exibi��o dos Dados e do Gr�fico:
	system("chcp 437 > nul");										// Formata os caracteres na tela para desenho do gr�fico.
	for (int a = 0, i = 20; a < 21; a++, i--) {
		cout << endl;
		
		exibirIntAlinhadoColorido(a, preto, verde, 3);						// Exibe a coluna 'Ano'.
		escreverEspacos(4);

		exibirFloatAlinhadoColorido(investimentos[a], branco, preto, 9);	// Exibe a coluna 'Investimento'.
		escreverEspacos(5);

		exibirFloatAlinhadoColorido(rendimentos[a], branco, preto, 9);		// Exibe a coluna 'Rendimento'.
		escreverEspacos(3);

		exibirFloatAlinhadoColorido(acumulados[a], branco, preto, 10);		// Exibe a coluna 'Acumulado'.
		escreverEspacos(4);

		for (int j = 0; j < 21; j++) {								// Exibe o gr�fico.
			if (grafico[j][i] == 0) {
				cout << "  ";										// Quando o valor presente no par de �ndices � 0 
																	// o programa exibe dois espa�os.
			}
			else {
				cout << "\xDC ";									// Quando o valor presente no par de �ndices � 1, o  
																	// programa exibe o caractere quadrado e um espa�o.
			}
		}
	}
	cout << endl;
	exibirLinhaColorida('-', tamTraco, ciano, preto);		
	cout << endl;
}

