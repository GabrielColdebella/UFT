#include <stdio.h>
#include <stdbool.h>

int main(){

    struct espica
    {
        char  *espicaChar;
        int espicaInt;
        bool espicaBool;
    };

    struct espica s1;
    s1.espicaInt = 13;
    s1.espicaChar = "Na rua na chuva na fazenda ou numa casinha de sapeeeeeee";
    s1.espicaBool = true;

    

    printf("jogue as suas maos para o ceu: %s", s1.espicaChar);

    return 0;
}