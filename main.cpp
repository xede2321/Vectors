#include"Matrix.h"
#include <cstdlib>
#include"Vector.h"
#include <time.h>
#include <clocale>
#include <malloc.h>
#include <vector>
#include<iostream>
#include <iomanip>
#include"Header.h"
using namespace std;
int main(){
  MyVector<int> A;
  cin >> A;
  cout << "your vector:";
  cout << A<<endl;
  int K = 0;
  int arr[] = { 7,5,1,4,2,6,9 };
  int arr1[] = { 2,7,8,5,6,3,4 };
  MyVector<int> B(7, arr);
  MyVector<int> C(7, arr1);
  MyVector<int> D;
  cout << "+ :  ";
  D = B + C;
  cout << D<<endl;
  cout << "* :  ";
  K = B * C;
  cout << K << endl;
  cout << "- :  ";
  D = B - C;
  cout << D << endl;
  cout << "/ :  ";
  D = C / B;
  cout << D << endl;
  cout << "--------------------" << endl;
  cout << "Matrix 1" << "\n";
  Matrix<int> AB;
  cin >> AB;
  cout << "square matrix 1:" << AB << endl;
  cout << "enter the same MatrixSize " << endl;
  Matrix<int> AC;
  cin >> AC;
  cout << "square matrix 2:" << AB << endl<<endl;
  Matrix<int> ABC;
  cout << "+ :  ";
  ABC = AB + AC;
  cout << ABC << endl << endl;
  cout << "* :  ";
  ABC = AB * AC;
  cout << ABC << endl << endl;
  cout << "- :  ";
  ABC = AB - AC;
  cout << ABC << endl << endl;
  return 0;
}