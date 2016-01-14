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
    cout << "Select(534 , T) : " << tree.select(tree.getRoot(),534,'t') << "\n";

    cout << "Select(3527, T) : " << tree.select(tree.getRoot(),3527,'t') << "\n";

    cout << "Select(140, C) : " << tree.select(tree.getRoot(),140,'c') << "\n";

    cout << "Select(2288, C) : " << tree.select(tree.getRoot(),2288,'c') << "\n";

    cout << "Select(3949, T) : " << tree.select(tree.getRoot(),3949,'t') << "\n";


    cout << "Rank(T, 32024) : " << tree.rank(tree.getRoot(),32024,'t') << "\n";

    cout << "Rank(A, 10667) : " << tree.rank(tree.getRoot(),10667,'a') << "\n";

    cout << "Rank(T, 45756) : " << tree.rank(tree.getRoot(),45756,'t') << "\n";

    cout << "Rank(T, 33834) : " << tree.rank(tree.getRoot(),33834,'t') << "\n";

    cout << "Rank(T, 43286) : " << tree.rank(tree.getRoot(),43286,'t') << "\n";

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