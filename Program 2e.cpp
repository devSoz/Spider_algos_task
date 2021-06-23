//Maximum element in array 2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int l, r, q, n;
    long v;
    cin>>n>>q;
     long long int a[n+2],temp[n+2],max=0;
    //the generic logic times out for large numbers and queries, so maintaining log of array with from and to range specifying the value.
    for(int i=0; i<=n; i++)
    {
        a[i]=i;
        temp[i]=0;
    }
  
    //increment v for the start range and subtract for r+1 (so finally use this log array to add value into the original array
    for(int i=1; i<=q; i++)
    {
        cin>>l>>r>>v;
        temp[l]+=v;
        if((r+1)<=n) {
            temp[r+1]=temp[r+1]-v;}
    }
   
    //add the overall value to be added into the original natural numbers and find max
    a[1] += temp[1];
    max=a[1];
    for(int i=2; i<=n; i++)
    {
        temp[i] += temp[i-1];
        a[i] += temp[i];
        if (a[i] > max) max=a[i];
    }
    
    cout<<max;
        
    return 0;
}
