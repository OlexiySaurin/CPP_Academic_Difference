#include <iostream>

using namespace std;

class rational_exception: public exception {
    const int exc_num;
public:
    rational_exception(int n) : exc_num(n){}

    const char * what() const noexcept {
        if (exc_num == 0) {
            return "Division by zero";
        }
        else if (exc_num == 1) {
            return "Incorrect value of denominator";
        }
    }
}; 

class rational
{
public:
    long long numer;
    long long denom;

    rational(long long a, long long b):numer(a), denom(b){
        if (denom == 0) {
            throw rational_exception(0);
        }
        else if (b < 0) {
            throw rational_exception(1);
        }
    }

    rational(long long a) : numer(a), denom(1){}

    rational operator -() {
        return rational(-numer, denom);
    }
};

ostream& operator << (ostream& stream, rational rat) {
    if (rat.denom == 1) {
        stream << rat.numer;
    }
    else {
        stream << rat.numer << "/" << rat.denom;
    }
    return stream;
}

int main()
{
    try {
        rational a{ 1, 4 }; // correct
        cout << a << endl;
    }
    catch (const rational_exception& e) {
        cout << e.what() << endl;
    }

    try {
        rational a{ 1, -2 }; // incorrect denominator
        cout << a << endl;
    }
    catch (const rational_exception& e) {
        cout << e.what() << endl;
    }

    try {
        rational a{ 1, 0 }; // division by zero
        cout << a << endl;
    }
    catch (const rational_exception& e) {
        cout << e.what() << endl;
    }
}