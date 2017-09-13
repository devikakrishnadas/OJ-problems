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
	cin>>n>>m;
	vector<pair<char,int> >ans,ans2;
	int A[102][102]={0};
	int B[102][102]={0};
	vi rows(102,INT_MAX);
	vi cols(102,INT_MAX);
	vi rows2(102,INT_MAX);
	vi cols2(102,INT_MAX);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>A[i][j];
			B[i][j]=A[i][j];
			rows[j]=min(rows[j],A[i][j]);
			rows2[j]=rows[j];
			cols[i]=min(cols[i],A[i][j]);
			cols2[i]=cols[i];
		}
	}
	for(int j=0;j<m;j++)
	{
		if(rows[j]<=0)
			continue;
		for(int i=0;i<n;i++)
		{
			A[i][j]=A[i][j]-rows[j];
			cols[i]=min(cols[i],A[i][j]);
			//cout<<A[i][j]<<endl;
		}
		while(rows[j]>0)
                {
                	ans.pb(mp('r',j+1));
			rows[j]--;
                }
		//cout<<endl<<endl;

	}
	for(int i=0;i<n;i++)
        {
                if(cols2[i]<=0)
                        continue;
                for(int j=0;j<m;j++)
                {
                        B[i][j]=B[i][j]-cols2[i];
                        rows2[j]=min(rows2[j],B[i][j]);
                }
                while(cols2[i]>0)
                {
                        ans2.pb(mp('c',i+1));
                        cols2[i]--;
                }
        }
	for(int j=0;j<m;j++)
        {
                if(rows2[j]<=0)
                        continue;
                for(int i=0;i<n;i++)
                {
                        B[i][j]=B[i][j]-rows2[j];
                        cols2[i]=min(cols2[i],B[i][j]);
                        //cout<<A[i][j]<<endl;
                }
                while(rows2[j]>0)
                {
                        ans2.pb(mp('r',j+1));
                        rows2[j]--;
                }
                //cout<<endl<<endl;
        }
	for(int i=0;i<n;i++)
	{
		if(cols[i]<=0)
			continue;
		for(int j=0;j<m;j++)
		{
			A[i][j]=A[i][j]-cols[i];
			rows[j]=min(rows[j],A[i][j]);
		}
		while(cols[i]>0)
                {
                	ans.pb(mp('c',i+1));
			cols[i]--;
                }
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(A[i][j])
			{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	if(ans.size()<ans2.size())
	{
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
	{
		if(ans[i].ff=='r')
			cout<<"col "<<ans[i].ss<<endl;
		else cout<<"row "<<ans[i].ss<<endl;
	}
	}
	else
	{
	cout<<ans2.size()<<endl;
	for(int i=0;i<ans2.size();i++)
        {
                if(ans2[i].ff=='r')
                        cout<<"col "<<ans2[i].ss<<endl;
                else cout<<"row "<<ans2[i].ss<<endl;
        }
	}
	return 0;
}

