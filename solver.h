//
// Created by Christian Ledgard on 9/26/19.
//
#ifndef SOLVER_CHRISTIANLEDGARD_SOLVER_H
#define SOLVER_CHRISTIANLEDGARD_SOLVER_H

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>

#include "node.h"

using namespace std;

class Solver{

private:
    vector<char> numeros;
    vector<node*> vectorNodos;
    stack<char> operadores;
    stack<node*> stackArbol;
    map<char, int> variables;

    string expression;

public:

    Solver(const string &str) : expression(str) {
        createPostOrder(str);
        calculateStack();
    }

    void createPostOrder(string line);
    float evaluar(char operador);
    void calculateStack();
    void printPostOrder();
    T resultado();

};

#endif //SOLVER_CHRISTIANLEDGARD_SOLVER_H
