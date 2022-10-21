#include<bits/stdc++.h>
#define sz 5000010
#define ll long long int
using namespace std;
vector<pair<int,int>>tree(sz);
vector<pair<int,int>>segment(sz);
vector<int>bit(sz);
void update(int ind,int lb,int ub,int pos,int val)
{
    if(pos<lb || pos>ub)return;
    if(lb==ub)
    {
        if(lb==pos)
        {
            if(val==0)
            {
                tree[ind].first=1;
                tree[ind].second=0;
            }
            else
            {

                tree[ind].first=0;
                tree[ind].second=1;
            }
            segment[ind]= {pos,pos};
        }
        return;
    }
    int mid = (lb+ub)/2;
    if(pos<=mid) update(2*ind,lb,mid,pos,val);
    else update(2*ind+1,mid+1,ub,pos,val);
    tree[ind]= {tree[2*ind].first+tree[2*ind+1].first,tree[2*ind].second+tree[2*ind+1].second};
    segment[ind]= {min(segment[2*ind].first,segment[2*ind+1].first),max(segment[2*ind].second,segment[2*ind+1].second)};



}
int query(int ind,int lb,int ub,int qlb,int qub)
{

    if(qlb <= lb && ub <= qub)
    {
        cout<<"node = "<<" "<<ind<<endl;
        cout<<tree[ind].first<<" "<<tree[ind].second<<endl;
        if(tree[ind].first==tree[ind].second)
        {
            return abs(segment[ind].second-segment[ind].first);
        }
        else return 0;
    }
    if(qub < lb || qlb > ub) return 0;

    int mid =  (ub+lb)/2;
    int ret = 0;
    int ans=0;

    ret = query(ind*2,lb,mid,qlb,qub);
    ans=max(ans,ret);
    ret =max(query(ind*2+1,mid+1,ub,qlb,qub),ret);
    ans=max(ans,ret);
    return (ans+1);


}
int main()
{
    //freopen("input.txt","r+",stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0; i<n; i++)
    {
        int x=s[i]-'0';
        cout<<x<<endl;
        update(1,0,n-1,i,x);
    }
    cout<<query(1,0,n-1,0,n-1)<<endl;
    return 0;
}
