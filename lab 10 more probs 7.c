#include <stdio.h>

#define METERS_TO_KM 0.001

void convertToKilometers(float meters) {
    static int count = 0;
    count++;
    printf("%.2f meters is equal to %.2f kilometers.\n", meters, meters * METERS_TO_KM);
    printf("Function called %d times.\n", count);
}

int main() {
    convertToKilometers(1500);
    convertToKilometers(2000);
    convertToKilometers(3500);

    return 0;
}
