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
        vi bit0(30,1);
        vi bit1(30,0);
        int n,k;
        cin>>n>>k;
        vi a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            int j=0;
            while(a[i])
            {
                if(a[i]%2==0)
                {
                    bit0[j]++;
                }
                else 
                {
                    
                    bit1[j]++;
//                    cout<<"pos"<<j<<" is 1"<<bit1[j]<<endl;
                }
                j++;
                a[i]=a[i]/2;
            }
        }
  //      cout<<bit1[0]<<endl;
        int cnt=0;
        for(int i=0;i<=30;i++)
        {
            if(bit1[i]==n)
                bit0[i]=0;
    //        cout<<bit1[i]<<" "<<bit0[i]<<endl;
            if(bit1[i] && bit0[i])
            {
                cnt++;
            }
            
        }

        if(cnt>=k)
        {
            cout<<0<<endl;
        }
        else
        {
            for(int t=1;cnt*t
        }
        cout<<k<<endl;
    }
	return 0;
}

