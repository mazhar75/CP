#include<bits/stdc++.h>
#define sz 1000
#define inf 1e10
using namespace std;
int grid[sz][sz];
int dp[sz][sz];
int n,m;
int called=0;
int solve(int i,int j)
{
    called++;
    if(i>=n || j>=m)return inf;
    if(i==n-1 && j==m-1)return dp[n-1][m-1];
    if(dp[i][j]!=-1)
    {
        cout<<dp[i][j]<<endl;
        return dp[i][j];
    }
    dp[i][j]=grid[i][j]+min(solve(i+1,j),solve(i,j+1));
    return dp[i][j];





}


void init()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dp[i][j]=-1;
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }

    init();
    int i=0,j=0;
    int ans=solve(i,j);
    cout<<"----------"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Funtion called=="<<called<<endl;
    cout<<ans<<endl;
    return 0;

}

