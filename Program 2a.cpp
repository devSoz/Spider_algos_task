#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int t, n, flag=1, open=0, close=0, x, tclose=0, topen=0;
    cin>>t;
    int output[t];
    string s;
    
    for(int i=0; i<t; i++)
    {
        tclose=0;
        topen=0;
        flag=1; //to track if any of invalid condition and set accordingly
        x=0;
        open=0;
        close=0;
        cin>>s;
        
        if(s[0]=='>')
            output[i]=0;
        else
        {
            n = s.length();
            
            for(int j=0; j<n; j++)
            {
                if(open>(n/2)) //if opening bracket is more than half, then no valid pair till now, it should be complete invalid
                {
                    if(x==0)
                        flag=0;
                    break;
                }
		// increment open and close counters
                if(s[j]=='<')
                    open++;
                else if(close<open)
                {
                    close++;
                }
                else
                    break;
		if there is already atleast one set of valid pair, proceed to next validation
                if(open==close)
                {
                    x=1;
                    topen+=open;
                    tclose+=close;
                    open=0;
                    close=0;
                }
            }    
        }
        
        if(flag==0)
            output[i]=0;
        else 
            output[i]=tclose*2;
        
    }
    
    for(int i=0; i<t; i++)
    {
        cout<<output[i]<<"\n";
    }                  
    return 0;
}
