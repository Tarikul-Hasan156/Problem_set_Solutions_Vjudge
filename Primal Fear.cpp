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
unordered_set<int>se;
const int MAX=1e6+7;
bool test[MAX];
int res[MAX];
void sieve (){
    for (int i=2;i*i<MAX;i++){
        for (int j=i*i;j<MAX;j+=i){
            if (!test[j]){
                test[j]=true;
            }
        }
    }
}
bool check (int n){
    while (n){
        int mod=n%10;
        if (mod==0)return false;
        n/=10;
    }
    return true;
}
bool check2 (int n){
    string s=to_string(n);
    for (int i=1;i<s.size();i++){
        string x(s.begin()+i,s.end());
        if (!se.count(stoi(x)))return false;
    }
    return true;
}
void sum (){
    for (int i=2;i<MAX;i++){
        if (!test[i]){
            se.insert(i);
            if (check(i) and check2(i))res[i]++;
        }
    }
    for (int i=1;i<MAX;i++){
        res[i]=res[i]+res[i-1];
    }
}
void solve ()
{
    int n;cin>>n;
    cout<<res[n]<<endl;
}

int main ()
{
    speed;
    sieve();
    sum();
    int t;cin>>t;
    while (t--){
        solve();
    }
    return 0;
}