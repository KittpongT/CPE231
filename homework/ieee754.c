#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ieee754
{
    char sign;
    char *expo;
    char mantis[52];
}ieee754_T;


char *reverseBit(char bit[], int size){
    int i = 0;
    while(i < size){
        char temp = bit[i];
        bit[i++] = bit[size];
        bit[size--] = temp;
    }
    return bit;
}

char *base2FromInt(int integer, char bin[],int mode){
    int i = 0;
    while(integer > 0){
        bin[i] = (integer % 2) + '0';
        integer /= 2;
        i++;
    }
    if(mode == 1 && i < 12){
        for(int j = i; j < 11 ; j++){
            bin[j] = '0';
        }
        i = 11;
    }
    bin[i] = '\0';
    return reverseBit(bin, --i);
}

char *base2FromFrac(double fraction, char bin[]){
    int i = 0;
    while(fraction - (int)fraction > 0.00 && i < 52){
        (fraction > 1.00) ? fraction -= 1 : fraction;
        bin[i] = (int)(fraction * 2) + '0';
        fraction *= 2;
        
        i++;
    }
    int j;
    for(j = i; j < 53 ; j++){
        bin[j] = '0';
    }

    bin[j] = '\0';
    return bin;
}

ieee754_T convertToIEEE754(double decimal){
    ieee754_T bitDouble;
    bitDouble.sign = (decimal < 0.00) ?  '1' : '0';
    decimal = (decimal < 0.00) ? decimal * -1 : decimal;

    int intPart = (int) decimal;
    double fracPart = decimal - intPart;

    char *binInt = (char*) malloc(sizeof(char)*52);
    char *intBase2 = base2FromInt(intPart, binInt,0);

    char *expo = (char*) malloc(sizeof(char)*12);
    bitDouble.expo = base2FromInt((int)(strlen(intBase2)+1022), expo,1);
    

    char *binFrac = (char*) malloc(sizeof(char)*52);
    char *fracBase2 = base2FromFrac(fracPart, binFrac);

    for(int i = 0; i < 52; i++){
        if(i < ((int)strlen(intBase2))-1){
            bitDouble.mantis[i] = intBase2[i+1];
        }else{
            bitDouble.mantis[i] = fracBase2[i-(int)strlen(intBase2)+1];
        }
            
        
    }
    return bitDouble;
}
int main(){

    double decimal;
    printf("__________________________________________________________________\n");
    printf("\tEnter real number :");
    scanf("%lf", &decimal);
    ieee754_T test = convertToIEEE754(decimal);

    printf("%c %s %s\n",test.sign, test.expo, test.mantis);
    printf("__________________________________________________________________\n");
    return 0;
}