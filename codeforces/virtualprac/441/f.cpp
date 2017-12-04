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

int binNext(vi &a, int key)
{
    int l=0;
    int r=a.size();
    int ans=-1;
    
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]<=key)
        {
            l=mid+1;
        }
        else if(a[mid]>key)
        {
            r=mid-1;
            ans=mid;
        }
//        cout<<"r5"<<endl;
    }
    return ans;
}
    
int binPrev(vi &a,int key)
{
    int l=0;
    int r=a.size();
    int ans=-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]<key)
        {
            l=mid+1;
            ans=mid;
        }
        else if(a[mid]>=key)
        {
            r=mid-1;
        }
//        cout<<"r6"<<endl;
    }
    return ans;
}

void printArr(vi &R,int l,int r)
{
    cout<<endl;
    for(int i=l;i<r;i++)
    {
        cout<<R[i]<<" ";
    }
    cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vi a(n),t(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        t[i]=a[i];
    }
    vi L(n+1,-1);
    vi R(n+1,-1);
    if(n<=1)
    {
        cout<<0<<endl;
        return 0;
    }
//    cout<<"r1"<<endl;
    // calculate the first biggest neighbour to the left
    for(int i=1;i<n;i++)
    {
        L[i]=i;
        if(a[i-1]>a[i])
        {
            L[i]=i-1;
            continue;
        }
        int t=i-1;
        while(t!=-1 && L[t]!=t)
        {
            t=L[t];
            if(a[t]>a[i])
            {
                L[i]=t;
                break;
            }
        }
    }
    L[0]=0;
    printArr(L,0,n);
//    cout<<"r2"<<endl;
    // calculate the first biggest neighbour to the right
    for(int i=n-2;i>=0;i--)
    {
        R[i]=i;
        if(a[i+1]>a[i])
        {
            R[i]=i+1;
            continue;
        }
        int t=i+1;
        while(t!=-1 &&  R[t]!=t)
        {
            t=R[t];
            if(a[t]>a[i])
            {
                R[i]=t;
                break;
            }
        }
    }
    R[n-1]=n-1;
    printArr(R,0,n);
//    cout<<"r3"<<endl;
    // bit[i] stores the indices of the numbers whose i'th bit is set
    vector<vi> bit(40);
    for(int i=0;i<40;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(t[j]%2)
            {
                bit[i].pb(j);
            }
            t[j]=t[j]/2;
        }
    }
//    cout<<"r4"<<endl;
    /* For each element a[i], let l be the index of the element larger than it to the left and r be the same to the right.
       Then, find the first occurance of an element, say x, such that a[i]|x > a[i] and x belongs to [i+1,r-1].
       Let y be the same in the range [l+1,i-1].
       Then, any element to the right of x and to the left of y can be added to the set of answers.
       So, add (r-1 - i + 1) and (i - ( l + 1)) to answer.
    */

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        int miposr=0;
        int miposl=0;
        while(a[i])
        {
//            cout<<"a[i]"<<a[i]<<endl;
            if(a[i]%2==0)   
            {
                int firstToRight=binNext(bit[cnt],i);
                int firstToLeft=binPrev(bit[cnt],i);
                for(int kk=0;kk<bit[cnt].size();kk++)
                {
                    cout<<bit[cnt][kk]<<" ";
                }
                cout<<endl;
                cout<<"firsToLeft : "<<firstToLeft<<" && L[i] :"<<L[i]<<" & i : "<<i<<" & a[i] : "<<a[i]<<endl;
                if(firstToRight!=-1 && firstToRight<R[i])
                {
                    //ans+=max(0,R[i]-firstToRight);
                    miposr=max(miposr,R[i]-firstToRight);
                    //cout<<R[i]-firstToRight<<"R"<<endl;
                }
                if(firstToLeft!=-1 && firstToLeft>L[i])
                {
                    //ans+=(max(0,firstToLeft-L[i]));
                    miposl=max(miposl,firstToLeft-L[i]);
                    //cout<<firstToLeft-L[i]<<"L"<<endl;
                }
            }
            a[i]=a[i]/2;
            cnt++;
        }
        ans+=miposl;
        ans+=miposr;
        
        //cout<<miposl<<endl;
//        cout<<miposr<<endl;
        
    }
    cout<<ans<<endl;
    
    
	return 0;
}

