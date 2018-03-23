#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define MAXN  1000005
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t,k;
    cin>>t;
    string s1,s2;
    for(ll i=0;i<t;i++){
        cin>>s1>>s2;
        cin>>k;
        ll ans=LLONG_MAX;
        for(ll j=0;j<26;j++){
            ll cc=0;
            ll e=(j+k)%26;
            ll l1=s1.size();
            ll l2=s2.size();
            for(ll h=0;h<l1;h++){
                if(!(s1[h]>=min(j,e)&&s1[h]<=max(j,e))){
                    ll w=s1[h]-'a';
                    ll temp=LLONG_MAX;
                    temp=min(temp,abs(j-w));
                    temp=min(temp,abs(e-w));
                    temp=min(temp,abs(j+26-w));
                    temp=min(temp,abs(e+26-w));
                    cc+=temp;
                }
            }
            for(ll h=0;h<l2;h++){
                if(!(s2[h]>=min(j,e)&&s2[h]<=max(j,e))){
                    ll w=s2[h]-'a';
                    ll temp=LLONG_MAX;
                    temp=min(temp,abs(j-w));
                    temp=min(temp,abs(e-w));
                    temp=min(temp,abs(j+26-w));
                    temp=min(temp,abs(e+26-w));
                    cc+=temp;
                }
            }
            //cout<<j<<" "<<e<<" "<<cc<<endl;
            ans=min(ans,cc);
        }
        cout<<ans<<endl;
    }


    return 0;
}

