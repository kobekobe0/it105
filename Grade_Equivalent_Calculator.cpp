// Program that will compute the grade of 3 inputted student's info..
// C++

// defining header file
#include <iostream>
using namespace std;

// class Grade
class Grade {

  // setting class variables or data members to private
private:
  // initializing class variables
  float quiz = 50;
  float midtermExam = 60;
  float laboratoryActivity = 90;
  float midtermGrade;

  // setting class member functions to public
public:

  // Defining our class setters which are responsible for setting up values for our class variables 

  // setter setQuiz()
  // this setQuiz() function is responsible for setting up the right value for our quiz variable.
  // This function will ask the user to enter their quiz score and will make sure that only values within 0 to 50 is allowed or else, it will reject that score and ask again until the user finally enters a value within the range of 0-50
  void setQuiz() {
    float Quiz;
    // run a loop
    while(true) {
      // ask the user to enter quiz score
      cout << "\nEnter Quiz Score (0-50): ";
      cin >> Quiz;
      // check if Quiz value entered is within 0-50
      if(Quiz >= 0 and Quiz <= this->quiz) {
	// assign the Quiz score to our quiz variable
	this->quiz = Quiz; 
	break; // stop the loop
      } else {
	// prompt the user to enter only value within 0-50
	cout << "\nQuiz score should only be within 0 to 50 only!\n";
      }
    }
  }

  // setter setMidtermExam()
  // this setMidtermExam() function is responsible for setting up the right value for our midtermExam variable.
  // This function will ask the user to enter their midterm exam  score and will make sure that only values within 0 to 60 is allowed or else, it will reject that score and ask again until the user finally enters a value within the range of 0-60
  void setMidtermExam() {
    float MidtermExam;
    // run a loop
    while(true) {
      // ask user to enter their midterm exam scote
      cout << "\nEnter Midterm Exam Score (0-60): ";
      cin >> MidtermExam;
      // check if user entered midterm exam score is within 0-60
      if(MidtermExam >= 0 and MidtermExam <= this->midtermExam) {
	// assign user entered MidtermExam value to our midtermExam variable
        this->midtermExam = MidtermExam;
        break; // stop the loop
      } else {
	// prompt user to enter only score value within 0-60
        cout << "\nMidterm exam score should only be within 0 to 60 only!\n";
      }
    }
  }

  // setter setLaboratoryActivity()
  // this function is responsible for setting up the right value for our laboratoryActivity variable.
  // This function will ask the user to enter their laboratoryActivity score and will make sure that only values within 0 to 90 is allowed or else, it will reject that score and ask again until the user finally enters a value within the range of 0-90
  void setLaboratoryActivity() {
    float LaboratoryActivity;
    // run a loop
    while(true) {
      // ask user to enter score
      cout << "\nEnter Laboratory Activity Score (0-90): ";
    cin >> LaboratoryActivity;
    // check if score is within 0-90
      if(LaboratoryActivity >= 0 and LaboratoryActivity <= this->laboratoryActivity) {
	// assign user entered laboratory activity score to our laboratoryActivity variable
        this->laboratoryActivity = LaboratoryActivity;
        break; // stop the loop
      } else {
	// prompt user to enter only within 0-90 range
        cout << "\nLaboratory activity score should only be within 0 to 90 only!\n";
      }
    }
  }


  // method to calculate sum of student's grade.
  // this function/method will return the midterm exam result.
  float calculateGrade() {
    // defining variables
    float Quiz, MidtermExam, LaboratoryActivity;
    // calculate score to quiz
    Quiz = (this->quiz / 50 * 50 + 50) * 0.20;
    // calculate score for midterm exam
    MidtermExam = (this->midtermExam / 60 * 50 + 50) * 0.40;
    // calculate score for lab activity
    LaboratoryActivity = (this->laboratoryActivity / 90 * 50 + 50) * 0.40;
    // sum up all scores and assign to our midtermGrade variable.
    this->midtermGrade = Quiz + MidtermExam + LaboratoryActivity;
    // return the value of midtermGrade variable
    return this->midtermGrade;
  }
};

// ask option function
// this function is responsible for asking the user if they want to do another transaction or not and make sure that only Y or N answers are accepted or else, it will ask again for input.
char askOption() {
  char option;
  while(true) {
    cout << "\nDo you want another transaction? Y/N: ";
    cin >> option;
    if(option == 'Y' || option == 'N') {
      break;
    } else {
      cout << "\nInvalid Choice! Choose only Y or N.\n";
    }
  }
  return option;
}

// Get Grade Equivalent function
// this function will take the midterm grade result of the user and using switch case, will determine the grade equivalent of their score.
string gradeEquivalent(int midtermGrade) {
  string result;
  switch(midtermGrade) {
  case 97 ... 100:
    result = "1.0";
    break;
  case 94 ... 96:
    result = "1.25";
    break;
  case 91 ... 93:
    result = "1.50";
    break;
  case 88 ... 90:
    result = "1.75";
    break;
  case 85 ... 87:
    result = "2.0";
    break;
  case 82 ... 84:
    result = "2.25";
    break;
  case 79 ... 81:
    result = "2.50";
    break;
  case 76 ... 78:
    result = "2.75";
    break;
  case 75:
    result = "3.0";
    break;
  case 0 ... 74:
    result = "5.0";
    break;
  default:
    result = "n/a";
    break;
  }
  return result;
}

// main program
int main() {

  // instantiates grade class and defining few variables for our program.
  Grade grade;
  char option;
  float midtermGrade;

  // run a loop to keep our program rolling until the user decides to exit.
  while(true) {
    // call setQuiz() method
    grade.setQuiz();
    // call setMidtermExam() method
    grade.setMidtermExam();
    // call setLaboratoryActivity() method
    grade.setLaboratoryActivity();

    // call calculateGrade() method and assign tje result to midtermGrade variable
    midtermGrade = grade.calculateGrade();

    // display midterm grade value
    printf("\nMIDTERM GRADE:  %.2f\n", midtermGrade);
    // display midterm grade equivalent
    cout << "Grade Equivalent: " << gradeEquivalent(midtermGrade) << endl;

    // call askOption function and assign the result to option variable
    option = askOption();
    // check if option value is N. which means the user chooses not to make another transaction
    if(option == 'N') {
      // display message
      cout << "\nProgram exiting...\n";
      break; // stop the loop.
    }
  }

  return 0;
}
