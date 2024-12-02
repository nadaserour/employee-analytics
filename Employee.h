#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
  private: 
    int age;
    double income;
    double performance;

  public:
    //Constructors
    Employee();
    Employee(int age, double income, double perfromance);

    //getters
    int getAge() const;
    double getIncome() const;
    double getPerformance() const;

    //setters
    void setAge(int age);
    void setIncome(double income);
    void setPerformance(double performance);

    //Destructor
    ~Employee();
};


#endif 