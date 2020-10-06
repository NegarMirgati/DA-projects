#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include<set>
#include <list>
using namespace std;

# define INF 0x3f3f3f3f
map<long long int,vector<long long int> > closed;
class Graph
{
    int V;
    list< pair<long long int,long long  int> > *adj;
 
public:
    Graph(long long int V);  
    void addEdge(long long int u,long long int v,long long int w);
    bool isclosed(long long int vertex,long long int time);
    long long int shortestPath(long long int s,long long int sink);
};
 
Graph::Graph(long long int V)
{
    this->V = V;
    adj = new list< pair<long long int,long long int> >[V];
}
 
void Graph::addEdge(long long int u,long long int v,long long int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

bool Graph::isclosed(long long int vertex,long long int time)
{
  if(closed.find(vertex)!=closed.end())
  {
    vector<long long int>::iterator it=find(closed[vertex].begin(), closed[vertex].end(), time);
    if( it!= closed[vertex].end() && closed[vertex][*it]!=INF)
      {
      return true ;
      }
  }
   return false;
 }

long long int Graph::shortestPath(long long int src,long long int sink)
{
    set< pair<long long int,long long int> > setds;

    vector<long long int> dist(V, INF);

    setds.insert(make_pair(0, src));
    dist[src] = 0;

    while (!setds.empty())
    {
        pair<long long int,long long int> tmp = *(setds.begin());
        setds.erase(setds.begin());

        long long int u = tmp.second;
        /*while (isclosed(u,dist[u]))
          dist[u]+=1;*/

        list< pair<long long int,long long int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            long long int v = (*i).first;
            long long int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));

                dist[v] = dist[u] + weight;
                 if (dist[v] != INF)
                while  ( isclosed(v,dist[v]) && v!=sink && dist[v]!=INF) ++dist[v];
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
 
    return dist[sink];
}
 
int main()
{
   long long int n , m ;
   long long int a , b , w ;
   
   cin >> n >> m ;
   int V = n+1000;
   Graph g(V);
   for (long long int i=0;i<m;i++)
   {
     cin>> a >> b >> w;
     g.addEdge(a-1,b-1,w);
   }

   for (long long int j=0;j<n;j++)
   {
      long long int num ;
      cin >> num ;
      for(long long int i=0;i<num;i++)
        {
          long long int val;
          cin>>val;
          closed[j].push_back(val);
        }   
    }
    long long int out=g.shortestPath(0,n-1);
    if(out==INF)
      cout<<"-1"<<endl;
    else 
      cout<<out<<endl;
  
    return 0;
}
