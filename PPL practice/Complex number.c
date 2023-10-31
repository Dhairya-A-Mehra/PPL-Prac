#include <stdio.h>

// Define a structure for a complex number
struct Complex {
    float real;
    float imag;
};

// Function to add two complex numbers and return the result
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

int main() {
    struct Complex num1, num2, sum;

    printf("Enter real and imaginary parts of the first complex number:\n");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter real and imaginary parts of the second complex number:\n");
    scanf("%f %f", &num2.real, &num2.imag);

    sum = addComplex(num1, num2);

    printf("Sum of the two complex numbers: %.2f + %.2fi\n", sum.real, sum.imag);

    return 0;
}

