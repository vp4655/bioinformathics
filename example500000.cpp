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
    cout << "Select(16559 , A) : " << tree.select(tree.getRoot(),16559,'a') << "\n";

    cout << "Select(41719, t) : " << tree.select(tree.getRoot(),41719,'t') << "\n";

    cout << "Select(25361, A) : " << tree.select(tree.getRoot(),25361,'a') << "\n";

    cout << "Select(16316, A) : " << tree.select(tree.getRoot(),16316,'a') << "\n";

    cout << "Select(4875, T) : " << tree.select(tree.getRoot(),4875,'t') << "\n";


    cout << "Rank(A, 278492) : " << tree.rank(tree.getRoot(),278492,'a') << "\n";

    cout << "Rank(A, 286555) : " << tree.rank(tree.getRoot(),286555,'a') << "\n";

    cout << "Rank(T, 231402) : " << tree.rank(tree.getRoot(),231402,'t') << "\n";

    cout << "Rank(A, 131252) : " << tree.rank(tree.getRoot(),131252,'a') << "\n";

    cout << "Rank(T, 475306) : " << tree.rank(tree.getRoot(),475306,'g') << "\n";

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