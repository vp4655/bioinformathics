/* Stjepan Livacic
 *
 * Class created to store data in red-black tree node.
 *   id - id of Node
 *   r - number of blocks in left subtree
 *   p - number of simbols in left subtree
 *   NoX - number of number of occurrences of symbol X in this subtree
 */

#ifndef BIOINFORMATICS_DATA_H
#define BIOINFORMATICS_DATA_H
#include <iostream>
using namespace std;
class Data{
private:
    unsigned long id;
    unsigned long p;
    unsigned long NoA;
    unsigned long NoC;
    unsigned long NoG;
    unsigned long NoT;

//constructor
public:
    Data(unsigned long id1, unsigned long p1, unsigned long NoA1, unsigned long NoC1, unsigned long NoG1, unsigned long NoT1) : id(id1), p(p1), NoA(NoA1), NoC(NoC1), NoG(NoG1),
                                                                    NoT(NoT1) {}

//getters and setters for all variables
public:
    unsigned long getId(){
        return this->id;
    }
    void setId( unsigned long ID){
        this->id =ID;
    }
    unsigned long getP(){
        return this->p;
    }
    void setP(unsigned long P){
        this->p =P;
    }
    unsigned long getNoA(){
        return this->NoA;
    }
    void setNoA(unsigned long NOA){
        this->NoA =NOA;
    }
    unsigned long getNoC(){
        return this->NoC;
    }
    void setNoC( unsigned long NOC){
        this->NoC =NOC;
    }
    unsigned long getNoG(){
        return this->NoG;
    }
    void setNoG(unsigned long NOG){
        this->NoG =NOG;
    }
    unsigned long getNoT(){
        return this->NoT;
    }
    void setNoT(unsigned long NOT){
        this->NoT =NOT;
    }

};

#endif //BIOINFORMATICS_DATA_H
