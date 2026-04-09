//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
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

//   size_t operator()(uint64_t x) const {
//       static const uint64_t FIXED_RANDOM =
//           chrono::steady_clock::now().time_since_epoch().count();
//       return splitmix64(x + FIXED_RANDOM);
//   }
// };
int n;
int sod[N],nod[N],spf[N];
int lpf (int n){
    return spf[n];
}
int d(int n){
    return nod[n];
}
int S (int n){
    return sod[n];
}
void solve ()
{
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;i++)cin>>a[i];
    // for (int i=1;i<=n;i++){
    //     cout<<a[i]<<sp;
    // }cout<<endl;
    for (int i=1;i<=n;i++){
        int val=a[i];
        map<int,int>mp;
        while (val>1){
            mp[spf[val]]++;
            val/=spf[val];
        }
        int total=0;
        for (auto [k,v]:mp){
            total+=v;
        }
        auto it=mp.rbegin();
        cout<<lpf(a[i])<<sp<<it->first<<sp<<mp.size()<<sp<<total<<sp<<d(a[i])<<sp<<S(a[i])<<endl;
    }
}
int main ()
{
    speed;
    for (int i=1;i<N;i++)spf[i]=i;
    for (int i=1;i<N;i++){
        for (int j=i;j<N;j+=i){
            nod[j]++;
            sod[j]+=i;
        }
    }
     for (int i=2;i<N;i++){
        for (int j=i;j<N;j+=i){
            spf[j]=min(spf[j],i);
        }
     }
    solve();
    return 0;
}