#include <iostream>
#include "RedBlackTree.h"
#include "CreateTree.h"
#include "windows.h"
#include "psapi.h"
#include <ctime>

using namespace std;
using namespace my_color;

int main(){

    // Write that Tree is being created

    cout << "Building tree is starting...." << "\n";

    // Start time counting for Tree creation
    clock_t begin = clock();

    // Calling algorithm for creating Red Black Trees with Wavelet Trees in it's nodes.
    RedBlackTree tree= createTree('#',8);

    // Finish time counting for Tree creation and calculate time passed
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    // Write that Tree is created
    cout << "Building tree is finished in " << elapsed_secs << "s. Starting functions......" << "\n";

    // Start time counting for Rank/Select operations
    clock_t beginFunctions = clock();

    // RANK/SELECT CALLS
    cout << "Select(8 , T) : " << tree.select(tree.getRoot(),8,'t') << "\n";

    cout << "Select(2, C) : " << tree.select(tree.getRoot(),2,'c') << "\n";

    cout << "Select(5, A) : " << tree.select(tree.getRoot(),5,'a') << "\n";

    cout << "Select(6, T) : " << tree.select(tree.getRoot(),6,'t') << "\n";

    cout << "Select(7, G) : " << tree.select(tree.getRoot(),7,'G') << "\n";


    cout << "Rank(G, 15) : " << tree.rank(tree.getRoot(),15,'g') << "\n";

    cout << "Rank(G, 40) : " << tree.rank(tree.getRoot(),40,'g') << "\n";

    cout << "Rank(A, 94) : " << tree.rank(tree.getRoot(),94,'a') << "\n";

    cout << "Rank(G, 36) : " << tree.rank(tree.getRoot(),36,'g') << "\n";

    cout << "Rank(A, 45) : " << tree.rank(tree.getRoot(),45,'a') << "\n";

    // Algorithm finished successfully
    cout << "Job is done !\n";

    // Finish time counting for Rank/Select operations and calculate time passed
    clock_t endFunc = clock();
    double elapsed_secs_functions = double(endFunc - beginFunctions) / CLOCKS_PER_SEC;

    // Calculate memory used
    PROCESS_MEMORY_COUNTERS_EX pmc;
    GetProcessMemoryInfo(GetCurrentProcess(), reinterpret_cast<PPROCESS_MEMORY_COUNTERS>(&pmc), sizeof(pmc));
    SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;

    cout << "Memory used : " << virtualMemUsedByMe << "\n";

    cout << "Time elapsed for functions : " << elapsed_secs_functions << "s\n";

    return 0;
}