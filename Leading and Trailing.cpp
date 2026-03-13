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
int power (int n, int a, int mod){
    int ans=1%mod;
    while (a){
        if (a&1){
            ans=1LL*ans*n%mod;
        }
        n=1LL*n*n%mod;
        a>>=1;
    }
    return ans;
}
int power3 (int n, int a){
    int ans=1;
    while (a){
        if (a&1){
            ans=ans*n;
        }
        n=n*n;
        a>>=1;
    }
    return ans;
}
string power2(int n, int k){
    double x=k*log10(n);
    x-=(int)x;
    x=pow(10,x);
    string temp=to_string(x);
    temp.erase(temp.find('.'),1);
    string last="";
    bool flag=false;
    for (int i=0;i<temp.size() and last.size()<3;i++){
        if (temp[i]>'0' or flag){
            last+=temp[i];flag=true;
        }
    }
    while (last.size()<3)last+='0';
    return (last);
}
string last (int n,int k){
    int val=power(n,k,1000);
    string s=to_string(val);
    while (s.size()<3){
        s.insert(s.begin(),'0');
    }
    return s;
}
void solve ()
{
    int n,k;cin>>n>>k;
    cout<<power2(n,k);
    cout<<"...";
    cout<<last(n,k)<<endl;
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