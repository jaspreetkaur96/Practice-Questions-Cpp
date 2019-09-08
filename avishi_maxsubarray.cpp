//maxizing subarray total

#include<bits/stdc++.h>

using namespace std;

//main function 
int main(int agrc, char** argv)
{
	string stringval = argv[1];
	stringstream strstream(stringval);

	int value[100];
	int i=0;
	
	while(strstream>>value[i]){
		getline(strstream,stringval,' ');
		i++;
	}
	
	float maxval=0,total=0;
	for(int j=0;j<i;j++){
		total+=value[j];
		if(total>maxval)
			maxval=total;
		if(total<0)
			total=0;
	}
	cout<<maxval;
	return 0;
}
