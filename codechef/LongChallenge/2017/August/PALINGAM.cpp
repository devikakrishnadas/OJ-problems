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
        string a,b;
        cin>>a>>b;
        int A[300]={0},B[300]={0};
        for(int i=0;i<a.length();i++)
        {
            A[a[i]]++;
        }
        for(int i=0;i<b.length();i++)
        {
            B[b[i]]++;
        }
        bool enter=0;
        bool enter1=0, enter2=0,enter3=0,enter4=0,enter3_1=0;
        for(int i=0;i<300;i++)
        {
            if(A[i] && B[i]==0)
            {
                enter=1;
            }
            if(A[i] &&  B[i])
            {
                enter1=1;
            }      
            if(A[i]==0 && B[i])
            {
                enter2=1;
            }
            if(A[i]>1)
            {
                enter3=1;
                if(A[i] && B[i]==0)
                {
                    enter3_1=1;
                }
            }
            if(B[i]>1)
            {
                enter4=1;
            }
        }
        if(enter3_1)
        {
            cout<<'A'<<endl;
        }
        else if(enter2==0 && enter==1)
        {
            cout<<'A'<<endl;
        }
        else cout<<'B'<<endl;
    }
	return 0;
}

