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