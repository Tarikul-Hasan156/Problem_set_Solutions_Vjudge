//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;

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
ll x;
vector<ll>vv;
ll divide (ll l, ll r){
    if (l==r)return 0;
    ll mid=(l+r)/2;
    ll ans=divide(l,mid);
       ans+=divide(mid+1,r);
       vector<ll>v;
       for (int i=mid+1;i<=r;i++){
            v.push_back(vv[i]);
       }
       sort(v.begin(),v.end());
       for (int i=l;i<=mid;i++){
            ans+=lower_bound(v.begin(),v.end(),vv[i])-v.begin();
       }
       return ans;
}
void solve ()
{
    cin>>x;
    vv.resize(x);
    for (int i=0;i<x;i++)cin>>vv[i];
    ll res=divide(0,x-1);
    cout<<res<<endl;

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