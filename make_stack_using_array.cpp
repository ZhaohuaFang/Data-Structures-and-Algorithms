#include<iostream>
using namespace std;

class twoStacks
{
	int *arr;// array has only non negative elements.
	int size;
	int top1;
    //top1 is index of the topmost element of stack1 and is -1 if stack1 is empty  
    int top2;
    // top2 is index of the topmost element of stack2 and is equal to size if stack2 is empty 
public:
	twoStacks(int n) 
	{
		size = n;
		arr = new int[n];
		for (int i = 0; i < n; i ++) { //动态数组需要初始化为0才能都是0 
		arr[i] = 0;}                   //for a dynamic array, if we want all 
                                       //elements to be 0, we need to initialize them to be 0.
		top1 = -1; //initialization
		top2 = size;//initialization
	}
	bool push1(int i);//push i onto stack 1
	bool push2(int i);
	int pop1();// pop top element from stack 1
	int pop2();
    void double_resize();// resize the arr to double its current size
    int A(){
    	for(int i=0;i<size;i++){
    		cout<<arr[i];
		}
	}
};


/*
Function double_size() must double the size of the array by reallocating the array using the C++ operator new, and copy both the stacks into this newly created array.
It must also deallocate the dynamic memory previously allocated to the arr by using the keyword delete in C++
*/
void twoStacks::double_resize() {
	
    int newsize=2*size;
    int *newdata=new int[newsize];
    for (int i = 0; i < newsize; i ++) {
	newdata[i] = 0;}
    for (int i = 0; i<(top1+1); ++i)
	{
		newdata[i] = arr[i];
	}
	for (int j=(size+top2);j<newsize;++j)
	{
	    newdata[j]=arr[j-size];
	}
	size=newsize;
	top2=size-1;
	delete []arr;
	arr=newdata;
}

/*
	If stack1 is not full then the function push1(int i) should add element i into stack1 and return true. 
	Else it should return false
*/
bool twoStacks::push1(int i) {
    if (top1 < top2 - 1) 
       { 
           top1++; 
           arr[top1] = i; 
           return true;
       } 
    else
       { 
           return false;
       } 
}

/*
	If stack2 is not full then the function push2(int i) should add element i into stack2 and return true. 
	Else it should return false
*/

bool twoStacks::push2(int i) {
    if (top1 < top2 - 1) 
       { 
           top2--; 
           arr[top2] = i; 
           return true;
       } 
    else
       { 
           return false;
       } 
}

/*
If stack1 is not empty then the function pop1() should pop the top most element from the stack and return its value.
If stack1 is empty then the function pop1() must return -1
You may assume that the arr contains only non-negative integers
*/
int twoStacks::pop1() {

    if (top1 >= 0 ) 
       { 
          int x = arr[top1]; 
          top1--; 
          return x; 
       } 
    else
       { 
           return -1;
       } 
}
/*
If stack2 is not empty then the function pop2() should pop the top most element from the stack and return its value.
If stack2 is empty then the function pop2() must return -1
You may assume that the arr contains only non-negative integers
*/
int twoStacks::pop2() {
	
    if (top2 < size) 
       { 
          int x = arr[top2]; 
          top2++; 
          return x; 
       } 
    else
       { 
           return -1;
       } 
}

int main()
{
	twoStacks stack(5);
	stack.push1(5);
	stack.push1(2);
	
	stack.push2(4);
	stack.push2(3);
	stack.push1(5);
	cout<<stack.pop1();
	stack.double_resize();
	stack.A();
	
	return 0;
}
