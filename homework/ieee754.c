#include <stdio.h>

char *reverseBit(char bit[], int size){
    int i = 0;
    while(i < size){
        char temp = bit[i];
        bit[i++] = bit[size];
        bit[size--] = temp;
    }
    return bit;
}

char *base2FromInt(int integer, char bin[]){
    int i = 0;
    while(integer > 0){
        bin[i] = (integer % 2) + '0';
        integer /= 2;
        i++;
    }
    bin[i] = '\0';
    return reverseBit(bin, --i);
}

char *base2FromFrac(double fraction, char bin[]){
    int i = 0;
    while(fraction - (int)fraction > 0.00 && i < 64){
        (fraction > 1.00) ? fraction -= 1 : fraction;
        bin[i] = (int)(fraction * 2) + '0';
        fraction *= 2;
        i++;
    }
    bin[i] = '\0';
    return bin;
}

void convertToIEEE754(double decimal){
    int intPart = (int) decimal;
    double fracPart = decimal - intPart;
    char binInt[64];
    char binFrac[64];
    char *intBase2 = base2FromInt(intPart, binInt);
    char *fracBase2 = base2FromFrac(fracPart, binFrac);
    printf("%s.%s",intBase2, fracBase2);
}

int main(){

    double decimal = 45.354;
    convertToIEEE754(decimal);
    return 0;
}