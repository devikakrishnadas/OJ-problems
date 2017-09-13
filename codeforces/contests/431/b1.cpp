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
set<int>B[10001];
//int A[1000][1000]={0};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;  
    vi a(n);
    cin>>n;
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<pair<pair<int,int>,pair<int,int> > >slope;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            int num=a[j]-a[i];
            int den=j-i;
            int g=1;
            if(num && den)
            g=__gcd(abs(num),abs(den));
            num=num/g;
            den=den/g;
            if(num<=0 && den<=0)
            {
                num=abs(num);
                den=abs(den);
            }
            slope.pb(mp(mp(num,den),mp(a[i],a[j])));
        }
    }
    cout<<"R!"<<endl;
    int ptr=0;
    sort(all(slope));
    B[ptr].insert(slope[0].ss.ff);
    B[ptr].insert(slope[0].ss.ss);

    for(int i=1;i<slope.size();i++)
    {
        cout<<slope[i].ff.ff<<" "<<slope[i].ff.ss<<endl;
        if(slope[i].ff==slope[i-1].ff)
        {
            ptr++;
        }
        B[ptr].insert(slope[0].ss.ff);
        B[ptr].insert(slope[0].ss.ss);
    }
    bool yes=0;
    bool enter=0;
    for(int i=0;i<=1000;i++)
    {
        if(B[i].size()>=n-1)
        {
            yes=1;
        }
        else
        {
            enter=1;
        }
    }
    cout<<yes<<" "<<enter<<endl;
    if(yes && enter)
    {
        cout<<"Yes"<<endl;
    }
    else
        cout<<"No"<<endl;
	return 0;
}

