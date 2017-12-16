def ModE(a,b) :
    res = 1
    m = 1000000007
    while b>0 :
        #print " %d %d %d " %(res,a,b)
        if b & 1 :
            res = (res * a)%m;
        b = b >> 1
        a = (a*a)%m;
        #print "%d %d %d" % (a , a%m, m) ;
        res = res%m
    return res


n,m,k = raw_input().split()
n = int(n)
m = int(m)
k = int(k)
if (n%2 != m%2) and k==-1 :
    print 0
else :
    print ModE(2,(m-1)*(n-1))
