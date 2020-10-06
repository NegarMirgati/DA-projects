 #include <iostream>  
 #include <vector>  
 #include <queue>  
 #include <climits>
 #include <algorithm>

 using namespace std;  

 vector <int> Graph[1000]; 
 vector <int> GraphBar[1000];
 int match[1000],table[1000]; 
  
 int  MaxMatching(int,int);
 void constructGraphBar(int,int);
 bool BFS(int);
 bool DFS(int);


 int main(){

   int a,b; 
   int n , m , e ; 
   cin >> n >> m >> e;

   for(int i=0;i<e;i++) 
   { 
     cin>>a>>b;
     GraphBar[a+1].push_back(b+n+1);  
     
   }

   cout<<n+m-MaxMatching(n,m)<<endl;
   return 0;
 }  


 bool BFS(int n) {  
     int u, v;  
     queue<int> Queue;

     for(int i=1; i<=n; i++) {  
         if(match[i]==0) {
             table[i] = 0;  
             Queue.push(i);  
     }  
     else table[i] = INT_MAX;  
   }  
   table[0] = INT_MAX;  
   while( !Queue.empty() ) {  
     u = Queue.front();  
     Queue.pop();  
     if(u) {  
       for(int i = 0; i < Graph[u].size() ; i++) {  
         v = Graph[u][i];  

         if( table[match[v]]==INT_MAX ) {  
             table[match[v]] = table[u] + 1;  
             Queue.push(match[v]);  
         }  
       }  
     }  
   }  
   return (table[0]!=INT_MAX);  
 }  

 bool DFS(int u) {  

   if(u) {  
     for(int i = 0; i < Graph[u].size(); i++) {  
         int v = Graph[u][i];  
         if( table[match[v]] == table[u]+1 ) {  
             if(DFS(match[v])) {  

                match[v] = u;  
                match[u] = v;  

           return true;  
         }  
       }  
     }  
     table[u] = INT_MAX;  
     return false;  
   }  
   return true;  
 }  

 int MaxMatching(int n ,int m) {  

    int matching_size = 0; 

    constructGraphBar(n,m);
    while(BFS(n))  
     for(int i = 1; i <= n; i ++){
       if( !(match[i]) && DFS(i) )  
           matching_size++;
       }

    return matching_size;  
 }  

 void constructGraphBar(int n,int m)
 {

    for(int i = 1;i <= n; i++)
      for(int j = n+1;j <=n+m ;j++){

        if( find( GraphBar[i].begin(),GraphBar[i].end(),j ) == GraphBar[i].end() )
        Graph[i].push_back(j);
    }
 }



