#include <iostream>
#include "matrix.hpp"
#include "macros.hpp"

using namespace std;


void createMatrix(MatrixList & ListHead){
	//CLEAR();
	int row, column;
	cout<<"Please enter the new Matrixes dimensions."<<endl;
	cout<<"Row size: ";
	cin>>row;
	cout<<endl<<"Column size: ";
	cin>>column;
	ListHead.addMatrixtoList(row,column);
}

void listMatrixes(MatrixList & ListHead){
	if (!ListHead.isEmpty()){
		ListHead.listMatrixList();
	}
	else{
		cout<<"There is no Matrixes yet!"<<endl;
	}
}
void printMenu(){
	cout<<"Please enter your operation\n\r";
	cout<<"1-> Create a Matrix\n\r";
	cout<<"2-> List Matrixes\n\r";
	cout<<"3-> Print a Matrix\n\r";
	cout<<"-1-> Exit the app.\n\r";
}

int main(int argc, char *argv[]){
	bool loop=true;
	MatrixList * matrixList = new MatrixList();
	while(loop){
		int choice;
		printMenu();
		cin>>choice;
		switch(choice){
			case 1:
				createMatrix(*matrixList);
				break;
			case 2:
				listMatrixes(*matrixList);
				break;
			case 3:
				cout<<"This is case 3\n\r";
				break;
			case -1:
				loop=false;
				break;
			default:
				cout<<"Please enter a valid value!\n\r";
		}
		CLEAR();
	}
	return 0;
}