//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll unsigned long long
#define sp ' '
#define endl '\n'
using namespace std;
const int N=5e6+9;

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
int ca=1;
int spf[N];
ll r_p[N];
void calculate (){
    for (int i=2;i<N;i++){
        spf[i]=i;
    }
    for (int i=2;i<N;i++){
        for (int j=i;j<N;j+=i){
            spf[j]=min(spf[j],i);
        }
    }
}
void r_prime (){
    for (int i=1;i<N;i++){
        int x=i;int res=1;
        while (x>1){
            int p=spf[x];
            // int e=0;
            int pw=1;
            while (x%p==0){
                pw*=p;
                // e++;
                x/=p;
            }
            res*=(pw/p)*(p-1);
        }
        // r_p[i]=res;
        r_p[i]=r_p[i-1]+1LL*res*res;
    } 
}

void solve ()
{
   // cout<<r_p[16]<<endl;
    int a,b;cin>>a>>b;
    cout<<"Case "<<ca++<<":"<<sp<<r_p[b]-r_p[a-1]<<endl;
}

int main ()
{
    speed;
    calculate();
    r_prime();
    int tt;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
