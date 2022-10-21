#include<bits/stdc++.h>
#define ll long long int
#define sz 1000000
using namespace std;
vector<int>permutation;
bool choosen[sz];
int n,m;

const ll MOD = 1e9 + 7;
void per()
{
    if(permutation.size()==m)
    {
        for(auto x: permutation)
        {
            cout<<x<<" ";
        }
        cout<<endl;

    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(choosen[i])continue;
            choosen[i]=true;
            permutation.push_back(i);
            per();
            choosen[i]=false;
            permutation.pop_back();

        }

    }


}

int main()
{
    //freopen("00_input.txt","r+",stdin);
    // freopen("00_input.txt","r+",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    per();

    return 0;

}


