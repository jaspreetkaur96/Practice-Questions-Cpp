//Binary search
#include <iostream>
#include <stdio.h>
#include <fstream> 
#include <string.h>
#include <stdlib.h>
using namespace std;
int comp;

//binary search
int binarysearchfunction(int array1[], int lowerlimit, int upperlimit, int element) 
{ 
if (upperlimit >= lowerlimit) { 
        int middleterm = (lowerlimit+upperlimit) / 2; 
        if (array1[middleterm] == element) 
       {comp++;
            return middleterm; 
  	} 
       else if (array1[middleterm] > element) 
       {
       	comp++;
       	return binarysearchfunction(array1, lowerlimit, middleterm - 1, element); 
	   }
            
  		else
  		{comp++;
		  return binarysearchfunction(array1, middleterm + 1, upperlimit, element); 
		  }
        
    } 
  
   
return -1;
}
  
//main function
int main(int argc,char** argv)
 { 
    ifstream file_in;
    ofstream file_out;
    
	string val1,val2;
    int array1[100],array2[100];
    int i=0,j=0; 
    file_in.open(argv[1]); 
    if(!file_in)
	{
		exit(1);
	}
	
    file_out.open(argv[2]); 
	if(!file_out)
	{
		exit(1);
	}
  	
	while(file_in>>array1[i]) 
	{
  		getline(file_in, val1 ,',');
		i++;
	}
	 
	 
	file_in.clear();
	file_in.seekg(0, ios::beg);
	while(file_in>>array2[j])
	{
	  getline(file_in, val2, '\n');
	  j++;

	}

	 
	int m, n, temp=0;
    for(m = 0; m <i; m++)
    {
        for(n = 0; n < i-m-1; n++)
        {
            if( array1[n] > array1[n+1])
            {
                temp = array1[n];
                array1[n] = array1[n+1];
                array1[n+1] = temp;
            } 
        }
    }
  

	for(int x=1;x<j;x++)
	{ 
		int element=array2[x];
	    comp=0;
	  	int result = binarysearchfunction(array1, 0, i-1 , element); 
        (result == -1) ? (file_out<<element<<"  not found  "<<endl) : (file_out<<element<<" found at position "<< result+1<< " after "<<comp<<" comparisons"<<endl ) ; 
    }
     
    file_in.close();
    file_out.close();
 	return 0;
} 


