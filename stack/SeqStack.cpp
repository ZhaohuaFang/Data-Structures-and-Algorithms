#include<assert.h>
#include<iostream>
using namespace std;

template<class T>
class SeqStack{
	private:
		T * elements;
		int top;
		int maxSize;
	public:
		SeqStack(int max){
			maxSize=max;
			top=-1;
			elements=new T[maxSize];
		    assert(elements!=NULL);}
		bool getTop(T & x);
		bool push(T & x);
		bool pop(T & x);
		bool isEmpty(){return(top == -1)?true:false;}
		bool isFull(){return(top == maxSize-1)?true:false;}
		void makeEmpty(){top=-1;}
};

template<class T>
bool SeqStack<T>::getTop(T & x){
	if(isEmpty()==true)return false;
	x=elements[top];
	return true;
};

template<class T>
bool SeqStack<T>::push(T & x){
	if(isFull()==true)return false;
	top++;
	elements[top]=x;
	return true;
};

template<class T>
bool SeqStack<T>::pop(T & x){
	if(isEmpty()==true)return false;
	x=elements[top];
	top--;
	return true;
};

//**************************************************************************************
//testing
int main(){
	SeqStack<int> stack(5);
	int x=1;
	stack.push(x);
	x=2;
	stack.push(x);
	x=3;
	stack.push(x);
	x=4;
	stack.push(x);
	x=5;
	stack.push(x);
	if(stack.isFull()) cout<<"栈已满"<<endl;
	else cout<<"栈未满"<<endl;
	stack.getTop(x);
	cout<<"栈顶元素为"<<x<<endl;
	stack.pop(x);
	stack.getTop(x);
	cout<<"栈顶元素为"<<x<<endl;
	stack.makeEmpty();
	if(stack.isEmpty()) cout<<"栈为空"<<endl;
	else cout<<"栈不空"<<endl;
	return 0;
}
