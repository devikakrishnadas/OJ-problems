#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    ll n,k;
    cin>>n>>k;
    vll c(n+1);
    ll tn=n;
    vll timeOfDepart(n+1,0);
    priority_queue<pair<ll,ll> > a;
    //priority_queue<pair<ll,pair<ll,ll> >, vector<pair<ll,pair<ll,ll> > > , std::greater<pair<ll,pair<ll,ll> > > >b;
    
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
        a.push(mp(c[i],i+1));
    }
    ll ptr=k+1;
    ll val=0;
    vector<bool> isEmpty(3*n,0);
    while(!a.empty())
    {
        while(isEmpty[ptr]) ptr++;
        int t=max((ll)ptr,a.top().ss);
        val=val+max((ll)0,(ptr-a.top().ss)*a.top().ff);
        timeOfDepart[a.top().ss]=t;
        isEmpty[t]=1;
        a.pop();
    }
    cout<<val<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<timeOfDepart[i]<<" ";
    }
    cout<<endl;
	return 0;
}

