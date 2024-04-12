#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double radius, volume;
    int mass;
    const double density_platinum = 21500;  // кг/м^3

    if (scanf("%lf", &radius) != 1 || radius <= 0) {
        printf("n/a\n");
        return 0;
    }

    volume = (4.0/3.0) * M_PI * radius * radius * radius;
    mass = (int)(density_platinum * volume + 0.5);  // Округляем до ближайшего целого

    printf("%d\n", mass);

    return 0;
}