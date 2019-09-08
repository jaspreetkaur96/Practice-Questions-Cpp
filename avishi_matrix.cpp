//matrix multiplication

#include<iostream>
#include<fstream>
#include<climits> 


using namespace std; 

//Print output
void printoutput(fstream& infile,int i,int j,int n,int s[], int &t) 
{ 
	if(i==j) 
    { 
		infile<<'A'<<t;
		t++; 
        return; 
    } 
    
    infile<<"("; 
    printoutput(infile,i,s[n*i+j],n,s,t);
	printoutput(infile,s[n*i+j]+1,j,n, s,t); 
    infile<<")";
} 

//Ordering matrix
void matrixorder(fstream& infile,int arr[], int n) 
{ 
    int cost[n][n]; 
    int s[n][n]; 
    for (int i=1;i<n;i++) 
        cost[i][i]=0; 
 
    for (int l=2;l<n;l++) 
    { 
        for (int i=1;i<n-l+1;i++) 
        { 
            int j=i+l-1; 
            cost[i][j]=INT_MAX; 
            for (int k=i;k<=j-1;k++) 
            { 
                int c=cost[i][k]+cost[k+1][j]+arr[i-1]*arr[k]*arr[j]; 
                if (c<cost[i][j]) 
                { 
                    cost[i][j]=c; 
                    s[i][j]=k; 
                } 
            } 
        } 
    } 
  
    int t=1;
    printoutput(infile,1,n-1,n,(int *)s,t); 
  
} 
 
int main(int argc,char *argv[]) 
{ 
    int arr[1000];
    fstream infile;
    infile.open(argv[1],ios::in);
    int i=0;
    while(infile)
    {
        infile>>arr[i];
        i++;
    }
    infile.close();
	int n=i-1;
	fstream outfile;
	outfile.open(argv[2],ios::out);
    matrixorder(outfile,arr,n);
	outfile.close(); 
    return 0; 
}
