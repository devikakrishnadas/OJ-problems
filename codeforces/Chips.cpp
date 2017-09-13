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
	int n,m;
    cin>>n>>m;
	int A[1001][1001]={0};
    int row[1001]={0};
    int col[1001]={0};
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        row[x]=1;
        col[y]=1;
    }
    int cnt=0;
    int kk=(n/2) + (n%2);
    for(int i=2;i<=kk;i++)
    {
        if(n%2 && i==kk )
        {
            if(row[i]==0 || col[i]==0)
                cnt+=1;
            continue;
        }
        int nt=0;
        if(row[i]) nt++;
        if(col[i]) nt++;
        if(row[n-i+1]) nt++;
        if(col[n-i+1]) nt++;
        cnt+=(4-nt);
    }
    cout<<cnt<<endl;
	return 0;
}

