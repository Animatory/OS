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
    printf("%i %d\n", i, (int) sizeof(i));
    printf("%f %d\n", f, (int) sizeof(f));
    printf("%lf %d\n", d, (int) sizeof(d));

}

