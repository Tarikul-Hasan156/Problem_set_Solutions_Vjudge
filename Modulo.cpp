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
int c=1;
void solve ()
{
    int n;cin>>n;
    priority_queue<pair<ll,int>>q;
    for (int i=1;i<=n;i++){
        ll val;cin>>val;
        q.push({val,i});
    }
    int Q;cin>>Q;
    while (Q--){
        ll mod;cin>>mod;
        while (!q.empty()){
            auto [val,index]=q.top();
            if (val<mod)break;
            q.pop();
            q.push({val%mod,index});
        }
    }
    cout<<"Case"<<sp<<c++<<":"<<endl;
    ll a[n+1];
    while (!q.empty()){
        auto [val,index]=q.top();
        q.pop();
        a[index]=val;
    }
    for (int i=1;i<=n;i++)cout<<a[i]<<(i<n?' ':'\n');
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