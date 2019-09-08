//RANGE OF PRIME NUMBER

//header files
#include<bits/stdc++.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

//Funtion to check wheather a number is prime or not
int checkprime(int num)
{
	for(int i=2; i <= sqrt(num); i++)
		if(num%i==0)
			return 0;
	return 1;
}

//main function
int main(int argc, char **argv){

	int l= atoi(argv[1]), u= atoi(argv[2]);
	for(int i=l; i<= u; i++)
		if(checkprime(i)==1)
			cout<<"1 ";
		else
			cout<<"0 ";
	return 0;
}


