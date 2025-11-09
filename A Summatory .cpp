//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp " "
#define endl '\n'
using namespace std;
const ll Mod=1000000003;
const ll N=1000000+5;
vector<ll>vv(N,0);
void solve ()
{
    ll x;cin>>x;
    cout<<vv[x]%Mod<<endl;
}
int main ()
{   
    speed;
    ll sum=0;
     for (int i=1;i<=N;i++){
        ll temp=(((i%Mod)*((i%Mod)+1))/2)%Mod;
        temp=((temp%Mod)*(temp%Mod))%Mod;
        sum=sum%Mod;
        sum+=(temp%Mod);
        vv[i]=sum;
    }
    int tt;
    cin>>tt;
    while (tt--)
    {
        solve ();
    }
    return 0;
}