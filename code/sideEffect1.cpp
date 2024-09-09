#include <iostream>
using namespace std;
int i;
void bar (int j) {
    i = i + j; 
};
int main() {
    i = 0;
    bar (3);
    cout << i;
}
