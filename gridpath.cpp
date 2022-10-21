#include<iostream>
#define sz 1010
#define mod 1000000007
#define ll long long int
using namespace std;
char a[sz][sz];
ll dp[sz][sz];
void solve(int n)
{
    dp[0][0]=1;
   // cout<<dp[0][0]<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]=='*')
            {
                dp[i][j]=0;
            }
            else
            {
                if(i-1>=0 && j-1>=0)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    dp[i][j]=dp[i][j]%mod;
                }
                else if(i-1>=0)
                {
                    dp[i][j]=dp[i-1][j];
                    dp[i][j]=dp[i][j]%mod;
                }
                else if(j-1>=0)
                {   //cout<<i<<" "<<j<<endl;
                   //cout<<dp[i][j-1]<<endl;
                    dp[i][j]=dp[i][j-1];
                    dp[i][j]=dp[i][j]%mod;
                }



            }
        }
    }



}
void init(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j]=0;
        }
    }
}
int main()
{
    //freopen("input.txt","r+",stdin);
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        for(int j=0; j<n; j++)
        {
            a[i][j]=s[j];
        }
    }
    init(n);
    solve(n);
   /** for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    cout<<dp[n-1][n-1]<<endl;

    return 0;
}

