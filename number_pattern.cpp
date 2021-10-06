/*
        1
      2 1 2
    3 2 1 2 3 
  4 3 2 1 2 3 4
5 4 3 2 1 2 3 4 5
*/
#include<iostream>
using namespace std;
int main()
{
  int i, j,k,z,l;                          
    for(i=5;i>=1;i--)                
    {
      for(j=(i-1); j>=1; j--)      
      {
          cout<<"  ";
      }
      for(k=(6-i); k>=1 ; k--)
      {
        cout<<k<<" ";
      }
      l=1;
      for(z=(5-i); z>=1; z--)
      {
        cout<<++l<<" ";
      }
      cout<<"\n";
    }
    return 0;
}
