#include <iostream>
#include <vector>
#include "priority_queue.h"
#include "header.h"

int main() 
{
	int N, M, S, F;
	std::cin >> N >> M >> S >> F;
	std::vector<std::vector<Vertex>> G(N + 3);
	std::vector<Vertex> vertexes(N + 3);
	int a, b, d;
	for (int i = 0; i < M; i++) 
	{
		std::cin >> a >> b >> d;
		G[a].push_back(Vertex(b, d));
	}
	Dijkstra D(N, G);
	int l = 0;
	l = D.algs(S, F);
	if (l != -1)
	{
		std::cout << l << "\n";
	}
	system("pause");
	return 0;
}
