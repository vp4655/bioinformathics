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

    // RANK/SELECT CALLS
    cout << "Select(27 , A) : " << tree.select(tree.getRoot(),27,'a') << "\n";

    cout << "Select(36, C) : " << tree.select(tree.getRoot(),36,'c') << "\n";

    cout << "Select(24, C) : " << tree.select(tree.getRoot(),24,'c') << "\n";

    cout << "Select(91, G) : " << tree.select(tree.getRoot(),91,'g') << "\n";

    cout << "Select(56, T) : " << tree.select(tree.getRoot(),56,'t') << "\n";


    cout << "Rank(C, 609) : " << tree.rank(tree.getRoot(),609,'c') << "\n";

    cout << "Rank(T, 50) : " << tree.rank(tree.getRoot(),50,'t') << "\n";

    cout << "Rank(C, 337) : " << tree.rank(tree.getRoot(),337,'c') << "\n";

    cout << "Rank(C, 754) : " << tree.rank(tree.getRoot(),754,'c') << "\n";

    cout << "Rank(T, 502) : " << tree.rank(tree.getRoot(),502,'t') << "\n";

    // Algorithm finished successfully
    cout << "Job is done !\n";

    return 0;
}