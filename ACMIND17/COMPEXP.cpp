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
    int t;
    cin>>t;
    while(t--)
    {
        double n,k;
        cin>>n>>k;
        long double answer=0.0;
        
        if(k==1 || n==1)
        {
            answer=2.0;
        }
        else
        {
            answer=(2.0*(n+1)*(k-1))/k;
        }
        cout<<fixed<<setprecision(12)<<answer<<endl;

    }
	return 0;
}

