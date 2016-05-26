/*
   SR Kanna
   4/28/2015
   CS202
   HW2

   MAIN.CPP

   PURPOSE OF PROGRAM: The purpose of this program is to determine if the user has been admitted into the CS program by taking in all the classes they've taken by term and evaluating if they meet the department's requirements
 */

#include "bst.h"
using namespace std;
int main()
{

	//declaring objects:
	lll lll_object;
	term_list term_list_object;
	manager manager_object;

	char response[1000];
	char * more = NULL;
	int term2;
	cout << "How many terms have you taken at PSU? " << endl;
	cin >> term2;
	cin.ignore(100,'\n');


	char temp[1000];		//temporary array
	int classes;			//number of classes taken
	course * temp_insert;

	cout << "Please enter your information in order by the term you took them! " << endl << endl;


	for (int j = 0; j < term2; ++j)
	{

		term term_object;
		cout << "What is the name of a term you would like enter. Please enter the year and then the term. EXAMPLE: 2015 Spring? ";
		cin.get(temp,1000,'\n');	cin.ignore(100,'\n');
		char * term_name = new char[strlen(temp)+1];
		strcpy(term_name,temp);
		term_object.insert_name(term_name);	
		delete [] term_name;

		do
		{
			int credit;	//number of credits
			int required;	//if the course is required or not

			//ask course name, grade, credits for number of classes taken

			cout << "Please enter your information in order by the term you took them! " << endl << endl;


			cout << "Please enter a course title: ";
			cin.get(temp,1000,'\n');	cin.ignore(100,'\n');
			char * course_title = new char[strlen(temp)+1];
			strcpy(course_title,temp);


			cout << "Please enter the number of credits ";
			cin >> credit;		cin.ignore(100,'\n');

			cout << "Please enter the grade you recieved. A, A-, B+, B, B-, C+, C, C-, D+, D, D- and F are all valid entries. ";
			cin.get(temp,1000,'\n');	cin.ignore(100,'\n');
			char * grade = new char[strlen(temp)+1];
			strcpy(grade,temp);

			cout << "Whas this course mandatory? Y/N. ";
			cin.get(temp,1000,'\n');	cin.ignore(100,'\n');
			char * mandatory = new char[strlen(temp)+1];
			strcpy(mandatory,temp);

			*mandatory = toupper(*mandatory);
			if (strcmp(mandatory,"N")==0)
			{
				required = 0;
				temp_insert = new not_required(credit,required,grade,course_title);

			}


			if (strcmp(mandatory,"Y")==0)
			{
				cout << "Is this course a CS course? Y/N ";
				cin.get(temp,1000,'\n');	cin.ignore(100,'\n');
				char * class_is_cs = new char[strlen(temp)+1];
				strcpy(class_is_cs,temp);

				*class_is_cs = toupper(*class_is_cs);
				if (strcmp(class_is_cs,"Y")==0)
				{
					required = 1;
					temp_insert = new cs(credit,required,grade,course_title);
				}
				else
				{
					required = 2;
					temp_insert = new non_cs(credit,required,grade,course_title);
				}	
			}

			cout << "Are you done entering classes for this term? Y/N ";
			cin.get(response,100,'\n');	cin.ignore(100,'\n');
			if(more)
				delete [] more;
			more = new char[strlen(response)+1];
			strcpy(more,response);
			*more = toupper(*more);

			term_object.insert(*temp_insert);
		}	
		while(strcmp(more,"N")==0);

		term_list_object.insert_term_list(term_object);
	}	

	for(int i = 0; i < term2; ++i)
	{
		manager_object.insert_wrapper(term_list_object.find_random_wrapper());
	}
	
		manager_object.wrapper_display();

	char retrieve[1000];
	cout << "Please enter a term to see " << endl;
	cin.get(retrieve,1000,'\n');	cin.ignore(100,'\n');
	char * retrieve_term = new char[strlen(retrieve)+1];
	strcpy(retrieve_term,retrieve);
	manager_object.wrapper_retrieve(retrieve_term);


	char remove_term[1000];
	cout << "Please enter a term to remove " << endl;
	cin.get(remove_term,1000,'\n');	cin.ignore(100,'\n');
	char * remove = new char[strlen(remove_term)+1];
	strcpy(remove,remove_term);
	manager_object.wrapper_remove_one(remove);
	cout << "This is after removing " << remove << ":" << endl;
	manager_object.wrapper_display();


	return 0;
};
