//Recursive function

#include<bits/stdc++.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

//Recursive function
int recursive_function(int val1, int val2){
	if(val1==0 || val2==0)
		return 1;
	else 
		return(recursive_function(val1-1,val2)+recursive_function(val1-1,val2-1));	
}


//Main function
int main(int argc, char **argv){
	int val1,val2;
	val1=atoi(argv[1]);
	val2=atoi(argv[2]);
	cout<<recursive_function(val1,val2);
	return 0;
}


