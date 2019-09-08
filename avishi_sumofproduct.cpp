

#include<bits/stdc++.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char** argv)
{	
	int val1=atoi(argv[1]), val2=atoi(argv[2]);
	int sumofval=0;
	
	while(val1 && val2)
	{
		sumofval+= ( val1 % 10 ) * ( val2 % 10 );
		val2/=10;
		val1/=10;
	}
	
	if(val1!=0 || val2!=0)
		cout<<-1;
		
	else
		cout<<sumofval;
		
	return 0;
}
