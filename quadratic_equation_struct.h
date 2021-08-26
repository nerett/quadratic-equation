#ifndef QUADRATIC_EQUATION_STRUCT_H_INCLUDED
#define QUADRATIC_EQUATION_STRUCT_H_INCLUDED

enum number_of_roots { TWO, ONE, NO_ROOTS };

struct quadratic_equation
{
    double coeff_a = NAN, coeff_b = NAN, coeff_c = NAN;
    double root_1 = NAN, root_2 = NAN;
    double discriminant = NAN;
    number_of_roots roots = {};
};

void beau_input ( double*, double*, double*, bool );
void beau_output ( struct quadratic_equation* );
void solve_quadratic_equation( struct quadratic_equation* );
void input_wipe_char();
struct quadratic_equation solve_equation( struct quadratic_equation* );
struct quadratic_equation check_solvability( struct quadratic_equation* );
void calc_discriminant( struct quadratic_equation* );
struct quadratic_equation set_equation_coeffs( struct quadratic_equation*, double, double, double );

#endif // QUADRATIC_EQUATION_STRUCT_H_INCLUDED
