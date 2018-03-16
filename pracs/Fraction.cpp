#include <iostream>
 
using namespace std;
class Fraction
{
private:
	int m_numerator;
	int m_denominator;
 
public:
	Fraction(int numerator=0, int denominator=1):
		m_numerator(numerator), m_denominator(denominator)
	{
		// We put reduce() in the constructor to ensure any new fractions we make get reduced!
		// Any fractions that are overwritten will need to be re-reduced
		cout<<"in constr...."<<endl;
		reduce();
	}
	~Fraction(){cout<<"In destr....."<<endl;}
 
	// We'll make gcd static so that it can be part of class Fraction without requiring an object of type Fraction to use
	static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a % b);
	}
 
	void reduce()
	{
		int gcd = Fraction::gcd(m_numerator, m_denominator);
		m_numerator /= gcd;
		m_denominator /= gcd;
	}
 
	Fraction& operator*(const Fraction &f1)
{
  this->m_numerator*=f1.m_numerator;
  this->m_denominator*=f1.m_denominator;
  return *this;
}
	Fraction& operator*(int value)
{
  this->m_numerator*=value;
  return *this;
}
	friend Fraction& operator*(int value, Fraction &f1);
	friend istream& operator>>(istream& in, Fraction &f1);
	friend ostream& operator<<(ostream& out,const Fraction &f1);
 
	void print()
	{
		std::cout << m_numerator << "/" << m_denominator << "\n";
	}
};
 
Fraction& operator*(int value, Fraction &f1)
{
	f1.m_numerator*=value;
	return f1;
}
istream& operator>>(istream& in, Fraction &f1)
{
	in>>f1.m_numerator;
	in>>f1.m_denominator;
	return in;
}
ostream& operator<<(ostream& out,const Fraction &f1)
{
	out<<"("<<f1.m_numerator<<","<<f1.m_denominator<<")";
	return out;
}
int main()
{
 
	Fraction f1;
	std::cout << "Enter fraction 1: ";
	std::cin >> f1;
 
	Fraction f2;
	std::cout << "Enter fraction 2: ";
	std::cin >> f2;
 
	std::cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n';
	Fraction f3;
  std::cout << "Enter fraction 3: ";
  std::cin >> f3;
	int num=0;
	std::cout << "Enter number : ";
  std::cin >> num;
	cout<<f3<<"*"<<num<<" is "<<f3*num<<endl;
 
	return 0;
}
