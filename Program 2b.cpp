//Maximum possible sum
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int b[n], sum=0, x;
    //get input
    for(int i=0; i<(n-1); i++)
        cin>>b[i];
    
    //maintain sum to take previous or current
    sum=b[0]+b[n-2];
    for(int i=1; i<(n-1); i++)
    {
        x = (b[i]<b[i-1]) ? b[i] : b[i-1];
        sum+=x;
    }
    cout<<sum;
    
    return 0;
}

