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
pair<bool,double> check (double val){
    double temp=8*val*val*val*val + 7*val*val*val + 2*val*val + 3*val + 6;
    if (abs(temp-x)<1e-5)return make_pair(true,temp);
    return make_pair(false,temp);
}
void solve ()
{
    cin>>x;
    // if (x<0){
    //     cout<<"No solution!"<<endl;
    //     return;
    // }
    
    double l=0,r=100;
    ll iterator=100;
    while (iterator--){
        double mid=(l+r)/2; 
        auto [flag,val]=check(mid);
        if (flag){
            cout<<fixed<<setprecision(10)<<mid<<endl;
            return;
        }else{
            if (val>=x){
                r=mid;
            }else l=mid;
        }
    }
    cout<<"No solution!"<<endl;
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