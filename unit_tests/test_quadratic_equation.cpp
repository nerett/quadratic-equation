#include "test_quadratic_equation.h"


void TEST_quadratic_equation()
{
    int N_errors = 0;


    ///                  test №, coeff_a, coeff_b, coeff_c, expected_N_roots, expected_root_1, expected_root_2
    if( conduct_unit_test( 1,     1,       -2,      -15,     TWO,              5,               -3 ) == false ) N_errors++;
    if( conduct_unit_test( 2,     1,        4,        4,     ONE,             -2,               -2 ) == false ) N_errors++;
    if( conduct_unit_test( 3,     1,       -2,       15,     NO_ROOTS,       NAN,               NAN ) == false ) N_errors++;
    if( conduct_unit_test( 4,     0,        0,        0,     INFINITY_ROOTS, NAN,               NAN ) == false ) N_errors++;
    if( conduct_unit_test( 5,     0,        1,        0,     ONE,              0,               0 ) == false ) N_errors++;          //bX+c=0, bX=-c, X=-c/b;
    if( conduct_unit_test( 6,    16,      -19,        9,     NO_ROOTS,       NAN,               NAN ) == false ) N_errors++;
    if( conduct_unit_test( 7,     4,       -7,        3,     TWO,              1,               0.75 ) == false ) N_errors++;
    if( conduct_unit_test( 8,     8,       -4,       -4,     TWO,              1,               -0.5 ) == false ) N_errors++;


    printf("NUMBER OF ERRORS: %d\n\n", N_errors );
}



bool conduct_unit_test( int test_number, double coeff_a, double coeff_b, double coeff_c, number_of_roots expected_N_roots, double expected_root_1, double expected_root_2 )
{
    printf( "starting test %d...\n", test_number );


    quadratic_equation tested_equation = {};

    set_equation_coeffs( &tested_equation, coeff_a, coeff_b, coeff_c );
    solve_equation( &tested_equation );


    if( ( tested_equation.roots != expected_N_roots ) || ( tested_equation.root_1 != expected_root_1 ) || ( tested_equation.root_2 != expected_root_2 ) )
    {
        if( tested_equation.roots == expected_N_roots )
        {
            if( ( expected_N_roots == NO_ROOTS ) || ( expected_N_roots == INFINITY_ROOTS ) )
            {
                return true;
            }
            else
            {
                if( ( expected_N_roots == ONE ) && ( tested_equation.root_1 == expected_root_1 ) )
                {
                    return true;
                }
            }
        }


        printf("ERROR in test №%d! \n", test_number);
        printf( "N_roots = %d, coeff_a = %g, coeff_b = %g, coeff_c = %g, root_1 = %g, root_2 = %g; \n", tested_equation.roots, tested_equation.coeff_a, tested_equation.coeff_b, tested_equation.coeff_c, tested_equation.root_1, tested_equation.root_2 );
        printf( "EXPECTED: N_roots = %d, root_1 = %g, root_2 = %g!\n", expected_N_roots, expected_root_1, expected_root_2 );

        return false;
    }
    else
        return true;
}



//void display_error_message(  );
