#include<iostream>
#include<vector>
using namespace std;
int knapsack(int cap,vector<int>&wt,vector<int>&p,int n){
vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
for(int i=1;i<=n;i++)
    {
        for(int w=1;w<=cap;w++)
        {
            if(wt[i-1]<=w)
                dp[i][w]=max(p[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);


        else
            dp[i][w]=dp[i-1][w];
    }
}
return dp[n][cap];}
int main()
{
    int cap=8;
    vector<int>wt={3,4,6,5};
    vector<int>p={2,3,1,4};
    int n =wt.size();
    cout<<"max val:"<<knapsack(cap,wt,p,n)<<endl;
    return 0;
}