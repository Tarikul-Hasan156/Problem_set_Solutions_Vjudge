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

void solve ()
{
    int val;cin>>val;
    map<int,int>mp;
    for (int i=2;i*i<=val;i++){
        if (val%i==0){
            while (val%i==0){
                val/=i;
                mp[i]++;
            }
        }
    }
    if (val>=2)mp[val]++;
    // for (auto[value,cnt]:mp){
    //     cout<<value<<sp<<cnt<<endl;
    // }
    if (mp.empty()){
        cout<<"NO"<<endl;return;
    }
    set<int>se;
    if (mp.size()>=2){
        ll cnt=0;
        for (auto[value,cn]:mp){
            if (cnt==2)break;
            se.insert(value);cnt++;
            mp[value]--;
            if (mp[value]==0)mp.erase(value);
        }
        cnt=1;
        for (auto[value,cn]:mp){
            for (int i=0;i<cn;i++)cnt*=value;
        }
        if (cnt<2){cout<<"NO"<<endl;return;}
        se.insert(cnt);
        if (se.size()>=3){
            cout<<"YES"<<endl;
            for (auto x:se)cout<<x<<sp;cout<<endl;return;
        }else cout<<"NO"<<endl;
    }else{
        ll cn=0,_value=0;
        for(auto[value,cnt]:mp){
            cn=cnt;
            _value=value;
         }
         if (cn<6){
            cout<<"NO"<<endl;return;
         }else{
            se.insert(_value);
            cn--;
            se.insert(_value*_value);
            cn-=2;
            ll rem=1;
            for (int i=0;i<cn;i++)rem*=_value;
            se.insert(rem);
            cout<<"YES"<<endl;
            for (auto x:se)cout<<x<<sp;cout<<endl;return;
         }
    }
    

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