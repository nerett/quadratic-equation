#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadratic_equation_struct.h"

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

