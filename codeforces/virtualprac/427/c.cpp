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
    ll n,q,c;
    cin>>n>>q>>c;
    int A[101][101][101]={0};
    for(int i=0;i<n;i++)
    {
        int x,y,s;
        cin>>x>>y>>s;
        A[s][x][y]++;
    }
    for(int s=0;s<=3;s++)
    {
        for(int x=1;x<=3;x++)
        {
            for(int y=1;y<=3;y++)
            {
                A[s][x][y]=A[s][x][y]+A[s][x-1][y]+A[s][x][y-1]-A[s][x-1][y-1];
//                cout<<s<<" "<<x<<" "<<y<<" "<<A[s][x][y]<<endl;
            }
        }
    }
    
    while(q--)
    {
        int t,x1,y1,x2,y2;
        int ans=0;
        cin>>t>>x1>>y1>>x2>>y2;
        for(int s=0;s<=10;s++)
        {
            ans=ans+((s+t)%(c+1))*(A[s][x2][y2]-A[s][x2][y1-1]-A[s][x1-1][y2]+A[s][x1-1][y1-1]);
            cout<<A[s][x2][y2]<<" "<<A[s][x1][y1]<<" "<<A[s][x1][y2]<<" "<<A[s][x2][y1]<<endl;
        }
        cout<<ans<<endl;
    }
	return 0;
}

