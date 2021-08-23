#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int coeff_a = 0, coeff_b = 0, coeff_c = 0; // a*X^2+b*X+c=0


    //setlocale(LC_ALL, "rus");
    printf( "Квадратное уравнение имеет вид " );
    printf( "a*X^2+b*X+c=0 \n" );
    printf( "Введите коэффициент a: \n" );

    scanf( "%d", &coeff_a );

    printf( "Введите коэффициент b: \n" );

    scanf( "%d", &coeff_b );

    printf( "Введите коэффициент c: \n" );

    scanf( "%d", &coeff_c );

    printf( "%s%d%s%d%s%d%s", "Введено уравнение ", coeff_a, "*X^2+", coeff_b, "*X+", coeff_c, "=0 \n" ); // проверки на coeff==1 || coeff==0 будут позже

    return 0;
}
