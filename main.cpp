#include "quadratic_equation_struct.h"

int main()
{
    double coeff_a = NAN, coeff_b = NAN, coeff_c = NAN; // a*X^2+b*X+c=0
    quadratic_equation equation = {};


    beau_input( &coeff_a, &coeff_b, &coeff_c, false );


    set_equation_coeffs( &equation, coeff_a, coeff_b, coeff_c );
    solve_equation( &equation );


    beau_output( &equation );

     return 0;
}

