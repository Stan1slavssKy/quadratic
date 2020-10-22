#include <stdio.h>
#include <math.h>

#define INACCURACY 1E-6
#define ZERO 0

enum {

     INF_ROOTS = -2,
     NO_ROOTS  = -1,
     ONE_ROOT   = 1,
     TWO_ROOTS  = 2,

};

void unit_tests ();
int is_equal (double value, double number);
void Input (double* a, double* b, double* c);
void Output (double x1, double x2, int number_of_roots);
int SolveLinear (double b, double c, double* x1);
int SolveQuadratic (double a, double b, double c, double* x1, double* x2);

//---------------------------------------------------------------------------------------

int main(){

    unit_tests ();

    int number_of_roots = 0;

    double a =  0, b  = 0, c = 0;
    double x1 = 0, x2 = 0;

    Input (&a, &b, &c);

    if (is_equal (a, ZERO)){

        number_of_roots = SolveLinear(b, c, &x1);

    }

    else if (!is_equal (a, ZERO)){

        number_of_roots = SolveQuadratic (a, b, c, &x1, &x2);

    }

    Output (x1, x2, number_of_roots);

    return 0;

}

//---------------------------------------------------------------------------------------

int is_equal (double value, double number){

    return (fabs (value - number) <= INACCURACY);

}

//---------------------------------------------------------------------------------------

void Input (double* a, double* b, double* c){

    printf ("Welcome to the master of solving quadratic equations.\n"
            "Enter the values of the three coefficients: \n");

    while (scanf("%lf%lf%lf", a, b, c) != 3){

        printf ("Incorrect data entered, please double-check and re-enter\n");

        fflush (stdin);

    }

}

//---------------------------------------------------------------------------------------

void Output (double x1, double x2, int number_of_roots){

    switch (number_of_roots){

        case INF_ROOTS:
            printf ("The equation has an infinite number of roots\n");
            break;

        case NO_ROOTS:
            printf ("The equation has no roots\n");
            break;


        case ONE_ROOT:
            printf ("The equation has one root: x = %lf", x1);
            break;

        case 2:
            printf ("The equation has 2 roots: x1 = %lf and x2 = %lf\n", x1, x2);
            break;

        default:
            printf ("Error");
            break;

    }

}

//---------------------------------------------------------------------------------------

int SolveLinear (double b, double c, double* x1){

if (is_equal (b, ZERO) && is_equal (c, ZERO)){

        return INF_ROOTS;

    }

    else if (is_equal (b, ZERO) && !is_equal (c, ZERO)){

        return NO_ROOTS;

    }

    else if (!is_equal (b, ZERO) && is_equal (c, ZERO)){

        *x1 = 0;
        return ONE_ROOT;

    }

    else if (!is_equal (b, ZERO) && !is_equal (c, ZERO)){

        printf ("You need to solve %lf * x + %lf = 0\n", b, c);
        *x1 = -c / b;
        return ONE_ROOT;

    }

    return 0;

}

//---------------------------------------------------------------------------------------

int SolveQuadratic (double a, double b, double c, double* x1, double* x2){

    if (is_equal (b, ZERO) && is_equal (c, ZERO)){

        *x1 = 0;
        return ONE_ROOT;

    }

    else if (!is_equal (b, ZERO) && is_equal (c, ZERO)){

        printf ("You need to solve %lf * x^2 + %lf * x = 0\n", a, b);
        *x1 = 0;
        *x2 = -b / a;
        return TWO_ROOTS;

    }

    else if (is_equal (b, ZERO) && !is_equal (c, ZERO)){

        printf ("You need to solve %lf * x^2 + %lf = 0\n", a, c);

        if(c < 0){

            double sqr = sqrt(-c / a);

            *x1 =  fabs (sqr);
            *x2 = -fabs (sqr);

            return TWO_ROOTS;

        }

        else if (c > 0){

            return NO_ROOTS;

        }

    }

    else if (!is_equal (b, ZERO) && !is_equal (c, ZERO)){

        double Discriminant = 0;

        Discriminant = b * b - 4 * a * c;

        if (Discriminant < ZERO){

            return NO_ROOTS;

        }

        else if (is_equal (Discriminant, ZERO)){

            *x1 = (-b) / (2 * a);
            return ONE_ROOT;

        }

        else if (Discriminant > ZERO){

            printf ("You need to solve: %lf * x^2 + %lf * x + %lf = 0\n", a, b, c);

            double sqr_D = sqrt(Discriminant);

            *x1 = (-b + sqr_D) / (2 * a);
            *x2 = (-b - sqr_D) / (2 * a);

            return TWO_ROOTS;

        }

    }

    return 0;

}

//---------------------------------------------------------------------------------------

void unit_tests (){

    printf ("Testing SolveQuadratic...\n");

	double coeffs_Q[] = {2, -1, -6};
	double ans_Q[]    = {2, -1.5};

	double x1 = 0;
	double x2 = 0;
	double x  = 0;

	SolveQuadratic (coeffs_Q[0], coeffs_Q[1], coeffs_Q[2], &x1, &x2);

	if (x1 != ans_Q[0] || x2 != ans_Q[1]) {

		printf("Test 1 failed");

	}

	else {

	    printf("Test 1 passed successfully!\n\n");

    }

    printf ("Testing SolveLinear...\n");

    double coeffs_L[] = {0.2, 3};
    double ans_L[]    = {-15};

    SolveLinear (coeffs_L[0], coeffs_L[1], &x);

    if (x != ans_L[0]) {

        printf ("Test 2 failed");

    }

    else {

        printf("Test 2 passed successfully!\n\n");

    }

}
