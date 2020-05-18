#pragma once
#include<iostream>
using namespace std;
template<typename M>
class Matrix{
private:
  void MemorySize(int width, int length){
    array = new M * [m];
    for (int i = 0; i < width; i++) this->array[i] = new M[length];
 }
protected:
  int m;
  int n;
  M** array;
public:
  Matrix();
  Matrix(int a, int b);
  Matrix(int c, int d, M** arr);
  Matrix(const Matrix<M>& other);
  ~Matrix();
  M** GetMatrix();
  int GetM();
  int GetN();
  void SetSize(int width, int length);
  void SetMatrix(M** e);
  Matrix<M> operator=(const Matrix<M>& other);
  bool operator ==(const Matrix<M>& other);
  M*& operator [](const int i);
  Matrix<M> operator+(const Matrix<M>& other);
  Matrix<M> operator-(const Matrix<M>& other);
  Matrix<M> operator*(const Matrix<M>& other);
  template<typename M>
  friend ostream& operator<<(ostream& os, const Matrix<M>& mat);
  template<typename M>
  friend istream& operator>>(istream& in, Matrix<M>& mat);
  int search(M a);
};
template<typename M>
Matrix<M>::Matrix(){
  m = 1;
  n = 1;
  MemorySize(m, n);
  array[0][0] = 0;
}
template<typename M>
Matrix<M>::Matrix(int a,int b){
  m = a;
  n = b;
  MemorySize(m, n);
  for (int i = 0; i < m; i++)  {
    for (int j = 0; j < n; j++)    {
      array[i][j] = 0;
    }
  }
}
template<typename M>
Matrix<M>::Matrix(int c, int d, M** arr){
  m = c;
  n = d;
  MemorySize(c, d);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    array[i][j] = arr[i][j];
}
template<typename M>
Matrix<M>::Matrix(const Matrix<M>& other){
  m = other.n;
  n = other.m;
  MemorySize(m, n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      array[i][j] = other.array[i][j];
}
template<typename M>
Matrix<M>::~Matrix(){
  if (array != 0){
    for (int i = 0; i < m; i++){
      array[i] = 0;
      delete[] array[i];
    }
    array = 0;
    delete[] array;
    n = 0;
    m = 0;
  }
}
template<typename M>
int Matrix<M>::search(M a){
  int quantity = 0;
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      if (array[i][j] == a){
        quantity = quantity + 1;
      }
    }
  }
  return quantity;
}
template<typename M>
int Matrix<M>::GetM(){
  return m;
}
template<typename M>
int Matrix<M>::GetN(){
  return n;
}
template<typename M>
M** Matrix<M>::GetMatrix(){
  return array;
}
template<typename M>
void Matrix<M>::SetSize(int width, int length){
  m = width;
  n = length;
}
template<typename M>
void Matrix<M>::SetMatrix(M** e){
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      array[i][j] = e[i][j];
}
template<typename M>
Matrix<M> Matrix<M>::operator=(const Matrix<M>& other){
	if (*this == other)
		return *this;
	for (int i = 0; i < m; i++){
		array[i] = 0;
		delete[] array[i];
	}
	delete[] array;
	array = 0;
	m = other.m;
	n = other.n;
	MemorySize(m, n);
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			array[i][j] = other.array[i][j];
		}
	}
	return *this;
}
template<typename M>
M*& Matrix<M>::operator [](const int i){
  return array[i];
}
template<typename M>
bool Matrix<M>::operator==(const Matrix<M>& other){
  if (m == other.m && n == other.n){
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (array[i][j] != other.array[i][j])
          return false;
    return true;
  }
  else
    return false;
}
template<typename M>
Matrix<M> Matrix<M>::operator+(const Matrix<M>& other){
  if (n == other.n && m == other.m){
    Matrix<M> F(m,n,other.array);
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        F.array[i][j] = other.array[i][j] + array[i][j];
      }
    }
    return F;
  }
}
template<typename M>
Matrix<M> Matrix<M>::operator-(const Matrix<M>& other){
  if (n == other.n && m == other.m){
    Matrix<M> F(m, n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        F.array[i][j] = array[i][j]-other.array[i][j];
    return F;
  }
  else
    throw - 1;
}
template<typename M>
Matrix<M> Matrix<M>::operator*(const Matrix<M>& other){
  if (n == other.m){
    Matrix<M> mat(m,(other.n));
    for (int i = 0; i < mat.m; i++)
      for (int j = 0; j < mat.n; j++){
        mat.array[i][j] = 0;
        for (int k = 0; k < n; k++){
          mat.array[i][j] = mat.array[i][j] + (array[i][k] * other.array[k][j]);
        }
      }
    return mat;
  }
  else
    throw - 1;
}
template<typename M>
ostream& operator<<(ostream& os, const Matrix<M>& mat){
  cout << "\n";
  for (int i = 0; i < mat.m; i++){
    if (i > 0) os << endl;
    for (int j = 0; j < mat.n; j++)
      os << mat.array[i][j] << " ";
  }
  return os;
}
template<typename M>
istream& operator>>(istream& in, Matrix<M>& mat){
  if ((mat.GetM()!=0)||(mat.GetN()!=0)){
    for (int i = 0; i < mat.m; i++)
      delete[] mat.array[i];
    delete[] mat.array;
  }
  cout << "Enter size" << "\n";
  cout << "m = ";
  in >> mat.m;
  cout << "n = ";
  in >> mat.n;
  mat.MemorySize(mat.m,mat.n);
  for (int i = 0; i < mat.m; i++){
    cout << "Enter " << i + 1 << " line" << "\n";
    for (int j = 0; j < mat.n; j++)
      in >> mat.array[i][j];
  }
  return in;
}