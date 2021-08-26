#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "quadratic_equation.h"

enum boolean { YES, NO, NODATA };

struct quadratic_equation
{
    double coeff_a, coeff_b, coeff_c;
    double root_1, root_2;
    boolean is_solvable = NODATA;
};

void beau_input ( double*, double*, double*, bool );
void beau_output ( struct quadratic_equation* );
void input_wipe_char();
struct quadratic_equation solve_equation( struct quadratic_equation* );
struct quadratic_equation check_solvability( struct quadratic_equation* );
double calc_discriminant( struct quadratic_equation* );
struct quadratic_equation set_equation_coeffs( struct quadratic_equation*, double, double, double );

int main()
{
    double coeff_a = NAN, coeff_b = NAN, coeff_c = NAN; // a*X^2+b*X+c=0
    quadratic_equation equation = {};


    beau_input( &coeff_a, &coeff_b, &coeff_c, false );


    set_equation_coeffs( &equation, coeff_a, coeff_b, coeff_c );
    solve_equation( &equation );

    beau_output( &equation );
/*
    switch( equation.is_solvable )
    {
        case YES:
                printf( "%f%s", equation.root_1, "\n" );
                printf( "%f%s", equation.root_2, "\n" );X+-
        case NO:
                printf( "Уравнение не имеет корней! \n" );
        case NODATA:
                printf( "Уравнение не было решено! \n" );
    }
*/

     return 0;
}

// quadratic_equation

struct quadratic_equation set_equation_coeffs( struct quadratic_equation* temporary, const double coeff_a, double coeff_b, double coeff_c ) //!TODO написать ассерты сделать const
{
    temporary->coeff_a = coeff_a;
    temporary->coeff_b = coeff_b;
    temporary->coeff_c = coeff_c;
}

double calc_discriminant( struct quadratic_equation* temporary ) //!TODO написать сравнение с нулём нормально, fabs compare_with_zero
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

struct quadratic_equation solve_equation( struct quadratic_equation* temporary ) //!TODO частные случаи линейное квадратное
{
    double discriminant = calc_discriminant( temporary );
    check_solvability( temporary );

    if( temporary->is_solvable == YES )
    {
        temporary->root_1 = ( -1* temporary->coeff_b + sqrt( discriminant ) ) / ( 2* temporary->coeff_a ); //!TODO вынести во временную переменную
        temporary->root_2 = ( -1* temporary->coeff_b - sqrt( discriminant ) ) / ( 2* temporary->coeff_a );
    }
}

void input_wipe_char() //очищает входной файл от элементов типа char
{
    while( getchar() != '\n' ) {}
}

void beau_input( double* coeff_a, double* coeff_b, double* coeff_c, bool min_user_info )
{
    int success_inputs = NAN;


    //setlocale(LC_ALL, "rus");
    if( min_user_info == false )
    {
        printf( "Квадратное уравнение имеет вид " );
        printf( "a*X^2+b*X+c=0 \n" );
    }


    do
    {
        success_inputs = 0;


        printf( "Введите коэффициент a: \n" );

        success_inputs += scanf( "%lf", &coeff_a );

        printf( "Введите коэффициент b: \n" );

        success_inputs += scanf( "%lf", &coeff_b );

        printf( "Введите коэффициент c: \n" );

        success_inputs += scanf( "%lf", &coeff_c );

        input_wipe_char();


        if( success_inputs < 3 )
            printf( "Один или несколько коэффициентов введены неверно, попробуйте ещё раз\n" );
    }
    while( success_inputs < 3 );


    if( min_user_info == false )
    {
        printf( "Введено уравнение %fX^2+%f*X+%f=0 \n \n", coeff_a, coeff_b, coeff_c); // адекватный вывод будет позже

    }
}

void beau_output( struct quadratic_equation* temporary )
{
    if ( temporary->is_solvable == YES )      //!TODO enum для колва корней
    {
        printf( "Корнями уравнения являются числа: \n" );
        printf( "%f\n", temporary->root_1 );
        printf( "%f\n", temporary->root_2 );

    }
    else
        printf( "Уравнение не имеет корней! \n" ); // так, давайте без этой вашей вузовской программы пока

}


