#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector> 
#include <string>
using namespace std;

#include "Matrix.hpp"
namespace zich{

// the constructor of the matrix
Matrix::Matrix(vector<double> &mat, const int m, const int n)
    
    : _mat(mat), _m(m), _n(n){

        if (m < 0 || n < 0) {

            throw invalid_argument("Incorrect matrix initialization: negative input");
        }

        if (m * n != mat.size()) {

            throw std::invalid_argument("Incorrect matrix initialization: incorrect dimensions");
        }
}
    
Matrix Matrix:: operator + (Matrix const &other) const{
    
    if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
        }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( this->_mat.at(i) + other._mat.at(i) );
    }

    Matrix new_mat{mat, m, n};
    return new_mat;
    
}

Matrix& Matrix:: operator += (Matrix const &other){

    if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
        }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;

    for ( unsigned long i = 0; i < size; i++){

        this->_mat.at(i) += other._mat.at(i);
    }

    return *this;
   
}

Matrix Matrix:: operator + (){
 
    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( this->_mat.at(i) );
    }

    Matrix new_mat{mat, m, n};
    
    return new_mat;
}
        
Matrix Matrix:: operator - (Matrix const &other) const{

    if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
        }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( this->_mat.at(i) - other._mat.at(i) );
        // cout << mat.back() << '\n'; // will print: "a b c"
    }

    Matrix new_mat{mat, m, n};
    return new_mat;

}

Matrix& Matrix:: operator -= (Matrix const &other){

    if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
        }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;

    for ( unsigned long i = 0; i < size; i++){

        this->_mat.at(i) -= other._mat.at(i);
    }

    return *this;
}
        
Matrix Matrix:: operator - (){

    int m = this->_m;
    int n = this->_n;
    int size = m * n;
    vector<double> mat;

    for ( unsigned long i = 0; i < size; i++){

        mat.push_back( - this->_mat.at(i) );
    }

    Matrix new_mat{mat, m, n};
    
    return new_mat; 

}

bool Matrix:: operator > (Matrix const &other) const{

    return true;
}  // big
    
bool Matrix:: operator >= (Matrix const &other) const{

    return true;
} // big-or-equal
        
bool Matrix:: operator < (Matrix const &other) const{

    return true;
}  // small
        
bool Matrix:: operator <= (Matrix const &other) const{

    return true;
} // small-or-equal
        
bool Matrix:: operator == (Matrix const &other) const{  // equal

    if (this ->_m != other._m || this ->_n != other._n) {

            throw invalid_argument("the matrices are not of the same size mXn.");
    }
    
    int m = this->_m;
    int n = this->_n;
    int size = m * n;

    for ( unsigned long i = 0; i < size; i++){

        if ( this->_mat.at(i) != other._mat.at(i) ){

            return false;
        }
    }

    return true;
} 

bool Matrix:: operator != (Matrix const &other) const{ // not-equal

    // if (this ->_m != other._m || this ->_n != other._n) {

    //         throw invalid_argument("the matrices are not of the same size mXn.");
    //     }

    // bool ans = *this != other ;
    
    // return ans;

    return true;

} 
// Increase by 1 (++) and decrease by 1 (--) before and after the number:

Matrix& Matrix:: operator ++ (){

    return *this;
} // +prefix

Matrix Matrix:: operator ++ (int){

    return *this;
} // postfix++

Matrix& Matrix:: operator -- (){

    return *this;
} // --prefix

Matrix Matrix:: operator -- (int){

    return *this;
} // postfix--

// Real scalar multiplication:

Matrix operator * (double scalar, const Matrix& mat){

    // vector<double> mat1(12,1);

    // Matrix new_mat{mat._mat, mat._m, mat._n};

    return mat;

}

Matrix& Matrix:: operator *= (double scalar){

    return *this;
} 

// Multiplying a matrix by a matrix:

Matrix Matrix:: operator * (Matrix const &mat) const{

    return *this;
}

Matrix& Matrix:: operator *= (const Matrix& other){

    return *this;
} 

ostream& operator<<(ostream& os, const Matrix& mat){

    os <<  " 1 ";
    os << endl;
    return os;

} //cout
//  ostream& operator<<(ostream& os, const Matrix& mat) {
//         for (int i = 0; i < mat.; i++) {
//             for (int j = 0; j < mat.cols; j++) {
//                 os <<  "[" << mat.vec[(double)(i*mat) + j] << "]";
//             }
//             os << endl;
//         }
//         return os;
//     }

// friend std::ostream& operator << (std::ostream& out, const Matrix& mat); //cout
// istream& operator >> (std::istream& in,  Matrix& mat){} //cin
}
