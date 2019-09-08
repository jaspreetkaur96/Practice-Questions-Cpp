//Quick Sort

#include<algorithm>
#include<iostream>
#include<fstream>


//Namespace declaration
using namespace std;


int ch=0;
int pivot;


void function(int array[],int a,int b)
{
	int temp=array[b];
	for(int x=(b-1);x>=a;x--)
	{
		array[x+1]=array[x];
	}
	array[a]=temp;
	a++;
	b++;
}

//print your output
void outputprint(fstream& outputfile,int array[],int final[])
{
	for(int y=0;y<pivot;y++)
	{
		for(int b=0;b<ch;b++)
		{
			if(array[y]==final[b])
			{
				outputfile<<"(";
			}
		}
		outputfile<<array[y];
        for(int b=0;b<ch;b++)
		{
			if(final[b]==array[y])
			{
				outputfile<<")";
			}
		}
		if(y!=(pivot-1))
		{
			outputfile<<",";
		}
	}
	outputfile<<endl;
}
//
int function2(fstream& outputfile,int array[],int l,int h,int final[])
{
	int pivot=array[h];
	int i=l-1;
	int j=l;

	for(;j<h;j++)
	{
		if(array[j]<=pivot)
		{
			i++;
			function(array,i,j);
		}
	}
	function(array,i+1,h);

	final[ch]=array[i+1];
	ch++;
	outputprint(outputfile,array,final);
	return(i+1);
}



//recursive quick sort
void quicksortalgorithm(fstream& outputfile,int array[],int final[],int l,int h)
{
	int t;
	if(l<=h)
	{
		t=function2(outputfile,array,l,h,final);

		quicksortalgorithm(outputfile,array,final,l,t-1);
		quicksortalgorithm(outputfile,array,final,t+1,h);

	}
}


int main(int argc,char *argv[])
{
	int array[1000];
	
	//input file
	fstream inputfile;
    inputfile.open(argv[1],ios::in);
    int i=0;
    while(inputfile)
    {
        inputfile>>array[i];
        i++;
    }
    int total=i-1;
    pivot=total;
	inputfile.close();
    int final[1000];
    
    //output file
    fstream outputfile;
    outputfile.open(argv[2],ios::out);
    outputfile<<array[0];
	for(int o=1;o<total;o++)
	{
		outputfile<<","<<array[o];
	}
	outputfile<<endl;
	quicksortalgorithm(outputfile,array,final,0,total-1);

	outputfile<<array[0];
	for(int o=1;o<total;o++)
	{
		outputfile<<","<<array[o];
	}

	return 0;
}

