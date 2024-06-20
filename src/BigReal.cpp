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

#include "BigReal.h"
#include <bits/stdc++.h>

using namespace std;

bool BigReal :: isValidReal(string realNumber){ // Check the validation of the input
    return regex_match(realNumber, regex ("[+-]?\\d*.?\\d*"));
}

BigReal :: BigReal (){ // Default constructor
    integer = '0';
    fraction = '0';
    sign = '+';

}

BigReal :: BigReal (string realNumber) { // Constructor to store the string BigReal
    if(isValidReal(realNumber)){
        setNumber(realNumber);
    }

    if(integer.empty()){
        integer = '0';
    }
    if(fraction.empty()){
        fraction = '0';
    }

}

void BigReal :: setNumber(string realNumber){ // Method to set the BigReal if the input is valid
    if(realNumber[0] == '-'){
        realNumber.erase(0, 1);
        sign = '-';
        if(realNumber[0] == '.'){
            realNumber.erase(0, 1);
            integer = '0';
            fraction = realNumber;
        }
        else if(realNumber[0] == '+'){
            integer = '0';
            fraction = '0';
            sign = '+';
        }
        else{
            if(realNumber.find('.') == string::npos){// If there's no dot in the input
                integer = realNumber;
                fraction = '0';
            }
            else{
                integer = realNumber.substr(0, realNumber.find('.'));
                fraction = realNumber.substr(integer.size() + 1, realNumber.size() - 1);
            }
        }
    }
    else if(realNumber[0] == '+'){
        realNumber.erase(0, 1);
        if(realNumber[0] == '.'){
            realNumber.erase(0, 1);
            integer = '0';
            fraction = realNumber;
        }
        else if(realNumber[0] == '-'){
            integer = '0';
            fraction = '0';
        }
        else{
            if(realNumber.find('.') == string::npos){ // If there's no dot in the input
                integer = realNumber;
                fraction = '0';
            }
            else{
                integer = realNumber.substr(0, realNumber.find('.'));
                fraction = realNumber.substr(integer.size() + 1, realNumber.size() - 1);
            }
        }
    }
    else if(realNumber[0] == '.'){
        realNumber.erase(0, 1);
        integer = '0';
        fraction = realNumber;
    }
    else{
        if(realNumber.find('.') == string::npos){// If there's no dot in the input
            integer = realNumber;
            fraction = '0';
        }
        else{
            integer = realNumber.substr(0, realNumber.find('.'));
            fraction = realNumber.substr(integer.size() + 1, realNumber.size() - 1);
        }
    }
}

BigReal :: BigReal(const BigReal& other){ // Copy constructor
    integer = other.integer;
    fraction = other.fraction;
    sign = other.sign;
}

BigReal& BigReal:: operator = (const BigReal& anotherNum){ // Overloading assignment operator
    sign = anotherNum.sign;
    integer = anotherNum.integer;
    fraction = anotherNum.fraction;
    return *this;

}

int BigReal :: size(){ // Method to print size of BigReal
    return integer.size()+fraction.size();
}

int BigReal :: Sign(){ // Method to print sign of BigReal
    if(sign == '+'){
        return 1;
    }
    else {
        return 0;
    }
}

BigReal BigReal :: operator + (const BigReal& anotherNum){ // Overloading addition operator
    // Copy the object to edit on the copy
    BigReal copy_anotherNum = anotherNum;
    int n_integer, n_fraction;
//padding
    // integer
    if(integer.size() < copy_anotherNum.integer.size()){
        n_integer = copy_anotherNum.integer.size();
        string zeros;
        for (int i = 0; i < copy_anotherNum.integer.size() - integer.size(); ++i){
            zeros += '0';
        }
        integer = zeros + integer;
        zeros.clear();
    }
    else{
        n_integer = integer.size();
        string zeros;
        for (int i = 0; i < integer.size() - copy_anotherNum.integer.size(); ++i){
            zeros += '0';
        }
        copy_anotherNum.integer = zeros + copy_anotherNum.integer;
        zeros.clear();
    }
    // fraction
    if(fraction.size() < copy_anotherNum.fraction.size()){
        n_fraction = copy_anotherNum.fraction.size();
        string zeros;
        for (int i = 0; i < copy_anotherNum.fraction.size() - fraction.size(); ++i){
            zeros += '0';
        }
        fraction += zeros;
        zeros.clear();
    }
    else{
        n_fraction = fraction.size();
        string zeros;
        for (int i = 0; i < fraction.size() - copy_anotherNum.fraction.size(); ++i){
            zeros += '0';
        }
        copy_anotherNum.fraction += zeros;
        zeros.clear();
    }

// Comparing
    BigReal big, small;
    bool flag = false;
    for (int i = 0; i < n_integer; ++i){
        if(integer[i] < copy_anotherNum.integer[i]){
            small.sign = sign;
            small.integer = integer;
            small.fraction = fraction;
            big.sign = copy_anotherNum.sign;
            big.integer = copy_anotherNum.integer;
            big.fraction = copy_anotherNum.fraction;
            flag = true;
            break;
        }
        else if (integer[i] > copy_anotherNum.integer[i]){
            big.sign = sign;
            big.integer = integer;
            big.fraction = fraction;
            small.sign = copy_anotherNum.sign;
            small.integer = copy_anotherNum.integer;
            small.fraction = copy_anotherNum.fraction;
            flag = true;
            break;
        }
    }
    for (int i = 0; i < n_fraction; ++i){
        if(flag){
            break;
        }
        else{
            if(fraction[i] < copy_anotherNum.fraction[i]){
                small.sign = sign;
                small.integer = integer;
                small.fraction = fraction;
                big.sign = copy_anotherNum.sign;
                big.integer = copy_anotherNum.integer;
                big.fraction = copy_anotherNum.fraction;
                flag = true;
                break;
            }
            else if(fraction[i] > copy_anotherNum.fraction[i]){
                big.sign = sign;
                big.integer = integer;
                big.fraction = fraction;
                small.sign = copy_anotherNum.sign;
                small.integer = copy_anotherNum.integer;
                small.fraction = copy_anotherNum.fraction;
                flag = true;
                break;
            }
        }

    }
    if(!flag){
        big.sign = sign;
        big.integer = integer;
        big.fraction = fraction;
        small.sign = copy_anotherNum.sign;
        small.integer = copy_anotherNum.integer;
        small.fraction = copy_anotherNum.fraction;
    }
// Adding
    BigReal addresult;
    addresult.integer.clear();
    addresult.fraction.clear();

    if(big.sign == small.sign){
        addresult.sign = big.sign;
        int carry = 0;
        for(int i = big.fraction.size()-1; i >= 0 ; i--){
            int temp = carry + ((int)big.fraction[i]-48) + ((int)small.fraction[i]-48);
            if(temp > 9){
                carry = 1;
                temp -=10;
            }
            else{
                carry = 0;
            }
            addresult.fraction = char(temp+48) + addresult.fraction;
        }
        for(int i = big.integer.size()-1; i >= 0 ; i--){
            int temp = carry + ((int)big.integer[i]-48) + ((int)small.integer[i]-48);
            if(temp > 9){
                carry = 1;
                temp -=10;
            }
            else{
                carry = 0;
            }
            addresult.integer = char(temp+48) + addresult.integer;
        }
        if(carry == 1){
            addresult.integer = char(carry+48) + addresult.integer;
        }
    }
    else{
        addresult.sign = big.sign;
        int carry = 0;
        for(int i = big.fraction.size()-1; i >= 0 ; i--){
            int temp = ((int)big.fraction[i]-48) - ((int)small.fraction[i]-48) - carry;
            if(temp < 0){
                carry = 1;
                temp +=10;
            }
            else{
                carry = 0;
            }
            addresult.fraction = char(temp+48) + addresult.fraction;
        }
        for(int i = big.integer.size()-1; i >= 0 ; i--){
            int temp = ((int)big.integer[i]-48) - ((int)small.integer[i]-48) - carry;
            if(temp < 0){
                carry = 1;
                temp +=10;
            }
            else{
                carry = 0;
            }
            addresult.integer = char(temp+48) + addresult.integer;
        }
    }


    return addresult;
/*
     +big  +  +small  == +(big + small)
     -big  +  -small  == -(big + small)
     +big  +  -small  == +(big - small)
     -big  +  +small  == -(big - small)
     +small  +  +big  == +(big + small)
     -small  +  -big  == -(big + small)
     +small  +  -big  == -(big - small)
     -small  +  +big  == +(big - small)
     */
}

BigReal BigReal :: operator - (const BigReal& anotherNum){ // Overloading subtraction operator
    // Copy the object to edit on the copy
    BigReal copy_anotherNum = anotherNum;
    int n_integer, n_fraction;
//padding
    // integer
    if(integer.size() < copy_anotherNum.integer.size()){
        n_integer = copy_anotherNum.integer.size();
        string zeros;
        for (int i = 0; i < copy_anotherNum.integer.size() - integer.size(); ++i){
            zeros += '0';
        }
        integer = zeros + integer;
        zeros.clear();
    }
    else{
        n_integer = integer.size();
        string zeros;
        for (int i = 0; i < integer.size() - copy_anotherNum.integer.size(); ++i){
            zeros += '0';
        }
        copy_anotherNum.integer = zeros + copy_anotherNum.integer;
        zeros.clear();
    }
    // fraction
    if(fraction.size() < copy_anotherNum.fraction.size()){
        n_fraction = copy_anotherNum.fraction.size();
        string zeros;
        for (int i = 0; i < copy_anotherNum.fraction.size() - fraction.size(); ++i){
            zeros += '0';
        }
        fraction += zeros;
        zeros.clear();
    }
    else{
        n_fraction = fraction.size();
        string zeros;
        for (int i = 0; i < fraction.size() - copy_anotherNum.fraction.size(); ++i){
            zeros += '0';
        }
        copy_anotherNum.fraction += zeros;
        zeros.clear();
    }
// Comparing
    BigReal big, small;
    bool flag = false;
    for (int i = 0; i < n_integer; ++i){
        if(integer[i] < copy_anotherNum.integer[i]){
            small.sign = sign;
            small.integer = integer;
            small.fraction = fraction;
            big.sign = copy_anotherNum.sign;
            big.integer = copy_anotherNum.integer;
            big.fraction = copy_anotherNum.fraction;
            flag = true;
            break;
        }
        else if (integer[i] > copy_anotherNum.integer[i]){
            big.sign = sign;
            big.integer = integer;
            big.fraction = fraction;
            small.sign = copy_anotherNum.sign;
            small.integer = copy_anotherNum.integer;
            small.fraction = copy_anotherNum.fraction;
            flag = true;
            break;
        }
    }
    for (int i = 0; i < n_fraction; ++i){
        if(flag){
            break;
        }
        else{
            if(fraction[i] < copy_anotherNum.fraction[i]){
                small.sign = sign;
                small.integer = integer;
                small.fraction = fraction;
                big.sign = copy_anotherNum.sign;
                big.integer = copy_anotherNum.integer;
                big.fraction = copy_anotherNum.fraction;
                flag = true;
                break;
            }
            else if(fraction[i] > copy_anotherNum.fraction[i]){
                big.sign = sign;
                big.integer = integer;
                big.fraction = fraction;
                small.sign = copy_anotherNum.sign;
                small.integer = copy_anotherNum.integer;
                small.fraction = copy_anotherNum.fraction;
                flag = true;
                break;
            }
        }

    }
    if(!flag){
        big.sign = sign;
        big.integer = integer;
        big.fraction = fraction;
        small.sign = copy_anotherNum.sign;
        small.integer = copy_anotherNum.integer;
        small.fraction = copy_anotherNum.fraction;
    }
// Subtracting
    BigReal subtractresult;
    subtractresult.integer.clear();
    subtractresult.fraction.clear();

    if(sign != copy_anotherNum.sign){
        subtractresult.sign = sign;
        int carry = 0;
        for(int i = big.fraction.size()-1; i >= 0 ; i--){
            int temp = carry + ((int)big.fraction[i]-48) + ((int)small.fraction[i]-48);
            if(temp > 9){
                carry = 1;
                temp -=10;
            }
            else{
                carry = 0;
            }
            subtractresult.fraction = char(temp+48) + subtractresult.fraction;
        }
        for(int i = big.integer.size()-1; i >= 0 ; i--){
            int temp = carry + ((int)big.integer[i]-48) + ((int)small.integer[i]-48);
            if(temp > 9){
                carry = 1;
                temp -=10;
            }
            else{
                carry = 0;
            }
            subtractresult.integer = char(temp+48) + subtractresult.integer;
        }
        if(carry == 1){
            subtractresult.integer = char(carry+48) + subtractresult.integer;
        }

    }
    else{
        if(big.integer == integer && big.fraction == fraction){
            subtractresult.sign = '+';
        }
        else{
            subtractresult.sign = '-';
        }

        int carry = 0;
        for(int i = big.fraction.size()-1; i >= 0 ; i--){
            int temp = ((int)big.fraction[i]-48) - ((int)small.fraction[i]-48) - carry;
            if(temp < 0){
                carry = 1;
                temp +=10;
            }
            else{
                carry = 0;
            }
            subtractresult.fraction = char(temp+48) + subtractresult.fraction;
        }
        for(int i = big.integer.size()-1; i >= 0 ; i--){
            int temp = ((int)big.integer[i]-48) - ((int)small.integer[i]-48) - carry;
            if(temp < 0){
                carry = 1;
                temp +=10;
            }
            else{
                carry = 0;
            }
            subtractresult.integer = char(temp+48) + subtractresult.integer;
        }
    }

    return subtractresult;
/*
     +big  -  +small  == +big + -small  == +(big - small)
     -big  -  -small  == -big + +small  == -(big - small)
     +big  -  -small  == +big + +small  == +(big + small)
     -big  -  +small  == -big + -small  == -(big + small)
     +small  -  +big  == +small + -big  == -(big - small)
     -small  -  -big  == -small + +big  == -(big - small)
     +small  -  -big  == +small + +big  == +(big + small)
     -small  -  +big  == -small + -big  == -(big + small)

     */
}

bool BigReal :: operator < (const BigReal& anotherNum){ // overloading less than operator
    // Copy the object to edit on the copy
    BigReal copy_anotherNum = anotherNum;
    int n_integer, n_fraction;
//padding
    // integer
    if(integer.size() < copy_anotherNum.integer.size()){
        n_integer = copy_anotherNum.integer.size();
        string zeros;
        for (int i = 0; i < copy_anotherNum.integer.size() - integer.size(); ++i){
            zeros += '0';
        }
        integer = zeros + integer;
        zeros.clear();
    }
    else{
        n_integer = integer.size();
        string zeros;
        for (int i = 0; i < integer.size() - copy_anotherNum.integer.size(); ++i){
            zeros += '0';
        }
        copy_anotherNum.integer = zeros + copy_anotherNum.integer;
        zeros.clear();
    }
    // fraction
    if(fraction.size() < copy_anotherNum.fraction.size()){
        n_fraction = copy_anotherNum.fraction.size();
        string zeros;
        for (int i = 0; i < copy_anotherNum.fraction.size() - fraction.size(); ++i){
            zeros += '0';
        }
        fraction += zeros;
        zeros.clear();
    }
    else{
        n_fraction = fraction.size();
        string zeros;
        for (int i = 0; i < fraction.size() - copy_anotherNum.fraction.size(); ++i){
            zeros += '0';
        }
        copy_anotherNum.fraction += zeros;
        zeros.clear();
    }

// comparing
    if (sign == '-' && copy_anotherNum.sign == '+'){
        return true;
    }
    else if(sign == '+' && copy_anotherNum.sign == '-'){
        return false;
    }
    else if(sign == '+' && copy_anotherNum.sign == '+'){
        for (int i = 0; i < n_integer; ++i){
            if(integer[i] > copy_anotherNum.integer[i]){
                return false;
            }
            else if (integer[i] < copy_anotherNum.integer[i]){
                return true;
            }
        }
        for (int i = 0; i < n_fraction; ++i){
            if(fraction[i] > copy_anotherNum.fraction[i]){
                return false;
            }
            else if(fraction[i] < copy_anotherNum.fraction[i]){
                return true;
            }
        }
        return false;
    }
    else if(sign == '-' && copy_anotherNum.sign == '-'){
        for (int i = 0; i < n_integer; ++i){
            if(integer[i] > copy_anotherNum.integer[i]){
                return true;
            }
            else if (integer[i] < copy_anotherNum.integer[i]){
                return false;
            }
        }
        for (int i = 0; i < n_fraction; ++i){
            if(fraction[i] > copy_anotherNum.fraction[i]){
                return true;
            }
            else if(fraction[i] < copy_anotherNum.fraction[i]){
                return false;
            }
        }
        return false;
    }
}

bool BigReal :: operator > (const BigReal& anotherNum){  // Overloading greater than operator
    // Copy the object to edit on the copy
    BigReal copy_anotherNum = anotherNum;
    int n_integer, n_fraction;
//padding
    // integer
    if(integer.size() < copy_anotherNum.integer.size()){
        n_integer = copy_anotherNum.integer.size();
        string zeros;
        for (int i = 0; i < copy_anotherNum.integer.size() - integer.size(); ++i){
            zeros += '0';
        }
        integer = zeros + integer;
        zeros.clear();
    }
    else{
        n_integer = integer.size();
        string zeros;
        for (int i = 0; i < integer.size() - copy_anotherNum.integer.size(); ++i){
            zeros += '0';
        }
        copy_anotherNum.integer = zeros + copy_anotherNum.integer;
        zeros.clear();
    }
    // fraction
    if(fraction.size() < copy_anotherNum.fraction.size()){
        n_fraction = copy_anotherNum.fraction.size();
        string zeros;
        for (int i = 0; i < copy_anotherNum.fraction.size() - fraction.size(); ++i){
            zeros += '0';
        }
        fraction += zeros;
        zeros.clear();
    }
    else{
        n_fraction = fraction.size();
        string zeros;
        for (int i = 0; i < fraction.size() - copy_anotherNum.fraction.size(); ++i){
            zeros += '0';
        }
        copy_anotherNum.fraction += zeros;
        zeros.clear();
    }

// comparing
    if (sign == '-' && copy_anotherNum.sign == '+'){
        return false;
    }
    else if(sign == '+' && copy_anotherNum.sign == '-'){
        return true;
    }
    else if(sign == '+' && copy_anotherNum.sign == '+'){
        for (int i = 0; i < n_integer; ++i){
            if(integer[i] < copy_anotherNum.integer[i]){
                return false;
            }
            else if (integer[i] > copy_anotherNum.integer[i]){
                return true;
            }
        }
        for (int i = 0; i < n_fraction; ++i){
            if(fraction[i] < copy_anotherNum.fraction[i]){
                return false;
            }
            else if(fraction[i] > copy_anotherNum.fraction[i]){
                return true;
            }
        }
        return false;
    }
    else if(sign == '-' && copy_anotherNum.sign == '-'){
        for (int i = 0; i < n_integer; ++i){
            if(integer[i] > copy_anotherNum.integer[i]){
                return false;
            }
            else if (integer[i] < copy_anotherNum.integer[i]){
                return true;
            }
        }
        for (int i = 0; i < n_fraction; ++i){
            if(fraction[i] > copy_anotherNum.fraction[i]){
                return false;
            }
            else if(fraction[i] < copy_anotherNum.fraction[i]){
                return true;
            }
        }
        return false;
    }
}

bool BigReal :: operator == (const BigReal& anotherNum){ // Overloading equal operator
    // Copy the object to edit on the copy
    BigReal copy_anotherNum = anotherNum;
    int n_integer, n_fraction;
//padding
    // integer
    if(integer.size() < copy_anotherNum.integer.size()){
        n_integer = copy_anotherNum.integer.size();
        string zeros;
        for (int i = 0; i < copy_anotherNum.integer.size() - integer.size(); ++i){
            zeros += '0';
        }
        integer = zeros + integer;
        zeros.clear();
    }
    else{
        n_integer = integer.size();
        string zeros;
        for (int i = 0; i < integer.size() - copy_anotherNum.integer.size(); ++i){
            zeros += '0';
        }
        copy_anotherNum.integer = zeros + copy_anotherNum.integer;
        zeros.clear();
    }
    // fraction
    if(fraction.size() < copy_anotherNum.fraction.size()){
        n_fraction = copy_anotherNum.fraction.size();
        string zeros;
        for (int i = 0; i < copy_anotherNum.fraction.size() - fraction.size(); ++i){
            zeros += '0';
        }
        fraction += zeros;
        zeros.clear();
    }
    else{
        n_fraction = fraction.size();
        string zeros;
        for (int i = 0; i < fraction.size() - copy_anotherNum.fraction.size(); ++i){
            zeros += '0';
        }
        copy_anotherNum.fraction += zeros;
        zeros.clear();
    }
// compare
    if(sign != copy_anotherNum.sign){
        return false;
    }
    else{
        for (int i = 0; i < n_integer; ++i){
            if(integer[i] < copy_anotherNum.integer[i] || integer[i] > copy_anotherNum.integer[i]){
                return false;
            }
        }
        for (int i = 0; i < n_integer; ++i){
            if(fraction[i] < copy_anotherNum.fraction[i] || fraction[i] > copy_anotherNum.fraction[i]){
                return false;
            }
        }
        return true;
    }

}

ostream &operator << (ostream &out, BigReal& num){ // Print the BigReal
    if(num.sign == '-'){
        out << num.sign << num.integer << '.' << num.fraction;
    }
    else{
        out << num.integer << '.' << num.fraction;
    }

    return out;

}
