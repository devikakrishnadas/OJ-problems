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
    int n,k;
    cin>>n>>k;
    vi a;
    a.pb(0);
    for(int i=1;i<=2*n;i++)
    {
        a.pb(i);
    }
    for(int i=1;i<=k;i++)
    {
        swap(a[2*i],a[2*i-1]);
    }
    for(int i=1;i<=2*n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
	return 0;
}

