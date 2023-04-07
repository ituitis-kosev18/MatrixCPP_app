#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "macros.hpp"
#include "iostream"
#include "string"


class Matrix {
    public:
        Matrix() : ROW(0),COLUMN(0){}
        Matrix(int, int);
        void initMatrix();
        void printMatrixWhole();
        void printMatrixName(){std::cout<<this->name<<std::endl;}
        ~Matrix();
        void addNode();
        Matrix * getNext() {return this->matrixNext;}
        Matrix * getLast();
        void changeName();

    private: 
        double ** matrixHead;
        Matrix * matrixNext;
        std::string name;
        const int ROW;
        const int COLUMN;
};

class MatrixList {
    public:
        MatrixList();
        void addMatrixtoList(int, int);
        void listMatrixList();
        bool isEmpty(){return size==0 ? true : false;}
    private:
        Matrix * listHead;
        int * size;
};


#endif