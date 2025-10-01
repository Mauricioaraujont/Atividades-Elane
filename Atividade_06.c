#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

main() {
	char nomeCliente;
	int tipoCliente;
	int tipoPacote;
	int tipoKit;
	int kitChurrasco;
	int guiaLocal;
	int seguraEquipamentos;
	int nruUtilidades;
	int qtdPeriodos;
	double valorPorperiodo;
	double percentualMultaExtravio;
	int extravioItens;
	 //contates - valores fixos
	double VALOR_KIT_HURRASCO = 50.0;
	double VALOR_GUIA_LOCAL = 60;
	double TAXA_LIMPEZA_FIXA = 30.0;
	double ACRESCIMO_FIXO_KIT_COMPLETO = 25.0;

	printf("==========================================================================\n");
	printf("   SISTEMA DE LOCACAO DE EQUIPAMENTOS PARA ACAMPAMENTO E PESCA\n");
	printf("==========================================================================\n");

	printf(" NOME DO CLIENTE");
	scanf(" %40[^\n]", nomeCliente);

	printf("TIPO DE CLIENTE: [1. DIARIA 2. FIM DE SEMANA]:");
	scanf("%d", &tipoCliente);

	printf("TIPO DE KIT [1. BASICO 2. INTERMEDIARIO 3. COMPLETO]");
	scanf("%d", &tipoKit);

	printf("INCLUIR KIT CHURRASCO [1. SIM 2. NAO]");
	scanf("%d", &kitChurrasco);

	printf("GUIA LOCAL INCLUIDO [1. SIM 2. NAO]");
	scanf("%d", &guiaLocal);

	printf("SEGURO DOS EQUIPAMENTOS [1. SIM 2.NAO]");
	scanf("%d", &seguraEquipamentos);

	printf("NUMERO DE VEZES QUE UTILIZOU O SERVICO:");
	scanf("%d", &nruUtilidades);

	printf("NUMERO DE PERIODOS [1. DIARIAS 2.FIM DE SEMANA]");
	scanf("%d", &qtdPeriodos);

	printf("VALOR BASE POR PERIODO (R$):";
	scanf("%lf", &valorPorperiodo);

	printf(" PERCENTUAL DE MULTA POR EXTRAVIO (%%):");
	scanf("%lf", &percentualMultaExtravio);

	printf(" HOUVE EXTRAVIO DE ITENS [1. SIM 2. NAO]");
	scanf("%d", &extravioItens);

	double custoBase = qtdPeriodos * valorPorperiodo;

	double percDescTipoCliente = 0.0;



	if (tipoCliente == 1 && tipoKit == 1)
		percDescTipoCliente = 0.00; // Ocasional +  Basico 
	if (tipoCliente == 1 && tipoKit == 2)
		percDescTipoCliente = 0.05; // Ocasional +  Intermediario
	if (tipoCliente == 1 && tipoKit == 3)
		percDescTipoCliente = 0.08; // Ocasional +  Completo 
	if (tipoCliente == 1 && tipoKit == 1)
		percDescTipoCliente = 0.05; // VIP +  Basico 
	if (tipoCliente == 1 && tipoKit == 2)
		percDescTipoCliente = 0.08; // VIP +  Intermediario 
	if (tipoCliente == 1 && tipoKit == 3)
		percDescTipoCliente = 0.10; // VIP +  Completo
	if (tipoCliente == 1 && tipoKit == 1)
		percDescTipoCliente = 0.12; // Corporativo +  Basico 
	if (tipoCliente == 1 && tipoKit == 2)
		percDescTipoCliente = 0.15; // Corporativo +  Basico 
	if (tipoCliente == 1 && tipoKit == 3)
		percDescTipoCliente = 0.20; // Corporativo +  Basico 

	double descTipoCliente = percDescTipoCliente * custoBase;

	double percDescRecorrente = 0.0;
	if (nruUtilidades > 5)
		percDescRecorrente = 0.05;
	else
		percDescRecorrente = 0.0;

	double percAcrescimoKit = 0.0;
	if (tipoKit == 1)
		percAcrescimoKit = 0.00;
	if (tipoKit == 2)
		percAcrescimoKit = 0.10;
	if (tipoKit == 3)
		percAcrescimoKit = 0.20;

	double acrescimoKit = percAcrescimoKit * custoBase;

	double acrescimoChurrasco = 0.0;
	if (kitChurrasco == 1 && VALOR_KIT_HURRASCO > 0.0)
		acrescimoChurrasco = VALOR_KIT_HURRASCO;
	else
		acrescimoChurrasco = 0.0;

	double acrescimoGuia = 0.0;
	if (guiaLocal == 1 && VALOR_GUIA_LOCAL > 0.0)
		acrescimoGuia = VALOR_GUIA_LOCAL;
	else
		acrescimoGuia = 0.0;

	double taxaLimpeza = 0.0;
	if (TAXA_LIMPEZA_FIXA >= 0.0) {
		taxaLimpeza = TAXA_LIMPEZA_FIXA;
	}
	else {
		taxaLimpeza = 0.0;
	}

	double acrescimoSeguro = 0.0;
	if (seguraEquipamentos == 1 && custoBase > 0.0)
		acrescimoSeguro = 0.05 * custoBase;
	else
		acrescimoSeguro = 0.0;

	double acrescimoFixoKitCompleto = 0.0;
	if (tipoKit == 3 && ACRESCIMO_FIXO_KIT_COMPLETO > 0.0)
		acrescimoFixoKitCompleto = ACRESCIMO_FIXO_KIT_COMPLETO;
	else
		acrescimoFixoKitCompleto = 0.0;

	double multaExtravio = 0.0;
	if (extravioItens == 1 && percentualMultaExtravio > 0.0)
		multaExtravio = (percentualMultaExtravio / 100.0) * custoBase;

	double totalDescontos = descTipoCliente + percDescRecorrente;
	double totalExtrasFixos = acrescimoChurrasco + acrescimoGuia + taxaLimpeza;

	double valorFinal = custoBase + acrescimoKit + acrescimoSeguro + acrescimoFixoKitCompleto + totalExtrasFixos + multaExtravio - totalDescontos;

	// relatorio 
	printf("CLIENTE: %s", nomeCliente);
	printf("")

	
	
	
	return = 0;


}