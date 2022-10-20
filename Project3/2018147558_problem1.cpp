#include <iostream>

using namespace std;

int max_m(int** mat, int n){
	int ret;
	/*
	Information of variables:
		mat: the target matrix. you can regard it as mat[n][n] in your function.
		ret: you have to store value of your answer.
	*/

	// ****** insert your code ****** //
	ret = mat[0][0]; //Set ret to mat[0][0]
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ret < mat[i][j]){
				ret = mat[i][j]; //Compares the value of ret with the value of mat and sets the larger value to ret.
			}
		}
	}
	// ****************************** //

	return ret;
}

int min_m(int** mat, int n){
	int ret;
	/*
	Information of variables:
		mat: the target matrix. you can regard it as mat[n][n] in your function.
		ret: you have to store value of your answer.
	*/

	// ****** insert your code ****** //
	ret = mat[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(ret > mat[i][j]){
				ret = mat[i][j]; //Compares the value of ret with the value of mat and sets the smaller value to ret.
			}
		}
	}
	// ****************************** //

	return ret;
}

int sum_m(int** mat, int n){
	int ret;
	/*
	Information of variables:
		mat: the target matrix. you can regard it as mat[n][n] in your function.
		ret: you have to store value of your answer.
	*/

	// ****** insert your code ****** //
	ret =0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ret += mat[i][j]; //Add the value of all mat to the ret value.
		}
	}
	// ****************************** //

	return ret;
}

int** transpose_m(int** mat, int n){
	int** ret;
	ret = new int*[n];
	for(int i=0; i<n; i++)
		ret[i] = new int[n];

	/*
	Information of variables:
		mat: the target matrix. you can regard it as mat[n][n] in your function.
		ret: the matrix you have to store value of your answer. you can regard it as ret[n][n] in your function
	*/

	// ****** insert your code ****** //
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ret[j][i] = mat[i][j]; //The index of the ret value is reversed at the index of the met value.
		}
	}
	// ****************************** //

	return ret;
}

int** mul_m(int** mat1, int** mat2, int n){
	int** ret;
	ret = new int*[n];
	for(int i=0; i<n; i++)
		ret[i] = new int[n];

	/*
	Information of variables:
		mat1: the first matrix. you can regard it as mat1[n][n] in your function.
		mat2: the second matrix. you can regard it as mat2[n][n] in your function.
		ret: the matrix you have to store value of your answer. you can regard it as ret[n][n] in your function
	*/

	// ****** insert your code ****** //
	int k=0,t=0,y=0,x=0; //Set index of ret and mat1, mat2. 
	for(int r = 0;r<n;r++){ 
		y=0;
		t=0;
		for(int i = 0;i<n;i++){
			for(int j =0;j<n;j++){
				ret[k][t] += mat1[x][j]*mat2[j][y]; //Calculate the matrix multiplication.
			}
			y++;
			t++;
		}
		k++;
		x++;
	}
	// ****************************** //

	return ret;
}


//*********************************************************//
//************ DON'T TOUCH ANYTHING BELOW HERE ************//
//*********************************************************//

void print_matrix(int** mat, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}


int main(){
	int n;
	int** mat1;
	int** mat2;
	int** sol;

	// take inputs
	cout << "*inputs are two NxN matrices*" << endl;
	cout << "n: ";
	cin >> n;

	// allocate memory to pointers
	mat1 = new int*[n];
	mat2 = new int*[n];

	for(int i=0; i<n; i++){
		mat1[i] = new int[n];
		mat2[i] = new int[n];
	}

	// take matrice
	cout << "matrix 1: " << endl;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> mat1[i][j];

	cout << "matrix 2: " <<endl;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> mat2[i][j];

	// max value of a matrix
	cout <<"max of matrix 1: "<< max_m(mat1, n) << endl;
	cout <<"max of matrix 2: "<< max_m(mat2, n) << endl;
	// min value of a matrix
	cout <<"min of matrix 1: "<< min_m(mat1, n) << endl;
	cout <<"min of matrix 2: "<< min_m(mat2, n) << endl;
	// sum of a matrix
	cout <<"sum of matrix 1: "<< sum_m(mat1, n) << endl;
	cout <<"sum of matrix 2: "<< sum_m(mat2, n) << endl;
	// matrix transposition
	cout <<"transposed matrix 1: " << endl;
	print_matrix(transpose_m(mat1, n), n);
	cout <<"transposed matrix 2: " << endl;
	print_matrix(transpose_m(mat2, n), n);
	// matrix multiplication
	cout <<"multiplication of matrices: " << endl;
	sol = mul_m(mat1, mat2, n);
	print_matrix(sol, n);

	return 0;
}
