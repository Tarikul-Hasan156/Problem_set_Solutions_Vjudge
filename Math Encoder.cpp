//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
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
int test=1;
int pw[N];
const int mod=1e9+7;
void solve ()
{
    int n;cin>>n;
    int a[n+1];
    for (int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ll ans=0;
    // for (int i=1;i<=n;i++)cout<<a[i]<<sp;cout<<endl;
    for (int i=1;i<=n;i++){
        ll min_contrib=(1LL*pw[n-i]*a[i])%mod;
        ll max_contrib=(1LL*pw[i-1]*a[i])%mod;
        ans+=max_contrib-min_contrib;
        ans%=mod;
    }
    cout<<"Case #"<<test++<<": "<<ans<<endl;
}

int main ()
{
    speed;
    pw[0]=1;
    for (int i=1;i<N;i++){
        pw[i]=pw[i-1]*2%mod;
    }
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}