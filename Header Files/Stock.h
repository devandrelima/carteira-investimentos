#pragma once
#include "Date.h"

struct Transacoes {
	Data data;
	int quantidadeAcoes;
	float preco;
};

struct Empresa {
	char nome[15];
	char ticker[6];
	int qntTransacoes;
	Transacoes *transacoes;
};

int somarQntAcoes(Transacoes* transacoes, int qnt);
float calcularPrecoMedio(Transacoes* transacoes, int totalAcoes, int qnt);
float resumoCarteira(Empresa empresas[], int tamVetor); 
void rentabilidadeCarteira(float investAportRendi[], float investimentos[], float rendimentos[],
						   float acumulados[], int reguaGrafico[], char grafico[21][21]);