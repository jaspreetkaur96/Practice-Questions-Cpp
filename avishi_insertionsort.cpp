//Insertion Sort
#include<fstream>
#include<iostream>
#include<algorithm>


using namespace std;


//Main function
int main(int argc,char **argv)
{
	//declarimg input file
	
	
	ifstream inputfile(argv[1]);
	int array[10000];
	int x=0;
	while(inputfile)
	{
	    string inputstring;
	    inputfile>>inputstring;
	    int size=inputstring.size();
	    inputstring=inputstring+" ";
		for(int i=0;i<size;i++)
		{
		    int num=inputstring[i]-48;
			i++;
		    while(inputstring[i]!=32)
		    {
				num=(num*10)+inputstring[i]-48;
				i++;
		    }
        	array[x]=num;
        	x++;
    	}
	}

	int n=x;
	ofstream outputfile(argv[2]);
	for(int i=0;i<n;i++)
	{
		outputfile<<array[i]<<" ";
	}
	outputfile<<endl;
	
	for(int i=1;i<n;i++)
    {
		int val=array[i];
        int x=i-1;
        while(array[x]>array[i]&&x>-1)
        {
            x--;
        }
        x++;
        int m=i-1;
       	for(m=i-1;m>=x;m--)
       	{
           array[m+1]=array[m];
       	}
       	array[m+1]=val;

		for(int i=0;i<n;i++)
    	{
			outputfile<<array[i]<<" ";
    	}
    }	
}

