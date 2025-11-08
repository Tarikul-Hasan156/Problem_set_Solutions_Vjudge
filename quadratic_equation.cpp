#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve ()
{
    ll a,b,c;cin>>a>>b>>c;
    ll del=(b*b)-(4*a*c);
    del=sqrt(del);
    if (del<0){
        cout<<"No roots"<<endl;
        return;
    }else if (del==0){
        cout<<"One root: "<<(-1*b)/(2*a)<<endl;
    }else{
        ll eq_positive=(-1*b+del)/(2*a);
        ll eq_negative=(-1*b-del)/(2*a);
        cout<<"Two roots: "<<min(eq_positive,eq_negative)<<" "<<max(eq_positive,eq_negative)<<endl;
    }
    // if ((b*b)<(4*a*c)){
    //     cout<<"No roots" << endl;
    //     return;
    // }
    // double temp1=(b*b)-(4*a*c);
    // temp1=sqrt(temp1);
    // if (temp1!=(ll)temp1){
    //     cout<<"No roots"<<endl;
    //     return;
    // }
    // double eq_positive=(-b+temp1)/(2*a*1.0);
    // double eq_negative=(-b-temp1)/(2*a*1.0);
    // if(eq_positive==(ll)eq_positive and eq_negative==(ll)eq_negative){

    //     cout<<"Two roots: "<<min(eq_positive,eq_negative)<<" "<<max(eq_positive,eq_negative)<<endl;
    // }else if (eq_positive==(ll)eq_positive)
    // {
    //     cout<<"One root: "<<eq_positive<<endl;
    // }else if (eq_negative==(ll)eq_negative)
    // {
    //     cout<<"One root: "<<eq_negative<<endl;
    // }else
    // {

    //     cout<<"No roots"<<endl;
    // }
}
int main ()
{
    solve();
    return 0;
}
