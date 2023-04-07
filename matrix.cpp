#include "matrix.hpp"
#include <iostream>

using namespace std;

MatrixList::MatrixList(){
    this->listHead=nullptr;
    this->size=new int;
    this->size=0;
}

void MatrixList::addMatrixtoList(int recievedRow, int recievedColumn){
    Matrix * listIterator= this->listHead->getLast();
    listIterator = new Matrix(recievedRow,recievedColumn);
}

void MatrixList::listMatrixList(){
    //CLEAR();
    Matrix * listIterator=this->listHead;
    int i = 0;
    while(listIterator){
        cout << i<<". ";
        listIterator->printMatrixName();
        listIterator=listIterator->getNext();
    }
}


Matrix::Matrix(int recievedRow, int recievedCol) : ROW(recievedRow), COLUMN(recievedCol){
    this->matrixHead = new double * [ROW];
    for (int i=0;i<ROW;i++){
        this->matrixHead[i]=new double[COLUMN];
    }
    for (int i=0;i<ROW;i++){
        for (int j=0;j<COLUMN;j++){
            this->matrixHead[i][j]=0;
        }    
    }
    this->initMatrix();
}

Matrix * Matrix::getLast(){
    if(this){
        return this->getNext()->getLast();
    }
    else {
        return this;
    }
}

void Matrix::changeName(){
    cout<<"Please rename your Matrix below:";
}

void Matrix::initMatrix(){
    cout<<"Please give your Matrix a name: ";
    cin>>this->name;
    for(int i=0;i<(this->ROW);i++){
        for (int j=0;j<COLUMN;j++){
            //CLEAR();
            cout<<"Please enter the Matrix "<<this->name<<" values to fill:"<<endl;
            this->printMatrixWhole();
            cin>>this->matrixHead[i][j];
        }
    }
}

void Matrix::printMatrixWhole(){
    cout<<"Matrix "<<this->name<<endl;
    for (int i=0;i<ROW;i++){
        for (int j=0;j<COLUMN;j++){
            cout<<this->matrixHead[i][j];
        }    
        cout<<endl;
    }
}

Matrix::~Matrix(){
    if(this){
        delete this->matrixNext;
        for(int i=0;i<this->ROW;i++){
            delete[] this->matrixHead[i];
        }
        delete[] matrixHead;
    }
}