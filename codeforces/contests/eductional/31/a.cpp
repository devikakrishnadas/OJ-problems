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
    int n,t;
    cin>>n>>t;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int temp,x;
        cin>>x;
        temp=86400-x;
        t=t-temp;
        if(t<=0 && ans==0)
        {
            ans=i+1;
        }
    }
    cout<<ans<<endl;
	return 0;
}

