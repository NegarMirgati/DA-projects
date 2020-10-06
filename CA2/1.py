def main():
    T=int(raw_input())
    for i in range (0 , T):
        n=int(raw_input())
        if n==0:
            print(0)
        elif n==1:
            print(1)
        else:
            print(findPerms(int(n)))
            
def findPerms(n):
    vec = [[[0 for k in xrange(n+1)] for j in xrange(n+1)] for i in xrange(n+1)]
    vec[0][0][0]=0
    vec[1][0][0]=1
    vec[0][1][0]=0
    vec[0][0][1]=0
    vec[1][0][1]=0
    vec[1][1][0]=1
    vec[1][0][1]=0
    vec[1][1][1]=1
    
    for l in range (2 , n*3 + 1):
        for a in range ( 1, min(l,n) + 1):
            for b in range (0 , min (l-a , n) + 1):
                c=l-(a+b)
                if(c>n or c<0  or a<b or b<c):
                    continue
                if(b==0):
                    vec[a][b][c]= vec[a][b-1][c];
                    if(a>b):
                        vec[a][b][c]+=vec[a-1][b][c];
                    continue
                elif( ( a > b) and (b > c) ):
                
                    vec[a][b][c] = vec[a-1][b][c] + vec[a][b-1][c] + vec[a][b][c-1]
                

                elif ((a>b) and b==c):
                
                    vec[a][b][c] = vec[a-1][b][c] + vec[a][b][c-1]
                
                elif((a==b) and b>c):
                
                    vec[a][b][c] = vec[a][b-1][c] + vec[a][b][c-1]
                

                elif((a==b) and (b==c)):
                
                    vec[a][b][c] = vec[a][b][c-1]
    return vec[n][n][n]
                
    
main()
            