//Pattern Matching

#include <bits/stdc++.h>
#include<sstream>


using namespace std;

//Main function
int main (int argc,char* argv[])
{
 	string val1=argv[1];
	stringstream ss(val1);
   
   string val2;
   val2 = argv[2];
   
	unsigned int i = val1.find(val2); 
    if (i != string::npos) 
        cout <<(i+1) ; 
        else
        cout<<"0";
   
   
   return 0;
}
