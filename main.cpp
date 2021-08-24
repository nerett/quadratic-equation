#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "quadratic_equation.h"

enum boolean { YES, NO, NODATA };

struct quadratic_equation {

    double coeff_a, coeff_b, coeff_c;
    double root_1, root_2;
    boolean is_solvable = NODATA;
};

struct quadratic_equation create_equation ( double coeff_a, double coeff_b, double coeff_c )
{
    struct quadratic_equation temporary;

    temporary.coeff_a = coeff_a;
    temporary.coeff_b = coeff_b;
    temporary.coeff_c = coeff_c;

    return temporary;
}

double calc_discriminant ( struct quadratic_equation temporary )
{
    double discriminant = (temporary.coeff_b * temporary.coeff_b) - 4*(temporary.coeff_a * temporary.coeff_c);
    return discriminant;
}

struct quadratic_equation check_solvability ( struct quadratic_equation temporary )
{
    double discriminant = calc_discriminant( temporary );

    if ( discriminant >= 0 )
        temporary.is_solvable = YES;
    else
        temporary.is_solvable = NO;

    return temporary;
}

struct quadratic_equation solve_equation ( struct quadratic_equation temporary )
{
    double discriminant = calc_discriminant( temporary );
    temporary = check_solvability( temporary );

    if( temporary.is_solvable == YES )
    {
        temporary.root_1 = ( -1* temporary.coeff_b + sqrt(discriminant) ) / ( 2* temporary.coeff_a );
        temporary.root_2 = ( -1* temporary.coeff_b - sqrt(discriminant) ) / ( 2* temporary.coeff_a );
    }

    return temporary;
}

int main()
{
    double coeff_a = 1, coeff_b = 1, coeff_c = 1; // a*X^2+b*X+c=0
    struct quadratic_equation equation;

    //setlocale(LC_ALL, "rus");
    printf( "Квадратное уравнение имеет вид " );
    printf( "a*X^2+b*X+c=0 \n" );
    printf( "Введите коэффициент a: \n" );

    scanf( "%lf", &coeff_a );

    printf( "Введите коэффициент b: \n" );

    scanf( "%lf", &coeff_b );

    printf( "Введите коэффициент c: \n" );

    scanf( "%lf", &coeff_c );

    printf( "%s%f%s%f%s%f%s", "Введено уравнение ", coeff_a, "*X^2+", coeff_b, "*X+", coeff_c, "=0 \n \n" ); // адекватный вывод будет позже

    equation = create_equation( coeff_a, coeff_b, coeff_c );
    equation = solve_equation( equation );

    if ( equation.is_solvable == YES )
    {
        printf( "Корнями уравнения являются числа: \n" );
        printf( "%f%s", equation.root_1, "\n" );
        printf( "%f%s", equation.root_2, "\n" );

    }
    else
        printf( "Уравнение не имеет корней! \n" ); // так, давайте без этой вашей вузовской программы пока

     return 0;
}
