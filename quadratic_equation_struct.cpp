#include "quadratic_equation_struct.h"


void set_equation_coeffs( struct quadratic_equation* temporary, const double coeff_a, const double coeff_b, const double coeff_c )
{
    assert( std::isfinite( coeff_a ) );
    assert( std::isfinite( coeff_b ) );
    assert( std::isfinite( coeff_c ) );
    assert( temporary != NULL );

    //printf( "\n adress=%d \n", temporary );


    temporary->coeff_a = coeff_a;
    temporary->coeff_b = coeff_b;
    temporary->coeff_c = coeff_c;
}



void calc_discriminant( struct quadratic_equation* temporary )
{
    assert( temporary != NULL );


    double discriminant = (temporary->coeff_b * temporary->coeff_b) - 4*(temporary->coeff_a * temporary->coeff_c);
    temporary->discriminant = discriminant;
}



void check_solvability( struct quadratic_equation* temporary )
{
    assert( temporary != NULL );


    calc_discriminant( temporary );


    if ( temporary->discriminant > 0 )
        temporary->roots = TWO;
    if ( temporary->discriminant == 0 )
        temporary->roots = ONE;
    if ( temporary->discriminant < 0 )
        temporary->roots = NO_ROOTS;
}



void solve_equation( struct quadratic_equation* temporary )
{
    assert( temporary != NULL );


    if( compare_with_zero( temporary->coeff_a ) )
    {
        solve_linear_equation( temporary );
    }
    else
    {
        check_solvability( temporary );

        if( temporary->roots != NO_ROOTS )
        {
            solve_quadratic_equation( temporary );
        }
    }
}



void input_wipe_char() //очищает входной файл от элементов типа char
{
    while( getchar() != '\n' ) {}
}



void beau_input( double* coeff_a, double* coeff_b, double* coeff_c, bool min_user_info )
{
    assert( coeff_a != NULL );
    assert( coeff_b != NULL );
    assert( coeff_c != NULL );


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

        success_inputs += scanf( "%lf", coeff_a );

        printf( "Введите коэффициент b: \n" );

        success_inputs += scanf( "%lf", coeff_b );

        printf( "Введите коэффициент c: \n" );

        success_inputs += scanf( "%lf", coeff_c );

        input_wipe_char();


        if( success_inputs < 3 )
            printf( "\nОдин или несколько коэффициентов введены неверно, попробуйте ещё раз\n" );
    }
    while( success_inputs < 3 );


    if( min_user_info == false )
    {
        printf( "Введено уравнение %fX^2+%f*X+%f=0 \n \n", coeff_a, coeff_b, coeff_c); // адекватный вывод будет позже

    }
}



void beau_output( struct quadratic_equation* temporary )
{
    assert( temporary != NULL );


    if( temporary->roots == TWO )
    {
        printf( "Корнями уравнения являются числа: \n" );
        printf( "%f\n", temporary->root_1 );
        printf( "%f\n", temporary->root_2 );
    }
    if( temporary->roots == ONE )
    {
        printf( "Уравнение имеет единственный корень: \n" );
        printf( "%f\n", temporary->root_1 );
    }
    if( temporary->roots == NO_ROOTS )
    {
        printf( "Уравнение не имеет корней! \n" ); // так, давайте без этой вашей вузовской программы пока

    }
    if( temporary->roots == INFINITY_ROOTS )
    {
        printf( "Уравнение имеет бесконечное количество корней! \n" );
    }
}



void solve_quadratic_equation( struct quadratic_equation* temporary )
{
        assert( temporary != NULL );


        temporary->root_1 = ( -1* temporary->coeff_b + sqrt( temporary->discriminant ) ) / ( 2* temporary->coeff_a );
        if( temporary->roots == TWO )
            temporary->root_2 = ( -1* temporary->coeff_b - sqrt( temporary->discriminant ) ) / ( 2* temporary->coeff_a );
        else
            temporary->root_2 = temporary->root_1;
}



void solve_linear_equation( struct quadratic_equation* temporary ) //b*X+c=0, b*X=-c, X=-c/b
{
    assert( temporary != NULL );


    if( temporary->coeff_b == 0 )
    {
        if( temporary->coeff_c == 0 )
        {
            temporary->roots = INFINITY_ROOTS;
        }
        else
        {
            temporary->roots = NO_ROOTS;
        }
    }
    else
    {
        temporary->roots = ONE;
        temporary->root_1 = ( -1* temporary->coeff_c ) / temporary->coeff_b;
        temporary->root_2 = temporary->root_2;
    }
}



bool compare_with_zero( double value )
{
    assert( std::isfinite( value ) );


    if( fabs( value ) < DEVIATION_IN_CMP )
        return true;
    else
        return false;
}







