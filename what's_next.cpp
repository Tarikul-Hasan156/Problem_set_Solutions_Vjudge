//بِسْمِ ٱللّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll int64_t
#define sp " "
#define endl '\n'
using namespace std;
     
void solve ()
{
    ll a,b,c;
    while (cin>>a>>b>>c){
        if (a==0 and b==0 and c==0)return;
        ll temp=c-b;
        // cout<<temp<<endl;
        if (temp==b-a){
            cout<<"AP"<<sp<<c+temp<<endl;
        }else{
            cout<<"GP"<<sp<<c*(c/b)<<endl;
        }
    }
}
int main ()
{
    speed;
    // int tt;
    // cin>>tt;
    // while (tt--)
    // {
        solve ();
    // }
    return 0;
}