/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

class Point {
private:
    int x;
    int y;
public:
    Point(int x=0, int y=0)
	{
		this->x=x;
		this->y=y;
	}
    string toString() const
	{
		string ans="<Point["+to_string(this->x)+","+to_string(this->y)+"]>";
		return ans;
	}

    int distanceTo(const Point & otherPoint) const
	{
		return ceil(sqrt( (this->x-otherPoint.x)*(this->x-otherPoint.x) + (this->y-otherPoint.y)*(this->y-otherPoint.y) ));
	}
};

class Node {
private:
    Point point;
    Node * next;
    
    friend class Path;
    
public:
    Node(const Point & point=Point(), Node * next=NULL)
	{
    	this->point=point;
    	this->next=next;
	}
    string toString() const
	{
		//<Node[<Point[1,2]>]>;
		string ans="<Node["+point.toString()+"]>";
		return ans;
	}
};

class Path {
private:
    Node * head;
    Node * tail;
    int count;
    int length;

public:
    Path()
	{
    	head=nullptr;
    	tail=nullptr;
    	count=0;
    	length=-1;
	}
	int getLength() const
	{
		return length;
	}
    ~Path()
	{
    	Node* pre=head;
    	while(pre!=nullptr)
		{
    		Node* p=pre->next;
    		delete pre;
    		pre=p;
		}
    	pre=nullptr;
	}

    void addPoint(int x, int y)
	{
    	Node* newNode=new Node;
    	Point tmpNode(x,y);
    	newNode->point=tmpNode;
    	if(head==nullptr)
		{
    		head=newNode;
    		tail=newNode;
    		count++;
    		length=0;
		}
		else
		{
			Node* pretail=tail;
			tail->next=newNode;
			tail=newNode;
			count++;
			length+=pretail->point.Point::distanceTo(tail->point);
		}
	}
    string toString() const
	{
		string ans="<Path[count:"+to_string(count)+","+"length:"+to_string(length);
		if(count==0) return ans+",[]]>";
		Node* run= new Node;
		run=head;
		for(int i=0;i<count;i++)
		{
			if(i==0) ans+=",["+run->Node::toString();
			else ans+=","+run->Node::toString();
			run=run->next;
		}
		return ans+"]]>";
	}
    Point getLastPoint() const
	{
		Node* run=new Node;
		run=head;
		while(run->next!=nullptr) run=run->next;
		return run->point;
	}
};

class Character {
private:
    string name;
    Path * path;

public:
    Character(const string & name="")
	{
    	this->name=name;
    	Path* curPath=new Path;
    	path=curPath;
	}
    ~Character()
	{
    	delete path;
	}

    string getName() const
	{
		return this->name;
	}
    void setName(const string & name)
	{
    	this->name=name;
	}

    void moveToPoint(int x, int y)
	{
    	path->addPoint(x,y);
	}
	Point getCurrentPosition() const
	{
		return path->getLastPoint();
	}
	int getpathLength() const
	{
		return path->getLength();
	}
    string toString() const
	{
		return "<Character[name:"+name+",path:"+path->toString()+"]>";
	}
};

bool rescueSherlock(
        const Character & chMurderer,
        const Character & chWatson,
        int maxLength,
        int maxDistance,
        int & outDistance
        )
{
        	int l1=chWatson.getpathLength();
        	int l2=chMurderer.getpathLength();
        	if(l1-l2<=maxLength)
			{
        		outDistance=chWatson.getCurrentPosition().distanceTo(chMurderer.getCurrentPosition());
        		if(outDistance>maxDistance) return false;
        		return true;
			}
           else
		   {
           	 outDistance=-1;
           	 return false;
		   } 
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
