/*
SR Kanna
CS202
HW2
4/28/2015
COURSE.CPP

PURPOSE OF FILE:

*/

#include "course.h"
using namespace std;

//default constructor
course::course()
{
	credit = 0;
	required = 0;
	gpa = 0;
	grade = NULL;
	course_name = NULL;
}


//copy constructor that takes course pointer
course::course(course * const& course_obj)
{
	credit = course_obj->credit;
	required = course_obj->required;
	gpa = course_obj->required;
/*	
	if(grade)
	{
		delete [] grade;
	}
*/	
	grade = new char[strlen(course_obj->grade)+1];
	strcpy(grade,course_obj->grade);
/*	
	if(course_name)
	{
		delete [] course_name;
	}
*/
	course_name = new char[strlen(course_obj->course_name)+1];
	strcpy(course_name,course_obj->course_name);
}


//copy constructor obj
course::course(const course & course_obj)
{
	credit = course_obj.credit;
	required = course_obj.required;
	gpa = course_obj.required;
/*
	if(grade)
	{
		delete [] grade;
	}
*/
	grade = new char[strlen(course_obj.grade)+1];
	strcpy(grade,course_obj.grade);
/*
	if(course_name)
	{
		delete [] course_name;
	}
*/	course_name = new char[strlen(course_obj.course_name)+1];
	strcpy(course_name,course_obj.course_name);

}


//course counstructor
course::course(int credit,int required,char * grade,char * course_name)
{
	this->credit = credit;
	this->required = required;
	
/*	if(this -> grade)
	{
		delete [] this -> grade;
	}
*/
	this->grade = new char[strlen(grade)+1];
	strcpy(this->grade,grade);

/*	if(this -> course_name)
	{
		delete [] this -> course_name;
	}
*/
	this->course_name = new char[strlen(course_name)+1];
	strcpy(this->course_name,course_name);

}


//deconstructor
course::~course()
{
	credit = 0;	
	required = 0;
	gpa = 0;
	delete [] grade;
	delete [] course_name;
}


//display function for course
void course::display()
{
	cout << "The name of the course is " << course_name << '\t' << "The number of credits is " << credit << '\t' << "The grade earned was " << grade << endl;

}


//getter that gives back course name
char *& course::get_course_name()
{
	return course_name;
}


//returns grade recieved
char *& course::get_grade()
{
	return grade;
}


//returns number of credits
int course::get_credit()
{
	return credit;
}


//getter of the required number - cs/noncs/notreq
int course::get_required()
{
	return required;
}

/*
//cast it to the right dynamic function
int course::check_grades_wrapper(course & r)
{
	r.what_is_grade();
}


int course::what_is_grade()
{

}



//making sure the right cs classes have been taken
int *& course::check_classes_wrapper(course & r)
{
	int classes_taken[6];
	r.what_classes_taken(clases_taken);
}


int *& course::what_classes_taken(int * classes_taken)
{


}


//dynamic binding of copy function
course * course::copy()
{

}

float course::calculate_gpa()
{
switch(grade)
case "A":
	return 4.00;
	break;
case "A-":
	return 3.69;
	break;
case "B+":
	return 3.33;
	break;
case "B":
	return 3.00;
	break;
case "B-":
	return 2.67;
	break;
case "C+":
	return 2.33;
	break;
case "C":
	return 2.00;
	break;
case "C-":
	return 1.67;
	break;
case "D+"
	return 1.33;
	break;
case "D"
	return 1.00;
	break;
case "D-"
	return .67;
	break;
default:
	return 0;
}
*/

//default constructor
req::req()
{
	credit = 0;
	required = 0;
	gpa = 0;
	grade = NULL;
	course_name = NULL;
}


//copy constructor
req::req(const req & req_obj):course(req_obj)
{

}



//initialization list w/arguments
req::req(int credit,int required, char * grade,char * course_name):course(credit,required,grade,course_name)
{


}


//deconstrucor- calls base class
req::~req()
{
//no more private data members
}


/*
//base class dynamic function
int *& req::what_classes_taken(int * classes):course(classes)
{

}


//base class dynamic function
int req::what_is_grade()
{


}
*/


//default constructor
not_required::not_required()
{
	credit = 0;
	required = 0;
	gpa = 0;
	grade = NULL;
	course_name = NULL;
}



//copy constructor - object as argument
not_required::not_required(const not_required & not_required_object):course(not_required_object)
{


}


//construcor w/arguments
not_required::not_required(int credit,int required, char * grade, char * course_name):course(credit,required,grade,course_name)
{


}


//copy function
course * not_required::copy()
{
	not_required  * temp = new not_required(credit,required,grade,course_name);
	return(course*)temp;
}


//deconstructor
not_required::~not_required()
{

}




//default constructor
non_cs::non_cs():req()
{
	credit = 0;
	required = 0;
	gpa = 0;
	grade = NULL;
	course_name = NULL;
}


//copy constructor 
non_cs::non_cs(const non_cs & non_cs_object):req(non_cs_object)
{

}


//constructor w/arguments
non_cs::non_cs(int credit2,int required2,char * grade2,char * course_name2)
{
	credit = credit2;
	required = required2;
	
/*	if(grade)
	{
		delete [] grade;
	}
*/
	grade = new char[strlen(grade2)+1];
	strcpy(grade,grade2);
/*	
	if(course_name)
	{
		delete [] course_name;
	}
*/	course_name = new char[strlen(course_name2)+1];
	strcpy(course_name,course_name2);

}


//destructor
non_cs::~non_cs()
{


}


//calculate the grade- if pass everything with c- or better
/*
int non_cs::what_is_grade()
{
if (strcmp(grade,"A")==0)
	return 1;
if else (strcmp(grade,"B+")==0)
	return 1;
if else (strcmp(grade,"B")==0)
	return 1;
if else (strcmp(grade,"B-")==0)
	return 1;
if else (strcmp(grade,"C+")==0)
	return 1;
if else (strcmp(grade,"C")==0)
	return 1;
if else(strcmp(grade,"C-")==0)
	return 1;
else 
	return 0;
}




course * non_cs::copy()
{
	non_cs * temp = new non_cs(credit,required,grade,course_name);
	return(course*)temp;	//setting temp to course
}



int *& non_cs::what_classes_taken(int * classes_taken)
{
if (strcmp(course_name,"MTH251")==0)
{
	classes_taken[0] = 1;
	return classes_taken;
}

if (strcmp(course_name,"MTH252")==0)
{
	classes_taken[1] = 1;
	return classes_taken;
}

if (strcmp(course_name,"COMM220")==0)
{
	classes_taken[2] = 1;
	return classes_taken;
}

if (strcmp(course_name,"WR121")==0)
{
	classes_taken[3] = 1;
	return classes_taken;
}

if ((strcmp(course_name,"BIO251")==0) || (strcmp(course_name,"CHEM251")==0) || (strcmp(course_name,"PHY251")==0))
{
	classes_taken[4] = 1;
	return classes_taken;
}

if ((strcmp(course_name,"BIO252")==0) || (strcmp(course_name,"CHEM252")==0) || (strcmp(course_name,"PHY252")==0))
{
	classes_taken[5] = 1;
	return classes_taken;
}
}
*/


//default constructor
cs::cs():req()
{

}


//destructor
cs::~cs()
{


}


//constructor w/arguments
cs::cs(const cs & cs_object):req(cs_object)
{

}


//constructor with arguments
cs::cs(int credit2,int required2,char * grade2,char * course_name2)
{
	credit = credit2;
	required = required2;

/*	if(grade)
	{
		delete [] grade;
	}
*/	grade = new char[strlen(grade2)+1];
	strcpy(grade,grade2);

/*	if(course_name)
	{
		delete [] course_name;
	}
*/	course_name = new char[strlen(course_name2)+1];
	strcpy(course_name,course_name2);

}



/*
course * cs::copy()
{
	cs * temp = new cs(credit,required,grade,course_name);
	return (course *)temp;	//setting course to temp
}



int cs::what_is_grade()
{
switch(grade)
case "A":
	return 1;
	break;
case "A-":
	return 1;
	break;
case "B+":
	return 1;
	break;
case "B":
	return 1;
	break;
case "B-":
	return 1;
	break;
case "C+":
	return 1;
	break;
case "C":
	return 1;
	break;
default:
	return 0;
}



int *& cs::what_classes_taken(int * classes_taken)
{
if (strcmp(course_name,"CS162")==0)
{
	classes_taken[0] = 1;
	return classes_taken;
}

if (strcmp(course_name,"CS163")==0)
{
	classes_taken[1] = 1;
	return classes_taken;
}

if (strcmp(course_name,"CS202")==0)
{
	classes_taken[2] = 1;
	return classes_taken;
}

if (strcmp(course_name,"CS201")==0)
{
	classes_taken[3] = 1;
	return classes_taken;
}

if (strcmp(course_name,"CS250")==0)
{
	classes_taken[4] = 1;
	return classes_taken;
}

if (strcmp(course_name,"CS251")==0)
{
	classes_taken[5] = 1;
	return classes_taken;
}
}

*/
