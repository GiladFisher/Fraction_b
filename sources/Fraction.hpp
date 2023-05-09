#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#pragma once
using namespace std;
namespace ariel{


    class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        int gcd(int first, int second);
        Fraction(){
            this->numerator = 1;
            this->denominator = 1;
        }
        Fraction(int _numerator, const int _denominator): numerator(_numerator), denominator(_denominator){
            if(_denominator == 0){
                throw std::invalid_argument("Math: can't devide by 0");
            }
            int to_divide = this->gcd(_numerator, _denominator);
            this->numerator /= to_divide;
            this->denominator /= to_divide;
        }
        Fraction(float num){
            int deno = 1;
            int cnt = 0;
            while (num != (int)num && cnt < 3){
                num *= 10;
                deno *= 10;
                cnt++;
            }
            this->numerator = num;
            this->denominator = deno;
            int to_divide = this->gcd(this->numerator, this->denominator);
            this->numerator /= to_divide;
            this->denominator /= to_divide;
        }
        Fraction operator+(const Fraction& other);
        friend Fraction operator+(double num, const Fraction& other);
        Fraction operator+(double num);
        Fraction operator-(const Fraction& other);
        friend Fraction operator-(double num, const Fraction& other);
        Fraction operator-(double num);
        Fraction operator*(const Fraction& other);
        friend Fraction operator*(double num, const Fraction& other);
        Fraction operator/(const Fraction& other);
        Fraction operator/(double num);
        friend Fraction operator/(double num, const Fraction& other);

        bool operator==(const Fraction& other) const ;
        bool operator==(double num);
        bool operator>(const Fraction& other)const;
        bool operator>(double num);
        friend bool operator>(double num, const Fraction& other);
        bool operator<(const Fraction& other)const;
        bool operator<(double num);
        friend bool operator<(double num, const Fraction& other);
        bool operator>=(const Fraction& other) const;
        bool operator>=(double num);
        friend bool operator>=(double num, const Fraction& other);
        bool operator<=(const Fraction& other)const;
        bool operator<=(double num);
        friend bool operator<=(double num, const Fraction& other);

        Fraction operator++(int); // postfix
        Fraction operator--(int); // postfix
        Fraction &operator++(); // prefix
        Fraction &operator--(); // prefix

        friend std::ostream& operator<<(std::ostream& ost, const Fraction& frc);
        friend std::istream& operator>>(std::istream& ist, Fraction& frc);

        int getNumerator() const
        {
            return this->numerator;
        }
        int getDenominator() const{
            return this->denominator;
        }
    };





}