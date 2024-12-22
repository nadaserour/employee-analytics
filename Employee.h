//
// Created by Nada Serour on 12/21/2024.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H



class Employee {

private:
    double age = 0;
    double income = 0;         //q1
    double performance = 0;    //q2

public:
    //Constructors
    Employee();
    Employee(double age, double income, double performance);

    //getters
    double getAge() const ;
    double getIncome() const;
    double getPerformance() const;

    //setters
    void setAge(double age);
    void setIncome(double income);
    void setPerformance(double performance);

    //Destructor
    ~Employee();


};



#endif //EMPLOYEE_H
