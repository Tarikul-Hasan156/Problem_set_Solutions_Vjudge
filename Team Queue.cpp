//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp ' '
#define endl '\n'
using namespace std;


ll j=1;
void solve ()
{
    ll n;
    while (cin>>n) {
        if (n==0)return;
        cout <<"Scenario #"<<j++<<endl;
        queue<ll>q;
        map<int,queue<ll>>vv;
        map<ll,ll>mp;
        for (int i=1;i<=n;i++){
            ll size;cin>>size;
            while (size--){
                ll temp;cin>>temp;
                mp[temp]=i;
            }
        }
        string s;
        while (cin>>s and s!="STOP"){
            if (s=="ENQUEUE"){
                ll val;cin>>val;
                ll key=mp[val];
                auto it=vv.find(key);
                if (it!=vv.end()){
                    vv[key].push(val);
                }else{
                    q.push(key);
                    vv[key].push(val);
                }
            }else if (s=="DEQUEUE" and !vv.empty() and !q.empty()){
                // print(q);
                    ll first=q.front();
                    auto it=vv.find(first);
                    if (it!=vv.end()){
                        cout<<vv[first].front()<<endl;
                        vv[first].pop();
                        if (vv[first].empty()){
                            vv.erase(first);
                            q.pop();
                        }
                    }
                }
            }
            cout<<endl;
    }
}

int main ()
{
    speed;
    // int tt;
    // cin >> tt;
    // while (tt--)
    // {
        solve();
    // }
    return 0;
}