
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>;
#include <locale.h>


// CÓDIGO DESENVOLVIDO POR: MAURÍCIO NETO
int main() {
	int tipoCLiente, tipoVista, tipoQuarto;
	int diariaS, coffeeBreak, numeroHospedes, transFer, tmpFer, reservaAnterior;
	int reservasCancel;
	float valorDiarias, valorRefeicao, multaCancel;
	float custoBase, desconto;
	char nomeCliente[50];
	float taxaCafe, taxaTransfer = 0.0, totalRefeicao,multa , valorFinal = 0;

	setlocale(LC_ALL, "pt_BR.UTF-8");

	printf("\n====================================================================\n");
	printf("\n			SISTEMA DE RESERVAS  HOTEL FLOR DO VALE\n");
	printf("\n====================================================================\n");
	printf("DIGITE O NOME DO CLIENTE:");
	fgets(nomeCliente, 50, stdin);

	printf("TIPO DE CLIENTE (1. NOVO | 2. FIDELIZADO | 3. VIP):");
	scanf(" %d", &tipoCLiente);

	printf("TIPO DE QUARTO (1. STANDARD | 2. LUXO | 3. MASTER):");
	scanf(" %d", &tipoQuarto);

	printf("TIPO DE VISTA (1. INTERNA | 2. JARDIM | 3. MAR):");
	scanf(" %d", &tipoVista);

	printf("QUANTIDADE DE DIARIAS:");
	scanf(" %d", &diariaS);

	printf("VALOR DAS DIARIAS:");
	scanf(" %f", &valorDiarias);

	printf("DESEJA INCLUIR O CAFÉ DA MANHÃ? (1. SIM | 2. NAO):");
	scanf(" %d", &coffeeBreak);

	printf("NÚMERO DE HÓSPEDES:");
	scanf(" %d", &numeroHospedes);

	printf("VALOR DAS REFEIÇÕES POR DIA:\n");
	scanf(" %f", &valorRefeicao);

	printf("INCLUI TRANSFER? (1. SIM | 2. NAO):");
	scanf(" %d", &transFer);

	printf("É TEMPORADA OU FERIADO? (1. TEMPORADA | 2. FERIADO):");
	scanf(" %d", &tmpFer);

	printf("NÚMERO DE RESERVAS ANTERIORES:");
	scanf(" %d", &reservaAnterior);

	printf("RESERVA CANCELADA EM MENOS DE 24H? (1. SIM | 2. NAO):");
	scanf(" %d", &reservasCancel);

	//	Q.02
	custoBase = diariaS * valorDiarias;

	// Q.03
	if (tipoQuarto == 1) {
		custoBase = custoBase;
	} else if (tipoQuarto == 2) {
		custoBase = custoBase * 1.10;
	} else if (tipoQuarto == 3) {
		custoBase = custoBase * 1.20;
	}
	// Q. 04
	if (tipoVista == 1) {
		custoBase = custoBase;
	}
	else if (tipoVista == 2) {
		custoBase = custoBase * 1.05;
	}
	else if (tipoVista == 3) {
		custoBase = custoBase * 1.10;
	}
	// Q. 05
	if (coffeeBreak == 1) {
		taxaCafe = 30.0 * numeroHospedes * diariaS;
	}
	else {
		taxaCafe = 0;
	}
	// Q. 06
	totalRefeicao = valorRefeicao * numeroHospedes * diariaS;

	// Q. 07
	if (transFer == 1) {
		taxaTransfer = 120.0;
	}
	else {
		taxaTransfer = 0;
	}
	// Q.08
	if (tmpFer == 1) {
		custoBase = custoBase * 1.12;
	}

	//Q. 09
	if (tipoCLiente == 2) {
		desconto = custoBase * 0.05;

	//Q. 10
	if (reservaAnterior > 10) {
			desconto += custoBase * 0.08;
		}
	}
	else if (reservaAnterior > 10) {
		desconto = custoBase * 0.06;
	}

	else { 
		desconto = 0 ; }

	if (reservasCancel == 1) {
		multa = (multaCancel / 100.0) * custoBase;
	} else {
		multa = 0;
	}
	// Q 11
	valorFinal = custoBase + taxaCafe + totalRefeicao + taxaTransfer - desconto + multa;

	printf("\n ==================================================================== \n");
	printf("\n RELATÓRIO FINAL – HOTEL FLOR DO VALE \n");
	printf("\n ==================================================================== \n");
	printf("CLIENTE: %s\n", nomeCliente);
	printf("TIPO DE CLIENTE: %d\n", tipoCLiente);
	printf("RESERVAS ANTERIORES: %d\n", reservaAnterior);
	printf("CLIENTE FREQUENTE? (>10): %s\n", reservaAnterior > 10 ? "SIM" : "NÃO");
	printf("-------------------- DADOS DA RESERVA ------------------------------\n");
	printf("TIPO DE QUARTO: %d\n", tipoQuarto);
	printf("TIPO DE VISTA: %d\n", tipoVista);
	printf("CAFÉ DA MANHÃ INCLUÍDO? %s\n", coffeeBreak == 1 ? "SIM" : "NÃO");
	printf("Nº DE HÓSPEDES: %d\n", numeroHospedes);
	printf("TRANSFER INCLUÍDO? %s\n", transFer == 1 ? "SIM" : "NÃO");
	printf("É TEMPORADA OU FERIADO? %s\n", tmpFer == 1 ? "SIM" : "NÃO");
	printf("RESERVA CANCELADA C/ <24H? %s\n", reservasCancel == 1 ? "SIM" : "NÃO");
	printf("------------------- VALORES CALCULADOS -----------------------------\n");
	printf("DIÁRIAS: %d\n", diariaS);
	printf("VALOR DA DIÁRIA: R$ %.2f\n", valorDiarias);
	printf("CUSTO BASE: R$ %.2f\n", custoBase);
	printf("ACRÉSCIMO POR TIPO DE QUARTO: R$ %.2f\n", 0.0f); // pode calcular depois
	printf("ACRÉSCIMO POR VISTA: R$ %.2f\n", 0.0f);          // idem
	printf("VALOR DO CAFÉ DA MANHÃ: R$ %.2f\n", taxaCafe);
	printf("VALOR DAS REFEIÇÕES: R$ %.2f\n", totalRefeicao);
	printf("VALOR DO TRANSFER: R$ %.2f\n", taxaTransfer);
	printf("ACRÉSCIMO TEMPORADA/FERIADO: R$ %.2f\n", 0.0f);
	printf("DESCONTO POR FIDELIDADE: R$ %.2f\n", desconto);
	printf("VALOR DA MULTA POR CANCELAMENTO: R$ %.2f\n", multa);
	printf("====================================================================\n");
	printf("VALOR FINAL TOTAL DA RESERVA: R$ %.2f\n", valorFinal);
	printf("====================================================================\n");
	printf("DATA DA RESERVA: ___/___/____\n");
	printf("@2025 - Todos os direitos reservados\n");
	printf("====================================================================\n");






		return 0;
}
	
	

