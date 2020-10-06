#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
 

bool maxmatchingutil(vector<vector<int> > bpGraph, int u, bool seen[], int matchR[],int M , int N)
{
    for (int v = 0; v < N; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true; 
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR,M,N))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
 
int maxmatching(vector<vector<int> > bpGraph,int M , int N )
{
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));
 
    int ans = 0;
    for (int u = 0; u < M; u++)
    {
        bool seen[N];
        memset(seen, 0, sizeof(seen));
        if (maxmatchingutil(bpGraph, u, seen, matchR,M,N))
            ans++;
    }
    return ans;
}
 vector<vector<int> > constructgraph(map< int,map<int,int> > gmap,int m,int n){

    vector < vector < int > > bpGraph(m, vector< int >(n,0));
    map<int,map<int,int> >::iterator it;
    for (int i=1 ;i<=m ;i++)
        for (int j=m+1 ; j<=n+m+1; j++)
          { 
                
                if(gmap[i].find(j)==gmap[i].end())
                bpGraph[i-1][j-m-1]=1;
            }
   /*for(int i=0;i<bpGraph.size();i++)
       { for(int j=0;j<bpGraph[0].size();j++)
            cout<<bpGraph[i][j]<<"**";
            cout<<endl;
        }*/

    return bpGraph;
    

 }
// Driver program to test above functions
int main()
{
    int m , n , e;
    int a , b;
    cin>>m>>n>>e;
    map<int,map<int,int> > gmap;
    map<int,map<int,int> >::iterator it;

    for (int i=0;i<e;i++)
    {
        cin>>a>>b;
        if(a>= m || b>=n)
            continue;
        a=a+1;
        b=b+m+1;
        
        it=gmap.find(a);
        if ((it==gmap.end()))
        {
            map<int,int> temp;
            temp.insert(pair<int,int>(b,0));
            gmap[a]=temp;
        }
        else
            gmap[a].insert(pair<int,int>(b,0));

    }
    if(e==0)
        cout<<max(n,m)<<endl;
    else{
    int maxFlow =maxBPM(constructgraph(gmap,m,n),m,n);
 
    cout<<n+m-maxFlow<<endl;
}
    return 0;
}

