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
    vector<vi>a(n+1);
    vector<pair<int,int> >b;

    for(int i=1;i<n;i++)
    {
        int t;
        cin>>t;
        a[t].pb(i+1);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i].size() == 0) continue;
        int leaf = 0;
        for(int j=0;j<a[i].size();j++)
        {
            //cout<<a[i][j]<<" "<<a[a[i][j]].size()<<endl;
            if(a[a[i][j]].size() == 0)
            {
                leaf++;
            }
        }
//        cout<<i<<" "<<leaf<<endl;
        if(leaf < 3)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
	return 0;
}

