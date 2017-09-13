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
	map<string,int>A;
	A["Tetrahedron"]=4;
	A["Cube"]=6;
	A["Octahedron"]=8;
	A["Dodecahedron"]=12;
	A["Icosahedron"]=20;
	int n;
	cin>>n;
	string a;
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		ans+=A[a];
	}
	cout<<ans<<endl;
	return 0;
}

