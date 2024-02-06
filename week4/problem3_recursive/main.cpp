///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Sum digits
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes a number and
/// find sum of digits recursively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>


int SumOfDigits(int n){
    if (n == 0) return 0;

    int sum = n % 10;
    sum += SumOfDigits(n / 10);

    return sum;
}

int SumOfDigits(double n){
    if (n == 0) return 0;
    else if (n < 10 && n % 1 != 0) n *= 10;

    int sum = n % 10;
    sum += SumOfDigits(n / 10);

    return sum;
}

int main()
{
    int num_1;
    double num_2;
    std::cin >> num_1 >> num_2;
    std::cout << SumOfDigits(num_1) << '\n' << SumOfDigits(num_2);

    return 0;
}
