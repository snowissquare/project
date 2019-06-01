#pragma once
#include "priority_queue.h"
#include <vector>

const int INF = 10000000;

class Dijkstra
{
public:
	Dijkstra(int n, std::vector<std::vector<Vertex>> g) : N(n) { G = g; } 

	int algs(int s, int f) // номера вершин:) o_O
	{
		priority_queue PQ;
		PQ.insert(Vertex(s, 0));
		for (int i = 1; i <= N; i++)
		{
			if (i != s)
			{
				PQ.insert(Vertex(i, INF));
			}
		}
		std::vector<int> dist(G.size() + 3, INF); // двойная контрацепция
		dist[s] = 0;
		while (!PQ.empty()) 
		{
			int u = PQ.extract_top().v;
			for (int i = 0; i < G[u].size(); i++)
			{
				int v = G[u][i].v;
				int weight = G[u][i].w;
				if (dist[v] > dist[u] + weight)
				{
					dist[v] = dist[u] + weight;
					PQ.decrease_key(PQ.position(G[u][i]), Vertex(v, dist[v]));
				}
			}
		} 
		if (dist[f] == INF)
		{
			std::cout << "ban" << std::endl;
			return -1;
		}
		std::vector<std::vector<Vertex>> I(G.size(),std::vector<Vertex>());
		for (int i = 0; i < G.size(); i++)
		{
			for (int j = 0; j < G[i].size(); j++)
			{
				I[G[i][j].v].push_back(Vertex(i, G[i][j].w));
			}
		}
		std::vector<int> vertres;
		vertres.push_back(f);
		while (vertres[vertres.size() - 1] != s)
		{
			for (int i = 0; i < I[vertres[vertres.size() - 1]].size(); i++)
			{
				if (dist[I[vertres[vertres.size() - 1]][i].v] + I[vertres[vertres.size() - 1]][i].w == dist[vertres[vertres.size() - 1]])
				{
					vertres.push_back(I[vertres[vertres.size() - 1]][i].v);
					break;
				}
			}
		}
		std::reverse(vertres.begin(), vertres.end());
		for (int i = 0; i < vertres.size(); i++)
		{
			std::cout << vertres[i] <<' ';
		}
		std::cout << '\n';

		return dist[f];
	}
private:
	int N;
	std::vector<std::vector<Vertex>> G;
};


