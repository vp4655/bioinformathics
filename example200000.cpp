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
    cout << "Select(15791 , A) : " << tree.select(tree.getRoot(),15791,'a') << "\n";

    cout << "Select(9218, t) : " << tree.select(tree.getRoot(),9218,'t') << "\n";

    cout << "Select(14375, C) : " << tree.select(tree.getRoot(),14375,'c') << "\n";

    cout << "Select(4755, A) : " << tree.select(tree.getRoot(),4755,'a') << "\n";

    cout << "Select(18485, T) : " << tree.select(tree.getRoot(),18485,'t') << "\n";


    cout << "Rank(A, 115995) : " << tree.rank(tree.getRoot(),115995,'a') << "\n";

    cout << "Rank(T, 144707) : " << tree.rank(tree.getRoot(),144707,'t') << "\n";

    cout << "Rank(C, 2805) : " << tree.rank(tree.getRoot(),2805,'c') << "\n";

    cout << "Rank(A, 174535) : " << tree.rank(tree.getRoot(),174535,'a') << "\n";

    cout << "Rank(G, 4875) : " << tree.rank(tree.getRoot(),4875,'g') << "\n";

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