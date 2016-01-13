#include <iostream>
#include "RedBlackTree.h"
#include "CreateTree.h"

using namespace std;
using namespace my_color;

int main(){

    // Write that Tree is being created

    cout << "Building tree is starting...." << "\n";

    // Calling algorithm for creating Red Black Trees with Wavelet Trees in it's nodes.
    RedBlackTree tree= createTree('#',8);

    // Write that Tree is created
    cout << "Building tree is finished. Starting functions......" << "\n";

    // RANK/SELECT CALLS
    cout << "Select(8, A) : " << tree.select(tree.getRoot(),8,'a');

    cout << "Select(800, C) : " << tree.select(tree.getRoot(),800,'c');

    cout << "Select(12000, G) : " << tree.select(tree.getRoot(),12000,'g');

    cout << "Select(150000, T) : " << tree.select(tree.getRoot(),150000,'t') << "\n";

    //cout << "Select(1000000, A) : " << tree.select(tree.getRoot(),1000000,'a');

    cout << "Rank(36, a) : " << tree.rank(tree.getRoot(),36,'a') << "\n";

    cout << "Rank(9000, C) : " << tree.rank(tree.getRoot(),9000,'c') << "\n";

    cout << "Rank(500000, G) : " << tree.rank(tree.getRoot(),500000,'g') << "\n";

    cout << "Rank(1000000, T) : " << tree.rank(tree.getRoot(),1000000,'t') << "\n";

    //cout << "Rank(20000000, A) : " << tree.rank(tree.getRoot(),20000000,'a');

    // Algorithm finished successfully
    cout << "Job is done !";

    return 0;
}