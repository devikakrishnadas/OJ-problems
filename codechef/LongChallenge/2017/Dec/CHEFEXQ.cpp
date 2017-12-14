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

int A[350][1000000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n,q;
    cin>>n>>q;
    vi a(n);
    vi block(1000,0);
    int j=0;
    vi original(n);
    int dn = sqrt(n);
    int ds = (n+dn-1)/dn;
    for(int i=0;i<n;i++)
    {
        if(i%dn == 0 && i) j++;
        cin>>a[i];
        original[i]=a[i];
        if(i) a[i]=a[i]^a[i-1];
        A[j][a[i]]++;
//        cout<<a[i]<<" ";
    }
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int ind,x;
            cin>>ind>>x;
            ind--;
            int endi=-1;
            int in = original[ind];
            original[ind]=x;
            int val = in^x;
//            cout<<"val "<<val<<" in "<<in<<" x "<<x<<endl;
            for(int i=ind;i<n;i++)
            {
                if(i%dn == 0) 
                {
                    endi=i;
                    break;
                }
                int bb=a[i];
                a[i] = a[i]^val;
                
                int curBlock = i/dn;
                A[curBlock][a[i]^val]--;
                A[curBlock][a[i]]++;
            }
            if(endi==-1) continue;
            int curBlock = endi/dn;
            for(int i=curBlock;i<ds;i++)
            {
                block[i] = block[i] ^ val;
            }
        }
        else
        {
            int ind,k;
            cin>>ind>>k;
            ind--;
            int cnt=0;
            int curBlock = ind/dn;
            int endi=curBlock;
            if((ind+1)%dn)
                endi--;
                        
            for(int i=0;i<=endi;i++)
            {
                int val=block[i]^k;
                cnt+=A[i][val];
//                cout<<"BlockNo "<<i<<" has pending xor = "<<block[i]<<" k is "<<k<<" val is "<<val<<" A[i][val] = "<<A[i][val]<<endl;
            }
            for(int i=ind;i>=0;i--)
            {
                if((i+1)%dn == 0) break;
                int val=block[curBlock]^k;
                if(a[i]==val) cnt++;
            }
            cout<<cnt<<endl;
        }
    }
	return 0;
}

