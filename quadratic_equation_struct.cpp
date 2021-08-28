#include "quadratic_equation_struct.h"


void set_equation_coeffs( struct QuadraticEquation* equation, const double coeff_a, const double coeff_b, const double coeff_c )
{
    assert( equation != NULL );
    assert( std::isfinite( coeff_a ) );
    assert( std::isfinite( coeff_b ) );
    assert( std::isfinite( coeff_c ) );


    //printf( "\n adress=%d \n", equation );
    equation->coeff_a = coeff_a;
    equation->coeff_b = coeff_b;
    equation->coeff_c = coeff_c;
}



void calc_discriminant( struct QuadraticEquation* equation )
{
    assert( equation != NULL );
    assert( std::isfinite( equation->coeff_a ) );
    assert( std::isfinite( equation->coeff_b ) );
    assert( std::isfinite( equation->coeff_c ) );


    double discriminant = (equation->coeff_b * equation->coeff_b) - 4 * (equation->coeff_a * equation->coeff_c);
    assert( std::isfinite( discriminant ) ); //защита от переполнения
    equation->discriminant = discriminant;
}



void check_solvability( struct QuadraticEquation* equation )
{
    assert( equation != NULL );
    assert( std::isfinite( equation->coeff_a ) );
    assert( std::isfinite( equation->coeff_b ) );
    assert( std::isfinite( equation->coeff_c ) );


    calc_discriminant( equation );

    if ( equation->discriminant > 0 )
        equation->roots = TWO;
    if ( compare_with_zero( equation->discriminant ) )
        equation->roots = ONE;
    if ( equation->discriminant < 0 )
        equation->roots = NO_ROOTS;
}



void solve_equation( struct QuadraticEquation* equation )
{
    assert( equation != NULL );


    if( compare_with_zero( equation->coeff_a ) )
    {
        solve_linear_equation( equation );
    }
    else
    {
        check_solvability( equation );

        if( equation->roots != NO_ROOTS )
        {
            solve_quadratic_equation( equation );
        }
    }
}



void input_wipe_char() //очищает входной файл от элементов типа char
{
    while( getchar() != ( '\n' ) ) {}
}



void beau_input( double* coeff_a, double* coeff_b, double* coeff_c, bool minimize_user_info )
{
    assert( coeff_a != NULL );
    assert( coeff_b != NULL );
    assert( coeff_c != NULL );


    int success_inputs = NAN;


    //setlocale(LC_ALL, "rus");
    if( minimize_user_info == false )
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


        if( success_inputs < NUMBER_OF_COEFFS )
            printf( "\nОдин или несколько коэффициентов введены неверно, попробуйте ещё раз\n" );
    }
    while( success_inputs < NUMBER_OF_COEFFS );


    if( minimize_user_info == false )
    {
        printf( "Введено уравнение %gX^2+%g*X+%g=0 \n \n", *coeff_a, *coeff_b, *coeff_c); // адекватный вывод будет позже

    }
}



void beau_output( struct QuadraticEquation* equation )
{
    assert( equation != NULL );


    switch( equation->roots )
    {
        case NO_ROOTS: printf( "Уравнение не имеет корней! \n" );                                                       break;
        case ONE: printf( "Уравнение имеет единственный корень: \n%f\n", equation->root_1 );                            break;
        case TWO: printf( "Корнями уравнения являются числа: \n%f\n%f\n", equation->root_1, equation->root_2 );         break;
        case INFINITY_ROOTS: printf( "Уравнение имеет бесконечное количество корней! \n" );                             break;
        default:                                                                                                        break;
    }

/*
    if( equation->roots == TWO ) //switch
    {
        printf( "Корнями уравнения являются числа: \n" );
        printf( "%f\n", equation->root_1 );
        printf( "%f\n", equation->root_2 );
    }
    if( equation->roots == ONE )
    {
        printf( "Уравнение имеет единственный корень: \n" );
        printf( "%f\n", equation->root_1 );
    }
    if( equation->roots == NO_ROOTS )
    {
        printf( "Уравнение не имеет корней! \n" ); // так, давайте без этой вашей вузовской программы пока

    }
    if( equation->roots == INFINITY_ROOTS )
    {
        printf( "Уравнение имеет бесконечное количество корней! \n" );
    }
    */
}



static void solve_quadratic_equation( struct QuadraticEquation* equation )
{
        assert( equation != NULL );
        assert( std::isfinite( equation->coeff_a ) );
        assert( std::isfinite( equation->coeff_b ) );
        assert( std::isfinite( equation->coeff_c ) );
        assert( std::isfinite( equation->discriminant ) );


        equation->root_1 = ( -1 * equation->coeff_b + sqrt( equation->discriminant ) ) / ( 2 * equation->coeff_a );
        if( equation->roots == TWO )
        {
            equation->root_2 = ( -1 * equation->coeff_b - sqrt( equation->discriminant ) ) / ( 2 * equation->coeff_a );
        }
        else
        {
            equation->root_2 = equation->root_1;
        }
}



static void solve_linear_equation( struct QuadraticEquation* equation ) //b*X+c=0, b*X=-c, X=-c/b
{
    assert( equation != NULL );
    assert( std::isfinite( equation->coeff_a ) );
    assert( std::isfinite( equation->coeff_b ) );
    assert( std::isfinite( equation->coeff_c ) );


    if( compare_with_zero( equation->coeff_b ) )
    {
        if( equation->coeff_c == 0 )
        {
            equation->roots = INFINITY_ROOTS;
        }
        else
        {
            equation->roots = NO_ROOTS;
        }
    }
    else
    {
        equation->roots = ONE;
        equation->root_1 = ( -1* equation->coeff_c ) / equation->coeff_b;
        equation->root_2 = equation->root_1;
    }
}



bool compare_with_zero( double value ) //!TODO is_equal(double a, double b);
{
    assert( std::isfinite( value ) );


    return ( fabs( value ) < DEVIATION_IN_CMP );
}
