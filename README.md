Problem Description :

You are expected to write the code of a function which takes two line segments as input and return true if the line segments are intersecting and false if not . 

A line segment can be uniquely represented by its endpoints and its endpoints by their x and y-coordinates wrt to a fixed origin.  Given two line segments , we need to check if these two line segments intersect or not (ie. have atleast one point in common) . For example, consider two line segments joining (0,0) , (0,2) and (0,0) , (2,0) respectively . Both of them indeed intersect at (0,0) .

![image](https://github.com/ZhaohuaFang/Line-Segments-Intersecting/blob/master/Graded_Programming_Assignment_GPA_01__Problem_Description_.png)

Indeed , please note the fact that the line segments AB and CD are not intersecting though the lines AB and CD intersect on extending the line segments . 

A point is said to be a lattice point if both its x and y coordinates are integers. In this problem , we consider only the line segments having both their end-points being lattice points . 

Consider the following class 'LineSeg' that has member variables Point p1 and p2.

class LineSeg {

public:

    Point p1,p2;
    
};

Here, class 'Point' is the data structure for a point that has its coordinates x and y as data variables.

class Point {

public:

 int x,y; 
 
};

You are required to Write A function :

Function Name : SegIntersect

This function has two parameters:

1. LineSeg l1 :  First line segment with its end-points given.

2. LineSeg l2 :  Second line segment with its end-points given.

The function should do the following

1. It should take two line segments as its parameters and find out whether the line segments are intersecting.

2. If they are intersecting , the function must return true else it must return false .

The function is given below, in which you need to write your code

bool SegIntersect(class LineSeg l1,class LineSeg l2) {
   
}

In the 'main' program, the function 'SegIntersect' is called using two arguments, l1 and l2 which are passed by value, both of type 'class LineSeg' .

To deal with this problem, I used a two-stage method to determine whether two line segments intersect, which are rapid rejection experiment and straddle experiment.

Despite using 'struct' to define two line segments, I use two 'class' to define points and line segments respectively.

This is GPA 01 assignment of Foundations of Data Structures, IITBombayX: CS213.1x, on edX.
