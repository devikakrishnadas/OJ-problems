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
int Length=0;
vi cycleHead;
int cur=-1;
int ttt[10001][1001]={0};
int miCycleHead=-1;
void countOddCycles(vector<vi>&A,int a,int prev,vi &len,int l,int &ans)
{
    if(len[a])
    {
        
        int cycleLen=l-len[a]; 
        if(cycleLen<=2)
            return;
        if(cycleLen%2)
        {
            ans++;
            if(Length==0)
            Length=cycleLen;
            else 
            {
                Length=min(Length,cycleLen);
                miCycleHead=a;
            }
            cycleHead.pb(a);
            //cout<<a<<endl;
        }
        return;
    }
    len[a]=l;
    for(int i=0;i<A[a].size();i++)
    {
        if(A[a][i]!=prev)
        {
            countOddCycles(A,A[a][i],a,len,l+1,ans);
        }
    }
    
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector< vi >A(n+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        ttt[x][y]=1;
        ttt[y][x]=1;
        A[x].pb(y);
        A[y].pb(x);
    }
    vi len(n+1,0);
    int oddCycle=0;
    countOddCycles(A,1,-1,len,1,oddCycle);
    if(oddCycle==0)
    {
        cout<<m<<endl;
    }
    else if(oddCycle==1)
    {
        cout<<Length<<endl;
    }
    else
    {
        
    }

	return 0;
}

