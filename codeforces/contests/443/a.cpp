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
    int n;
    cin>>n;
    int ans=0;
    vector<pair<int,int> >a;
    for(int i=0;i<n;i++)
    {
        int s,d;
        cin>>s>>d;
        if(ans==0)
            ans=s;
        else
        {
            int tt=max(0,(ans-s)/d);
            while(s+tt*d <= ans) tt++;
            ans=s+tt*d;
        }
        //a.pb(mp(s,d));
    }
    //int ans=0;
    cout<<ans<<endl;
	return 0;
}

