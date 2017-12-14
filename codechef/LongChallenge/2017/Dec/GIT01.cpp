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
    int t;
    cin>>t;
    char m1[110][110],m2[110][110];
    for(int i=0;i<100;i++)
    {
        char f='R',s='G';
        for(int j=0;j<100;j++)
        {
            if((i+j)%2==0)
            {
                m1[i][j]=f;
                m2[i][j]=s;
            }
            else
            {
                m1[i][j]=s;
                m2[i][j]=f;
            }
        }
    }
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        char A[110][110];
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(A[i][j]!=m1[i][j])
                {
                    if(A[i][j]=='R')
                        cnt1+=5;
                    else cnt1+=3;
                }
                if(A[i][j]!=m2[i][j])
                {
                    if(A[i][j]=='R')
                        cnt2+=5;
                    else cnt2+=3;
                }
            }
        }
        cout<<min(cnt1,cnt2)<<endl;
    }
	return 0;
}

