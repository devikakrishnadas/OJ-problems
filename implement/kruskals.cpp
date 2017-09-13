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

class DisjointSet{ public:

    vector<int> parent;

    DisjointSet(int n)  { for(int i=0; i<n; i++) parent.pb(i); }

    void join(int a, int b) { parent[find(b)] = find(a); }

    int find(int a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }

    bool check(int a, int b){ return find(a) == find(b); }
};

bool compare(pair<pair<int,int> , int>  x,  pair<pair<int,int> , int >y)
{
	if(x.second<y.second) return 1;
    else if(x.second>y.second) return 0;
    else return x.first.first+x.first.second<y.first.first+y.first.second;
}
int main()
{
	
	int n,m;
	cin>>n>>m;
	int x,y,z;
	DisjointSet D(n);
	vector< pair<pair<int,int> , int > >B;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>z;
		B.pb(mp(mp(x,y),z));
	}
	
	sort(B.begin(),B.end(),compare);
	ll cut=0;
	for(int i=0;i<B.size();i++)
	{
		if(!D.check(B[i].first.first,B[i].first.second))
		{
			D.join(B[i].first.first,B[i].first.second);
			cut+=B[i].second;
		}
	}
	cout<<cut<<endl;
	return 0;
}
