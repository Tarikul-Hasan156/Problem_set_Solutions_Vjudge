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

//   size_t operator()(uint64_t x) const {
//       static const uint64_t FIXED_RANDOM =
//           chrono::steady_clock::now().time_since_epoch().count();
//       return splitmix64(x + FIXED_RANDOM);
//   }
// };
int ca=1;
set<int>se;
// unordered_map<int,int,custom_hash>mp;
const int MAX=1e7+7;
// bool is_prime[MAX];
bitset<MAX>is_prime;
void calculate (){
    for (int i=2;1LL*i*i<MAX;i++){
        for (int j=i*i;j<MAX;j+=i){
            if (!is_prime[j]){
                is_prime[j]=1;
            }
        }
    }
    for (int i=2;i<MAX;i++){
        if (!is_prime[i]){se.insert(i);}
        //  if (!is_prime[i])mp[i]++;
    }
}
void solve ()
{
    int n;cin>>n;
    int ans=0;
    for (auto a:se){
        if (a>n)break;
        int b=n-a;
        if (b<a)break;
        if (!is_prime[b])++ans;
    }
    cout<<"Case "<<ca++<<": ";
    cout<<ans<<endl;
}

int main ()
{
    speed;
    calculate();
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}