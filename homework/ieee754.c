#include <stdio.h>

char *base2FromInt(int integer){
    return "Hello Wrold";
}

char *base2FromFrac(double fraction){

    return "Hello World";
}

void convertToIEEE754(double decimal){
    int intPart = (int) decimal;
    double fracPart = decimal - intPart;

    char *intBase2 = base2FromInt(intPart);
    char *fracBase2 = base2FromFrac(fracPart);
}

int main(){

    double decimal;
    scanf("%lf", &decimal);

    convertToIEEE754(decimal);


    return 0;
}