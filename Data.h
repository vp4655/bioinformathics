//
// Created by Stjepan on 4.1.2016..
//

#ifndef BIOINFORMATICS_DATA_H
#define BIOINFORMATICS_DATA_H
#include <iostream>
using namespace std;
class Data{
// id - id of Node
//r - number of blocks in left subtree
//p - number of simbols in left subtree
//NoX - number of number of occurrences of symbol X in this subtree
private:
    long id;
    long p;
    long NoA;
    long NoC;
    long NoG;
    long NoT;

//getters and setters for all variables
public:
    Data(long id1, long p1, long NoA1, long NoC1, long NoG1, long NoT1) : id(id1), p(p1), NoA(NoA1), NoC(NoC1), NoG(NoG1),
                                                                    NoT(NoT1) {}


public:
    long getId(){
        return this->id;
    }
    void setId(long ID){
        this->id =ID;
    }
    long getP(){
        return this->p;
    }
    void setP(long P){
        this->p =P;
    }
    long getNoA(){
        return this->NoA;
    }
    void setNoA(long NOA){
        this->NoA =NOA;
    }
    long getNoC(){
        return this->NoC;
    }
    void setNoC(long NOC){
        this->NoC =NOC;
    }
    long getNoG(){
        return this->NoG;
    }
    void setNoG(long NOG){
        this->NoG =NOG;
    }
    long getNoT(){
        return this->NoT;
    }
    void setNoT(long NOT){
        this->NoT =NOT;
    }

};

#endif //BIOINFORMATICS_DATA_H
