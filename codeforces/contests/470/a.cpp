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
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n) FOR(i,0,n)

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    char A[510][510];
    REP(i,n)
    {
        cin>>A[i];
    }
    REP(i,n)
    {
        REP(j,m)
        {
            if(A[i][j]=='W')
            {
                if(i) 
                {
                    if(A[i-1][j]=='.')
                    {
                        A[i-1][j]='D';
                    }
                    else if(A[i-1][j]=='S')
                    {
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
            
                if(j)
                {
                    if(A[i][j-1]=='.')
                    {
                        A[i][j-1]='D';
                    }   
                    else if(A[i][j-1]=='S')
                    {
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
                if(i!=n-1)
                {
                    if(A[i+1][j]=='.')
                    {
                        A[i+1][j]='D';
                    }
                    else if(A[i+1][j]=='S')
                        {
                            cout<<"No"<<endl;
                            return 0;
                        }
                }
                if(j!=m-1)
                {
                    if(A[i][j+1]=='.')
                    {
                        A[i][j+1]='D';
                    }
                    else if(A[i][j+1]=='S')
                    {
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    REP(i,n)
    {
        cout<<A[i]<<endl;
    }
	return 0;
}

