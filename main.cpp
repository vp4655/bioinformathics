#include <iostream>
#include "RedBlackTree.h"
#include "CreateTree.h"

using namespace std;
using namespace my_color;

int main(){

    long N;
    Data *data;
    RedBlackTree tree= createTree('#',8);
    cout<<tree.select(tree.getRoot(),8,'a');

    return 0;
}