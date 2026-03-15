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
int ca=1;
void solve ()
{
    string s;getline(cin,s);
    string temp="";
    // int i=0;
    // while (i<s.size() and s[i]!=' '){
    //     if (s[i]!='-')
    //     temp.push_back(s[i]);
    //     i++;
    // }
    string _val="";
    stringstream ss(s);
    ss>>temp>>_val;
    // if (!temp.empty() && temp[0]=='-') temp.erase(0,1);
    // if (!_val.empty() && _val[0]=='-') _val.erase(0,1);
    // for (int j=i+1;j<s.size();j++){
    //     if (s[j]!='-')_val+=s[j];
    // }
    if (temp=="0"){
        cout<<"Case "<<ca++<<": "<<"divisible"<<endl;return;
    }
    // cout<<temp<<sp<<_val<<endl;
    int index=0;
    int val=stoi(_val);
    ll rem=0;
    while (index<temp.size()){
        if (temp[index]=='-'){index++;continue;}
        rem=(rem*10+(temp[index]-'0'))%val;
        index++;
    }
    if ((rem)==0){
        cout<<"Case "<<ca++<<": "<<"divisible"<<endl;return;
    }
    cout<<"Case "<<ca++<<": "<<"not divisible"<<endl;
}

int main ()
{
    speed;
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--)
    {
        solve();
    }
    return 0;
}