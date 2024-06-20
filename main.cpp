// FCAI � Object-Oriented Programming 2 � 2023 - Assignment 2
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

#include <bits/stdc++.h>
#include "BigReal.h"

using namespace std;

int main() {
    BigReal b1("12345.6789"), b2("98765.4321"), b3("-12345.6789"), b4("-98765.4321"), b5(".123"), b6("-.123"), b7("456"), b8("-456");

    cout << "Test Number 1---------------------------------------------------" << endl;
    cout << "b1 size: " << b1.size() << endl;
    cout << "b1 sign : " << b1.Sign() << endl;
    cout << "b2 size: " << b2.size() << endl;
    cout << "b2 sign : " << b2.Sign() << endl;
    cout << "b3 size: " << b3.size() << endl;
    cout << "b3 sign : " << b3.Sign() << endl;
    cout << "b4 size: " << b4.size() << endl;
    cout << "b4 sign : " << b4.Sign() << endl;
    cout << "b5 size: " << b5.size() << endl;
    cout << "b5 sign : " << b5.Sign() << endl;
    cout << "b6 size: " << b6.size() << endl;
    cout << "b6 sign : " << b6.Sign() << endl;
    cout << "b7 size: " << b7.size() << endl;
    cout << "b7 sign : " << b7.Sign() << endl;
    cout << "b8 size: " << b8.size() << endl;
    cout << "b8 sign : " << b8.Sign() << endl;

    cout << endl;

    cout << "Test Number 2---------------------------------------------------" << endl;
    BigReal b9 = b1 + b2;
    cout << b1 <<" + "<< b2 <<" = " << b9 << endl;
    b9 = b1 - b2;
    cout << b1 <<" - "<< b2 <<" = " << b9 << endl;
    cout << b9.Sign() << endl;
    cout << b9.size() << endl;
    b9 = b2 - b1;
    cout << b2 <<" - "<< b1 <<" = " << b9 << endl;
    cout << b9.Sign() << endl;
    cout << b9.size() << endl;
    cout << boolalpha << (b1>b2) << ' ' << (b1<b2) << ' ' << (b1 == b2) << endl;

    cout << endl;

    cout << "Test Number 3---------------------------------------------------" << endl;
    BigReal b10 = b2 + b3;
    cout << b2 <<" + "<< b3 <<" = " << b10 << endl;
    b10 = b2-b3;
    cout << b2 <<" - "<< b3 <<" = " << b10 << endl;
    cout << b10.Sign() << endl;
    cout << b10.size() << endl;
    b10 = b3-b2;
    cout << b3 <<" - "<< b2 <<" = " << b10 << endl;
    cout << b10.size() << endl;
    cout << boolalpha << (b2 > b3) << ' ' << (b2 < b3) << ' ' << (b2 == b3)  << endl;

    cout << endl;

    cout << "Test Number 4---------------------------------------------------" << endl;
    BigReal b11 = b3 + b4;
    cout << b3 <<" + "<< b4 <<" = " << b11 << endl;
    b11 = b3-b4;
    cout << b3 <<" - "<< b4 <<" = " << b11 << endl;
    cout << b11.Sign() << endl;
    cout << b11.size() << endl;
    b11 = b4-b3;
    cout << b4 <<" - "<< b3 <<" = " << b11 << endl;
    cout << b11.size() << endl;
    cout << boolalpha << (b3 > b4) << ' ' << (b3 < b4) << ' ' << (b4 == b4)  << endl;

    cout << "Test Number 5---------------------------------------------------" << endl;
    BigReal b12 = b4 + b5;
    cout << b4 <<" + "<< b5 <<" = " << b12 << endl;
    b12 = b4-b5;
    cout << b4 <<" - "<< b5 <<" = " << b12 << endl;
    cout << b12.Sign() << endl;
    cout << b12.size() << endl;
    b12 = b5-b4;
    cout << b5 <<" - "<< b4 <<" = " << b12 << endl;
    cout << b11.size() << endl;
    cout << boolalpha << (b4 > b5) << ' ' << (b4 < b5) << ' ' << (b4 == b5)  << endl;

    cout << endl;

    cout << "Test Number 6---------------------------------------------------" << endl;
    BigReal b13 = b5 + b6;
    cout << b5 <<" + "<< b6 <<" = " << b13 << endl;
    b13 = b5-b6;
    cout << b5 <<" - "<< b6 <<" = " << b13 << endl;
    cout << b13.Sign() << endl;
    cout << b13.size() << endl;
    b13 = b6-b5;
    cout << b6 <<" - "<< b5 <<" = " << b13 << endl;
    cout << b11.size() << endl;
    cout << boolalpha << (b5 > b6) << ' ' << (b5 < b6) << ' ' << (b5 == b6)  << endl;

    cout << endl;

    cout << "Test Number 7---------------------------------------------------" << endl;
    BigReal b14 = b6 + b7;
    cout << b6 <<" + "<< b7 <<" = " << b14 << endl;
    b14 = b6-b7;
    cout << b6 <<" - "<< b7 <<" = " << b14 << endl;
    cout << b14.Sign() << endl;
    cout << b14.size() << endl;
    b14 = b7-b6;
    cout << b7 <<" - "<< b6 <<" = " << b14 << endl;
    cout << b11.size() << endl;
    cout << boolalpha << (b6 > b7) << ' ' << (b6 < b7) << ' ' << (b6 == b7)  << endl;

    cout << endl;

    cout << "Test Number 8---------------------------------------------------" << endl;
    BigReal b15 = b7 + b8;
    cout << b7 <<" + "<< b8 <<" = " << b15 << endl;
    b15 = b7-b8;
    cout << b7 <<" - "<< b8 <<" = " << b15 << endl;
    cout << b15.Sign() << endl;
    cout << b15.size() << endl;
    b15 = b8-b7;
    cout << b8 <<" - "<< b7 <<" = " << b15 << endl;
    cout << b15.size() << endl;
    cout << boolalpha << (b7 > b8) << ' ' << (b7 < b8) << ' ' << (b7 == b8)  << endl;

    cout << endl;

    cout << "Test Number 9---------------------------------------------------" << endl;
    BigReal b16 = b1 + b3;
    cout << b1 <<" + "<< b3 <<" = " << b16 << endl;
    b16 = b1-b1;
    cout << b1 <<" - "<< b3 <<" = " << b16 << endl;
    cout << b16.Sign() << endl;
    cout << b16.size() << endl;
    b16 = b3-b1;
    cout << b3 <<" - "<< b1 <<" = " << b16 << endl;
    cout << b16.size() << endl;
    cout << boolalpha << (b1 > b3) << ' ' << (b1 < b3) << ' ' << (b1 == b1)  << endl;

    cout <<endl;

    cout << "Test Number 10----------------------------------------------------" << endl;
    BigReal b17 = b2 + b4;
    cout << b2 <<" + "<< b4 <<" = " << b17 << endl;
    b17 = b2-b4;
    cout << b2 <<" - "<< b4 <<" = " << b17 << endl;
    cout << b17.Sign() << endl;
    cout << b17.size() << endl;
    b17 = b4-b2;
    cout << b4 <<" - "<< b2 <<" = " << b17 << endl;
    cout << b17.size() << endl;
    cout << boolalpha << (b2 > b4) << ' ' << (b2 < b4) << ' ' << (b2 == b4)  << endl;

    cout << endl;

    cout << "Test Number 11----------------------------------------------------" << endl;
    BigReal b18 = b5 + b7;
    cout << b5 <<" + "<< b7 <<" = " << b18 << endl;
    b18 = b5-b7;
    cout << b5 <<" - "<< b7 <<" = " << b18 << endl;
    cout << b18.Sign() << endl;
    cout << b18.size() << endl;
    b18 = b7-b5;
    cout << b7 <<" - "<< b5 <<" = " << b18 << endl;
    cout << b18.size() << endl;
    cout << boolalpha << (b5 > b7) << ' ' << (b5 < b7) << ' ' << (b5 == b7)  << endl;

    cout << endl;

    cout << "Test Number 12----------------------------------------------------" << endl;
    BigReal b19 = b6 + b8;
    cout << b6 <<" + "<< b8 <<" = " << b19 << endl;
    b19 = b6-b8;
    cout << b6 <<" - "<< b8 <<" = " << b19 << endl;
    cout << b19.Sign() << endl;
    cout << b19.size() << endl;
    b19 = b8-b6;
    cout << b8 <<" - "<< b6 <<" = " << b19 << endl;
    cout << b19.size() << endl;
    cout << boolalpha << (b6 > b8) << ' ' << (b6 < b8) << ' ' << (b6 == b8)  << endl;





    return 0;
}
