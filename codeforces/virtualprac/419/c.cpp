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
	int n,m;
	int A[1002][1002]={0};
	vector<pair<char,int> >ans;
	cin>>n>>m;
	int rows[102]={0},cols[102]={0};
	priority_queue<pair<int,int> >row,col;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>A[i][j];
			rows[i]+=A[i][j];
			cols[j]+=A[i][j];
		}
	}
	int rowsub=0;
	int colsub=0;
	for(int i=0;i<n;i++)
	{
		row.push(mp(rows[i],i+1));
	}
	for(int i=0;i<m;i++)
	{
		col.push(mp(cols[i],i+1));
	}
	vector<pair<char,int > >ans;
	bool minus=0;
	while(1)
	{
		int a,b;
		if(row.size()!=0)
		a=row.top().ff;
		else a=INT_MAX;
		if(col.size()!=0)
		b=col.top().ff;
		else b=INT_MAX;
		
		if(a-rowsub<m && b-colsub<n)
		{
			if(a-rowsub>0 || b-colsub>0)
				minus=1;
			break;
		}
		//cout<<a<<" "<<b<<endl;
		if(a-rowsub>=m && row.size()!=0)
		{
			//cout<<"enter a"<<endl;
			a=a-m;
			colsub++;
			ans.pb(mp('r',row.top().ss));
			//cout<<ans.size()<<endl;
			if(a-rowsub>0)
			{
				//cout<<"enter push"<<endl;
				row.push(mp(a,row.top().ss));
			}
			row.pop();
			//cout<<"popped"<<endl;
		}
		else if(b-colsub>=n && col.size()!=0)
		{
			b=b-n;
			rowsub++;
			ans.pb(mp('c',col.top().ss));
			if(b-colsub>0)
				col.push(mp(b,row.top().ss));
			col.pop();
		}
		else break;
	}
	if(minus)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i].ff=='r')
			cout<<"row "<<ans[i].ss<<endl;
		else
			cout<<"col "<<ans[i].ss<<endl;
	}
	return 0;
}

