//
// Created by Christian Ledgard on 9/26/19.
//

#ifndef SOLVER_CHRISTIANLEDGARD_NODE_H
#define SOLVER_CHRISTIANLEDGARD_NODE_H


typedef std::string T;

struct node{
    T value;
    node *left;
    node *right;

    virtual ~node() {
        left = nullptr;
        right = nullptr;
    }

public:
    node(const T &value) : value(value) {
        left = nullptr;
        right = nullptr;
    }

    const T &getValue() const {
        return value;
    }
};



#endif //SOLVER_CHRISTIANLEDGARD_NODE_H
