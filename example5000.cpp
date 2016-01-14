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
    cout << "Select(372 , A) : " << tree.select(tree.getRoot(),372,'a') << "\n";

    cout << "Select(63, C) : " << tree.select(tree.getRoot(),63,'c') << "\n";

    cout << "Select(439, A) : " << tree.select(tree.getRoot(),439,'a') << "\n";

    cout << "Select(78, C) : " << tree.select(tree.getRoot(),78,'c') << "\n";

    cout << "Select(409, A) : " << tree.select(tree.getRoot(),409,'a') << "\n";


    cout << "Rank(G, 1232) : " << tree.rank(tree.getRoot(),1232,'g') << "\n";

    cout << "Rank(T, 3599) : " << tree.rank(tree.getRoot(),3599,'t') << "\n";

    cout << "Rank(T, 1060) : " << tree.rank(tree.getRoot(),1060,'t') << "\n";

    cout << "Rank(A, 1006) : " << tree.rank(tree.getRoot(),1006,'t') << "\n";

    cout << "Rank(A, 3086) : " << tree.rank(tree.getRoot(),3086,'a') << "\n";

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