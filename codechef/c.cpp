#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll  long long int
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back
pi cats[211];
pi mouse[211];
int cnt=0;
int N,K;
vector<int>g[211];
double dist(int i,int j){
    double ret=(cats[i].f-mouse[j].f)*(cats[i].f-mouse[j].f)+(cats[i].s-mouse[j].s)*(cats[i].s-mouse[j].s);
    ret=sqrt(ret);
    return ret;
}
int match[211];
int seen[211];
bool bpm(int p){
    for(auto x:g[p]){
        if(!seen[x]){
            seen[x]=1;
            cnt++;
            if(match[x]==-1 or bpm(match[x])){
                
                match[x]=p;
                return 1;
            }
        }
    }
    return 0;
}
int maxBPM(){
    int ans=0;
    rep(i,N) match[i]=-1;
    rep(i,N){
        rep(j,N) seen[j]=0;
        if(bpm(i)) ans++;
    }
    return ans;
}
bool ok(double x){
    int cnt=0;
    rep(i,N) g[i].clear();
    rep(i,N){
        rep(j,N){
            cout<<cats[i].f<<" "<<cats[i].s<<" "<<mouse[j].f<<" "<<mouse[j].s<<" "<<dist(i,j)<<endl;
            if(dist(i,j)>x){
                cnt++;
                g[i].pb(j);
            }
        }
    }
    int M=maxBPM();
    cout<<M<<endl;
    if(2*N-M>=K) return 1;
    return 0;
}
int main(){
    cin >> N >> K;
    rep(i,N){
        cin >> cats[i].f >> cats[i].s;
        cout<<cats[i].f<<" "<<cats[i].s<<endl;
    }
    rep(i,N){
        cin >> mouse[i].f >> mouse[i].s;
        cout<<mouse[i].f<<" "<<mouse[i].s<<endl;
    }
    double lo=0;
    double hi=1e14;
    double mid;
    mid=93132.3;
    ok(mid);
    return 0;
    rep(itr,200){
        mid=(hi+lo)/2.0;
        cout<<lo<<" "<<hi<<" "<<mid<<" ";
        bool kk = ok(mid);
        if(kk) hi=mid;
        else lo=mid;
    }
   printf("%.7f",hi);
}
