#ifndef TEST_QUADRATIC_EQUATION_H_INCLUDED
#define TEST_QUADRATIC_EQUATION_H_INCLUDED

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../quadratic_equation_struct.h" //!TODO -I <include_path>


void test_quadratic_equation(); ///<Starts equation solver testing
bool conduct_unit_test( int, double, double, double, number_of_roots, double, double ); ///<Starts test with given data
static void display_error_message( int test_number, struct QuadraticEquation* tested_equation, number_of_roots expected_N_roots, double expected_root_1, double expected_root_2 ); ///<Displays error message wit all necessary information


#endif // TEST_QUADRATIC_EQUATION_H_INCLUDED
