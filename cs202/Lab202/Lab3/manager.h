#include "employee.h"

//This file keeps track of a manager's responsibilities

class manager: public salaried_employee
{
      public:
             //These functions are already implemented
             manager();
             manager( const manager &);
             //This function create a group of employees 
             void create_a_group(employee *array[]);
             void display() const;

            
             //You will be implementing these functions
             manager( const salaried_employee &);  
             ~manager();                           

             //Step 7 - CHALLENGE      
	     void add_to_group(const employee & new_employee);
           
      protected:
             name group_name;
             int num_employees;
             employee ** group; //a dynamic array of group members
};

