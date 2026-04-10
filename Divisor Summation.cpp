//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const int N=500000+7;

// struct custom_hash {
//   static uint64_t splitmix64(uint64_t x) {
//       x += 0x9e3779b97f4a7c15ULL;
//       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
//       x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
//       return x ^ (x >> 31);
//   }
//
//   size_t operator()(uint64_t x) const {
//       static const uint64_t FIXED_RANDOM =
//           chrono::steady_clock::now().time_since_epoch().count();
//       return splitmix64(x + FIXED_RANDOM);
//   }
// };
int power (int n, int a){
    int ans=1;
    while (a){
        if (a&1){
            ans=1LL*ans*n;
        }
        n=1LL*n*n;
        a>>=1;
    }
    return ans;
}
int spf[N];
void solve ()
{
    int n;cin>>n;
    int val=n;
    map<int,int>mp;
    while (n>1){
        mp[spf[n]]++;
        n/=spf[n];
    }
    ll ans=1;
    for (auto [k,v]:mp){
        ans*=(power(k,v+1)-1)/(k-1);
    }
    cout<<ans-val<<endl;
}

int main ()
{
    speed;
    for (int i=2;i<N;i++)spf[i]=i;
    for (int i=2;i<N;i++){
        for (int j=i;j<N;j+=i){
            spf[j]=min(spf[j],i);
        }
    }
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}