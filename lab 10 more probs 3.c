#include <stdio.h>

#define MAX_TEMPERATURE 40

void checkTemperature(float temperature) {
    static int exceedCount = 0;
    if (temperature > MAX_TEMPERATURE) {
        exceedCount++;
        printf("Temperature %.2f exceeds the maximum allowable limit.\n", temperature);
    } else {
        printf("Temperature %.2f is within the allowable limit.\n", temperature);
    }
    printf("Number of exceedances so far: %d\n", exceedCount);
}

int main() {
    float temp;

    for (int i = 0; i < 5; i++) {
        printf("Enter temperature %d: ", i + 1);
        scanf("%f", &temp);
        checkTemperature(temp);
    }

    return 0;
}
