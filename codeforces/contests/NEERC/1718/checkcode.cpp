#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define MAXN  1000005
using namespace std;
map<char,ll>m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l;
    string s;
    cin>>l>>s;
    for(ll i=0;i<l;i++){
        m[s[i]]++;
    }
    ll odd=0;
    vector<char>v;
    for(auto it=m.begin();it!=m.end();it++){
        if(it->ss%2){
            odd++;
            it->ss--;
            v.pb(it->ff);
        }
    }
    ll l1=v.size(),k=0;
    if(l1==0){
        l1=1;
    }
    else
    while(((l1+k<=0||((l%(l1+k)))!=0)||(l-l1-k)%(2*(l1+k)))){
        k++;
    }
    l1+=k;
    if(l1>1){
        ll j=(ll)v.size();
        for(auto it=m.begin();it!=m.end();it++){
            if(j>=l1)
                break;
            while(it->ss>0&&j<l1){
                v.pb(it->ff);
                it->ss--;
                j++;
            }
        }
    }
    ll l2=v.size();
    //cout<<l1<<" "<<l2<<endl;
    string temp;
    vector<string>ans;
    ll j=0;
    if(j<l2){
        temp=v[j];
    }
    if(l1==l){
        cout<<l<<endl;
        for(ll i=0;i<l;i++){
            cout<<s[i]<<" ";
        }
        return 0;
    }
    for(auto it=m.begin();it!=m.end();){
        if(j>=l1)
            break;
        if(it->ss<=0){
            it++;
            continue;
        }
        temp=it->ff+temp+it->ff;
        it->ss-=2;
        //cout<<it->ff<<" "<<it->ss<<" "<<j<<" "<<temp<<endl;
        if((ll)temp.size()>=l/l1){
            ans.pb(temp);
            j++;
            //cout<<j<<" "<<l2<<endl;
            if(j>=l2)
                break;
            else temp=v[j];
        }
    }
    cout<<ans.size()<<endl;
    for(auto it=ans.begin();it!=ans.end();it++){
        cout<<*it<<" ";
    }




    return 0;
}
