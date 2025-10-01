#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>



int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Variáveis do cliente
    char nomeCliente[50], endereco[100], telefone[20];
    // Variáveis do animal
    char nomeAnimal[50], raca[40], dataNascimento[12];
    // Variáveis financeiras
    float valorConsulta, valorExame, valorMedicacao;
    int qtdExame, tipoPlano, tipoTratamento, formaPagamento;
    float desconto = 0, valorTotalExames, valorPagamento;



    printf("**************************************************************************************************\n");
    printf("PROGRAMADOR: Seu Nome Aqui\n");
    printf("ATIVIDADE DE ALGORITMOS E PROGRAMAÇÃO - DATA: 17/09/2025\n");
    printf("**************************************************************************************************\n");
    printf("SISTEMA DE CONTROLE DE CLÍNICA VETERINÁRIA\n");
    printf("**************************************************************************************************\n");
    printf("DIGITE AS INFORMAÇÕES ABAIXO:\n");

    printf("NOME DO CLIENTE: ");
    scanf(" %49[^\n]", nomeCliente);
    getchar(); 

    printf("NOME DO ANIMAL: ");
    scanf(" %49[^\n]", nomeAnimal);
    getchar();

    printf("RAÇA: ");
    scanf(" %39[^\n]", raca);
    getchar();

    printf("DATA DE NASCIMENTO (DD/MM/AAAA): ");
    scanf(" %11[^\n]", dataNascimento);
    getchar();

    printf("VALOR DA CONSULTA: ");
    scanf("%f", &valorConsulta);

    printf("VALOR DO EXAME: ");
    scanf("%f", &valorExame);

    printf("QUANTIDADE DE EXAME: ");
    scanf("%d", &qtdExame);

    printf("VALOR DA MEDICAÇÃO: ");
    scanf("%f", &valorMedicacao);

    // Tipo de plano, tratamento e forma de pagamento
    printf("TIPO DE TRATAMENTOS [(1) COMUM – (2) COMPLEXO]: ");
    scanf("%d", &tipoTratamento);

    printf("TIPO DE PLANO [ (1) SIMPLES – (2) FIDELIDADE]: ");
    scanf("%d", &tipoPlano);

    printf("FORMA DE PAGAMENTO [(1) A VISTA – (2) PARCELADO]: ");
    scanf("%d", &formaPagamento);


    if (tipoPlano == 1) { // SIMPLES
        if (tipoTratamento == 1) { // COMUM
            desconto = (formaPagamento == 1) ? 5 : 2;
        }
        else if (tipoTratamento == 2) { // COMPLEXO
            desconto = (formaPagamento == 1) ? 15 : 5;
        }
    }
    else if (tipoPlano == 2) { // FIDELIDADE
        if (tipoTratamento == 1) { // COMUM
            desconto = (formaPagamento == 1) ? 10 : 5;
        }
        else if (tipoTratamento == 2) { // COMPLEXO
            desconto = (formaPagamento == 1) ? 20 : 10;
        }
    }

    // CALCULO DO VALOR TOTAL
    valorTotalExames = valorExame * qtdExame;
    valorPagamento = valorConsulta - (valorConsulta * desconto / 100) + valorTotalExames + valorMedicacao;

    // LAYOUT DE SAÍDA
    printf("*****************************************************************************************\n");
    printf("PROGRAMADOR: Seu Nome Aqui\n");
    printf("ATIVIDADE DE ALGORITMOS E PROGRAMAÇÃO - DATA: 17/09/2025\n");
    printf("*****************************************************************************************\n");
    printf("RELATÓRIO GERAL DO ATENDIMENTO\n");
    printf("*****************************************************************************************\n");
    printf("NOME DO CLIENTE: %s\n", nomeCliente);
    printf("ENDEREÇO: %s\n", endereco);
    printf("TELEFONE: %s\n", telefone);
    printf("NOME DO ANIMAL: %s\n", nomeAnimal);
    printf("RAÇA: %s\n", raca);
    printf("DATA DE NASCIMENTO: %s\n", dataNascimento);
    printf("VALOR DA CONSULTA: R$ %.2f\n", valorConsulta);
    printf("VALOR DO EXAME: R$ %.2f\n", valorExame);
    printf("QUANTIDADE DE EXAME: %d\n", qtdExame);
    printf("VALOR DA MEDICAÇÃO: R$ %.2f\n", valorMedicacao);
    printf("TIPO DE PLANO: %s\n", (tipoPlano == 1) ? "SIMPLES" : "FIDELIDADE");
    printf("TIPO DE TRATAMENTOS: %s\n", (tipoTratamento == 1) ? "COMUM" : "COMPLEXO");
    printf("FORMA DE PAGAMENTO: %s\n", (formaPagamento == 1) ? "A VISTA" : "PARCELADO");
    printf("DESCONTO: %.2f%%\n", desconto);
    printf("VALOR DO PAGAMENTO: R$ %.2f\n", valorPagamento);
    printf("*****************************************************************************************\n");

    return 0;
}
