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

//bool G[100000][100000];
map<pair<int,int>,int >P;
map<pair<int,int>,int >Q;
vector<pair<int,pair<int,int> > >QA;
int e,n;
vi ans;
vi G[100023];
int x;
int DFS(int a,int k)
{
	ans.pb(a);
//	cout<<a<<endl;
	for(int i=0;i<G[a].size();i++)
	{
		//if(P.find(mp(a,G[a][i]))!=P.end())
		if(P[mp(a,G[a][i])]>0)
		{
			P[mp(a,G[a][i])]=0;
	//		P[mp(G[a][i],a)]=0;
			k--;
			if(k==0 && a==x)
				return 1;
			else if(k==0) return 0;
			return DFS(G[a][i],k);
		}
		
	}
	return 0;
}

int main()
{
	//int n,e;
	cin>>n>>e;
	int y;
	vector<pair<int,int> >A;
	int in[100023]={0};
	int out[100023]={0};
	//vi G[100023];
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		A.pb(mp(x,y));
		out[x]++;
		in[y]++;
		QA.pb(mp(i+1,mp(x,y)));
		QA.pb(mp(i+1,mp(x,y)));

		P[mp(x,y)]=1;
		P[mp(y,x)]=1;
		G[x].pb(y);
		G[y].pb(x);
	}
	
	if(e<n)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	x=A[0].first;
	int tt=e;
	int sk=DFS(x,k);
	
	if(!sk )
	{
		cout<<"NO"<<endl;
		return 0;
	}
	sort(QA.begin(),QA.end());
	cout<<"YES"<<endl;
	//x=A[0].first.first;
	
	vector<pair<int,int> >fa;
	for(int i=1;i<QA.size();i++)
	{
		if(!(*(P.find(QA[i].second))))
		{
			cout<<QA[i].second.first<<" "<<QA.second.second<<endl;
		}
	}
	return 0;
}
