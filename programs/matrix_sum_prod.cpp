#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <conio.h>
using namespace std;

void fillMatrix(int **&, int[]);
void printMatrix(int **, int[] );
void sumMatrix(int **&, int **,int **,int[],int[]);
void prodMatrix(int **&, int **,int **,int[],int[],int[]);

int nRow, nCol;


int main(){
	int **matrix1, **matrix2, size1[2], size2[2];
	fillMatrix(matrix1,size1);
	printMatrix(matrix1, size1);
	cout<<"\n\n";
	fillMatrix(matrix2,size2);
	printMatrix(matrix2, size2);
	
	cout<<"\n\n";
	int **sum1;
	sumMatrix(sum1,matrix1,matrix2,size1,size2);
	printMatrix(sum1, size2);
	
	int **prod, sizeprod[2];
	
	prodMatrix(prod,matrix1,matrix2,size1,size2,sizeprod);
	printMatrix(prod,sizeprod);
	getch();
	return 0;
}

//This matrix assign dynamic memory to a matrix given it size ant fill its ellements 
void fillMatrix(int **&ptr_matrix,int size[]){
	cout<<"Enter the number of rows: ";
	cin>>size[0];
	cout<<"Enter the number of columns: ";
	cin>>size[1];
	
	ptr_matrix = new int*[size[0]];
	for (int i=0;i<size[0];i++){
		ptr_matrix[i] = new int[size[1]];
		
	}
	
	cout<<"Enter the elements of the matrix: ";
	for (int i=0;i<size[0];i++){
		for (int j=0; j<size[1];j++){
			cin>>*(*(ptr_matrix+i)+j);
		}
		
	}
}

//This function print a matrix given its size
void printMatrix(int **ptr_matrix, int size[]){
	for (int i=0; i<size[0];i++){
		for(int j=0;j<size[1];j++){
			cout<<"["<<*(*(ptr_matrix+i)+j)<<"]"<< "  ";
		}
		cout<<"\n";
	}
}

//This function will sum two matrices and save the result in another matrix "sum"
void sumMatrix(int **&sum,int **ptr_matrixA,int **ptr_matrixB , int sizeA[], int sizeB[]){
	if (sizeA[0]==sizeB[0] && sizeA[1]==sizeB[1]){
		
		sum = new int*[sizeA[0]]; //Saving memory for rows
		for (int i=0;i<sizeA[0];i++){
			sum[i] = new int[sizeA[1]];	//Saving memory for columns
		}
		cout<<"The sum of matrices is: \n";
		for (int i=0;i<sizeA[0];i++){
			for (int j=0;j<sizeA[1];j++){
				*(*(sum+i)+j) = *(*(ptr_matrixA+i)+j) + *(*(ptr_matrixB+i)+j);
			}
		}
	}
	else cout<<"Matrices can not be added\n";
}

void prodMatrix(int **&prod,int **ptr_matrixA,int **ptr_matrixB , int sizeA[], int sizeB[],int newsize[]){
	if (sizeA[1] == sizeB[0]){
		
		prod = new int*[sizeA[0]]; //Saving memory for rows
		for (int i=0;i<sizeA[0];i++){ 
			prod[i] = new int[sizeB[1]]; //Saving memory for columns
		}
		
		newsize[0] = sizeA[0]; 
		newsize[1] = sizeB[1];
		
		cout<<"The product of matrices is:\n";
		
		//Filling the elements of the matrix with 0
		for (int i=0;i<newsize[0];i++){
			for (int j=0; j<newsize[1];j++){
				*(*(prod+i)+j) = 0;
			}	
		}
		
		for (int i=0;i<sizeA[0];i++){
			for (int j=0;j<sizeB[1];j++){
				for (int k=0;k<sizeB[0];k++){
					*(*(prod+i)+j) += (*(*(ptr_matrixA+i)+k))*(*(*(ptr_matrixB+k)+j));
				}
			}
		}
		
	}
	else cout<<"Matrices can not be multiplied\n";
}



