#include <stdio.h>

/**
    Valor de cada caractere na entrada
    valor = (posição do alfabeto - ASCII) +
    (elemento de entrada - qual string) +
    (posição do elemento - na String)

 hash final = soma de todos.

 */

int main(){
    int n, strings, valorCaractere, k, total, i, j;
    char str[51];

    scanf("%d%*c", &n);

    for(i = 0; i < n; i++){
        scanf("%d%*c", &strings);

        total = 0;
        for(j = 0; j < strings; j++){
            scanf("%s%*c", &str);

            k = 0;
            while(str[k] != '\0'){
                valorCaractere = 0;
                valorCaractere += str[k] - 65;
                valorCaractere += j;
                valorCaractere += k;
                k++;

                total += valorCaractere;
            }
        }
        printf("%d\n", total);


    }

    return 0;
}