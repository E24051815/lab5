#include<iostream>
#include<string>
#include"HugeInt.h"
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

HugeInt::HugeInt(){}
HugeInt::HugeInt(long long we){
	B=we;
	A=0;
}
HugeInt::HugeInt(string a){
	int lengthofa=a.length();
	
	//cut string a
	if(lengthofa>=11){
		string1=string1.assign(a,lengthofa-10,10);
		string2=string2.assign(a,0,lengthofa-10);
		stringstream ss;
		ss<<string1;
		ss>>B;
		stringstream SS;
		SS<<string2;
		SS>>A;
	}
	else{
		stringstream ss;
		ss<<a;
		ss>>B;
	}
	}

HugeInt HugeInt::operator +(HugeInt one){
	HugeInt two;
	if((one.B+B)/10000000000>0){
		two.B=one.B+B-((one.B+B)/10000000000)*10000000000;
		two.A=one.A+A+(one.B+B)/10000000000;
	}
	else{
		two.B=one.B+B;
		two.A=one.A+A;
	}
	return two;
}

HugeInt HugeInt::operator -(HugeInt one){
	HugeInt two;
	if(A>one.A||(A==one.A&&B>one.B)){
		if((B-one.B)<0){
			two.B=10000000000+(B-one.B);
			two.A=(A-one.A)-1;	
		}
		else{
			two.B=B-one.B;
			two.A=A-one.A;	
		}
	}	
	else{
		int memA,memB;
		memA=A;
		A=one.A;
		one.A=memA;
		memB=B;
		B=one.B;
		one.B=memB;
		if((B-one.B)<0){
			two.B=10000000000+(B-one.B);
			two.A=A-one.A-1;	
		}
		else{
			two.B=B-one.B;
			two.A=A-one.A;	
		}
	}
	return two;
}

void HugeInt::operator =(HugeInt one){
	A=one.A;
	B=one.B;
}

istream &operator >>(istream &input,HugeInt & obj){
	string a,string1,string2;
	input>>a;
	int lengthin=a.length();
	if(lengthin>=11){
		obj.string1=string1.assign(obj.a,lengthin-10,10);
		obj.string2=string2.assign(obj.a,0,lengthin-10);
		stringstream ss;
		ss<<obj.string1;
		ss>>obj.B;
		stringstream SS;
		SS<<obj.string2;
		SS>>obj.A;
	}
	else{
		stringstream ss;
		ss<<a;
		ss>>obj.B;
	}
	return input;
}
	
ostream &operator <<(ostream &output,HugeInt &OBJ){
	output<<OBJ.A<<OBJ.B;
	return output;
}

	


