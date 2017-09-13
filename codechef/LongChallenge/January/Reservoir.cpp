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
	int t,n,m;
	cin>>t;
	char A[1023][1023];
	while(t--)
	{
		cin>>n>>m;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		bool ent1=0,ent2=0;
		for(int i=0;i<n;i++)
		{
			if(A[i][0]=='W')
			{
				cout<<"no"<<endl;
				goto p;
			}
			if(A[i][m-1]=='W' )
			{
				cout<<"no"<<endl;
				goto p;
			}
			if(A[i][0]=='B') ent1=1;
			if(A[i][m-1]=='B') ent2=1;
			if(A[i][0]=='A' && ent1)
			{
				cout<<"no"<<endl;
				goto p;
			}
			if(A[i][m-1]=='A' && ent2)
			{
				cout<<"no"<<endl;
				goto p;
			}
		}
		for(int i=0;i<m;i++)
		{
			if(A[n-1][i]=='W') 
			{
				cout<<"no"<<endl;
				goto p;
			}
			if(A[n-1][i]=='A')
			{
				for(int j=n-1;j>=0;j--)
				{
					if(A[j][i]!='A')
					{
						cout<<"no"<<endl;
						goto p;
					}
				}
			}
		}
		for(int i=0;i<n-1;i++)
		{
			for(int j=1;j<m-1;j++)
			{
				if(A[i][j]=='W')
				{
					
					
					if(A[i+1][j]!='B' && A[i+1][j]!='W')
					{
						cout<<"no"<<endl;
						goto p;
					}
					if(A[i][j+1]!='B' && A[i][j+1]!='W')
                                        {
                                                cout<<"no"<<endl;
						goto p;
                                        }
					if(A[i][j-1]!='B' && A[i][j-1]!='W')
                                        {
                                                cout<<"no"<<endl;
						goto p;
                                        }
				}
			
				if(A[i][j]=='B')
				{
					if(A[i+1][j]!='B')
					{
						cout<<"no"<<endl;
						goto p;
					}
				}
				
			}
		}
		cout<<"yes"<<endl;
		p:continue;
	}
	return 0;
}

