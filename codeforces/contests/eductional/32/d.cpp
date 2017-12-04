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
    ll ans=0;
    vll C(10,1);
    for(int i=1;i<=4;i++)
    {
        C[i]=(C[i-1]*(n-(i-1)))/(i);
    }
    vll D(10,0);
    D[0]=D[1]=0;
    D[2]=1;
    D[3]=2;
    D[4]=9;
    D[5]=44;
    for(int i=k;i>=2;i--)
    {
        ans=ans+C[i]*D[i];
    }
    ans=ans+1;
    cout<<ans<<endl;
	return 0;
}

