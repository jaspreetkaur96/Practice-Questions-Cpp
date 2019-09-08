
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <bits/stdc++.h> 
using namespace std; 
  
int convertStrtoArr(string str, int arr[]) 
{ 
    int j = 0, i; 
    for (i = 0; str[i] != '\0'; i++) { 
  
        if (str[i] == ' ') 
		{   
            j++; 
        } 
        else 
		{ 
            arr[j] = arr[j] * 10 + (str[i] - 48); 
        } 
    }
	
	return j; 
} 

int main(int argc, char *argv[])
{
	int n=strlen(argv[1]);
	int arr[n] = { 0 }; 
	int i;

	n=convertStrtoArr(argv[1],arr);


	switch (atoi(argv[2]))
	{
	case 1:
		for (i=1;i<=n;i++) 
		{
			if (arr[0]<arr[i])
			{
			arr[0]= arr[i];	
	    	}		
		}
		cout<< arr[0];
		break;
	case 2:
			for (i=1;i<=n;i++)
			{
				if (arr[0]>arr[i])
				{
					arr[0]=arr[i];
				}
			}
			cout<< arr[0];
			break;
	default:
		break;
	}
}
