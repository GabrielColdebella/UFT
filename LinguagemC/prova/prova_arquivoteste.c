#include <stdio.h>

int main(){
    FILE *fptr;

    char randLet[10] = "doidos";
    fptr = fopen("binarioTeste.txt", "wb");
    fwrite(&randLet, 10 * sizeof(char), 1, fptr);






    // char randNum[10];
    // fptr = fopen("binarioTeste.txt", "rb");
    // fread(&randNum, 10 * sizeof(char), 1, fptr);
    // printf("%s\n", randNum);

    fclose(fptr);
    return 0;
}