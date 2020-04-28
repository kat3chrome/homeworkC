#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

struct ComplexNumber;
typedef struct ComplexNumber ComplexNumber;

ComplexNumber *addition(ComplexNumber *firstNumber, ComplexNumber *secondNumber);
ComplexNumber *subtraction(ComplexNumber *firstNumber, ComplexNumber *secondNumber);
ComplexNumber *multiplication(ComplexNumber* firstNumber, ComplexNumber* secondNumber);
ComplexNumber *division(ComplexNumber* firstNumber, ComplexNumber* secondNumber);

#endif