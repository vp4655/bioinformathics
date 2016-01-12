//
// Created by Valentino on 12.1.2016..
//

#ifndef BIOINFORMATICS_TEST100CHARACTERS_H
#define BIOINFORMATICS_TEST100CHARACTERS_H

#include <iostream>
#include <vector>
#include <string>
#include "RedBlackTree.h"
#include <iostream>
#include <fstream>
#include "wTree.h"
#include <algorithm>
#include <ctype.h>
//#include <w32api/wbemdisp.h>
#include "Data.h"
#include "CreateTree.h"

int main(){

    RedBlackTree tree= createTree('#',8);
    tree.disp();
    cout<<tree.select(tree.getRoot(),8,'a');

}

#endif //BIOINFORMATICS_TEST100CHARACTERS_H
