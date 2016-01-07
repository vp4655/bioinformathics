//
// Created by Valentino on 7.1.2016..
//

#ifndef BIOINFORMATICS_WAVELETNODE_H
#define BIOINFORMATICS_WAVELETNODE_H


#include "Node.h"

class WaveletNode: Node {

public:
    bool isLeaf(){
        return true;
    }

};


#endif //BIOINFORMATICS_WAVELETNODE_H
