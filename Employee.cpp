#include <iostream>
#include "Employee.h"
using namespace std;

//Constructors

Employee::Employee(){}

Employee::Employee(int age, double income, double perfromance)
:age(age), income(income), performance(performance)
{}

//getters implementation
int Employee::getAge() const{ return age; }
double Employee::getIncome() const{ return income;}
double Employee::getPerformance() const{ return performance;}


//setters
//we may use templates here later
void Employee::setAge(int age){
  if(age > 0)
    this->age = age;
  else
    cout << "You cannot enter a negative age, please try again";

}
void Employee::setIncome(double income){
  if(income > 0)
    this->income = income;
  else
    cout << "You cannot enter a income age, please try again";

}
void Employee::setPerformance(double performance){
  this -> performance = performance;
}

//Destructor
Employee::~Employee(){}