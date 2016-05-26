/*
SR Kanna
CS202
4/28/2015
HW2

COURSE.H

Purpose of COURSE.H: This implements the client's interface functionality
*/

//abstract base class




//#include "data_st.h"


#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <time.h>


//course class
class course
{
public:

	course();			//default constructor
	course(const course &);		//copy constructor  I: Takes a course object O: NA
	course(course * const&);	//copy constructor I: that takes a ptr O: NA
	course(int credit2,int required2,char * grade2,char * course_name2);		//construcotr that takes arguments I: 2 ints, 2 chars O: NA
	virtual ~course();			//deconstructor

	void display();				//display function I/O: Nothing
	int get_credit();			//getter of the credit I: NA O: credit
	int get_required();			//getter of required I: NA O: Int
	char *& get_grade();			//Geter of grade I: NA O: Char by reference
	char *& get_course_name();		//getter of course name O: Char by reference


//FUNCTIONS TO POTENTIALLY IMPLMENT:
//	int check_grades_wrapper(course &);
//	int what_is_grade();
//	int *& check_classes_wrapper(course &);
//	int *& what_classes_taken(int * classes);
//	float calculate_gpa();
//	int how_many_credits();


protected:
	int credit;		//the number of credits
	int required;		//required
	float gpa;		//the gpa
	char * grade;		//grade earned
	char * course_name;	//name of course

};


//required class
class req: public course
{
public:

	req();			//default constructor	I/O NA
	req(int credit,int required,char * grade,char * course_name);	//construcotr with arguments I: 2 ints, O: 2 chars
	virtual ~req();		//Deconstrucor I/O: NA
	req(const req &);	//copy constructor I: Takes a req by object O: NA

//FUNCTIONS TO BE POTENTIAL IMPLEMNETED:
//	virtual int what_is_grade()=0;	//abstract I: O: true/false flag of meeting requirement
//	virtual int *& what_classes_taken(int * classes_taken);		//abstract base class


};


//not required class
class not_required: public course
{
public:
	not_required();			//default I/O: NA
	not_required(int credit,int required,char * grade,char * course_name);	//Constructor w/arguments I:2 int2, 2 chars O: NA
	course * copy();	//return copy pointer	I: NA O: Course ptr
	~not_required();		//default constructor
	not_required(const not_required &);		//copy constructor I: Takes an object O: Nothing
};


class non_cs: public req
{
public:
	non_cs();			//default consturctor I/O: Nothing
	non_cs(int credit,int required,char * grade,char * course_name);		//Constuctor with arguments I/O: 2 ints, 2 chars O: Nothing
	~non_cs();			//deconstructor
	non_cs(const non_cs &);		//copy consturctor I: Takes a non_cs object O: Nothing
	course * copy();		//copy function I: Nothing O: course ptr

//FUNCTIONS TO BE POTENTIALLY IMPLEMENTED:
//	int *& what_classes_taken(int * classes_taken);
//	int what_is_grade();	//if user has taken all classes I: O: True false flags
//	int what_classes_taken(argument); //if user has tkaen correct classes I: O: True/False flags

};


//CS Class
class cs: public req
{
public:
	cs();		///default constructor	I/O: nothing	
	~cs();		//deconstructor		I/O: Nothing
	cs(int credit,int required,char * grade,char * course_name);		//Consturctor with Arugments I:2 ints, 2 chars O: Nothing
	cs(const cs &);		//copy construcotr I: Takes a cs object O: Nothing
	course * copy();	//Copy function I: nothing O: Coures ptr

//FUNCTIONS TO BE POTENTIALLY IMPLEMNTED
//	int what_is_grade();	//if user has taken all classes i: O: true false flags
//	int *& what_classes_taken(int * classes_taken); //if user has taken correct classes I: O: True/False Flags
//	int what_is_gpa(argument);	//calcuates user's gpa I: O: the gpa

};
