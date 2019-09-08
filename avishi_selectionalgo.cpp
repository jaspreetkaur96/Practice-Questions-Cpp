//Selection Sort Algorithm

#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;

//sorting function
int selectionsort(int array[],int n,int x)
{
	sort(array,array+n);
	int result=array[x-1];
	return result;
}

//main driving function
int main(int argc,char *argv[])
{
    int array[1000];
    //input file 
    fstream inputfile;
    inputfile.open(argv[1],ios::in);
    int i=0;
    
    //reading input file
    while(inputfile)
    {
        inputfile>>array[i];
        i++;
    }
    int v=array[i-2];
    int total=i-2;
    
    inputfile.close();
    
	//sorting
    int k=selectionsort(array,total,v);
    
    //output file
    fstream outputfile;
    outputfile.open(argv[2],ios::out);
    
    //print putput
    outputfile<<k;
    outputfile.close();
    return 0;
}
