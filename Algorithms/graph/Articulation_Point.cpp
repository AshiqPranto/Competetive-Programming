// resource -> http://www.shafaetsplanet.com/?p=2504


#include<bits/stdc++.h>
using namespace std;
#define N 100

vector<int>graph[N];

void findArticulationPoint_utils(int current_node, vector<int>& discovery_time, vector<int>& low, vector<int>& parent, int &time, vector<int>&articulation_points)
{
	//set discovery time and low of current node as time.
	discovery_time[current_node] = time;
	low[current_node] = time;

	//set children count of current node as 0
	int children_cnt = 0;
	//increment the time variable
	time++;

	for (int child_node : graph[current_node])
	{
		if (discovery_time[child_node] == -1)
		{	//if child node has not been visited before

			//set parent of child node and increment the children count
			parent[child_node] = current_node;
			children_cnt++;
			findArticulationPoint_utils(child_node, discovery_time, low, parent, time, articulation_points);
			//set the low for current node
			low[current_node] = min(low[current_node], low[child_node]);

			if (parent[current_node] == -1 && children_cnt > 1)
			{	//case 1:
				articulation_points[current_node] = 1;
			}
			else if (parent[current_node] != -1 && low[child_node] >= discovery_time[current_node])
			{	//case 2:
				articulation_points[current_node] = 1;
			}
		}
		else if (parent[current_node] != child_node)
		{	// if child node has been visited before it is a back-edge
			//set low for current node.
			low[current_node] = min(low[current_node], discovery_time[child_node]);
		}
	}
}
void findArticulationPoint(int vertices, int edges)
{
	//initilise parent,discovery_time and low as -1.
	vector<int>parent(vertices + 1, -1);
	vector<int>discovery_time(vertices + 1, -1);
	vector<int>low(vertices + 1, -1);

	//artipulation_points vector will be used to store articulation points
	vector<int>articulation_points(vertices + 1, 0);

	int time = 1;


	for (int i = 1; i <= vertices; i++)
	{
		//do dfs for the graph.
		if (discovery_time[i] == -1)
		{
			findArticulationPoint_utils(i,  discovery_time, low, parent, time, articulation_points);
			//set time as 1 for next dfs call
			time = 1;
		}
	}

	//print the articulation points
	cout << "The articulation point are:\n";
	for (int i = 1; i <= vertices; i++)
	{
		if (articulation_points[i] == 1)
		{
			cout << i << " ";
		}
	}

}

int main()
{

	int vertices, edges;

	vertices = 6, edges = 6;

	//make the undirected graph
	//same graph as the one shown in first example.

	graph[1].push_back(2);
	graph[2].push_back(1);

	graph[1].push_back(3);
	graph[3].push_back(1);

	graph[2].push_back(4);
	graph[4].push_back(2);

	graph[3].push_back(5);
	graph[5].push_back(3);

	graph[3].push_back(6);
	graph[6].push_back(3);

	graph[1].push_back(4);
	graph[4].push_back(1);

	findArticulationPoint(vertices, edges);

	return 0;


}