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
    cout << "Select(7462 , G) : " << tree.select(tree.getRoot(),7462,'g') << "\n";

    cout << "Select(1500, T) : " << tree.select(tree.getRoot(),1500,'t') << "\n";

    cout << "Select(7243, A) : " << tree.select(tree.getRoot(),7243,'a') << "\n";

    cout << "Select(5324, T) : " << tree.select(tree.getRoot(),5324,'t') << "\n";

    cout << "Select(867, T) : " << tree.select(tree.getRoot(),867,'t') << "\n";


    cout << "Rank(T, 39511) : " << tree.rank(tree.getRoot(),39511,'t') << "\n";

    cout << "Rank(C, 96133) : " << tree.rank(tree.getRoot(),96133,'c') << "\n";

    cout << "Rank(C, 41994) : " << tree.rank(tree.getRoot(),41994,'c') << "\n";

    cout << "Rank(T, 98295) : " << tree.rank(tree.getRoot(),98295,'t') << "\n";

    cout << "Rank(C, 43677) : " << tree.rank(tree.getRoot(),43677,'c') << "\n";

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