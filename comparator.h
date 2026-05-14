#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <vector>
#include "node.h"

struct CompareF {
    std::vector<Node> &pool;
    CompareF(std::vector<Node> &pool) : pool(pool) {}
    bool operator()(int a, int b) const {
        return pool[a].f_cost > pool[b].f_cost;
    }
};

struct CompareG {
    std::vector<Node> &pool;
    CompareG(std::vector<Node> &pool) : pool(pool) {}
    bool operator()(int a, int b) const {
        return pool[a].g_cost > pool[b].g_cost;
    }
};

#endif
