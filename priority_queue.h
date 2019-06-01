#pragma once

#include <vector>
#include <math.h>
#include <iostream>
#include <functional>
#include <cassert>
#include <unordered_map>

struct Vertex {
	int v, w;
	Vertex() {
		v = w = 0;
	}
	Vertex(int v_, int w_) {
		v = v_;
		w = w_;
	}
	Vertex& operator=(const Vertex& V) { v = V.v; w = V.w; return *this; }
	bool operator<(const Vertex& V) { return w < V.w; }
	bool operator>(const Vertex& V) { return w > V.w; }
};

class priority_queue {
private:
	std::vector<Vertex> heap;
	int heap_size;
	std::unordered_map<int, int> pos;

	int parent(int i) const;
	int left(int i) const;
	int right(int i) const;
	void max_heapify(int i);
	void build_max_heap(std::vector<Vertex> V);
public:
	priority_queue();
	priority_queue(std::vector<Vertex> V);
	Vertex top() const;
	Vertex extract_top();
	void decrease_key(int i, const Vertex& key);
	void insert(const Vertex& key);
	int size() const;
	bool empty() const;
	int position(const Vertex& V);
	void print(); // for testing
};

