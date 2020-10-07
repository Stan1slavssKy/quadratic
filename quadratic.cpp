#include <stdio.h>
#include <math.h>

int Input();
void SolveLinear(double a, double b, double c);
void SolveQuadratic(double a, double b, double c);

int main(){

    Input();

    return 0;

}

int Input(){

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    printf("Welcome to the master of solving quadratic equations\n"
           "Enter the values of the three coefficients: \n");

    if(scanf("%lf%lf%lf", &a, &b, &c) != 3){

        printf("Incorrect data entered, please double-check and re-enter\n");
        return 1;

    }

    SolveLinear(a, b, c);

}

void SolveLinear(double a, double b, double c){

    double x = 0;

    if(a == 0 && b == 0 && c == 0){

        printf("The equation has an infinite number of roots\n");

    }

    else if(a == 0 && b == 0 && c != 0){

        printf("The equation has no roots\n");

    }

    else if(a == 0 && b != 0 && c == 0){

        printf("The equation one root: x = 0");

    }

    else if(a == 0 && b != 0 && c != 0){

        printf("You need to solve %lf * x + %lf = 0\n", b, c);
        x = -c / b;
        printf("The equation has one root: x = %lf", x);

    }

    else if (a != 0){

        SolveQuadratic(a, b, c);

    }

}

void SolveQuadratic(double a, double b, double c){

    if(b == 0 && c == 0){

        printf("The equation one root: x = 0");

    }

    else if(b != 0 && c == 0){

        printf("You need to solve %lf * x^2 + %lf * x = 0\n", a, b); //axx+bx=0  x(ax + b) = 0  x = 0  x = -b/a
        printf("The equation has 2 roots: x = 0 and x = %lf\n", -b / a);

    }

    else if(b == 0 && c !=0){

        printf("You need to solve %lf * x^2 + %lf\n", a, c); //axx+c=0    axx= -c  xx= -c/a
        printf("The equation has no roots\n");

    }

    else if(b != 0 && c != 0){

        double x1 = 0, x2 = 0, D = 0;

        D  = b * b - 4 * a * c;

        if(D < 0){

            printf("The equation has no roots\n");

        }

        else if(D == 0){

            printf("The equation has one root: %lf", (-b) / (2 * a));

        }

        else if(D > 0){

            printf("You need to solve: %lf * x^2 + %lf * x + %lf = 0\n", a, b, c);
            
            x1 = (-b + sqrt(D)) / (2 * a);
            
            x1 = (-b - sqrt(D)) / (2 * a);
            
            printf("The equation has 2 roots: x = %lf and x = %lf", x1, x2);

        }

    }

}


