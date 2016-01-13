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
    cout << "Select(8, A) : " << tree.select(tree.getRoot(),8,'a');

    cout << "Select(800, C) : " << tree.select(tree.getRoot(),8,'c');

    cout << "Select(12000, G) : " << tree.select(tree.getRoot(),8,'g');

    cout << "Select(150000, T) : " << tree.select(tree.getRoot(),8,'t');

    cout << "Select(1000000, A) : " << tree.select(tree.getRoot(),8,'a');

    cout << "Rank(36, a) : " << tree.select(tree.getRoot(),8,'a');

    cout << "Rank(9000, C) : " << tree.select(tree.getRoot(),8,'c');

    cout << "Rank(500000, G) : " << tree.select(tree.getRoot(),8,'g');

    cout << "Rank(1000000, T) : " << tree.select(tree.getRoot(),8,'t');

    cout << "Rank(20000000, A) : " << tree.select(tree.getRoot(),8,'a');

    // Algorithm finished successfully
    cout << "Job is done !";

    return 0;
}