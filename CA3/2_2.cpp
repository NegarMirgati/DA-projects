#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
bool flowUtil(int &i, vector<int>&right, vector<int>&seen, map<int, vector<int> >&gmap, vector<int>&valid)
{
	for (int v = 0; v < right.size(); v++)
	{
		bool flag = true;
		for (int j = 0; j < gmap[i].size(); j++)
		{
			if (gmap[i][j] == right[v])
			{
				flag = false;
				break;
			}
			
		}
		if (flag && seen[v] == -1)
		{
			seen[v] = 1;
			if (valid[v] < 0 || flowUtil(valid[v],right, seen, gmap, valid))
			{
				valid[v] = i;
				return true;
			}
		}

	}
	return false;
	
}
int flow(vector<int>right,map<int, vector<int> >&gmap,int m, int n)
{
	vector<int>valid(m,-1);
	int ans=0;
	for (int i = 0; i < n; i++)
	{
		vector<int>seen(m,-1);
		if (flowUtil(i,right, seen, gmap,valid))
			ans+=1;
		
	}
	return ans;
}

int main()
{
	int n, m ,e;
	int  a,b;
	int ans = 0;
	map<int, vector<int> >gmap;
	map<int, vector<int> >::iterator it;
	cin >> n >> m >> e;
	vector<int> right(m,-1);
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b;
		it = gmap.find(a);
		if ( it == gmap.end())
		{
			vector<int> arr(1,b);
			gmap[a]=arr;
		}	
		else
		{
			gmap[a].push_back(b);
		}
	
	}
	
	if(e==0)
		{
			cout<<max(m,n)<<endl;
			return 0;
		}
		ans=flow(right,gmap,m,n);
		cout << n+m-ans <<  endl;
	return 0;
}