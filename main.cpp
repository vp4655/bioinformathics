#include <iostream>
#include "RedBlackTree.h"
#include "CreateTree.h"

using namespace std;
using namespace my_color;

int main(){

    // Calling algorithm for creating Red Black Trees with Wavelet Trees in it's nodes.
    RedBlackTree tree= createTree('#',8);

    // Write that Tree is created
    cout << "Building tree is finished. Starting functions......";

    // RANK/SELECT CALLS
    cout << "Select(8, a) : " << tree.select(tree.getRoot(),8,'a');

    // Algorithm finished successfully
    cout << "Job is done !";

    return 0;
}