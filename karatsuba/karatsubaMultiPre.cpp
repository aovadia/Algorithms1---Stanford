//
//  karatsubaMultiPre.cpp
//  
//
//  Created by Adam on 11/22/17.
//

#include <iostream>
#include <cmath>
using namespace std;

// Return number of digits in an integer
int countDigit(int val) {
    return log10(val) +1;
}

// Recursive function to compute the naive Karatsuba Multiplication routine
int doMulti(int val1, int val2) {
    if (countDigit(val1) == 1 || countDigit(val2) == 1) {
        return val1 * val2;
    }
    int a,b,c,d, ac, ad, bc, bd, result, digitC;
    digitC = countDigit(val1);
    int divider = digitC / 2;
  
    a = val1 / pow( 10, divider);
    b = val1 % (int)pow( 10, divider);
    
    c = val2 / pow( 10, divider);
    d = val2 % (int)pow( 10, divider);
    
    ac = doMulti(a,c);
    ad = doMulti(a, d);
    bc = doMulti(b, c);
    bd = doMulti(b,d);
    
    result = (pow(10, digitC)* ac + pow(10, digitC /2)* (ad + bc) +bd );
    return result;
}

int main() {
    int x, y, result;
    cout <<"Enter num1: ";
    cin >>x;
    cout <<endl;
    cout <<"Enter num2: ";
    cin >> y;
    cout <<endl;
    // Algorithm requires both numbers to be of the same length
    if (countDigit(x) != countDigit(y)) {
        cout <<"Each number should contain the same number of digits!" <<endl;
        exit(0);
    }
    cout <<"Preforming multiplication recursively!" <<endl;
    result = doMulti(x, y);
    cout <<"Result is: " << result <<endl;
    
    return 0;
}
