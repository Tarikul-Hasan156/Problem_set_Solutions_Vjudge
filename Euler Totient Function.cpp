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
ll T (int n){
    ll res=n;
    set<int>se;
    for (int i=2;i*i<=n;i++){
        if (n%i==0){
            while (n%i==0){
            n/=i;
           }
          se.insert(i);
        }
    }
    if (n>1)se.insert(n);
    for (auto val:se){
        res=(res/val)*(val-1);
    }
    return res;
}
void solve ()
{
    int n;cin>>n;
    cout<<T(n)<<endl;
}

int main ()
{
    speed;
    int t;cin>>t;
    while (t--){
        solve();
    }
    return 0;
}