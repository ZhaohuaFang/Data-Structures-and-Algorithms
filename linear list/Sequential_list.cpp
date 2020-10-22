#include <iostream>
using namespace std;

template <class T>
class SeqList{
private:
	T *array;
	int last;
	int max;
public:
	SeqList(int max);
	~SeqList();
	SeqList(SeqList & L);
	int size();
	int length();
	int search(T & x);
	bool getData(int index , T & x);
	bool setData( int index , T & x );
	bool insert( int index , T & x );
	bool remove( int index , T & x );
	bool isEmpty();
	bool isFull();
	void makeEmpty();
	void output();
};

template <class T>
SeqList<T>::SeqList(int max){
	if(max<=0){exit(1);}
	this->array=new T[max];
	if(this->array==NULL)
	{
	cout<<"分配内存错误！"<<endl;
	exit(1);
	}
	this->last=-1;
	this->max=max;
}

template <class T>
SeqList<T>::~SeqList()
{
	delete [] this ->array;
}

template <class T>
SeqList<T>::SeqList(SeqList & L){
	this->max=L.max;
	this->last=L.last;
	this->array=new T[this->max];
	if(this->array==NULL){
	cout<<"分配内存错误！"<<endl;
	exit(1);
	}
	for(int i=0;i<=L.last;i++){
	this->array[i]=L.array[i];
	}
}

template <class T>
int SeqList<T>::size(){
	return this->max;
}

template <class T>
int SeqList<T>::length(){

	return this->last+1;
}

template <class T>
int SeqList<T>::search( T & x ){
	for(int i=0;i<=this->last;i++){
		if(this->array[i]==x){
		return i;
		}
	}
	return -1;
}

template <class T>
bool SeqList<T>::getData( int index , T & x ) {
    if(index<0 || index>last){return false;}
	else{
	x=this->array[index];
	return true;
	}
	
}

template <class T>
bool SeqList<T>::setData( int index , T & x ){
    if(index<0 || index>last){return false;}
	else{
	this->array[index]=x;
	return true;
	}

}

template <class T>
bool SeqList<T>::insert( int index , T & x ){
	if(last == max - 1)return false;
	if(index<0 || index>last+1){return false;}
    for(int i = last; i >= index; i--)
	{
		array[i + 1] = array[i];
	}
	array[index] = x;
	last ++;
	return true;
}

template <class T>
bool SeqList<T>::remove( int index , T & x ){
	if(last == -1)return false;
	if(index < 0 || index > last)return false;
	x = array[index];
	for(int i = index; i < last; i++)
	{
		array[i] = array[i + 1];
	}
	last --;
	return true;
}

template <class T>
bool SeqList<T>::isEmpty(){
	if(last==-1){return true;}
	else{return false;}
}

template <class T>
bool SeqList<T>::isFull(){

	return(last==this->max-1)?true:false;
}

template <class T>
void SeqList<T>::makeEmpty(){
this->last=-1;
}

template <class T>
void SeqList<T>::output(){
	for(int i=0;i<=last;i++){
	cout<<this->array[i]<<' ';
	}
	cout<<endl;
}


//**************************************************************************************
int main()
{
	SeqList <int> seq(5);	
	if( seq.isEmpty() )cout << "顺序表为空" << endl;
	else cout << "顺序表不为空" << endl;
	if( seq.isFull() )cout << "顺序表已满" << endl;
	else cout << "顺序表未满" << endl;

	for(int i = 0; i < 5; i ++)
	{
		seq.insert(i , i);
	}
	cout << "顺序表当前内容如下：" << endl;
	seq.output();
	if( seq.isEmpty() )cout << "顺序表为空" << endl;
	else cout << "顺序表不为空" << endl;
	if( seq.isFull() )cout << "顺序表已满" << endl;
	else cout << "顺序表未满" << endl;
	int x;
	seq.remove(1 , x);
	cout << "顺序表当前内容如下：" << endl;
	seq.output();
	if( seq.isEmpty() )cout << "顺序表为空" << endl;
	else cout << "顺序表不为空" << endl;
	if( seq.isFull() )cout << "顺序表已满" << endl;
	else cout << "顺序表未满" << endl;
	cout << "顺序表内当前元素个数：" << seq.length() << endl;
	cout << "顺序表内最大存放元素个数：" << seq.size() << endl;
	x = 3;
	cout << "数据" << x << "在顺序表中的索引位置为：" << seq.search(x) << endl;
	seq.getData(1 , x);
	cout << "顺序表中1号索引位置的数据值为：" << x << endl;
	x = 100;
	seq.setData(2 , x);
	cout << "顺序表当前内容如下：" << endl;
	seq.output();
	seq.makeEmpty();
	if( seq.isEmpty() )cout << "顺序表为空" << endl;
	else cout << "顺序表不为空" << endl;
	return 0;
}
