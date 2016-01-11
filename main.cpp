#include <iostream>
#include "RedBlackTree.h"
#include "CreateTree.h"

using namespace std;
using namespace my_color;

int main(){

    long N;
    Data *data;
    RedBlackTree tree= createTree('#',8);
    tree.disp();
    //cout << "\n"<<tree.rank(tree.getRoot(),1,'a');


        /*RedBlackTree tree = RedBlackTree();

    do{
        cin >> N;
        if(N > -1){
            tree.insert(N,nullptr, nullptr);
        }
    }while (N > -1);

    tree.disp();

    return 0;*/


}