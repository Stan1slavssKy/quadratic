#include <stdio.h>
#include <math.h>

#define  INACCURACY 1E-6
#define ZERO 0

int is_equal(double value, double number);
int Input();
void SolveLinear (double a, double b, double c);
void SolveQuadratic (double a, double b, double c);

int main(){

    Input();

    return 0;

}

int is_equal (double value, double number){

    return (fabs (value - number) <= INACCURACY);

}

int Input(){

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    printf ("Welcome to the master of solving quadratic equations\n"
            "Enter the values of the three coefficients: \n");

    while (scanf("%lf%lf%lf", &a, &b, &c) != 3){

        printf ("Incorrect data entered, please double-check and re-enter\n");

        fflush (stdin);

    }

    SolveLinear (a, b, c);

}

void SolveLinear (double a, double b, double c){

    double x = 0;

    if (is_equal(a, ZERO) && is_equal(b, ZERO) && is_equal(c, ZERO)){

        printf ("The equation has an infinite number of roots\n");

    }

    else if (is_equal (a, ZERO) && is_equal (b, ZERO) && !is_equal (c, ZERO)){

        printf ("The equation has no roots\n");

    }

    else if (is_equal (a, ZERO) && !is_equal (b, ZERO) && is_equal (c, ZERO)){

        printf ("The equation one root: x = 0");

    }

    else if (is_equal(a, ZERO) && !is_equal(b, ZERO) && !is_equal(c, ZERO)){

        printf ("You need to solve %lf * x + %lf = 0\n", b, c);
        x = -c / b;
        printf ("The equation has one root: x = %lf", x);

    }

    else if (!is_equal (a, ZERO)){

        SolveQuadratic (a, b, c);

    }

}

void SolveQuadratic (double a, double b, double c){

    if (is_equal (b, ZERO) && is_equal (c, ZERO)){

        printf ("The equation one root: x = 0");

    }

    else if (!is_equal (b, ZERO) && is_equal (c, ZERO)){

        printf ("You need to solve %lf * x^2 + %lf * x = 0\n", a, b); //axx+bx=0  x(ax + b) = 0  x = 0  x = -b/a
        printf ("The equation has 2 roots: x = 0 and x = %lf\n", -b / a);

    }

    else if(is_equal (b, ZERO) && !is_equal (c, ZERO)){

        printf ("You need to solve %lf * x^2 + %lf = 0\n", a, c); //axx+c=0    axx= -c  xx= -c/a

        if(c < 0){

            printf ("First equal %lf, second %lf\n", fabs(sqrt(-c / a)), -fabs(sqrt(-c / a)));

        }

        else if(c > 0){

            printf("The equation has no roots\n");

        }

    }

    else if (!is_equal (b, ZERO) && !is_equal (c, ZERO)){

        double x1 = 0, x2 = 0, Discriminant = 0;

        Discriminant = b * b - 4 * a * c;

        if (Discriminant < ZERO){

            printf("The equation has no roots\n");

        }

        else if (is_equal (Discriminant, ZERO)){

            printf ("The equation has one root: %lf", (-b) / (2 * a));

        }

        else if (Discriminant > ZERO){

            printf ("You need to solve: %lf * x^2 + %lf * x + %lf = 0\n", a, b, c);

            x1 = (-b + sqrt(Discriminant)) / (2 * a);

            x2 = (-b - sqrt(Discriminant)) / (2 * a);

            printf ("The equation has 2 roots: x = %lf and x = %lf", x1, x2);

        }

    }

}
