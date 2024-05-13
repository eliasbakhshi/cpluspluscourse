#ifndef DISJOINTSETSTEACHER_HPP
#define DISJOINTSETSTEACHER_HPP

#include <unordered_map>
#include <iostream>
#include <vector>

template <class T>
class DisjointSets {
private:
    std::unordered_map<T, T> elems;
    std::unordered_map<T, int> ranks;

public:
    int size() {
        return elems.size();
    }

    void makeSet(T u) {
        if (elems.find(u) == elems.end()) {
            elems[u] = u;
            ranks[u] = 0;
        }
    }

    T findSet(T u, bool with_path_compression = false) {
        return _findSet(u, T(), with_path_compression);
    }

    T _findSet(T parent, T child, bool with_path_compression) {
        if (parent == child) {
            return parent;
        }
        if (!with_path_compression) {
            return _findSet(elems[parent], parent, with_path_compression);
        } else {
            elems[parent] = _findSet(elems[parent], parent, with_path_compression);
            return elems[parent];
        }
    }

    void unionSet(T u, T v, bool with_rank = false) {
        T u_set = findSet(u);
        T v_set = findSet(v);
        if (!with_rank) {
            if (u_set != v_set) {
                elems[v_set] = u_set;
            }
        } else {
            if (ranks[u_set] == ranks[v_set]) {
                ranks[u_set]++;
                elems[v_set] = u_set;
            } else if (ranks[u_set] < ranks[v_set]) {
                elems[u_set] = v_set;
            } else {
                elems[v_set] = u_set;
            }
        }
    }
};

#endif