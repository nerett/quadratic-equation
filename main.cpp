#include "quadratic_equation_struct.h"
#include "unit_tests/test_quadratic_equation.h"

#define TEST


int main()
{
#ifdef TEST

    test_quadratic_equation();

#endif
#ifndef TEST


    double coeff_a = NAN, coeff_b = NAN, coeff_c = NAN; // a*X^2+b*X+c=0
    quadratic_equation equation = {};


    printf( "Quadratic equation solving program\nby nerett\n(c) 2021\n\n" );


    beau_input( &coeff_a, &coeff_b, &coeff_c, false );

    set_equation_coeffs( &equation, coeff_a, coeff_b, coeff_c );
    solve_equation( &equation );

    beau_output( &equation );


#endif

     return 0;
}

