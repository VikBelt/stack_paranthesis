#pragma once
#include <iostream>
#include <vector>

using std::vector;

//Generic Stack Class Declaration
template<typename T>
class Stack{
    public: 
        //default constructor
        Stack():amt{0}{
            base = new T[cap]; //stack lives on the heap
            current = base-1;
            top = base+cap;
        }
        //parametrized constructor
        Stack(T val):amt{1}{
            base = new T[cap]; //stack lives on the heap
            current = base;
            base[amt] = val;
            top = base+cap;
        }
        //copy constructor
        Stack(const Stack<T> & source){
            cap = source.cap;
            amt = source.amt;
            base = new T[cap];
            top = base+cap;
            current = base-1;
            for(auto i = 0; i<amt; i++){
                base[i] = source.base[i];
                current++;
            }
        }
        //destructor
        ~Stack(){
            delete [] base;
            base = nullptr;
        }
        //return the top of the stack
        T peak() {
            return *current;
        }
        //add to the top of the stack
        void push(T val){
            //if stack full double it
            if(this->full()){
                this->double_capacity();
            }
            //same code for pushing
            current++;
            base[amt] = val;
            amt++;
        }
        //pops off the stack
        void pop(){
            if(empty()){
                throw "stack is empty - cannot pop";
            }
            else{
                current--;
                amt--;
            }
        }
        //method if stack is empty
        bool empty(){
            if(current == base-1) {
                return true;
            }
            else{
                return false;
            }
        }
        //print the stack
        void print(){
            if(empty()){
                std::cout<<"Stack is Empty - Nothing to Print\n";
            }
            else{
                T* temp = base;
                while(temp != current+1){
                    std::cout<<(*temp)<<" ";
                    temp++;
                }
                std::cout<<"\n";
            }
        }

        //converts Stack to std::vector
        vector<T> to_vector(){
            vector<T> vec;
            T* temp = base;
            while(temp != current+1){
                vec.push_back(*temp);
                temp++;
            }
            return vec;
        }
        //clear - resets the stack ptr but does not touch memory
        void clear(){
            while (current > base-1){ 
                current--;
            }
        }
        //returns size of the stack
        int size() {return amt;}
        int capacity() {return cap;}

    private:
        //private methods
        bool full(){
            if(current+1 == top) {return true;}
            else {return false;}
        }
        //to double the stack when capacity is full
        void double_capacity(){
            cap = cap*2;
            T* temp = base;
            base = new T[cap]; //want a new array
            //update top pointer
            top = base+cap;
            current = base-1;
            for(auto i = 0; i<this->size(); i++){
                base[i] = temp[i];
                current++;
            }
            //free the old array
            delete [] temp;
        }

        //fields
        int amt;
        int cap{5};
        T* base{nullptr};
        T* current{nullptr};
        T* top{nullptr};
};
