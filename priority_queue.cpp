#include "priority_queue.h"

priority_queue::priority_queue() {
	build_max_heap(std::vector<Vertex>());
}

priority_queue::priority_queue(std::vector<Vertex> V) {
	build_max_heap(V);
}

int priority_queue::parent(int i) const {
	return std::floor(i / 2.0);
}

int priority_queue::left(int i) const { // индексы детей
	return i * 2;
}

int priority_queue::right(int i) const {
	return i * 2 + 1;
}

void priority_queue::max_heapify(int i) {
	int l = left(i);
	int r = right(i);
	int largest = -1;
	if (l <= heap_size && heap[i] > heap[l]) {
		largest = l;
	}
	else {
		largest = i;
	}
	if (r <= heap_size && heap[largest] > heap[r]) {
		largest = r;
	}
	if (largest != i) {
		std::swap(pos[heap[largest].v], pos[heap[i].v]);
		std::swap(heap[largest], heap[i]);
		max_heapify(largest);
	}
}

void priority_queue::build_max_heap(std::vector<Vertex> V) {
	heap_size = V.size();
	heap.clear();
	heap.push_back(Vertex());
	heap.insert(heap.end(), V.begin(), V.end());
	for (int i = 1; i <= heap_size; i++) {
		pos[i] = i;
	}
	for (int i = std::ceil(heap_size / 2.0); i >= 1; i--) {
		max_heapify(i);
	}
}

Vertex priority_queue::top() const {
	assert(!empty());
	return heap[1];
}

Vertex priority_queue::extract_top() {
	assert(!empty());
	Vertex max = heap[1];
	pos[max.v] = -1;
	pos[heap[heap_size].v] = 1;
	heap[1] = heap[heap_size];
	heap_size--;
	max_heapify(1);
	return max;
}

void priority_queue::decrease_key(int i, const Vertex& key) {
	//assert(compare(heap[i], key) || heap[i] == key);
	heap[i] = key;
	while (i > 1 && heap[parent(i)] > heap[i]) {
		std::swap(pos[heap[parent(i)].v], pos[heap[i].v]);
		std::swap(heap[parent(i)], heap[i]);
		i = parent(i);
	}
}

void priority_queue::insert(const Vertex& key) {
	heap_size++;
	if (heap_size >= heap.size()) {
		heap.push_back(key);
	}
	else {
		heap[heap_size] = key;
	}
	pos[heap[heap_size].v] = heap_size;
	decrease_key(heap_size, key);
}

int priority_queue::size() const {
	return heap_size;
}

bool priority_queue::empty() const {
	return heap_size == 0;
}

int priority_queue::position(const Vertex& V) {
	return pos[V.v];
}

void priority_queue::print() {
	for (int i = 1; i <= heap_size; i++) {
		std::cout << heap[i].v << " " << heap[i].w << "\n";
	}
}
