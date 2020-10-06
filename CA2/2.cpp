#include <iostream>
#include <vector>
using namespace std;

#define   _INT_MAX 2147483647
int findMinFuel(vector<int> , int , int );


int main()
{
    int T , n , f , k;
    cin >> T;
    for ( int i = 0 ; i < T ; i++ ){
    cin >> k ;
    cin >> n ;
    vector < int > fuel ;
    for ( int j = 0 ; j < n ; j++ ){
    cin >> f ;
    fuel.push_back(f);
         
       }
       int ans = findMinFuel( fuel , fuel.size() , k );

         if(ans == _INT_MAX) 
            cout << -1 << endl ;
          else
            cout << ans<< endl;
     }
    return 0;
}

int findMinFuel(vector<int> fuel, int m, int k)
{
    int dp[k+1];

    dp[0] = 0;

    for (int i= 1 ; i <= k ; i++ )
        dp[i] = _INT_MAX;

    for (int i = 1 ; i <= k; i++ )
    {
        for (int j=0; j<m; j++)
          if (fuel[j] <= i)
          {
              int temp = dp[i-fuel[j]] ;
              if ( temp != _INT_MAX && temp + 1 < dp[i] )
                  dp[i] = temp + 1;
          }
    }
    return dp[k];
}