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
    unsigned long res = tree.select(tree.getRoot(),8,'a');
    if(res == 0){
        cout << "Select(8, A) : " << "Ne postoji 8i A !" << "\n";
    }
    else {
        cout << "Select(8, A) : " << res << "\n";
    }

    res = tree.select(tree.getRoot(),800,'c');
    if(res == 0){
        cout << "Select(800, A) : " << "Ne postoji 800i A !" << "\n";
    }
    else {
        cout << "Select(800, A) : " << res << "\n";
    }

    res = tree.select(tree.getRoot(),12000,'g');
    if(res == 0){
        cout << "Select(12000, A) : " << "Ne postoji 12000i A !" << "\n";
    }
    else {
        cout << "Select(12000, A) : " << res << "\n";
    }

    res = tree.select(tree.getRoot(),150000,'t');
    if(res == 0){
        cout << "Select(150000, A) : " << "Ne postoji 150000i A !" << "\n";
    }
    else {
        cout << "Select(150000, A) : " << res << "\n";
    }

    res = tree.select(tree.getRoot(),1000000,'a');
    if(res == 0){
        cout << "Select(1000000, A) : " << "Ne postoji 1000000i A !" << "\n";
    }
    else {
        cout << "Select(1000000, A) : " << res << "\n";
    }

    cout << "Rank(36, a) : " << tree.rank(tree.getRoot(),36,'a') << "\n";

    cout << "Rank(9000, C) : " << tree.rank(tree.getRoot(),9000,'c') << "\n";

    cout << "Rank(500000, G) : " << tree.rank(tree.getRoot(),500000,'g') << "\n";

    cout << "Rank(1000000, T) : " << tree.rank(tree.getRoot(),1000000,'t') << "\n";

    cout << "Rank(20000000, A) : " << tree.rank(tree.getRoot(),20000000,'a') << "\n";

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