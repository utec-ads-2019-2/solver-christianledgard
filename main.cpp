#include "solver.h"

using namespace std;

int main() {
    string input;
    getline(cin, input);

    Solver Exp(input);
    //Exp.printPostOrder();
    //cout << endl;
    cout << "El resultado es: " << Exp.resultado();

    return 0;
}