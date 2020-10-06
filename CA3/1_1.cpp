#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
bool f(int &i, vector<int>&numbers, vector<int>&seen, map<int, vector<int>>&graph, vector<int>&a)
{
	for (int v = 0; v < numbers.size(); v++)
	{
		bool ans = false;
		for (int j = 0; j < graph[i].size(); j++)
		{
			if (graph[i][j] == numbers[v])
			{
				ans = true;
				break;
			}
			
		}
		if (ans && seen[v] == -1)
		{
			seen[v] = 1;
			if (a[v] < 0 || f(a[v], numbers, seen, graph, a))
			{
				a[v] = i;
				return true;
			}
		}

	}
	return false;
	
}
int main()
{
	map<int, vector<int>>graph;
	vector <int> numbers;
	//vector <int> seen;
	int n,a,b,x;
	cin >> n;

	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		vector<int>temp;
		temp.push_back(a + b);
		if (find(numbers.begin(), numbers.end(), a + b) == numbers.end()){
			numbers.push_back(a + b);
			//seen.push_back(-1);
		}
		if (a + b != a*b)
		{
			temp.push_back(a * b);
			if (find(numbers.begin(), numbers.end(), a * b) == numbers.end())
			{
				numbers.push_back(a * b);
				//seen.push_back(-1);
			}
		}
			
		if (a - b != a*b || a - b != a + b)
		{
			temp.push_back(a - b);
			if (find(numbers.begin(), numbers.end(), a - b) == numbers.end())
			{
				numbers.push_back(a - b);
				//seen.push_back(-1);
			}
		}
			
		graph[i] = temp;
		temp.clear();
	}
	int answer = 0;
	
	vector<int>mm(numbers.size(), -1);
	for (int i = 0; i < n; i++)
	{
		
			vector<int>seen(numbers.size(), -1);
		if (f(i, numbers, seen, graph, mm))
			answer += 1;
		
	}
	if (answer >= n)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}