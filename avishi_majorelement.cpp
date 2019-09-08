//MAJOR ELEMENT 


#include<iostream>
#include<climits>

using namespace std;

// main funtion
int main(int argc,char **argv)
{
	string stringarg;
	stringarg=argv[1];
	int arr[10000];
	int index=0;
	int n=stringarg.size();
	
	for(int i=0;i<n;i++)
	{
		int num=stringarg[i]-48;
		i++;
		while(stringarg[i]!=32&&i!=n)
		{
			num=(num*10)+(stringarg[i]-48);
			i++;
		}
		arr[index]=num;
		index++;
	}
	
	int maxvalue=INT_MIN;
	
	for(int i=0;i<index;i++)
	{
		if(arr[i]>maxvalue)
		maxvalue=arr[i];
	}
	
	int val[maxvalue+1];
	
	for(int i=0;i<=maxvalue;i++)
	{
		val[i]=0;
	}
	
	for(int i=0;i<index;i++)
	{
		val[arr[i]]++;
	}
	
	int flag=0;
	
	for(int i=0;i<=maxvalue;i++)
	{
		if(val[i]>=index/2)
		{
			cout<<i;
			flag=1;
		}
	
	}
	if(flag==0)
	cout<<"NONE";
}


