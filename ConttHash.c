#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Ler um hash em MD5
    Quantidades de simbolos
    Formar 4 palavras 
    Gerar uma nova palavras

*/


#define Hash_Size 32 // Tamanho do hash MD5 em caracteres


int cont_simbolos(const char *hash){    
    int simbolos = 0;
        for(int i = 0; i < Hash_Size; i++)
        {
            if(!(hash[i] >= '0' && hash[i] <= '9') && !(hash[i] >= 'a' && hash[i] <= 'f')){
                simbolos++;
            }
        }
    return simbolos;
}

void formar_palavaras(const char *hash){
    char palavra1[9], palavra2[9], palavra3[9], palavra4[9];
    strncpy(palavra1, hash, 8);
    palavra1[8] = '\0';
    strncpy(palavra2, hash + 8, 8);
    palavra2[8] = '\0';
    strncpy(palavra3, hash + 16, 8);
    palavra3[8] = '\0';
    strncpy(palavra4, hash + 24, 8);
    palavra4[8] = '\0';

    printf("Palavra 1: %s\n", palavra1);
    printf("Palavra 2: %s\n", palavra2);
    printf("Palavra 3: %s\n", palavra3);
    printf("Paçavra 4: %s\n", palavra4);

    char last_palavra[9];
    strncpy(last_palavra, hash + 24, 8);
    last_palavra[8] = '\0';

    printf("Ultima palavra: %s\n", last_palavra);

    //Gerar novas palavras a partir da ultima palavra
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            last_palavra[j]++;
            if(last_palavra[j] > 'z'){
                last_palavra[j] = 'a';
            }
            //Garantir que apenas letras minúsculas são geradas
            if(last_palavra[j] > 'f' && last_palavra[j] < 'a'){
                last_palavra[j] = 'a';
            }
        }
      printf("Nova palavra %d: %s\n", i + 1, last_palavra);
    }
}

int main(){

char hash[Hash_Size + 1];

while(1){
    printf("Digite o hash MD5 (32 caracteres): ");
    scanf("%32s", hash);

    int simbolos = cont_simbolos(hash);
    printf("Quantidade de simbolos no hash: %d\n", simbolos);
    
    formar_palavaras(hash);
    
    char opcao;
    
    printf("\n\nDeseja gerar nova palavras novamente ? (S/N):   ");
    scanf(" %c", &opcao);

    if(opcao != 's' && opcao != 'S'){
    break;
    }
  }

    return 0;
}