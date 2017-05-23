#ifndef HUGEINT_H
#define HUGEINT_H
#include<iostream>
using namespace std;

class HugeInt{

friend ostream &operator <<(ostream &, HugeInt &);
friend istream &operator >>(istream &, HugeInt &);

public:
        HugeInt();
        HugeInt(long long);
        HugeInt(string);
        HugeInt operator +(HugeInt);
        HugeInt operator -(HugeInt);
        void operator =(HugeInt);
private:
		long long A,B,c;
		string a,string1,string2;
		
};

#endif
