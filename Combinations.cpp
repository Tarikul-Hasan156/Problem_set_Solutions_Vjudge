//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e6+2;

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
int c=1;
const int mod=1000003;
int power (int n, int a){
    n%=mod;
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
int fac[N],ifac[N];
void fact(){
    fac[0]=1;
    for (int i=1;i<N;i++){
        fac[i]=1LL*fac[i-1]*i%mod;
    }
    ifac[N-1]=power(fac[N-1],mod-2);
    for (int i=N-2;i>=0;i--){
        ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
    }
}
int nCr (int n, int r){
    if (n<0 or n<r)return 0;
    return 1LL*fac[n]*ifac[r]%mod*ifac[n-r]%mod;
}
// int nPr (int n, int r){
//     if (n<0 or n<r)return 0;
//     return 1LL*fac[n]*ifac[n-r]%mod;
// }
void solve ()
{
    int n,r;cin>>n>>r;
    cout<<"Case "<<c++<<": "<<nCr(n,r)<<endl;
    // cout<<nPr(n,r)<<endl;
}

int main ()
{
    speed;
    fact();
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}