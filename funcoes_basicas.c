#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void Copia_conteudo(char origem[], char buffer[]){
    for (int i = 2; i < 10; i++){
        buffer[i-2] = origem[i];
        printf("%c", buffer[i-2]);
    }
    printf("\n");
}


void ConvertChar(char vet[]){
    for (int i = 0; i < 8; i++){ 
        //caso seja de 0 a 9
        if((vet[i] >= '0') && (vet[i] <= '9')){
            vet[i] = vet[i] - '0'; //operacao para trasforma de char p/ int

        }
        //caso seja de a - f
        if((vet[i] >= 'a') && (vet[i] <= 'f')){
            vet[i] = vet[i] - 'W'; //operacao para trasforma de char p/ int
 
        }
        else if (vet[i] > 'f'){ //corrigir tal caso
            printf("O digito invalido, digite um digito em hexadecimal\n");
        }
    }
}


void Decodifica(char V_address[], char address_L1[], int memory_cache[], int first_address[], int last_address[], int hit_count[], int miss_count[]){    

    int R_address = 0;
    int op = (address_L1[7] & 3);
    switch(op){
        case 0:
            printf("Endereço inacessível");
            break;
        case 1:
             
            break;
        case 2:
            R_address = ((address_L1[0] << 28) | (address_L1[1] << 24)) | (address_L1[2] << 20);
            R_address = R_address | ((V_address[3] << 16) | (V_address[4] << 12)) | (V_address[5] << 8);
            R_address = R_address | ((V_address[6] << 4) | V_address[7]);

            int tag = 0;
            tag = (((address_L1[0] << 8) | (address_L1[1] << 4)) | address_L1[2]);
            break;
        case 3:

            break;
    }
}