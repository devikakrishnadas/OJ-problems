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
	int n,t,k,d;
	cin>>n>>t>>k>>d;
	if(n<=k)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
	int cycles=(n/k);
	if(n%k!=0)
		cycles++;
	int fin_cyc=(d/t);
	if(d%t) fin_cyc++;
	if(cycles*t>(ceil((double)((double)(cycles-fin_cyc)/2.0))*t+d))
	{
		//cout<<cycles*t<<" "<<(ceil((double)((cycles-fin_cyc)/2))*t+d)<<endl;
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	return 0;
}

