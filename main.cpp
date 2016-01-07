#include <iostream>
#include "RedBlackTree.h"

using namespace std;
using namespace my_color;

int main(){

    long N;
    Data *data;
    RedBlackTree tree = RedBlackTree();

    do{
        cin >> N;
        if(N > -1){
            tree.insert(N);
        }
    }while (N > -1);

    tree.disp();

    return 0;

}