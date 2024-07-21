#include <stdio.h>

int TamanhoString(char str[]);
int ConferePlacaAntiga(char placa[]);
int ConferePlacaNova(char placa[]);
int EhLetra(char c);
int EhNumero(char c);


char placa[10];

int main() {
    scanf("%[A-Z0-9-]", placa);

    if (TamanhoString(placa) > 8 || TamanhoString(placa) < 7){
        printf("0");
        return 0;
    }
    if(TamanhoString(placa) == 8){
        printf("%d", ConferePlacaAntiga(placa));
        return 0;
    }

    printf("%d", ConferePlacaNova(placa));

    return 0;
}

int TamanhoString(char str[]) {
    int i = 0;
    while(placa[i]) {
        i++;
    }
    return i;
}

int ConferePlacaAntiga(char placa[]) {
    if (EhLetra(placa[0]))
        if(EhLetra(placa[1]))
            if (EhLetra(placa[2]))
                if (placa[3] == '-')
                    if(EhNumero(placa[4]))
                        if(EhNumero(placa[5]))
                            if(EhNumero(placa[6]))
                                if(EhNumero(placa[7]))
                                    return 1;
    
    return 0;
}

int ConferePlacaNova(char placa[]){
    if (EhLetra(placa[0]))
        if(EhLetra(placa[1]))
            if (EhLetra(placa[2]))
                if (EhNumero(placa[3]))
                    if(EhLetra(placa[4]))
                        if(EhNumero(placa[5]))
                            if(EhNumero(placa[6]))
                                return 2;
    
    return 0;
}

int EhLetra(char c) {
    return (c <= 'Z' && c >= 'A');
}
int EhNumero(char c) {
    return (c <= '9' && c >= '0');
}
