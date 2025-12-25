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
ll n,q;
ll ca=1;
void solve ()
{
    cin>>n>>q;
    if (n==0 and q==0)return;
    cout<<"CASE# "<<ca++<<":"<<endl;
    vector<ll>vv(n);
    for (int i=0;i<n;i++)cin>>vv[i];
    sort(vv.begin(),vv.end());
    while (q--){
        ll temp;cin>>temp;
        ll l=0,r=n-1;
        ll ans=-1;
        while (l<=r){
            ll mid=(l+r)/2;
            if (vv[mid]==temp){
                ans=mid;
                r=mid-1;
            }
            else if (vv[mid]>temp){
                r=mid-1;
            }else l=mid+1;
        }
        if (ans==-1){
            cout<<temp<<" not found"<<endl;
        }else cout<<temp<<" found at "<<ans+1<<endl;
    }
}

int main ()
{
    speed;
    // int tt;
    // cin >> tt;
    while (1)
    {
        solve();
        if (n==0 and q==0)return 0;
    }
    return 0;
}