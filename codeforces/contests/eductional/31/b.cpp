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
    int n,x;
    cin>>n>>x;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        sum+=t;
    }
    if(sum==0)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    sum+=(n-1);
    if(sum==x)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
	return 0;
}

