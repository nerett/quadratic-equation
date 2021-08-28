#ifndef QUADRATIC_EQUATION_STRUCT_H_INCLUDED
#define QUADRATIC_EQUATION_STRUCT_H_INCLUDED

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static const double DEVIATION_IN_CMP = 0.001;
static const int NUMBER_OF_COEFFS = 3;

enum number_of_roots { NO_ROOTS, ONE, TWO, INFINITY_ROOTS };


struct QuadraticEquation ///<Quadratic/linear equation structure (contains coefficients, discriminant, number of roots and roots)
{
    double coeff_a = NAN, coeff_b = NAN, coeff_c = NAN;
    double root_1 = NAN, root_2 = NAN;
    double discriminant = NAN;
    number_of_roots roots = {};
};


void beau_input( double* coeff_a, double* coeff_b, double* coeff_c, bool minimize_user_info ); ///<Coefficients input with user interface and two interface layout options (minimal and standart)
void beau_output( struct QuadraticEquation* equation ); ///<Roots output with user interface

void check_solvability( struct QuadraticEquation* equation ); ///<Checks if equation is solvable and puts information about roots number into struct QuadraticEquation
void calc_discriminant( struct QuadraticEquation* equation ); ///<Calculates discriminant square and puts it into struct QuadraticEquation

void set_equation_coeffs( struct QuadraticEquation* equation, const double coeff_a, const double coeff_b, const double coeff_c ); ///<Sets equation coefficients in struct QuadraticEquation
void solve_equation( struct QuadraticEquation* equation ); ///<Determines the type of equation and solves it (roots are put into struct QuadraticEquation)
static void solve_quadratic_equation( struct QuadraticEquation* equation );///<Solves quadratic equation (roots are put into struct QuadraticEquation)
static void solve_linear_equation( struct QuadraticEquation* equation );///<Solves linear equation (roots are put into struct QuadraticEquation)

void input_wipe_char();///<Wipes char elements from input file (useful when char is entered by mistake)
bool compare_with_zero( double );///<Compares this double value with zero and returns true if value tends to zero
//начало функций с префикса

#endif // QUADRATIC_EQUATION_STRUCT_H_INCLUDED
