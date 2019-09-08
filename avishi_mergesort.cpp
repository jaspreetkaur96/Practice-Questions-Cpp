#include<iostream>
using namespace std;

void mergesortalgorithm(int *array,int size)
{
	if(size==1)
	return;
	int half_1[500],half_2[500];
	int array1_size=size/2;
	int array2_size=size-array1_size;
	for(int i=0;i<array1_size;i++)
	{
		half_1[i]=array[i];
	}
	int k=0;
	for(int i=array1_size;i<size;i++)
	{
		half_2[k]=array[i];
		k++;
	}
	mergesortalgorithm(half_1,array1_size);
	mergesortalgorithm(half_2,array2_size);
	
	int i=0,j=0;
	k=0;
	while(i<array1_size&&j<array2_size)
	{
		if(half_1[i]<half_2[j])
		{
			array[k]=half_1[i];
			i++;
			k++;
		}
		else if(half_1[i]>half_2[j]){
			array[k]=half_2[j];
			j++;
			k++;
		}
		else if(half_1[i]==half_2[j]){
			array[k]=half_1[i];
			k++;
			i++;
			array[k]=half_2[j];
			k++;
			j++;
		}
	}
	while(i<array1_size)
	{
		array[k]=half_1[i];
		i++;
		k++;
	}
	while(j<array2_size)
	{
		array[k]=half_2[j];
		j++;
		k++;
	}

}
int main(int argc,char**argv)
{
	string str;
	str=argv[2];
	int array[500];
	int k=0;
	int size=str.size();
	for(int i=0;i<size;i++)
	{
		int number=str[i]-48;
		i++;
		while(str[i]!=32&&i!=size)
		{
			number=(number*10)+(str[i]-48);
			i++;
		}
		array[k]=number;
		k++;
	}
	
	mergesortalgorithm(array,k);
	for(int i=0;i<k;i++)
	{
		cout<<array[i]<<" ";
	}
}

