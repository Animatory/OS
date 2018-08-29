#include "limits.h"
#include "float.h"
#include "stdio.h"

int main() {
    int i;
    float f;
    double d;
    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;
    printf("%i %i\n", i, sizeof(i));
    printf("%f %i\n", f, sizeof(f));
    printf("%lf %i\n", d, sizeof(d));

}

