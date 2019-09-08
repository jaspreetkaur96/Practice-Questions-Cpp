//Find Sum

//Header files
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;


int main(int argc,char **argv)
{
	ifstream inf(argv[1]);
	int val[10000];
	int x=0;
	while(inf)
	{
	    string input;
	    inf>>input;
	    int size=input.size();
	    input=input+" ";

		for(int i=0;i<size;i++)
	    {
	      	int num=input[i]-48;
			i++;
	        while(input[i]!=32)
	        {
				num=(num*10)+input[i]-48;
				i++;
	        }
	        val[x]=num;
	        x++;
	    }
	}
	
	int n=x;
	ofstream outf(argv[2]);
	int element=val[n-1];
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
		        if(val[i]+val[j]==element)
				outf<<val[i]<<","<<val[j]<<endl;
		}
	}
}

