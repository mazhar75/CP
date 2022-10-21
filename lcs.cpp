#include<bits/stdc++.h>
#define sz 1000
using namespace std;
int mem[sz][sz];
string p,q;
int lcs(int i,int j,int n,int m)
{
    if(i==n || j==m)return 0;
    int ans=0;
    if(p[i]==q[j])
    {
        ans=1+lcs(i+1,j+1,n,m);
    }
    else
    {
        int val1=lcs(i,j+1,n,m);
        int val2=lcs(i+1,j,n,m);
        ans=max(val1,val2);
    }
    mem[i][j]=ans;
    return mem[i][j];


}
int main()
{
    cin>>p>>q;
    int n=p.length();
    int m=q.length();
    int i=0,j=0;
    int mx=lcs(i,j,n,m);
    cout<<mx<<endl;
    return 0;
}
