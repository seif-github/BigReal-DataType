// FCAI – Object-Oriented Programming 2 – 2023 - Assignment 2
// Program Name: BigRealClass
// Last Modification Date: 5/11/2023
// Author1 and ID and Group: Seif Gamal Abdelmonem | 20220162 | S9
// Author2 and ID and Group: Samuel Moamen Samy | 20220168 | S9
// Author3 and ID and Group: Zeyad hussain Adel | 20220439 | S9
/*
Purpose: In this problem we developed a new C++ type (class).
that can hold unlimited decimal integer values and performs arithmetic operations on them.
such as: +, -, <, and >.
 */

#ifndef BIGREAL_H
#define BIGREAL_H

#include <bits/stdc++.h>

using namespace std;

class BigReal
{
private:
    char sign = '+';
    string integer, fraction;
    bool isValidReal(string realNumber);
public:
    BigReal ();
    BigReal (string realNumber);
    void setNumber(string realNumber);
    BigReal(const BigReal& other);
    BigReal& operator = (const BigReal& anotherNum);

    int size();
    int Sign();

    BigReal operator + (const BigReal& anotherNum);
    BigReal operator - (const BigReal& anotherNum);

    bool operator < (const BigReal& anotherNum);
    bool operator > (const BigReal& anotherNum);
    bool operator == (const BigReal& anotherNum);
    friend ostream &operator << (ostream &out, BigReal& num);
};

#endif // BIGREAL_H
