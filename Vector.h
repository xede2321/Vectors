#pragma once
#include <iostream>
#include <clocale>
#include <iomanip>
#include"Matrix.h"
using namespace std;
template <typename Vector>
class MyVector{
protected:
  int size;
  Vector* array;
public:
  MyVector();
  MyVector(int r, Vector* A);
  MyVector(MyVector& B);
  ~MyVector();
  Vector* GetVector();
  int Getsize();
  void SetVector(Vector* C);
  void Setsize(int e);
  MyVector<Vector> operator=(const MyVector<Vector>& other);
  bool operator ==(const MyVector<Vector>& other);
  Vector operator [](const int i);
  MyVector<Vector> operator + (const MyVector& other);
  MyVector<Vector> operator-(const MyVector<Vector>& other);
  Vector operator*(const MyVector<Vector>& other);
  MyVector<Vector> operator /(MyVector<Vector>& other);
  template <typename Vector>
  friend ostream& operator<<(ostream& os, const MyVector<Vector>& vec);
  template <typename Vector>
  friend istream& operator>>(istream& in, MyVector<Vector>& vec);
  clock_t BubbleSort();
  clock_t InsertionSort();
  clock_t QuickSort(int first, int last);
  int search(Vector a);
};
template<typename Vector>
MyVector<Vector>::MyVector(int r,Vector*A){
  array = NULL;
  try{
    if (r > 0){
      size = r;
      array = new Vector[size];
      for (int i = 0; i < size; i++){
        array[i] = A[i];
      }
    }
   else throw 1;
  }
  catch (int i){
    cout << "oshibka vvoda dannux, array=0" << "\n";
    exit(0);
  }
}
template<typename Vector>
MyVector<Vector>::MyVector(MyVector& B){
  array = nullptr;
  size = B.Getsize();
  array = new Vector[size];
  for (int i = 0; i < size; i++){
  array[i] = B.array[i];
  }
}
template<typename Vector>
Vector* MyVector<Vector>::GetVector(){
  return array;
}
template<typename Vector>
int MyVector<Vector>::Getsize(){
  return size;
}
template<typename Vector>
void MyVector<Vector>::SetVector(Vector* C){
  int i = strlen(C);
  if (array != 0){
    array = 0;
    delete[] array;
  }
  size = i;
  array = new Vector[size];
  for (int k = 0; k < i; k++){
    array[k] = C[k];
  }
}
template<typename Vector>
MyVector<Vector>::MyVector(){
  size = 1;
  array = new Vector[1];
  Vector a = 0;
  array[0] = a;
}
template<typename Vector>
MyVector<Vector>::~MyVector(){
  if (array != 0){
    array = 0;
    delete[] array;
  }
  size = 0;
}
template<typename Vector>
MyVector<Vector> MyVector<Vector>::operator=(const MyVector<Vector>& other){
  if (*this == other)
    return *this;
  delete[] array;
  this->size = other.size;
  array = new Vector[size];
  for (int i = 0; i < size; i++)
    array[i] = other.array[i];
  return *this;
}
template<typename Vector>
bool MyVector<Vector>::operator==(const MyVector<Vector>& other){
  int k = 0;
  if (size == other.size){
    for (int i = 0; i < size; i++){
      if (array[i] == other.array[i]){
        k = k + 1;
      }
    }
    if (k == size){
      return true;
    }
    else return false;
  }
  else
    return false;
}
template<typename Vector>
Vector MyVector<Vector>::operator[](const int i){
  return array[i];
}
template<typename Vector>
MyVector<Vector> MyVector<Vector>::operator + (const MyVector& other){
  if (size == other.size){
    MyVector<Vector> vector(size, other.array);
    for (int i = 0; i < size; i++)
      vector.array[i] = array[i]+other.array[i];
    return vector;
  }
}
template<typename Vector>
void MyVector<Vector>::Setsize(int e){
  size = e;
}
template<typename Vector>
MyVector<Vector> MyVector<Vector>::operator-(const MyVector<Vector>& other){
  if (size == other.size){
    MyVector<Vector> vector(size, other.array);
    for (int i = 0; i < size; i++)
      vector.array[i] = array[i]-other.array[i];
    return vector;
  }
  else
    throw - 1;
}
template<typename Vector>
Vector MyVector<Vector>::operator *(const MyVector<Vector>& other){
  Vector res = 0;
  if (size == other.size){
    for (int i = 0; i < size; i++)
      res = res + (array[i] * other.array[i]);
    return res;
  }
}
template<typename Vector>
MyVector<Vector> MyVector<Vector>::operator /(MyVector<Vector>& other){
  MyVector<Vector> K;
  K = *this;
  for (int i = 0; i < size; i++){
    if (K.array[i] != 0){
      K.array[i] = K.array[i] / other.array[i];
    }
  }
  return K;
}
template<typename Vector>
ostream& operator<<(ostream& os, const MyVector<Vector>& vec){
  os << "(";
  for (int i = 0; i < vec.size; i++){
    os << vec.array[i];
    if (i < vec.size - 1)
      os << " ";
  }
  os << ")^T";
  return os;
}
template<typename Vector>
istream& operator>>(istream& in, MyVector<Vector>& vec){
  cout << "Enter size: ";
  in >> vec.size;
  Vector* mas;
  mas=new Vector[vec.size];
  for (int i = 0; i < vec.size; i++){
    cout << "[" << i << "]" << "\n";
    in >> mas[i];
  }
  MyVector<Vector> V(vec.size,mas);
  vec = V;
  mas = 0;
  delete[] mas;
  return in;
}
template<typename Vector>
clock_t MyVector<Vector>::BubbleSort(){
  clock_t start, finish;
  start = clock();
  Vector tmp = 0;
  int i, j = 0;
  start = clock();
  for (int i = 0; i < size; i++){
    for (int j = 0; j < i; j++){
      if (array[j] > array[j + 1]){
        tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }
  finish = clock();
  return (finish - start);
}
template<typename Vector>
clock_t MyVector<Vector>::InsertionSort(){
  int k = 0;
  clock_t start, finish;
  start = clock();
  Vector tmp;
  for (int i = 1; i < size; i++)
  {
    tmp = array[i];
    k = i - 1;
    while (k >= 0 && array[k] > tmp)
    {
      array[k + 1] = array[k];
      k = k - 1;
    }
    array[k + 1] = tmp;
  }
  finish = clock();
  return (finish - start);
}
template<typename Vector>
clock_t MyVector<Vector>::QuickSort(int first, int last){
  clock_t t1, t2, t3;
  t1 = clock();
  int i = first, j = last;
  Vector tmp;
  Vector x = array[(first + last) / 2];
  do{
    while (array[i] < x)
      i++;
    while (array[j] > x)
      j--;
    if (i <= j){
      if (i < j){
        tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
      i++;
      j--;
    }
  } while (i <= j);
  if (i < last)
    t3 = QuickSort(i, last);
  if (first < j)
    t3 = QuickSort(first, j);
  t2 = clock();
  return t2 - t1;
}
template<typename Vector>
int MyVector<Vector>::search(Vector a){
	int quantity = 0;
	for (int i = 0; i < size; i++){
		if (array[i] == a){
			quantity = quantity + 1;
		}
	}
	return quantity;
}