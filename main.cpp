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

//struct quadratic_equation bea_input ( struct quadratic_equation );
//void bea_output ( struct quadratic_equation );
struct quadratic_equation solve_equation( struct quadratic_equation* );
struct quadratic_equation check_solvability( struct quadratic_equation* );
double calc_discriminant( struct quadratic_equation* );
struct quadratic_equation set_equation_coeffs( struct quadratic_equation*, double, double, double );

int main()
{
    double coeff_a = NAN, coeff_b = NAN, coeff_c = NAN; // a*X^2+b*X+c=0
    quadratic_equation equation;


    //setlocale(LC_ALL, "rus");
    printf( "Квадратное уравнение имеет вид " );
    printf( "a*X^2+b*X+c=0 \n" );
    printf( "Введите коэффициент a: \n" );

    scanf( "%lf", &coeff_a ); //проверка присваиванием

    printf( "Введите коэффициент b: \n" );

    scanf( "%lf", &coeff_b );

    printf( "Введите коэффициент c: \n" );

    scanf( "%lf", &coeff_c );

    printf( "Введено уравнение %fX^2+%f*X+%f=0 \n \n", coeff_a, coeff_b, coeff_c); // адекватный вывод будет позже


    set_equation_coeffs( &equation, coeff_a, coeff_b, coeff_c );
    solve_equation( &equation );


    if ( equation.is_solvable == YES )
    {
        printf( "Корнями уравнения являются числа: \n" );
        printf( "%f%s", equation.root_1, "\n" );
        printf( "%f%s", equation.root_2, "\n" );

    }
    else
        printf( "Уравнение не имеет корней! \n" ); // так, давайте без этой вашей вузовской программы пока

/*
    switch( equation.is_solvable )
    {
        case YES:
                printf( "%f%s", equation.root_1, "\n" );
                printf( "%f%s", equation.root_2, "\n" );
        case NO:
                printf( "Уравнение не имеет корней! \n" );
        case NODATA:
                printf( "Уравнение не было решено! \n" );
    }
*/

     return 0;
}

// quadratic_equation

struct quadratic_equation set_equation_coeffs( struct quadratic_equation* temporary ,double coeff_a, double coeff_b, double coeff_c ) //написат ассерты
{
    temporary->coeff_a = coeff_a;
    temporary->coeff_b = coeff_b;
    temporary->coeff_c = coeff_c;
}

double calc_discriminant( struct quadratic_equation* temporary ) //написать сравнение с нулём нормально, fabs compare_with_zero
{
    double discriminant = (temporary->coeff_b * temporary->coeff_b) - 4*(temporary->coeff_a * temporary->coeff_c);
    return discriminant;
}

struct quadratic_equation check_solvability( struct quadratic_equation* temporary )
{
    double discriminant = calc_discriminant( temporary );

    if ( discriminant >= 0 )
        temporary->is_solvable = YES;
    else
        temporary->is_solvable = NO;
}

struct quadratic_equation solve_equation( struct quadratic_equation* temporary ) //частные случаи линейное квадратное
{
    double discriminant = calc_discriminant( temporary );
    check_solvability( temporary );

    if( temporary->is_solvable == YES )
    {
        temporary->root_1 = ( -1* temporary->coeff_b + sqrt(discriminant) ) / ( 2* temporary->coeff_a );
        temporary->root_2 = ( -1* temporary->coeff_b - sqrt(discriminant) ) / ( 2* temporary->coeff_a );
    }
}
