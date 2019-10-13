//
// Created by Christian Ledgard on 10/13/19.
//
#include "solver.h"

bool isoperator(char x){
    switch(x){
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '^':
            return true;
        default:
            return false;
    }
}
int priorityOperator(char x){
    switch(x){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}
bool isparenthesis(char x){
    switch(x){
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}

void Solver::createPostOrder(string line) {
    for(int i = 0; i < line.size(); ++i ){
        if(isdigit(line[i])){
            numeros.push_back(line[i]);

            if(!isdigit(line[i+1])){
                string temporal;
                for(auto elemento: numeros){
                    temporal += elemento;
                }
                vectorNodos.push_back(new node(temporal));
                numeros.clear();
            }

        } else if (isalpha(line[i])) {
            string s; s=line[i];
            vectorNodos.push_back(new node(s));

        } else if (isoperator(line[i])){

            if(operadores.empty())
                operadores.push(line[i]);
            else{
                if(line[i] == '(')
                    operadores.push(line[i]);
                else if (line[i] == ')'){
                    while(operadores.top()!='('){
                        string s; s=operadores.top();
                        if(!isparenthesis(operadores.top()))
                            vectorNodos.push_back(new node(s));
                        operadores.pop();
                    }
                    operadores.pop();
                }
                else{
                    if(!operadores.empty()){
                        while((priorityOperator(operadores.top())>=priorityOperator(line[i]))){
                            string s; s=operadores.top();
                            vectorNodos.push_back(new node(s));
                            operadores.pop();
                            if (operadores.empty())
                                break;
                        }
                    }
                    operadores.push(line[i]);
                }
            }

        } else if (line[i] == ' ') {
            continue;
        }
    }

    while(!operadores.empty()){
        if(!isparenthesis(operadores.top())){
            string s; s=operadores.top();
            vectorNodos.push_back(new node(s));
        }
        operadores.pop();
    }

}
long Solver::evaluar(char operador){
    long n2 = stol(stackArbol.top()->getValue());
    stackArbol.pop();
    long n1 = stol(stackArbol.top()->getValue());
    stackArbol.pop();

    switch(operador){
        case '+':
            return n1+n2;
        case '-':
            return n1-n2;
        case '*':
            return n1*n2;
        case '/':
            return n1/n2;
        case '^':
            return pow(n1,n2);
        default:
            return 0;
    }
}
void Solver::calculateStack() {
    for(auto it = vectorNodos.begin(); it != vectorNodos.end(); ++it) {

        if(!isoperator((*it)->getValue()[0])){ //Numero o Letra
            if(isalpha((*it)->getValue()[0])){ //Variable
                if(variables[(*it)->getValue()[0]]){ //Si existe una variable registrada
                    stackArbol.push(new node(to_string(variables[(*it)->getValue()[0]])));
                } else {
                    long temp;
                    cout << "Ingrese el valor de la variable " << (*it)->getValue()[0] << ": ";
                    cin >> temp;
                    variables[(*it)->getValue()[0]]=temp;
                    stackArbol.push(new node(to_string(temp)));
                }
            } else { //Numeros
                stackArbol.push(*it);
            }
        } else {
            stackArbol.push(new node(to_string(evaluar((*it)->getValue()[0]))));
        }
    }
}
void Solver::printPostOrder() {
    for(auto it = vectorNodos.begin(); it != vectorNodos.end(); ++it) {
        cout << (*it)->getValue() << " | ";
    }
}
T Solver::resultado() {
    return stackArbol.top()->getValue();
}

