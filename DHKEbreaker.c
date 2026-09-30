#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Remember that fmod exists

int main(int argc, char *argv[])
{

    const int g = atoi(argv[1]);
    const double p = atof(argv[2]);    
    const double pk = atof(argv[3]);
    const int decimals = atoi(argv[4])*(-1);

    const double epsilon = pow(10,decimals);

    double fractal = 0;
    double val = 0;
    double integ = 0;

    int a = 0;

    const double relation = pk / p;

    while(1) {

        val = pow(g,a) / p;
        fractal = modf(val, &integ); 

        if (fabs(fractal - relation) < epsilon) {
            printf("\nSecret found: ");
            printf("%d", a);
            break;        
        }

        if ( (a % 100) == 0 && (a > 0) ) {
            printf("\nNumbers tried: ");
            printf("%d",a);
        }

        a++;
    }

    return 0;
}