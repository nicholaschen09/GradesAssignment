/* ------------------------
 Nicholas Chen       
 ICS4U1-02       
 Assignment #2: Grades Assignment  
--------------------------- */

#include <iostream>
#include <iomanip>
using namespace std;

//functions to calculate grades
void homework(double &finalHomeworkMark);

void midtermExam(double &midtermExamMark);

void finalExam(double &finalExamMark, double &courseGrade);

int main() {
  
  double finalHomeworkMark;
  double midtermExamMark;
  double finalExamMark;
  double courseGrade = 0;
  
  //set the values to have decimal place of 2 for every output
  cout << fixed << setprecision(2); 
  homework(finalHomeworkMark);
  midtermExam(midtermExamMark);
  
  //calculates course grade if student has not taken final exam
  courseGrade += finalHomeworkMark + midtermExamMark;
  finalExam(finalExamMark, courseGrade);
  
  //calculates course grade if student has not taken final exam
  courseGrade += finalExamMark;
    
  
}

//homework function
void homework(double &finalHomeworkMark) {
  double weight;
  int homeworkAssignments;
  double homeworkScore = 0;
  double maxScore = 0;

  //take in user input
  cout << "Homework: " << endl;
  cout << endl;
  cout << "   What is its weight (0-100)? ";
  cin >> weight;
  cout << "   How many homework assignments were there? ";
  cin >> homeworkAssignments;

  //for loop to take in the amount of homework assignements the student has done
  for (int i = 1, temp1, temp2; i <= homeworkAssignments; i++) {
     cout << "   Homework " << i << " score and max score: ";

    //creates two variables to store values and add to each other for each homework score and max input every time the for loop iterates
     cin >> temp1 >> temp2;
     homeworkScore += temp1;
     maxScore += temp2;
  }

  //calculates the final homework mark for the student
    finalHomeworkMark = (homeworkScore / maxScore) * weight;
    cout << "   Weighted homework score: " << finalHomeworkMark << endl;
}

//midterm exam function
void midtermExam(double &midtermExamMark) {
  double weight;
  double examScore = 0;
  double isCurve;
  double curve;
  double isFinalExam;
  cout << endl;

  //take in user input
  cout << "Midterm Exam: " << endl;
  cout << endl;
  cout << "   What is its weight (0-100)? ";
  cin >> weight;
  cout << "   Exam Score: ";
  cin >> examScore;
  cout << "   Was there a curve? (1 for yes, 2 for no) ";
  cin >> isCurve;

    //condition for yes curve
    if (isCurve == 1) {
      cout << "   How much was the curve? ";
      cin >> curve;
      examScore += curve;

      //checks if exam score is above 100 with curve and if yes set the score to 100 
      if (examScore > 100) {
        midtermExamMark = 100*(weight/100);
        cout << "   Weighted exam score: " << midtermExamMark << endl;
      }
      else {
        midtermExamMark = (examScore + curve)*(weight/100);
        cout << "   Weighted exam score: " << midtermExamMark << endl;
      }
    }
    //condition for no curve 
    if (isCurve == 2) {
     midtermExamMark = examScore*(weight/100);
     cout << "   Weighted exam score: " << midtermExamMark << endl; 
    }
}
  
void finalExam (double &finalExamMark, double &courseGrade) { 
  double isCurve;
  double curve;
  double isFinalExam;
  double weight;
  double desiredScore;
  double examScore;
  double neededScore = 0;
  double highestPossibleMark = 0;
  cout << endl;

  //take in input for user's stats
  cout << "Final Exam: " << endl;
  cout << endl;
  cout << "   Have you taken the final exam yet? (1 for yes, 2 for no) ";
  cin >> isFinalExam;
  if (isFinalExam == 1) {  
    cout << "   What is its weight (0-100)? ";
    cin >> weight;
    cout << "   Exam Score: ";
  cin >> examScore;
  cout << "   Was there a curve? (1 for yes, 2 for no) ";
  cin >> isCurve;

    //if there is a curve
    if (isCurve == 1) {
      cout << "   How much was the curve? ";
      cin >> curve;
      finalExamMark = examScore + curve;
      if (finalExamMark > 100) {

        // Cap the final exam score at 100 if above 100 with curve
        finalExamMark = 100;  
      }

      //calculate final exam mark
      finalExamMark *= (weight / 100.0); 
      cout << "   Weighted exam score: " << finalExamMark << endl;

      //calculate course grade mark
      courseGrade += finalExamMark;
      cout << endl;
      cout << "   Your course grade is " << courseGrade << endl;
    }
    //if there is no curve
    else if (isCurve == 2) {
      //calculate final exam mark (with weight)
      finalExamMark = examScore * (weight / 100.0); 
      cout << "   Weighted exam score: " << finalExamMark << endl; 
    }
  }

  //if there is no curve
  if (isFinalExam == 2) {
    cout << "   What is its weight (0-100)? ";
    cin >> weight;
    cout << "   What percentage would you like to earn in the course? ";
    cin >> desiredScore;
    cout << endl;

    //calculates the needed score based on the student's current stats
    neededScore = (100*(desiredScore - courseGrade))/weight;

    //condition for if needed score is above 100 
    if (neededScore > 100) {

      //prints out the neededScore even if above 100 for final exam
      cout << "   You need a score of " << neededScore << " on the final exam. " << endl;

      //set neededScore to 100 for realistic calculation
      neededScore = 100;

      //calculate the realistic grade possible with the needed score and desired grade
      highestPossibleMark += (neededScore*(weight/100)) + courseGrade;

      //lets the user know that if the needed score is above 100, it's impossible to get that grade the user wants
      cout << "   Sorry, it is impossible to achieve this percentage. " << endl;
      cout << "   The highest percentage you can get is " << highestPossibleMark << endl;
    }

    //condition for if needed score is less than 0 based on the user's stats
    else if (neededScore < 0) {
    cout << endl;
    neededScore = 0;
    cout << "   You need a score of " << neededScore << " on the final exam. " << endl;
    }
      
    //condition for if needed score is realistic based on the user's stats
    else {
    cout << endl;
      cout << "   You need a score of " << neededScore << " on the final exam. " << endl;
    }
    
  }
}

  