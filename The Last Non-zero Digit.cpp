//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e5+9;

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
const int mod=(int)1e9;
ll last (ll n){
    while (n>0 and n%10==0){
        n/=10;
    }
    return n%mod;
}
ll nPr (int n,int r){
    ll ans=1;
    for (int i=n;i>=n-r+1;i--){
        ans*=i;
        ans=last(ans); 
    }
    return ans;
}
void solve ()
{
    int n,r;
    while (cin>>n>>r){
        // if (r==0){
        //     cout<<1<<endl;continue;
        // }
        cout<<nPr(n,r)%10<<endl;
    }
}

int main ()
{
    speed;
    solve();
    return 0;
}