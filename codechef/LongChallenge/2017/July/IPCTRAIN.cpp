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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,d;
        cin>>n>>d;
        vector<pair<ll,pair<ll,ll> > >A;
        for(int i=0;i<n;i++)
        {
            ll di,ti,si;
            cin>>di>>ti>>si;
            A.pb(mp(di,mp(si,ti)));
        }
        sort(all(A));
        //reverse(all(A));
        ll val=0;
        ll td=d;
        
        ll j=0;
        priority_queue<pair<ll,pair<ll,ll> > >S;
        for(int i=1;i<=d;i++)
        {
            
            while(A[j].ff<=i && j<n)
            {
                S.push(mp(A[j].ss.ff,mp(A[j].ff,A[j].ss.ss)));
                j++;
                
            }
            //cout<<"Day "<<i<<" : "<<endl;
            if(S.empty())
                continue;
            //cout<<"Stack size: "<<S.size()<<endl;
            pair<ll,pair<ll,ll> > ttt=S.top();
            S.pop();
            ttt.ss.ss-=1;
            //cout<<"Day "<<i<<" : "<<endl;
            //cout<<"Stack size: "<<S.size()<<endl;
            //cout<<"si di ti :"<<ttt.ff<<" "<<ttt.ss.ff<<" "<<ttt.ss.ss<<endl;
            if(ttt.ss.ss)
            S.push(ttt);
        }
        //cout<<"size :"<<S.size()<<endl;
        
        while(!S.empty())
        {
            pair<ll,pair<ll,ll> >temp;
            temp=S.top();
            val=val+temp.ff*temp.ss.ss;
            //cout<<"element "<<temp.ff<<" "<<temp.ss.ff<<" "<<temp.ss.ss<<endl;
            S.pop();
        }
        cout<<val<<endl;
    }
	return 0;
}

