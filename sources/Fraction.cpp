#include "Fraction.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel{
    
    int Fraction::gcd(int first, int second){
        if (second == 0)
            return first;
        return gcd(second, first % second);
    }
    int gcd(int first, int second){
        if (second == 0)
            return first;
        return gcd(second, first % second);
    }
    Fraction Fraction::operator+(const Fraction& other){
        int newNumerator = this->numerator * other.denominator + other.numerator * this->denominator;
        int newDenominator = this->denominator * other.denominator;
        int to_divide = this->gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/to_divide, newDenominator/to_divide);
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
        Fraction other(num);
        return *this - other;
    }
    Fraction operator-(double num, const Fraction& other){
        Fraction other2(num);
        return other2 - other;
    }
    Fraction Fraction::operator*(const Fraction& other){
        int newNumerator = this->numerator * other.numerator;
        int newDenominator = this->denominator * other.denominator;
        int gcd = this->gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/gcd, newDenominator/gcd);
    }
    Fraction operator+(double num, const Fraction& other){
        int newNumerator = other.numerator + num * other.denominator;
        int newDenominator = other.denominator;
        int to_divide = ariel::gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/to_divide, newDenominator/to_divide);
        return other;
    }
    Fraction operator*(double num, const Fraction& other){
        Fraction other2(num);
        return other2 * other;
    }
    Fraction Fraction::operator/(const Fraction& other){
        int newNumerator = this->numerator * other.denominator;
        int newDenominator = this->denominator * other.numerator;
        int to_divide = gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/to_divide, newDenominator/to_divide);
        return *this;
    }
    Fraction Fraction::operator/(double num){
        int newNumerator = this->numerator;
        int newDenominator = this->denominator * num;
        int to_divide = gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/to_divide, newDenominator/to_divide);
    }
    Fraction operator/(double num, const Fraction& other){
        int newNumerator = num * other.denominator;
        int newDenominator = other.numerator;
        int to_divide = gcd(newNumerator, newDenominator);
        return Fraction(newNumerator/to_divide, newDenominator/to_divide);
        return other;
    }
    bool Fraction::operator==(const Fraction& other)const{
        return (this->numerator == other.numerator && this->denominator == other.denominator);
    }
    bool Fraction::operator==(double num){
        return (this->numerator == num * this->denominator);
    }
    bool Fraction::operator>(const Fraction& other)const{
        return (this->numerator * other.denominator > other.numerator * this->denominator);
    }
    bool Fraction::operator>(double num){
        return (this->numerator > num * this->denominator);
    }
    bool operator>(double num, const Fraction& other){
        return (num * other.denominator > other.numerator);
    }
    bool Fraction::operator<(const Fraction& other)const{
        return (this->numerator * other.denominator < other.numerator * this->denominator);
    }
    bool Fraction::operator<(double num){
        return (this->numerator < num * this->denominator);
    }
    bool operator<(double num, const Fraction& other){
        return (num * other.denominator < other.numerator);
    }
    bool Fraction::operator>=(const Fraction& other) const{
        return (this->numerator * other.denominator >= other.numerator * this->denominator);
    }
    bool Fraction::operator>=(double num){
        return (this->numerator >= num * this->denominator);
    }
    bool operator>=(double num, const Fraction& other){
        return (num * other.denominator >= other.numerator);
    }
    bool Fraction::operator<=(const Fraction& other)const{
        return (this->numerator * other.denominator <= other.numerator * this->denominator);
    }
    bool Fraction::operator<=(double num){
        return (this->numerator <= num * this->denominator);
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
        os << other.numerator << "/" << other.denominator;
        return os;
    }
    std::istream& operator>>(std::istream& is, Fraction& other){
        int numerator = 0, denominator = 0;
        is >> numerator >> denominator;
        if (denominator == 0){
            throw std::invalid_argument("Invalid argument");
        }
        other.numerator = numerator;
        other.denominator = denominator;
        return is;
    }
}