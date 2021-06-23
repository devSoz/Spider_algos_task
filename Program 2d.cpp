//Maximum element in array
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
    unsigned long long int a[n];
    
    for(int i=0; i<n; i++)
        a[i]=i+1; //initial array of natural number
    //add/subtract v for every query in the range of l and r
    for(int i=0; i<q; i++)
    {
        cin>>l>>r>>v;
        for(int j=(l-1); j<r; j++)
        {
            a[j]+=v;
        }
    }
    
    //find the max and print
    int t=0;
    for(int i=0; i<n; i++)
    {
        if(a[t]<a[i])
            t=i;
    }
    cout<<a[t];
    return 0;
}

