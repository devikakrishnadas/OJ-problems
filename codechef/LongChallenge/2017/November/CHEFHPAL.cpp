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
        int n,a;
        cin>>n>>a;
        int cnt=0;
        
        if(a==2)
        {
            char A[]={"abaabb"};
            if(n==3) cout<<"2 abb"<<endl;
            else if(n==4) cout<<"2 aabb"<<endl;
            else if(n==5) cout<<"3 aaabb"<<endl;
            else if(n==6) cout<<"3 aaabbb"<<endl;
            else if(n==7) cout<<"3 aaababb"<<endl;
            else if(n==8) cout<<"3 aaababbb"<<endl;
            //char A[]={"aabbab"};
            else
            {
                if(n>8) cout<<"4 "<<endl;
                else if(n<=2) cout<<"1 "<<endl;
                for(int i=0;i<n;i++)
                {
                    cout<<A[i%6];
                }
                cout<<endl;
            }
        }
        else
        {
            if(a!=1)
            cout<<1<<" ";
            else cout<<n<<" ";
            for(int i=0,j=0;i<n;i++,j++)
            {
                char ch='a'+j%a;
                cout<<ch;
            }
            cout<<endl;
        }
    }
	return 0;
}

