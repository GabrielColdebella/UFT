#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    //Recebe a quantidade total de entrevistas
    /* --------------------------------------------------------------- */
    int qtdRegistros, qtdRegistrosTotal;

    FILE *fptr;

    fptr = fopen("prova_arquivo3.bin", "rb");
    
    //apenas para pegar o total de registros
    int *pegaTotalRegistros = malloc(sizeof(int));
    fread(pegaTotalRegistros, sizeof(int), 1, fptr);

    if (pegaTotalRegistros[0] == 0){
        pegaTotalRegistros[0] = pegaTotalRegistros[0] + 1;
    }
    
    qtdRegistros = pegaTotalRegistros[0];
    qtdRegistrosTotal = (qtdRegistros * 5) + 4;
    // 5 -> Porque são 5 dados distintos; 5 -> Quantidade de separadores; 
    /* --------------------------------------------------------------- */


    int seletor1, seletor2;
    int candidatoPresidenciaEscolhido[qtdRegistros];
    int candidatoGovernadorEscolhido[qtdRegistros];
    int dadosEleitor[3][qtdRegistros];
    //idade, faixa e mês

    //zera as arrays, visto que tava dando um bug esquisito
    memset(candidatoPresidenciaEscolhido, 0, sizeof(candidatoPresidenciaEscolhido));
    memset(candidatoGovernadorEscolhido, 0, sizeof(candidatoGovernadorEscolhido));
    memset(dadosEleitor, 0, sizeof(dadosEleitor));

    //aluga espaço na memoria em bytes, a quantidade de entrevistas * 4 (tamanho do int)
    int *buffer = malloc(qtdRegistrosTotal * sizeof(int));
    //insere no espaço todos os registros, cujo o espaço foi alugado
    fread(buffer, sizeof(int), qtdRegistrosTotal, fptr);
    //qtdRegistrosTotal

    fclose(fptr);

    for (int i = 0; i < qtdRegistrosTotal; i++)
    {
        printf("\nreg atual %d: %d", i+1, buffer[i]);
    }
    

    // tira do buffer e bota nas arrays
    /* --------------------------------------------------------------- */
    seletor2 = 0; 
    //começa o loop e para de acordo com a qtd de entrevista
    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++) {

        //apesar do seletor1 sempre ser resetado, o seletor continua rodando na lista
        candidatoPresidenciaEscolhido[seletor1] = buffer[seletor2];
        seletor2++;
    }

    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++) {
        //quando o seletor2 parar no separador, ele vai adicionar +1 e vai continuar no proximo
        //nesse caso, vai colocar na lista de votados para governador
        //eu nunca demorei tanto pra pensar em um codigo T_T
        if (buffer[seletor2] == 999){
            seletor2++;
        }

        candidatoGovernadorEscolhido[seletor1] = buffer[seletor2];
        seletor2++;
    }

    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++) {
        if (buffer[seletor2] == 999){
            seletor2++;
        }

        dadosEleitor[0][seletor1] = buffer[seletor2];
        seletor2++;
    }

    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++) {
        if (buffer[seletor2] == 999){
            seletor2++;
        }

        dadosEleitor[1][seletor1] = buffer[seletor2];
        seletor2++;
    }

    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++) {
        if (buffer[seletor2] == 999){
            seletor2++;
        }

        dadosEleitor[2][seletor1] = buffer[seletor2];
        seletor2++;
    }
    /* --------------------------------------------------------------- */

    for (seletor1 = 0; seletor1 < qtdRegistros; seletor1++){
        printf("\n\nEleitor %d:", seletor1);
        printf("\nCandidato presidencia: %d", candidatoPresidenciaEscolhido[seletor1]);
        printf("\nCandidato governador: %d", candidatoGovernadorEscolhido[seletor1]);

        printf("\nIdade do eleitor: %d", dadosEleitor[0][seletor1]);
        printf("\nFaixa salarial do eleitor: %d", dadosEleitor[1][seletor1]);
        printf("\nMes da entrevista: %d", dadosEleitor[2][seletor1]);
        
        if (dadosEleitor[0][seletor1 + 1]  == 0){
            break;
        }
    }
    
    return 0;
}