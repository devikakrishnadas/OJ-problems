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
    while(t--)
    {
        int n;
        cin>>n;
        vi a(n),b(n);
        for(int i=0;i<n;i++) 
        {
            cin>>a[i];
            b[i]=a[i];
        }
        if(n==1)
        {
            cout<<0<<endl;
            cout<<a[0]<<endl;
            continue;
        }
        else if(n==2)
        {
            if(a[0]==a[1])
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<2<<endl;
                swap(a[0],a[1]);
            }
            cout<<a[0]<<" "<<a[1]<<endl;
            continue;
        }
        vi isPlace(n,1);
        int cnt=n;
        int tt=500;
        int val=0;
        int j=1;
        while(cnt && tt--)
        {
            j=1;
            for(int i=0;i<n;i++)
            {
                if(!isPlace[i]) continue;
                bool enter=0;
                while(!enter && j<n)
                {
                    if(b[j]!=a[i] && a[j]!=b[i])
                    {
                        enter=1;
                        swap(a[j],a[i]);
                        if(isPlace[i])
                        {
                            isPlace[i]=0;
                            cnt--;
                            val++;
                        }
                        if(isPlace[j])
                        {
                            isPlace[j]=0;
                            cnt--;
                            val++;
                        }
                    }
                    j++;
                }
                if(j==n)
                    j=1;
            }
        }
        cout<<val<<endl;
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
	return 0;
}

