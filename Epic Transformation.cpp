//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;

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

void solve ()
{
    ll x;cin>>x;
    unordered_map<ll,ll,custom_hash>mp;
    for (int i=0;i<x;i++){
        ll val;cin>>val;
        mp[val]++;
    }
    if (mp.size()==1){
        auto it=mp.begin();
        cout<<it->second<<endl;return;
    }
    priority_queue<ll>pq;
    for (auto it:mp){
        pq.push(it.second);
    }
    while (pq.size()>=2){
        ll val1=pq.top();
        pq.pop();
        ll val2=pq.top();
        pq.pop();
       val1--;
       val2--;
       if (val1!=0)pq.push(val1);
       if (val2!=0)pq.push(val2);
        // if (res!=0){
        //     pq.push(res);
        // }
    }
    if (pq.size()==0){
        cout<<0<<endl;return;
    }
    cout<<pq.top()<<endl;
    
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