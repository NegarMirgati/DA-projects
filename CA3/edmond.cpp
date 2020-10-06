#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm>
#include <cstddef>
using namespace std;
int bipartiteMatch(map<int,vector<int> >graph){
	
	map<int,int> matching ;
	map<int, vector<int> >::iterator it;

	for(it=graph.begin();it!=graph.end();it++)
	{
		int u = it->first;
		for(int j=0;j<it->second.size();j++)
		{
			int v=graph[u][j];
			if(find(graph[u].begin(),graph[u].end(), v)==graph[u].end())
			{
			matching[v]=u;
			break;
			}

		}
	}

	while (true)
	{
		map<int,vector<int> > preds;
		map<int,int > pred;
		map<int,int > ::iterator matchit;
		vector<int> unmatched;
		for (it=graph.begin();it!=graph.end();it++)
		{
			int u=it->first;
			pred[u]=unmatched;

		}
		for(matchit=matching.begin();matchit!=matching.end();matchit++)
		{
			int v=it->first;
			pred.erase(matching[v]);
		}
		vector<int> layer;
		for(matchit=matching.begin();matchit!=matching.end();matchit++)
		{
			layer.push_back(matchit->first);
		}
		while(layer.size()!=0 && unmatched.size()==0)
		{
			map<int,vector<int> > newLayer;
			for (int u=0;u<layer.size();u++)
			{
				for(int i=0;i<graph[u].size();i++)
				{
					int v=graph[u][i];
					if(preds[v]==preds.end())
					{
					newLayer[v]={};
					newLayer[v].push_back(u);
					}

				}
			}
		

		layer.clear();
		map<int,vector<int> >::iterator nlit;
		for(nlit=newLayer.begin();nlit!=newLayer.end();nlit++)
		{
			int v = nlit->first;
			preds[v]=newLayer[v];
			if (matching.find(v)!=matching.end())
			{
				layer.push_back(matching[v]);
				pred[matching[v]]=[v];
			}
			else
				unmatched.push_back(v);
		}
	}

	if(unmatched.size()!=0){
		map<int,int> unlayered;
		for(it=graph.begin();it!=graph.end();it++)
		{
			for (int i=0;i<graph[it->first].size();i++)
			{
				for(int j=0;j<graph[it->first].size();j++){
					int v=graph[i][j];
				if (preds.find(v)==preds.end())
					unlayered[v]=NULL;
			}
			}
		}
		return matching.size();
	}
		for (int i = 0; i<unmatched.size();i++){
			int v=unmatched[i];
			recurse(v,preds,pred,unmatched,matching);
		}
	}
}

bool recurse(int v,map<int,vector<int> > preds,
		map<int,int> pred,vector<int>unmatched,map<int,int> matching){
	if(preds.find(v)!=preds.end())
	{
		map<int,vector<int> >::iterator it;
		it=preds.find(v);
		vector<int> L=preds[v];
		preds.erase(it);
		for(int j=0;j<L.size();j++)
		{
			int u=L[j];
			if (pred.find(u)!=pred.end()){
				int pu =pred[u];
				it=pred.find(u);
				pred.erase(it);
				if(pu==unmatched || recurse(pu,preds,pred,unmatched,matching))
				{
					matching[v]=u;
					return 1;
				}
			}
		}

	}
	return 0;
}

int main(){
	return 0;
}