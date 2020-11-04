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
//带附加头结点的单链表
template <class T>
class LinkedList{
	protected:
		LinkNode<T> *first;
	public:
		LinkedList()
		{first=new LinkNode<T>;
		if(first==NULL){
			cerr<<"分配内存错误";
			exit(1);
		}}
		int length();
		int search(T & x);
		bool getData( int index , T & x );
		bool setData( int index , T & x );
		bool insert( int index , T & x );
		bool remove( int index , T & x );
		bool isEmpty();
		void makeEmpty();
		void output();
};
template <class T>
int LinkedList<T>::length(){
	int count=0;
	LinkNode<T> *p=first;
	while(p->link!=NULL){
		count=count+1;
		p=p->link;
	}
	return count;
};
template <class T>
int LinkedList<T>::search( T & x ){
	int index=0;
	LinkNode<T> *current=first->link;
	while(current!=NULL){
		if(current->data==x){return index;}
		else {current=current->link;index+=1;}
	}
	return -1;
};
template <class T>
bool LinkedList<T>::getData( int index , T & x ){
	if(index<0) return false;
	LinkNode<T> *current=first->link;
    for(int k=0;k<index;k++){
	  if(current!=NULL){current=current->link;}
    }
    if(current==NULL){return false;}
	x=current->data;
	return true;
   
};
template <class T>
bool LinkedList<T>::setData( int index , T & x ){
  if(index<0) return false; 
  LinkNode<T> *current=first->link;
  for(int k=0;k<index;k++){
	  if(current!=NULL){current=current->link;}
   }
   if(current==NULL){return false;}
  current->data=x;
  return true;
};
template <class T>
bool LinkedList<T>::insert( int index , T & x ){
   if(index<0) return false;
   LinkNode<T> *current=first;
   for(int k=0;k<index;k++){
	   if(current!=NULL){current=current->link;}
   }
   if(current==NULL){return false;}
   LinkNode<T> *newNode=new LinkNode<T>(x);
   if(newNode==NULL){cerr<<"分配内存错误";exit(1);}
   newNode->link=current->link;
   current->link=newNode;
   return true;
};
template <class T>
bool LinkedList<T>::remove( int index , T & x ){
	if(index<0) return false;
	LinkNode<T> *current=first;
    for(int k=0;k<index;k++){
	   if(current!=NULL){current=current->link;}
    }
    if(current==NULL){return false;}
    LinkNode<T> *del=current->link;
    current->link=del->link;
    x=del->data;
    delete del;
    return true;
};
template <class T>
bool LinkedList<T>::isEmpty( ){
	return first->link==NULL?true:false;
};
template <class T>
void LinkedList<T>::makeEmpty(){
	LinkNode<T> *q;
	while(first->link!=NULL){
		q=first->link;
		first->link=q->link;
		delete q;
	}
};
template <class T>
void LinkedList<T>::output(){
	LinkNode<T> *current=first;
	for(int i=0;i<length();i++){
		current=current->link;
		cout<<current->data<<' ';
	}
	cout<<endl;
};

//**************************************************************************************
//testing
int main()
{
	LinkedList <int> list;	
	if( list.isEmpty() )cout << "单链表为空" << endl;
	else cout << "单链表不为空" << endl;
	
	for(int i = 0; i < 5; i ++)
	{
		list.insert(i , i);
	}
	cout << "单链表当前内容如下：" << endl;
	list.output();
	if( list.isEmpty() )cout << "单链表为空" << endl;
	else cout << "单链表不为空" << endl;
	
	int x;
	list.remove(1 , x);
	cout << "单链表当前内容如下：" << endl;
	list.output();
	if( list.isEmpty() )cout << "单链表为空" << endl;
	else cout << "单链表不为空" << endl;
	
	cout << "单链表内当前元素个数：" << list.length() << endl;
	
	x = 3;
	cout << "数据" << x << "在单链表中的索引位置为：" << list.search(x) << endl;
	list.getData(1 , x);
	cout << "单链表中1号索引位置的数据值为：" << x << endl;
	x = 100;
	list.setData(2 , x);
	cout << "单链表当前内容如下：" << endl;
	list.output();
	list.makeEmpty();
	if( list.isEmpty() )cout << "单链表为空" << endl;
	else cout << "单链表不为空" << endl;
	return 0;
}
