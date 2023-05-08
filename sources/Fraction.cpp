#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel{
    int gcd(int first, int second){
        if (second == 0)
            return first;
        return gcd(second, first % second);
    }
    Fraction Fraction::operator+(const Fraction& other){
        int newNumerator = this->numerator * other.denominator + other.numerator * this->denominator;
        int newDenominator = this->denominator * other.denominator;
        int gcd = this->gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/gcd, newDenominator/gcd);
    }
    Fraction Fraction::operator+(double num){
        int newNumerator = this->numerator + num * this->denominator;
        int newDenominator = this->denominator;
        int gcd = this->gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/gcd, newDenominator/gcd);
    }
    Fraction Fraction::operator-(const Fraction& other){
        int newNumerator = this->numerator * other.denominator - other.numerator * this->denominator;
        int newDenominator = this->denominator * other.denominator;
        int gcd = this->gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/gcd, newDenominator/gcd);
    }
    Fraction Fraction::operator-(double num){
        int newNumerator = this->numerator - num * this->denominator;
        int newDenominator = this->denominator;
        int gcd = this->gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/gcd, newDenominator/gcd);
    }
    Fraction operator-(double num, const Fraction& other){
        int newNumerator = num * other.denominator - other.numerator;
        int newDenominator = other.denominator;
        int to_divide = gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/to_divide, newDenominator/to_divide);
    }
    Fraction Fraction::operator*(const Fraction& other){
        int newNumerator = this->numerator * other.numerator;
        int newDenominator = this->denominator * other.denominator;
        int gcd = this->gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/gcd, newDenominator/gcd);
    }
    Fraction operator+(double num, const Fraction& other){
        int newNumerator = this->numerator + num * this->denominator;
        int newDenominator = this->denominator;
        int gcd = this->gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/gcd, newDenominator/gcd);
        return other;
    }
    Fraction operator*(double num, const Fraction& other){
        // int newNumerator = this->numerator * num;
        // int newDenominator = this->denominator;
        // int gcd = this->gcd(newNumerator, newDenominator);
        // return Fraction(newNumerator/gcd, newDenominator/gcd);

        return other;
    }
    Fraction Fraction::operator/(const Fraction& other){
        // int newNumerator = this->numerator * other.denominator;
        // int newDenominator = this->denominator * other.numerator;
        // int gcd = this->gcd(newNumerator, newDenominator);
        // return Fraction(newNumerator/gcd, newDenominator/gcd);
        return *this;
    }
    Fraction Fraction::operator/(double num){
        int newNumerator = this->numerator;
        int newDenominator = this->denominator * num;
        int gcd = this->gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/gcd, newDenominator/gcd);
    }
    Fraction operator/(double num, const Fraction& other){
        int newNumerator = num * other.denominator;
        int newDenominator = other.numerator;
        int gcd = other.gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/gcd, newDenominator/gcd);
        return other;
    }
    bool Fraction::operator==(const Fraction& other){
        return (this->numerator == other.numerator && this->denominator == other.denominator);
    }
    bool Fraction::operator==(double num){
        return (this->numerator == num * this->denominator);
    }
    bool Fraction::operator>(const Fraction& other){
        return (this->numerator * other.denominator > other.numerator * this->denominator);
    }
    bool Fraction::operator>(double num){
        return (this->numerator > num * this->denominator);
    }
    bool operator>(double num, const Fraction& other){
        return (num * other.denominator > other.numerator);
    }
    bool Fraction::operator<(const Fraction& other){
        return (this->numerator * other.denominator < other.numerator * this->denominator);
    }
    bool Fraction::operator<(double num){
        return (this->numerator < num * this->denominator);
    }
    bool operator<(double num, const Fraction& other){
        return (num * other.denominator < other.numerator);
    }
    bool Fraction::operator>=(const Fraction& other) const{
        // return (this->numerator * other.denominator >= other.numerator * this->denominator);
        return true;
    }
    bool Fraction::operator>=(double num){
        // return (this->numerator >= num * this->denominator);
        return true;
    }
    bool operator>=(double num, const Fraction& other){
        return (num * other.denominator >= other.numerator);
    }
    bool Fraction::operator<=(const Fraction& other){
        // return (this->numerator * other.denominator <= other.numerator * this->denominator);
        return true;
    }
    bool Fraction::operator<=(double num){
        // return (this->numerator <= num * this->denominator);
        return true;
    }
    bool operator<=(double num, const Fraction& other){
        return (num * other.denominator <= other.numerator);
    }
    Fraction Fraction::operator++(int){
        Fraction temp = *this;
        this->numerator += this->denominator;
        return temp;
    }
    Fraction& Fraction::operator++(){
        this->numerator += this->denominator;
        return *this;
    }
    Fraction Fraction::operator--(int){
        Fraction temp = *this;
        this->numerator -= this->denominator;
        return temp;
    }
    Fraction& Fraction::operator--(){
        this->numerator -= this->denominator;
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const Fraction& other){
        // os << other.numerator << "/" << other.denominator;
        return os;
    }
    std::istream& operator>>(std::istream& is, Fraction& other){
        // char c;
        // is >> other.numerator >> c >> other.denominator;
        return is;
    }
}