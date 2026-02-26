#include <bits/stdc++.h>
#define ll unsigned long long
#define endl '\n'
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll n;cin>>n;
        if (n==1){
            cout<<1<<endl;
        }else if (n==2){
            cout<<5<<endl;
        }else{
            // cout<<1LL*n*(n+2)*(2*n+1)/8<<endl;
            cout<<1LL*n*n*2-5<<endl;
        }
    }
    return 0;
}