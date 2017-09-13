#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

int main()
{
	int e,o;
	cin>>e>>o;
	if(e==0 && o==0)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	if(e==o || e==o+1 || e==o-1 )
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

