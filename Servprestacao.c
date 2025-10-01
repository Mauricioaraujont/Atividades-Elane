#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <locale.h> 
#include <string.h>  // Para usar a função strcmp() 
int main() {
    char nome[41];            // Limitado a 40 caracteres + '\0' 
    char tipoCliente[16];     // Limitado a 15 caracteres + '\0' 
    char faixaEtaria[11];     // Limitado a 10 caracteres + '\0' 
    char tipoConserto[11];    // Limitado a 10 caracteres + '\0' 
    char desejaDesconto[4];   // Limitado a 3 caracteres + '\0' 
    int qtdPecas;
    int qtdAtendimentoMes;
    double valorPeca, valorConserto;
    setlocale(LC_ALL, " ");
    /* ENTRADAS */
    printf("=======================================================\n");
    printf("SISTEMA DE CONTROLE DE PRESTACAO DE SERVICO\n");
    printf("=======================================================\n");
    printf("NOME DO CLIENTE: ");
    scanf(" %40[^\n]", nome);  // Limita a leitura a 40 caracteres + '\0' 

    // Leitura do tipo de cliente 
    printf("TIPO DE CLIENTE (PREMIUM / EXCLUSIVO / FIDELIDADE): ");
    scanf(" %15s", tipoCliente);  // Limita a leitura a 15 caracteres + '\0' 

    // Leitura da faixa etária 
    printf("FAIXA ETARIA (CRIANCA / ADULTO / IDOSO): ");
    scanf(" %10s", faixaEtaria);  // Limita a leitura a 10 caracteres + '\0' 

    // Leitura do tipo de conserto 
    printf("TIPO DE CONSERTO (SIMPLES / COMPLEXO): ");
    scanf(" %10s", tipoConserto);  // Limita a leitura a 10 caracteres + '\0' 

    printf("QUANTIDADE DE PECAS: ");
    scanf("%d", &qtdPecas);

    printf("VALOR DA PECA: ");
    scanf("%lf", &valorPeca);

    printf("VALOR DO CONSERTO: ");
    scanf("%lf", &valorConserto);

    printf("DESEJA APLICAR O DESCONTO MENSAL? (SIM / NAO): ");
    scanf(" %3s", desejaDesconto);  // Limita a leitura a 3 caracteres + '\0' 

    printf("QUANTIDADE DE ATENDIMENTO NO MES: ");
    scanf("%d", &qtdAtendimentoMes);

    //questao 02 
    double valorDasPecas = valorPeca * qtdPecas;

    //questao 03 
    double valorAtendimento = valorConserto + valorDasPecas;

    //questao 04 
    double percDescConserto = 0.0;

    if (strcmp(tipoCliente, "PREMIUM") == 0) {
        if (strcmp(faixaEtaria, "CRIANCA") == 0)
            percDescConserto = 5;
        if (strcmp(faixaEtaria, "ADULTO") == 0)
            percDescConserto = 10;
        if (strcmp(faixaEtaria, "IDOSO") == 0)
            percDescConserto = 5;
    }






    if (strcmp(tipoCliente, "EXCLUSIVO") == 0) {
        if (strcmp(faixaEtaria, "CRIANCA") == 0)
            percDescConserto = 4;
        if (strcmp(faixaEtaria, "ADULTO") == 0)
            percDescConserto = 6;
        if (strcmp(faixaEtaria, "IDOSO") == 0)
            percDescConserto = 4;
    }
    if (strcmp(tipoCliente, "FIDELIDADE") == 0) {
        if (strcmp(faixaEtaria, "CRIANCA") == 0)
            percDescConserto = 2;
        if (strcmp(faixaEtaria, "ADULTO") == 0)
            percDescConserto = 4;
        if (strcmp(faixaEtaria, "IDOSO") == 0)
            percDescConserto = 2;
    }

    double valorDescConserto = valorConserto * (percDescConserto / 100);

    //QUESTAO 5 
    double percAcrescConserto = 0.0;
    if (strcmp(tipoConserto, "SIMPLES") == 0)
        percAcrescConserto = 5;
    if (strcmp(tipoConserto, "COMPLEXO") == 0)
        percAcrescConserto = 8;

    double valorAcrescConserto = valorConserto * (percAcrescConserto / 100);

    //QUESTAO 6 
    double valorTotalAtendimento = valorAtendimento - valorDescConserto +
        valorAcrescConserto;

    //QUESTAO 7 
    double percDescMensal = 0.0;
    if (strcmp(desejaDesconto, "SIM") == 0) {
        if (qtdAtendimentoMes >= 1 && qtdAtendimentoMes <= 3)
            percDescMensal = 5;
        if (qtdAtendimentoMes >= 4 && qtdAtendimentoMes <= 6)
            percDescMensal = 8;
        if (qtdAtendimentoMes > 6)
            percDescMensal = 10;
    }
    double valorDescTotalAtendimento = valorTotalAtendimento * (percDescMensal / 100);

    //QUESTAO 8 
    double valorPagamento = valorTotalAtendimento - valorDescTotalAtendimento;

    //QUESTAO 9 
    printf("\n=======================================================\n");
    printf("RELATORIO SOBRE O CONSERTO DO CELULAR\n");
    printf("=======================================================\n");
    printf("NOME DO CLIENTE: %s\n", nome);
    printf("TIPO DE CLIENTE: %s\n", tipoCliente);
    printf("TIPO DE CONSERTO: %s\n", tipoConserto);
    printf("FAIXA ETARIA: %s\n", faixaEtaria);
    printf("VALOR DA PECA: R$ %.2f\n", valorPeca);
    printf("QUANTIDADE DE PECAS: %d\n", qtdPecas);
    printf("VALOR DAS PECAS: R$ %.2f\n", valorDasPecas);
    printf("VALOR DO CONSERTO: R$ %.2f\n", valorConserto);
    printf("QUANTIDADE DE ATENDIMENTO NO MES: %d\n", qtdAtendimentoMes);
    printf("VALOR DO ATENDIMENTO: R$ %.2f\n", valorAtendimento);
    printf("DESCONTO NO CONSERTO: %.0f%%\n", percDescConserto);
    printf("VALOR DO DESCONTO NO CONSERTO: R$ %.2f\n", valorDescConserto);
    printf("ACRESCIMO NO CONSERTO: %.0f%%\n", percAcrescConserto);
    printf("VALOR DO ACRESCIMO NO CONSERTO: R$ %.2f\n", valorAcrescConserto);
    printf("VALOR TOTAL DO ATENDIMENTO: R$ %.2f\n", valorTotalAtendimento);
    printf("APLICOU DESCONTO MENSAL? %s\n", desejaDesconto);
    printf("DESCONTO MENSAL NO TOTAL: %.0f%%\n", percDescMensal);
    printf("VALOR DO DESCONTO NO TOTAL DO ATENDIMENTO: R$ %.2f\n",
        valorDescTotalAtendimento);
    printf("VALOR DO PAGAMENTO: R$ %.2f\n", valorPagamento);
    printf("=======================================================\n");
    printf("PROGRAMADOR: MAURICIO ARAUJO DE OLIVEIRA NETO\n");
    printf("=======================================================\n");
}
