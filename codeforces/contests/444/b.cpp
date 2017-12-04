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


vi exist(10000,0);
void in(vi &a)
{
    for(int i=0;i<6;i++)
    {
        exist[i].resize(100000,0);
        cin>>x;
        a.pb(x);
        exist[x]=1;
    }
}

void do3(vi &a,vi &b,vi &c)
{
    int aaa=0,aab=0,aba=0,abb=0,baa=0,bab=0;
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            for(int k=0;k<7;k++)
            {
                if(i!=7 && j!=7 && k!=7)
                {
                    exist[a[i]*100+b[j]*10+[k]]=1;
                    exist[a[i]*100+
                }
                else if(i!=7 && j!=7
            }
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vector<vi>a(n);
    for(int i=0;i<n;i++)
    {
        in(a[i]);
        sort(all(a[i]));
    }
    for(int i=1;i<9;i++)
    {
        if(!exist[i])
        {
            cout<<i-1<<endl;
            return 0;
        }
    }
    if(n==2)
    {
        
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<7;j++)
            {
                int aa=0;
                if(j!=7 &&i!=7)
                {
                    aa=a[i]*10+a[j];
                }
                else if(j!=7)
                {
                    aa=a[j];
                }
                else if(i!=7)
                {
                    aa=a[i];
                }
                else continue;
                exist[aa]=1;
            }
        }
    }
    else
    {
        do3();
        for(int i=0;;i++)
        {
            if(!exist[i])
            {
                cout<<i-1<<endl;
                return 0;
            }
        }
    }
	return 0;
}

