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
    ll n,a,b;
    cin>>n>>a>>b;
    for(int i=0;a*i<=n;i++)
    {
        if((n - a*i)%b == 0)
        {   
            cout<<"YES"<<endl;
            cout<<i<<" "<<(n-a*i)/b<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
	return 0;
}

