#include<bits/stdc++.h>
#define sz 1000000
using namespace std;
int root[sz];
int dp[sz];
int n;
vector<int>a;
int fun(int i)
{
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int ans=0;
    for(int j=i+1; j<a.size(); j++)
    {
        if(a[j]>a[i])
        {
            int sub=fun(j);
            if(sub>ans)
            {
                ans=sub;
                root[i]=j;
            }
        }
    }
    dp[i]=ans+1;
    return dp[i];

}
void init()
{
    for(int i=0; i<n; i++)
    {
        dp[i]=-1;
        root[i]=-1;
    }
    int ans=0;
    int index=-1;
    for(int i=0; i<n; i++)
    {
        int result=fun(i);
        if(result>ans)
        {
            ans=result;
            index=i;
        }
    }
    cout<<ans<<endl;
    /**vector<int>lis;
    if(index!=-1)
    {
        while(index!=-1)
        {
            lis.push_back(index);
            index=root[index];
        }
    }
    cout<<lis.size()<<endl;
    /**for(int i=0; i<lis.size(); i++)
    {
        cout<<lis[i]<<" ";
    }
    cout<<endl;
    */
}
int main()
{

    cin>>n;
    int x;


    for(int i=0; i<n; i++){
      cin>>x;
      a.push_back(x);
    }
    init();


    return 0;
}
