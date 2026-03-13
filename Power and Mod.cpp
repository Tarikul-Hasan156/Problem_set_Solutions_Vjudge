//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e5+9;
#define ull unsigned long long
#define i128 __int128
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
i128 read(){
    string s;cin>>s;
    i128 ans=0;
    for (int i=0;i<s.size();i++){
        ans=ans*10+s[i]-'0';
    }
    return ans;
}
ull mulmod(ull a, ull b, i128 mod){
    ull res=0;
    while (b){
        if (b&1){
            res=((i128)res+a)%mod;
        }
        a=((i128)a+a)%mod;
        b>>=1;
    }
    return res;
}
ull power(ull a, ull b, i128 mod){
    ull ans=1%mod;
    while (b){
        if (b&1){
            ans=mulmod(ans,a,mod)%mod;
         }
       a=mulmod(a,a,mod)%mod;
       b>>=1;
    }
    return ans;
}
void solve ()
{
    ull a,b;cin>>a>>b;
    i128 mod=0;
    mod=read();
    cout<<power(a,b,mod)<<endl;

}

int main ()
{
    speed;
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}