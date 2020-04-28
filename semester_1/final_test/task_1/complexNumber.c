#include <stdlib.h>
#include "complexNumber.h"

struct ComplexNumber
{
    float real;
    float imaginary;
};

typedef struct ComplexNumber ComplexNumber;

ComplexNumber *addition(ComplexNumber *firstNumber, ComplexNumber *secondNumber)
{
    ComplexNumber *result = malloc(sizeof(ComplexNumber));

    result->real = firstNumber->real + secondNumber->real;
    result->imaginary = firstNumber->imaginary + secondNumber->imaginary;

    return result;
}

ComplexNumber *subtraction(ComplexNumber *firstNumber, ComplexNumber *secondNumber)
{
    ComplexNumber *result = malloc(sizeof(ComplexNumber));

    result->real = firstNumber->real - secondNumber->real;
    result->imaginary = firstNumber->imaginary - secondNumber->imaginary;

    return result;
}

ComplexNumber *multiplication(ComplexNumber* firstNumber, ComplexNumber* secondNumber)
{
    ComplexNumber *result = malloc(sizeof(ComplexNumber));

    result->real = firstNumber->real * secondNumber->real - firstNumber->imaginary * secondNumber->imaginary;
    result->imaginary = firstNumber->real * secondNumber->imaginary + secondNumber->real * firstNumber->imaginary;

    return result;
}

ComplexNumber *division(ComplexNumber* firstNumber, ComplexNumber* secondNumber)
{
    ComplexNumber *result = malloc(sizeof(ComplexNumber));

    result->real = (firstNumber->real * firstNumber->imaginary + secondNumber->real * secondNumber->imaginary) / (firstNumber->imaginary * firstNumber->imaginary + secondNumber->imaginary * secondNumber->imaginary);
    result->imaginary = (firstNumber->imaginary * secondNumber->real - firstNumber->real * secondNumber->imaginary) / (firstNumber->imaginary * firstNumber->imaginary + secondNumber->imaginary * secondNumber->imaginary);

    return result;
}