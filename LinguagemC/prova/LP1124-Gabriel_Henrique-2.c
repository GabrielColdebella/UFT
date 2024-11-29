#include <stdio.h>
#include <stdlib.h>

#define qtdEntrevistas 90

void inicializador(
    int ini_cPresEscolhido[qtdEntrevistas],
    int ini_cGovEscolhido[qtdEntrevistas],
    int ini_eFaixaSalarial[qtdEntrevistas],
    int ini_pIdade[qtdEntrevistas]
){
    int seletor1, eleitorAtual = 0, mes = 0;
    // s de seletor
    int sPresidente, sGovernador, sIdade, sFaixaSalarial;

    do
    {
        scanf(" %d", &sPresidente);
        scanf(" %d", &sGovernador);
        scanf(" %d", &sIdade);
        scanf(" %d", &sFaixaSalarial);

        scanf(" %d", &ini_cPresEscolhido[eleitorAtual]);
        scanf(" %d", &ini_cGovEscolhido[eleitorAtual]);
        scanf(" %d", &ini_eFaixaSalarial[eleitorAtual]);
        scanf(" %d", &ini_pIdade[eleitorAtual]);        

    } while (eleitorAtual < 90 && mes < 3 && ini_pIdade != 0);
    
}

int main(){
    int mes, eleitorAtual, seletor1;
    struct dadosEleitor {
        int candidatoPresidenciaEscolhido[qtdEntrevistas];
        int candidatoGovernadorEscolhido[qtdEntrevistas];
        int pessoaIdade[qtdEntrevistas];
        int eleitorFaixaSalarial[qtdEntrevistas];
    };
    
    struct dadosEleitor seletorEstrutura;

    inicializador(
        seletorEstrutura.candidatoPresidenciaEscolhido,
        seletorEstrutura.candidatoGovernadorEscolhido,
        seletorEstrutura.eleitorFaixaSalarial,
        seletorEstrutura.pessoaIdade
    );


    // FILE *fptr;
    // fptr = fopen("resultadoEntrevistas.txt", "w");
    // fwrite(&ini_cPresEscolhido[eleitorAtual], sizeof(int), 1, fptr);
    // fwrite(&ini_cGovEscolhido[eleitorAtual], sizeof(int), 1, fptr);
    // fwrite(&ini_eFaixaSalarial[eleitorAtual], sizeof(int), 1, fptr);
    // fwrite(&ini_pIdade[eleitorAtual], sizeof(int), 1, fptr);

    return 0;
}