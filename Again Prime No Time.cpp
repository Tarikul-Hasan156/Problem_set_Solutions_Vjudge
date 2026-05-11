//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define sp ' '
#define endl '\n'
using namespace std;
const ll N=1e5+9;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
      x += 0x9e3779b97f4a7c15ULL;
      x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
      x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
      return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
      static const uint64_t FIXED_RANDOM =
          chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
  }
};
int ca=1;
void solve ()
{
    int m,n;cin>>m>>n;
    unordered_map<int,int,custom_hash>mp,mp_m,ans;
    for (int i=2;i<=n;i++){
        int val=i;
        for (int j=2;1LL*j*j<=val;j++){
            while (val%j==0){
                mp[j]++;
                val/=j;
            }
            // if (val>1){mp[val]++;flag=false;}
        }
        if (val>1)mp[val]++;
    }
    cout<<"Case "<<ca++<<":"<<endl;
    for (int i=2;1LL*i*i<=m;i++){
        while (m%i==0){
            mp_m[i]++;
            m/=i;
        }
    }
    if (m>1)mp_m[m]++;
    int res=INT_MAX;
    for (auto [k,v]:mp_m){
        // cout<<k<<sp<<v<<endl;
        if (mp.count(k)){
           ans[k]=mp[k];
        }else{
            cout<<"Impossible to divide"<<endl;return;
        }
    }
    for (auto [k,v]:ans){
        // cout<<k<<sp<<v<<endl;
        res=min(res,v/(mp_m[k]));
    }
    if (res==0){
        cout<<"Impossible to divide"<<endl;return;
    }else cout<<res<<endl;
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