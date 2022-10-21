// In this problem,given a least every number twice except one.
// The task to find this number using bitmask.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int t=1; t<=test; t++)
    {
        int n;
        cin>>n;
        vector<int>a(n);

        for(int i=0; i<n; i++)cin>>a[i];

        int xxor=0;
        for(int i=0; i<n; i++)
        {

            if(i==0)xxor=a[i];
            else xxor=(xxor ^ a[i]);
        }
        cout<<"Case #"<<t<<": "<<xxor<<endl;

    }

    return 0;
}
