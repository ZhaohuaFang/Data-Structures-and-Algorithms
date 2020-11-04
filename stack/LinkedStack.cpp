#include<assert.h>
#include<iostream>
using namespace std;

template <class T>
struct LinkNode{
	T data;
	LinkNode<T> *link;
	LinkNode(LinkNode<T> *ptr=NULL){link=ptr;}//仅初始化指针成员的构造函数
	LinkNode(T& item,LinkNode<T> *ptr=NULL){//初始化数据与指针成员的构造函数
		data=item;link=ptr;}  	
};

template<class T>
class LinkedStack{
	private:
		LinkNode<T> *top; //栈顶指针
	public:
		LinkedStack(){top=NULL;}
		bool getTop( T & x );
		void push( T & x );
		bool pop(T & x );
		bool isEmpty( ){return(top == NULL)?true:false;}
		void makeEmpty( );
};

template<class T>
bool LinkedStack<T>::getTop( T & x ){
	if(isEmpty()==true)return false;
	x=top->data;
	return true;
};

template<class T>
void LinkedStack<T>::push( T & x ){
	LinkNode<T> *newNode=new LinkNode<T>(x);
	newNode->link=top;
	top=newNode;
};

template<class T>
bool LinkedStack<T>::pop(T & x ){
	if(isEmpty()==true)return false;
	LinkNode<T> *p=top;
	x=p->data;
	top=top->link;
	delete p;
	return true;
};
template<class T>
void LinkedStack<T>::makeEmpty( ){
	LinkNode<T> *p=new LinkNode<T>();
	while(top!=NULL){
	p=top;top=top->link;delete p;
	}
};

//**************************************************************************************
//testing
int main(){
	LinkedStack<int> stack;
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
