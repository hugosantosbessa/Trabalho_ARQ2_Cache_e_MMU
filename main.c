#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

unsigned int memory_cache[255];
unsigned int first_address[255];
unsigned int last_address[255];
unsigned int hit_count[255];
unsigned int miss_count[255];


int main(){

    FILE *file;
    char url[] = "memoria.txt";
    char frase[50]; //buffer da linha
    char buffer[8]; //buffer do endereço
    
    file = fopen("memoria.txt", "r"); //lendo o arquivo memoria.txt
    if(file == NULL){
        printf("Nao e possivel abrir o arquivo: 1");
        getchar();
        exit(0);
    }
    
    FILE *file_2;
    char url_2[] = "input.txt";
    file_2 = fopen(url_2, "r"); //lendo o arquivo L1.txt
    
    char frase_2[50];
    if(file_2 == NULL){
        printf("Nao e possivel abrir o arquivo: 2");
        getchar();
        exit(0);
    }

    char address_L1[8]; //endereço da tabela L1
    while (fgets(frase, sizeof(frase), file) != NULL){
        Copia_conteudo(frase, buffer);
        ConvertChar(buffer);
        int PTE_L1 = 0;
        PTE_L1 = (((buffer[0] << 8) | (buffer[1] << 4)) | buffer[2]);
        int i = 0;
        while (fgets(frase_2, sizeof(frase_2), file_2) != NULL){
            if(i == PTE_L1){
                Copia_conteudo(frase_2, address_L1);
                ConvertChar(address_L1);
                Decodifica(buffer, address_L1, memory_cache, first_address, last_address, hit_count, miss_count);
            }
            i++;
         }
        
    }
    fclose(file);
    fclose(file_2); //fechando o arquivo 
    
    return 0;
}