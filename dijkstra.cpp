// shortest path routing using dijkstra algorithm

#include<bits/stdc++.h>
using namespace std;
const int inf = 1e7;

int main()
{
	int nodes,edges;
	cout<<"Enter number of nodes and edges = ";
	cin>>nodes>>edges;

	vector<vector<pair<int,int>>> graph(nodes + 1);

	vector<int> dist(nodes + 1,inf);

	cout<<"Enter edges (U V W) = "<<endl;
	for(int i=0; i<edges; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}

	int source;
	cout<<"Enter the Source node = ";
	cin>>source;

	dist[source] = 0;

	set<pair<int,int>> st;
	st.insert({0,source});

	while(!st.empty())
	{
		auto node = *st.begin();
		int v = node.second;
		int v_dist = node.first;
		st.erase(st.begin());

		for(auto child:graph[v])
		{
			int child_v = child.first;
			int w = child.second;

			if(dist[v] + w < dist[child_v])
			{
				dist[child_v] = dist[v] + w;
				st.insert({dist[child_v],child_v});
			}
		}
	}

	cout<<"Shortest Distances from node "<<source<<" : "<<endl;
	for(int i=1; i<=nodes; i++)
	{
		cout<<"Distance form "<<source<<" to "<<i<<" is ";
		if(dist[i] == inf)
			cout<<"INF"<<endl;
		else
			cout<<dist[i];
		cout<<endl;
	}
	return 0;
}


// Output :

// Enter number of nodes and edges = 5 6
// Enter edges (U V W) = 
// 1 2 10
// 1 3 5
// 2 3 2
// 2 4 1
// 3 2 3
// 3 4 9
// Enter the Source node = 1

// Shortest Distances from node 1 : 
// Distance form 1 to 1 is 0
// Distance form 1 to 2 is 7
// Distance form 1 to 3 is 5
// Distance form 1 to 4 is 8
// Distance form 1 to 5 is INF

