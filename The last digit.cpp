#include <bits/stdc++.h>
using namespace std;
const int mod=10;
int power (int n, long long a){
    int ans=1%mod;
    while (a){
        if (a&1){
            ans=1LL*ans*n%mod;
        }
        n=1LL*n*n%mod;
        a>>=1;
    }
    return ans;
}
void solve ()
{
    int a;
    long long b;cin>>a>>b;
    if (a==0)cout<<0<<'\n';
    else if (b==0)cout<<1<<'\n';
    else cout<<power(a,b)<<'\n';
}
int main ()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}