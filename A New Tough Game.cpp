//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
// #define endl '\n'
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
int ask (string s){
    cout<<"?"<<sp<<s<<endl;
    int temp;cin>>temp;
    return temp;
}
void solve ()
{
    int n;cin>>n;
    map<char,int>mp;
    int j=1;
    for (int i=97;i<123;i++){
        mp[char(i)]=j++;
    }
    string s="";
    for (int i=0;i<n;i++){
        s+='a';
    }
    string res="";
    int diff=ask(s);
    int tot=0;
    for (int i=0;i<n;i++){
        s[i]='z';
        int s_diff=ask(s);
        res+=char (((int)'z'+(int)'a'+(diff-s_diff))/2);s[i]='a';
    }
    cout<<"!"<<sp<<res<<endl;
}

int main ()
{
    speed;
    solve();
    return 0;
}