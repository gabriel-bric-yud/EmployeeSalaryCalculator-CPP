// Employee Salary Calculator
// vscode

#include <iostream>
using namespace std;

int main() 
{
  //Declare named constants.
  const double PAY_INCREASE = 0.056;
  const int TOTAL_MONTHS = 12;

  //Declare variables.
  char startChar;
  string employeeName = "";
  double formerSalary(0), increasedPay(0), newAnnualSalary(0), newMonthlySalary(0);

  //Set fixed decimal for output.
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "Welcome to the Employee Salary Calculator Application!\n";

  do //Outer loop start
  {
    startChar = 'z'; //set startChar to non y or n value.

    cout << "\nPlease enter an employee name: ";
    cin >> employeeName; //Collect basic employee data.
    cin.ignore(1000, '\n'); //get rid of first 1000 characters and linebreaks in cin buffer

    while (true)  //Int type validation loop to collect annual salary.
    {
      cout << "Please enter employee's annual salary: $";  
      if (cin >> formerSalary) //Collect salary data and check if input is type int.
      {
        if (formerSalary > 0) //Check input is not negative or null.
        {
          cin.ignore(1000, '\n'); //get rid of first 1000 characters and linebreaks in cin buffer
          break; //exit validation loop
        }
        else 
        {
          cout << "Enter a positive number greater than 0.\n";
        }
      }
      cout << "Invalid input!\n";
      cin.clear(); //clear cin errors
      cin.ignore(1000, '\n'); //get rid of first 1000 characters and linebreaks in cin buffer
    }

    //Calculate new salary data
    increasedPay = formerSalary * PAY_INCREASE;
    newAnnualSalary = formerSalary + increasedPay;
    newMonthlySalary = newAnnualSalary / TOTAL_MONTHS;

    //Display data
    cout << "\nSalary Info -\n";
    cout << "Former annual salary: $" << formerSalary << endl;
    cout << "Pay increase: $" << increasedPay << endl;
    cout << "New annual salary: $" << newAnnualSalary << endl;
    cout << "New monthly salary:  $" << newMonthlySalary << endl;

    cout << "\n" << employeeName << "'s former salary of $" << formerSalary 
    << " was increased at a percentage rate of " << (PAY_INCREASE * 100)
    << "%" << " to a new annual salary of $" << newAnnualSalary << ".\n"
    << "This increase of $" << increasedPay << " per year will change " 
    << employeeName << "'s monthly salary to $" << newMonthlySalary << ".\n\n";

    do //Yes or No validation loop to check if user wants to end program
    {
      string startApp; //empty string to capture user input
      cout << "Do you want to calculate salary for another employee? (Y/N): ";
      cin >> startApp;
      
      if (startApp.length() < 2) //Check string is only one char long
      {  
        startChar = startApp[0];  //set startChar to first char of validated input.
      }
      cin.clear(); //clear cin errors
      cin.ignore(1000, '\n'); //get rid of first 1000 characters and linebreaks in cin buffer
    }
    while ((tolower(startChar) != 'y') && (tolower(startChar) != 'n')); //end yes or no validation

  }
  while (tolower(startChar) == 'y'); //end outer loop

  //Exit program.
  cout << "Program terminated. Goodbye!" << endl;
  return 0;
}