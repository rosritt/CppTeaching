#include "cstack.hpp"
#include <stack>
#include <iostream>

using namespace std;

int main(){
    stack<int> s;
    s.pop();
    s.pop();
    s.push(1);
    cout <<  "done" << endl;
    return 0;
}