#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex() : real(0.0), imag(0.0) {}

    Complex(double r, double i) : real(r), imag(i) {}

    // Friend function to add two complex numbers
    friend Complex addComplex(const Complex& num1, const Complex& num2);

    void display() {
        std::cout << real << " + " << imag << "i";
    }
};

// Friend function definition
Complex addComplex(const Complex& num1, const Complex& num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

int main() {
    Complex num1, num2, sum;

    std::cout << "Enter real and imaginary parts of the first complex number:\n";
    double real1, imag1;
    std::cin >> real1 >> imag1;
    num1 = Complex(real1, imag1);

    std::cout << "Enter real and imaginary parts of the second complex number:\n";
    double real2, imag2;
    std::cin >> real2 >> imag2;
    num2 = Complex(real2, imag2);

    sum = addComplex(num1, num2);

    std::cout << "Sum of the two complex numbers: ";
    sum.display();
    std::cout << std::endl;

    return 0;
}

