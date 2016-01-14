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
    cout << "Select(36463 , G) : " << tree.select(tree.getRoot(),36463,'g') << "\n";

    cout << "Select(36695, c) : " << tree.select(tree.getRoot(),36695,'c') << "\n";

    cout << "Select(24089, G) : " << tree.select(tree.getRoot(),24089,'g') << "\n";

    cout << "Select(8435, G) : " << tree.select(tree.getRoot(),8435,'g') << "\n";

    cout << "Select(40930, A) : " << tree.select(tree.getRoot(),40930,'a') << "\n";


    cout << "Rank(C, 439095) : " << tree.rank(tree.getRoot(),439095,'c') << "\n";

    cout << "Rank(A, 368040) : " << tree.rank(tree.getRoot(),368040,'a') << "\n";

    cout << "Rank(A, 345937) : " << tree.rank(tree.getRoot(),345937,'a') << "\n";

    cout << "Rank(G, 29076) : " << tree.rank(tree.getRoot(),29076,'g') << "\n";

    cout << "Rank(A, 42352) : " << tree.rank(tree.getRoot(),42352,'a') << "\n";

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