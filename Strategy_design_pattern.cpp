//Strategy_design_pattern.cpp
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;
//we need to create seperate property for all the properties which chnage , keep only the properties in the main class which does not change 
class WalkableRobot
{
public:
	virtual void walk() = 0 ; //inline constructor 
	virtual ~WalkableRobot(){}
};

class NormalWalk : public WalkableRobot{
public:
	void walk() override
	{
		cout<<"WALKING NORMALLY "<<endl;
	}
}

class NoWalk: public WalkableRobot
{
public:
	void walk() override
	{
		cout<<"CANNOT WALK PROPERLY EVEN"<<endl;
	}
};

//interface for the talking robot 

class TalkableRobot
{
public:
	virtual void takl() = 0 ;
	virtual !TalkableRobot(){}
};

class Talk : public TalkableRobot
{
public:
	void talk()
	{
		cout<<"CAN TALK NORMALLY "<<endl;
	}
};

class NoTalk: public TalkableRobot
{
public:
	void talk()
	{
		cout<<"CANNOT TALK PROPERLY EVEN"<<endl;
	}
}

//now we create the main interface for the Robot
class Robot
{
protected:
	WalkableRobot* walkbehaviour;
	TalkableRobot* talkbehaviour;
public:
	//lets create a constructor for handling the above dependencies
	Robot(WalkableRobot* walking , Talkable* talking)
	{
		this->walkbehaviour = walking ;
		this->talkbehaviour = talking ;
	}

	void walk()
	{
		walkbehaviour->walk;
	}

	void talk()
	{
		talkbehaviour->talk;
	}
};

