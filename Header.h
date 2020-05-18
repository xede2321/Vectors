#pragma once
#include "Vector.h"
#include "Matrix.h"
template <typename T>
MyVector<T> operator *(Matrix<T>& matrix, MyVector<T>& vector){
  if (matrix.GetM() == vector.Getsize()){
    T* arr = new T[matrix.GetM()];
    T** arr_matrix = matrix.GetMatrix();
    T* arr_vector = vector.GetVector();
    for (int i = 0; i < matrix.GetM(); i++){
      arr[i]=0;
      for (int j = 0; j < matrix.GetN(); j++){
        arr[i]=arr[i] + (arr_matrix[i][j] * arr_vector[j]);
      }
    }
    MyVector<T> result(matrix.GetN(), arr);
    delete[] arr;
    return result;
  }
};
template <typename T>
Matrix<T> operator *(MyVector<T>& vector, Matrix<T>& matrix){
  if (matrix.GetN() == vector.Getsize() && matrix.GetM() == 1){
    T** arr = new T * [matrix.GetN()];
    for (int i = 0; i < vector.Getsize(); i++)
      arr[i] = new T[vector.Getsize()];
    for (int i = 0; i < vector.Getsize(); i++)
      for (int j = 0; j < matrix.GetN(); j++){
          arr[i][j]= (matrix[0][j] * vector[i]);
      }
    Matrix<T> result(matrix.GetN(), vector.Getsize(), arr);
    for (int i = 0; i < vector.Getsize(); i++)
      delete[] arr[i];
    delete[] arr;
    return result;
  }
};