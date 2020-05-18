#include<iostream>
using namespace std;
class Point {
public:
 int x,y; 
 Point(int x=2,int y=3){
 	this->x=x;
 	this->y=y;
 }
 Point(Point &p){
 	x=p.x;
 	y=p.y;
 }
};

class LineSeg {
public:
    Point p1,p2;
    LineSeg(Point xp1,Point xp2);
    LineSeg(LineSeg &L);    
};
LineSeg::LineSeg(Point xp1,Point xp2):p1(xp1),p2(xp2){}
LineSeg::LineSeg(LineSeg &L):p1(L.p1),p2(L.p2){}

bool SegIntersect(class LineSeg l1,class LineSeg l2) {
	if ((l1.p1.x > l1.p2.x ? l1.p1.x : l1.p2.x) < (l2.p1.x < l2.p2.x ? l2.p1.x : l2.p2.x) ||
        (l1.p1.y > l1.p2.y ? l1.p1.y : l1.p2.y) < (l2.p1.y < l2.p2.y ? l2.p1.y : l2.p2.y) ||
        (l2.p1.x > l2.p2.x ? l2.p1.x : l2.p2.x) < (l1.p1.x < l1.p2.x ? l1.p1.x : l1.p2.x) ||
        (l2.p1.y > l2.p2.y ? l2.p1.y : l2.p2.y) < (l1.p1.y < l1.p2.y ? l1.p1.y : l1.p2.y))
    {
        return false;
    }
    //straddle experiment
    if ((((l1.p1.x - l2.p1.x)*(l2.p2.y - l2.p1.y) - (l1.p1.y - l2.p1.y)*(l2.p2.x - l2.p1.x))*
        ((l1.p2.x - l2.p1.x)*(l2.p2.y - l2.p1.y) - (l1.p2.y - l2.p1.y)*(l2.p2.x - l2.p1.x))) > 0 ||
        (((l2.p1.x - l1.p1.x)*(l1.p2.y - l1.p1.y) - (l2.p1.y - l1.p1.y)*(l1.p2.x - l1.p1.x))*
        ((l2.p2.x - l1.p1.x)*(l1.p2.y - l1.p1.y) - (l2.p2.y - l1.p1.y)*(l1.p2.x - l1.p1.x))) > 0)
    {
        return false;
    }
    return true;

	
	
	
	
}
int main()
{       
	//this is a wrong way for defining an object of LineSeg
	//LineSeg line(Point pp,Point ppp);
	//cout<<line.p1.x 
	
	Point p1(0,0),p2(1,2),p3(3,2),p4(2,0);
	LineSeg line1(p1,p2);
	LineSeg line2(p3,p4);
	cout<<SegIntersect(line1,line2);
}
