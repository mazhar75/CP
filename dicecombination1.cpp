#include<bits/stdc++.h>
#define sz 1000010
#define ll long long int
#define mod 10000000007
using namespace std;
vector<ll>dp(sz,-1);
vector<ll>a(110);
ll solve(int n,ll x)
{
    if(x<0)return 0;
    if(x==0)return 1;
    if(dp[x]!=-1)
    {
        return dp[x];
    }
    ll cur=0;
    for(int i=0; i<n; i++)
    {
        (cur+=solve(n,(x-a[i])))%=mod;
    }
    return dp[x]=cur;


}


int main()
{
    int n;
    ll x;
    cin>>n>>x;
    for(int i=0; i<n; i++)cin>>a[i];
     cout<<solve(n,x)<<endl;
    return 0;
}
