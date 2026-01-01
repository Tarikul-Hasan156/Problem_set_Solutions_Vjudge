//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e6+9;

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
vector<ll>vv(N);
vector<bool>check;
vector<int>pre(N);
void solve ()
{
    // cout<<boolalpha<<is_prime(7)<<endl;
    ll x,y;cin>>x>>y;
    // cout<<check[y]<<sp<<check[x]<<endl;
    cout<<pre[y]-pre[x-1]<<endl;
}

int main ()
{
    speed;
    for (int i=1;i<=1e6;i++){
        for (int j=i;j<=1e6;j+=i){
            vv[j]+=i;
        }
    }
    ll mx=*max_element(vv.begin(),vv.end());
    check.resize(mx+1,true);
    check[0]=false;
    check[1]=false;
    for (int i=2;1LL*i*i<=mx;i++){
        if (check[i]){
            for (int j=1LL*i*i;j<=mx;j+=i){
                check[j]=false;
             }
        }
        
    }
    // for (int i=1;i<=11;i++)cout<<check[i]<<sp;cout<<endl;
    for (int i=1;i<=1e6;i++){
        pre[i]=pre[i-1]+(check[vv[i]]?1:0);
    }
    // for (int i=1;i<=11;i++)cout<<check[i]<<sp;cout<<endl;
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}