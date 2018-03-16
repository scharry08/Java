#include <iostream>

using namespace std;
class Cents
{
private:
	int m_cents;
 
public:
	Cents(int cents) { m_cents = cents;cout<<"in const...:"<<m_cents<<":"<<endl; }
	~Cents(){cout<<"in destr...:"<<m_cents<<":"<<endl;}
 
	// add Cents + int using a friend function
	Cents& operator+(int value)
	{
		this->m_cents+=value;
		return *this;
	}
 
	// add int + Cents using a friend function
	friend Cents operator+(int value, const Cents &c1);
 
 
	int getCents() { return m_cents; }
};
 
// note: this function is not a member function!
Cents operator+(int value, const Cents &c1)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return Cents(c1.m_cents + value);
}
 
int main()
{
	Cents c1 = Cents(4) + 6;
	Cents c2 = 6 + Cents(4);
 
	std::cout << "I have " << c1.getCents() << " cents." << std::endl;
	std::cout << "I have " << c2.getCents() << " cents." << std::endl;
 
	return 0;
}
