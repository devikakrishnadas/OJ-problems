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

int f[5005][5005],g[5005][5005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        int val=0;
        int b = 1;
        for(int j=i;j<n;j++)
        {
            if(s[j]==')')
                val--;
            else val++;
            if(val < 0)
                b=0;
            f[i][j]=b;
        }
    }
    for(int i=0;i<n;i++)
    {
        int val = 0;
        int b=1;
        for(int j=i;j>=0;j--)
        {
            if(s[j]=='(')
                val--;
            else val++;
            if(val < 0)
                b=0;
            g[j][i]=b;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((j-i+1)%2 == 0 and f[i][j] and g[i][j])
                cnt++;
        }
    }
    cout<<cnt<<endl;
	return 0;
}

