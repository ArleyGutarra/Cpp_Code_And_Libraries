#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;


bool isprime(int num);
int* primes(int min, int max);
int countPrimes(int min, int max);


int main(){
	unsigned t0, t1;
	
	int N, M, cant, random_position, cant_primes;
	bool val;
	int *ptr;
	t0=clock();
	cout << "Enter the minimum and maximum value of the range: ";
	cin>>N>>M;
	cout << "Enter the amount of random prime numbers you want: ";
	cin >> cant_primes;
	cant = countPrimes(N,M);
	ptr = primes(N,M);
	/*for (int i=0; i < cant; i++){
		cout << *(ptr+i) <<", ";
	}*/
	
	srand(time(NULL));
	
	for (int j=0; j < cant_primes; j++){
			random_position = rand()%cant;
			cout << *(ptr+random_position)<<", ";
	}

	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "\n\nExecution Time: " << time << endl;
	
	system("pause");
	return 0;
}

bool isprime (int num){
	bool validacion;
	int c=0, i=1;
	while (i<=num){
		if (num%i == 0){
			c++;}
		i++;
	}
	if (c == 2) validacion = true;
	else validacion = false; 
	return validacion;
}

int countPrimes(int min, int max){
	int c=0;
	for (int i=min; i<=max; i++){
		if (isprime(i) == true){ 
			c++;
		}
	}
	return c;
}


int* primes(int min, int max){

	int total_size;
	int c=0;
	//total_size = countPrimes(min,max)*sizeof(int);
	int *primes_arr; 
	primes_arr = (int*)malloc(countPrimes(min,max)*sizeof(int)); 
	
	
	for (int i=min; i<=max; i++){
		if (isprime(i) == true){
			*(primes_arr+c) = i; 
			c++;
		}
	}	
	
	return primes_arr;
}


