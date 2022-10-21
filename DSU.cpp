#include<iostream>
#include<set>
#include<vector>
#define sz 100010
using namespace std;
int head[sz];
int find(int node)
{
    if(node==head[node])return node;
    return head[node]=find(head[node]);

}

void uni_on(int u,int v)
{
    int head_u=find(u);
    int head_v=find(v);
    if(head_u==head_v)return;
    head[head_v]=u;

}
void init(int n)
{
    for(int i=0; i<=n; i++)
    {
        head[i]=i;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    a[0]=0;
    for(int i=1; i<=n; i++)cin>>a[i];
    init(n);
    for(int i=1,u,v; i<=n; i++)
    {
        u=a[i];
        uni_on(i,u);

    }
    set<int>s;
    for(int i=1; i<=n; i++)
    {
        s.insert(find(i));
    }
    cout<<(s.size()-1)<<endl;


    return 0;
}
