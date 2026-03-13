//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const int N=1e7+9;
const ll mod=109546051211;
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
vector<ll>fac;
// ll mulmod (int n, int a){
//     ll ans=0;
//     while (a){
//         if (a&1){
//             ans=(ans+n)%mod;
//         }
//         n=(n+n)%mod;
//         a>>=1;
//     }
//     return ans;
// }
#define i128 __int128
void fact(int n){
    fac[0]=1;
    for (int i=1;i<=n;i++){
        fac[i]=(i128)fac[i-1]*i%mod;
    }
}
ll calculate (int n){
    ll res=1;
    for (int i=1;i<=n;i++){
        res=(i128)fac[i]*res%mod;
    }
    return res;
}
void solve ()
{
    int n;cin>>n;fac.resize(n+1);
    fact(n);
    // for (int i=0;i<=n;i++){
    //     cout<<i<<sp<<fac[i]<<endl;
    // }
    cout<<calculate(n)<<endl;
}

int main ()
{
    speed;
    solve();
    return 0;
}