#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

void identify(float);
void roundNumber(float); 

int main(){
	float num;
	cout<<"Enter a number: "; cin>>num;
	cout<<"\n";
	
	identify(num);
	roundNumber(num);
	cout<<"\n";
	return 0;
}

void identify(float number){
	int a_number = int(number);
	if (a_number == number){
		cout<<"\nInteger"<<endl;
	} 
	else cout<<"\nReal"<<endl;
}

void roundNumber(float number){
	float remainder;
	int aux = number;
	int a_number = int (aux);
	remainder = number - a_number;
	if (remainder >= 0.5){
		a_number++;
		cout<<a_number;
	}
	else cout<<a_number;
}

