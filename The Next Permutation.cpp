//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp " "
#define endl '\n'
using namespace std;
     
void solve ()
{
    ll x;cin>>x;
    string s;cin>>s;
    vector<ll>vv;
    for (int i=0;i<s.size();i++){
        vv.push_back(s[i]-'0');
    }
   bool flag= next_permutation(vv.begin(),vv.end());
    if (flag){
        cout<<x<<sp;
        for (auto &x:vv)cout<<x;cout<<endl;
    }else{
        cout<<x<<sp;
        cout<<"BIGGEST"<<endl;
    }
    
}
int main ()
{
    speed;
    int tt;
    cin>>tt;
    while (tt--)
    {
        solve ();
    }
    return 0;
}