//
// Created by Stjepan on 4.1.2016..
//

#ifndef BIOINFORMATICS_DATA_H
#define BIOINFORMATICS_DATA_H
#include <iostream>
class Data{
// id - id of Node
//r - number of blocks in left subtree
//p - number of simbols in left subtree
//NoX - number of number of occurrences of symbol X in this subtree
private:
    long id;
    long r;
    long p;
    long NoA;
    long NoC;
    long NoG;
    long NoT;

//getters and setters for all variables
public:
    long getId(){
        return this->id;
    }
    void setId(long ID){
        this->id =ID;
    }
    long getR(){
        return this->r;
    }
    void setR(long R){
        this->r =R;
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
    Data(long ID) {
        this->id = ID;
        this->NoC = 0;
        this->NoA = 0;
        this->NoG = 0;
        this->NoT = 0;
        this->r = 0;
        this->p = 0;
    }
};

#endif //BIOINFORMATICS_DATA_H
