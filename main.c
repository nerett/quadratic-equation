#include <stdio.h>
#include <stdlib.h>
//#include "quadratic_equation.h"
/*
struct quadratic_equation {

    long double coeff_a, coeff_b, coeff_c;
    long double root_1, root_2;
    //equation_type type;

};

struct quadratic_equation create_equation ( long double coeff_a, long double coeff_b, long double coeff_c )
{
    struct quadratic_equation temporary;

    temporary.coeff_a = coeff_a;
    temporary.coeff_b = coeff_b;
    temporary.coeff_c = coeff_c;

    return temporary;
}
*/
int main()
{
    double coeff_a = 1, coeff_b = 1, coeff_c = 1; // a*X^2+b*X+c=0
    //struct quadratic_equation equation;

    //setlocale(LC_ALL, "rus");
    printf( "Квадратное уравнение имеет вид " );
    printf( "a*X^2+b*X+c=0 \n" );
    printf( "Введите коэффициент a: \n" );

    scanf( "%lf", &coeff_a );

    printf( "Введите коэффициент b: \n" );

    scanf( "%lf", &coeff_b );

    printf( "Введите коэффициент c: \n" );

    scanf( "%lf", &coeff_c );

    printf( "%s%f%s%f%s%f%s", "Введено уравнение ", coeff_a, "*X^2+", coeff_b, "*X+", coeff_c, "=0 \n" ); // адекватный вывод будет позже

    //equation = create_equation( coeff_a, coeff_b, coeff_c );

    return 0;
}
