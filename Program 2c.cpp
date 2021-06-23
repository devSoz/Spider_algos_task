//stairs problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



#define M  1000000007;  //for the modulo

int main()
{
    int n, bcnt;
    cin>>n>>bcnt;
    int b[bcnt] ;
   //get broken stair array
    for(int i=0; i<bcnt; i++)
        cin >> b[i];
        
	//if number of stair is 1 return possible count as 1
        if (n == 1)
        cout<< 1;

        else{
    		long long int dp[n + 1];  //array to store value of every step using dynamic programming

    	for (int i = 0; i < n; i++)	dp[i]=-1;  //set all stair to -1 initially and then to 0 for broken ones alone

    	for (int i = 0; i < bcnt; i++)	dp[b[i]] = 0;

    	dp[0] = 1;
    	dp[1] = (dp[1] == -1) ? 1 : dp[1];
    	for (int i = 2; i <= n; ++i) {
        	if (dp[i] == 0)	continue; //if broken stair proceed to next
        	dp[i] = dp[i - 1] + dp[i - 2]; //for current stair to reach previous and previous to previous (step 1 or 2 possible)
        	dp[i] %= M; //as the number can be huge, take modulo
    }
    
    cout << dp[n]; 
        }
        
    return 0;
}
