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
    cout << "Select(85 , G) : " << tree.select(tree.getRoot(),85,'g') << "\n";

    cout << "Select(101, T) : " << tree.select(tree.getRoot(),101,'t') << "\n";

    cout << "Select(160, G) : " << tree.select(tree.getRoot(),160,'g') << "\n";

    cout << "Select(84, T) : " << tree.select(tree.getRoot(),84,'t') << "\n";

    cout << "Select(123, A) : " << tree.select(tree.getRoot(),123,'a') << "\n";


    cout << "Rank(T, 704) : " << tree.rank(tree.getRoot(),704,'T') << "\n";

    cout << "Rank(A, 992) : " << tree.rank(tree.getRoot(),992,'a') << "\n";

    cout << "Rank(G, 644) : " << tree.rank(tree.getRoot(),644,'g') << "\n";

    cout << "Rank(C, 814) : " << tree.rank(tree.getRoot(),814,'c') << "\n";

    cout << "Rank(C, 1534) : " << tree.rank(tree.getRoot(),1534,'c') << "\n";

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