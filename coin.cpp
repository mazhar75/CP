#include<bits/stdc++.h>
#define sz 1000010
#define INF 99999999
using namespace std;
int dp[101][sz];
int n;
vector<int>a(n);
int solve(int i,int x)
{
    if(x<0)return INF;
    if(i==n)
    {
        if(x==0)return 0;
        return INF;
    }
    if(dp[i][x]!=-1)return dp[i][x];
    int p=1+solve(i,x-a[i]);
    int q=solve(i+1,x);
    dp[i][x]=min(p,q);
    return dp[i][x];




}
void init(int x)
{

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=x; j++)
        {
            dp[i][j]=-1;
        }
    }


}
int main()
{
    int x;
    cin>>n>>x;
    for(int i=0; i<n; i++)cin>>a[i];
    int i=0;
    init(x);
    int cnt=solve(i,x);
    cout<<cnt<<endl;
    return 0;
}
