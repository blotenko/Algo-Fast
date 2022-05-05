
//
//  alogorithms.hpp
//  GoF pattern
//
//  Created by Blotenko on 04.04.2022.
//

#ifndef alogorithms_hpp
#define alogorithms_hpp
/*!
@file alogorithms.hpp
 
 @brief This is the header file where my  algorithms is contained.
 
 This file contains method for work with algorithms decalaration.

 */
#include <stdio.h>

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

void bubbleSort(int data[], int lenD);
void insertionSort(int data[], int lenD);
void mergeSort(int data[], int lenD);
void merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR);
void quickSort(int* data, int const len);

int Partition(char arr[], int start, int end);
void Quicksort(char arr[], int start, int end );



#pragma mark - using Strategy pattern


/*!
 @class algoSort
 
 @brief The algoSort class
 
 @discussion    This abstract class was designed and implemented for algorithms children classes.
 
 @superclass SuperClass: no\n
 @classdesign    No special design is applied here.
 @helps It helps algo classes.
 @helper    No helper exists for this class.
 */
class algoSort
{
public:
    virtual ~algoSort(){}
    virtual void algo(int data[],int lenD) = 0;
};
/*!
 @class bubbleSort
 
 @brief The bubbleSort class
 
 @discussion    This  class was designed and implemented for bubbleSort algorithm.
 
 @superclass SuperClass: no\n
 @classdesign    No special design is applied here.
 @helps No.
 @helper    No helper exists for this class.
 */
class bubbleSort : public algoSort
{
public:
    void algo(int data[],int lenD)
    {
        int tmp = 0;
        for(int i = 0;i<lenD;i++){
          for(int j = (lenD-1);j>=(i+1);j--){
            if(data[j]<data[j-1]){
              tmp = data[j];
              data[j]=data[j-1];
              data[j-1]=tmp;
            }
          }
        }
    }
};
#pragma mark- using Abstract Factory pattern
/*!
 @class AbstractFactory
 
 @brief The AbstractFactory class
 
 @discussion    This  class was designed and implemented for AbstractFactory pattern and using algorithm.
 
 @superclass SuperClass: no\n
 @classdesign    No special design is applied here.
 @helps Helps ConcreteFactory1 .
 @helper    No helper exists for this class.
 */
class AbstractFactory {
 public:
  virtual algoSort *algo() const = 0;
};

class ConcreteFactory1 : public AbstractFactory {
 public:
    algoSort *algo(int data[],int lenD) {
        return (new class bubbleSort());
  }
};

#pragma mark - using Adapter pattern
/*!
 @class Sort
 
 @brief The Sort class
 
 @discussion    This  class was designed and implemented for Sort algorithm.
 
 @superclass SuperClass: no\n
 @classdesign    No special design is applied here.
 @helps Helps no .
 @helper    No helper exists for this class.
 */
class Sort : public algoSort
{
public:
    void algo(int data[],int lenD)
    {
    }
};

/*!
 @class Adapter
 
 @brief The Adapter class
 
 @discussion    This  class was designed and implemented for Adapter pattern while using Sort algorithm.
 
 @superclass SuperClass: no\n
 @classdesign    No special design is applied here.
 @helps Helps no .
 @helper    No helper exists for this class.
 */
class Adapter : public bubbleSort {
 private:
    Sort *sorT;

 public:
  void  algo(int data[],int lenD)  {
      std::vector<int> vec;
      for(int i=0;i<lenD;i++)
      {
          vec.push_back(data[i]);
      }
      sort(vec.begin(),vec.end());
  }
};
#pragma mark -

/*!
 @class insertionSort
 
 @brief The insertionSort class
 
 @discussion    This  class was designed and implemented for insertionSort algorithm.
 
 @superclass SuperClass: no\n
 @classdesign    No special design is applied here.
 @helps Helps no .
 @helper    No helper exists for this class.
 */
class insertionSort :public algoSort
{
public:
    void algo(int data[],int lenD)
    {
        int key = 0;
        int i = 0;
        for(int j = 1;j<lenD;j++){
          key = data[j];
          i = j-1;
          while(i>=0 && data[i]>key){
            data[i+1] = data[i];
            i = i-1;
            data[i+1]=key;
          }
        }
    }
};
/*!
 @class mergeSort
 
 @brief The mergeSort class
 
 @discussion    This  class was designed and implemented for mergeSort algorithm.
 
 @superclass SuperClass: no\n
 @classdesign    No special design is applied here.
 @helps Helps no .
 @helper    No helper exists for this class.
 */
class mergeSort :public algoSort
{
public:
    void algo(int data[],int lenD)
    {
        if(lenD>1){
          int middle = lenD/2;
          int rem = lenD-middle;
          int* L = new int[middle];
          int* R = new int[rem];
          for(int i=0;i<lenD;i++){
            if(i<middle){
              L[i] = data[i];
            }
            else{
              R[i-middle] = data[i];
            }
          }
            algo(L,middle);
            algo(R,rem);
          merge(data, lenD, L, middle, R, rem);
        }
    }
    void merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR)
    {
        int i = 0;
        int j = 0;
        while(i<lenL||j<lenR){
          if (i<lenL & j<lenR){
            if(L[i]<=R[j]){
              merged[i+j] = L[i];
              i++;
            }
            else{
              merged[i+j] = R[j];
              j++;
            }
          }
          else if(i<lenL){
            merged[i+j] = L[i];
            i++;
          }
          else if(j<lenR){
            merged[i+j] = R[j];
            j++;
          }
        }
    }
};

/*!
 @class quickSort
 
 @brief The quickSort class
 
 @discussion    This  class was designed and implemented for quickSort algorithm.
 
 @superclass SuperClass: no\n
 @classdesign    No special design is applied here.
 @helps Helps no .
 @helper    No helper exists for this class.
 */
class quickSort :public algoSort
{
public:
    void algo(int data[],int lenD){
        int const len = lenD;
        int pivot = 0;
        int ind = len/2;
        int i,j = 0,k = 0;
        if(len>1){
          int* L = new int[len];
          int* R = new int[len];
          pivot = data[ind];
          for(i=0;i<len;i++){
            if(i!=ind){
              if(data[i]<pivot){
                L[j] = data[i];
                j++;
              }
              else{
                R[k] = data[i];
                k++;
              }
            }
          }
            algo(L,j);
            algo(R,k);
          for(int cnt=0;cnt<len;cnt++){
            if(cnt<j){
              data[cnt] = L[cnt];;
            }
            else if(cnt==j){
              data[cnt] = pivot;
            }
            else{
              data[cnt] = R[cnt-(j+1)];
            }
          }
        }
    }
};
/*!
 @class algorithm
 
 @brief The algorithm class
 
 @discussion    This  class was designed and implemented for Strategy pattern for using algorithms.
 
 @superclass SuperClass: no\n
 @classdesign    No special design is applied here.
 @helps Helps algo classes .
 @helper    No helper exists for this class.
 */
class algorithm
{
  public:
    algorithm( algoSort* comp): p(comp) {}
   ~algorithm() { delete p; }
    void algo( int data[],int lenD ) {
      p->algo( data,lenD);
    }
  private:
    algoSort* p;
};


#pragma mark - using Builder pattern
/*!
 @class Builder
 
 @brief The Builder class
 
 @discussion    This  class was designed and implemented for Builder pattern for using algorithms.
 
 @superclass SuperClass: no\n
 @classdesign    No special design is applied here.
 @helps Helps algo classes .
 @helper    No helper exists for this class.
 */
class Builder{
    public:
    int* data;
    int len;
    virtual ~Builder(){}
    virtual std::vector<int> massToVector()  =0;
    virtual std::vector<int> sort()  =0;
    virtual int* vectorToMass()  =0;
};

class ConcreteBuilder1 : public Builder{
    private:
    public:
    int* dat;
    int len;

    ConcreteBuilder1(int data[],int lenD){
        this->Reset();
        dat = data;
        len = lenD;
    }

    ~ConcreteBuilder1(){
        
    }

    void Reset(){
       
    }

    std::vector<int> massToVector() {
        std::vector<int> vec;
        for(int i =0;i<len;i++){
            vec.push_back(dat[i]);
        }
        return vec;
        
    }

    std::vector<int> sort(){
        std::vector<int> vec = massToVector();
        std::sort(vec.begin(), vec.end());
        return vec;
    }

    int* vectorToMass(){
        std::vector<int> vec = sort();
        int mass[vec.size()];
        for (int i =0;i<vec.size(); i++) {
            mass[i] = i;
        }
        return mass;
    }
};

class Director{
    
    private:
    Builder* builder;
    
    public:
    
    void set_builder(Builder* builder){
        this->builder=builder;
    }

    
    void BuildFullFeaturedProduct(){
        this->builder->massToVector();
        this->builder->sort();
        this->builder->vectorToMass();
    }
};

#endif /* alogorithms_hpp */
