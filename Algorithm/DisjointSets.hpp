#ifndef DISJOINTSETS_HPP
#define DISJOINTSETS_HPP

#include <unordered_map>
#include <iostream>
#include <vector>

template <class T>
class DisjointSets {
private:
	std::unordered_map<T, T> sets;
public:
	DisjointSets();
	int size();
	void makeSet(T u);
	T findSet(T u, bool with_path_compression = false);
	void unionSet(T u, T v, bool with_rank = false);

};
template <class T>
DisjointSets<T>::DisjointSets() {


}
template <class T>
int DisjointSets<T>::size() {
	return sets.size();

}
template <class T>
void DisjointSets<T>::makeSet(T u) {
	sets[u] = u;
}
template <class T>
T DisjointSets<T>::findSet(T u, bool with_path_compression) {
	T parent = u;
	while (parent != sets[parent]) {
		parent = sets[parent];
	}
	return parent;
}
template <class T>
void DisjointSets<T>::unionSet(T u, T v, bool with_rank) {
	T roor_u = findSet(u);
	T root_V = findSet(v);
	if (root_V != roor_u) {
		sets[root_V] = roor_u;
	}
}

#endif