#include <iostream>
#include <string>

using namespace std;

bool Validator(int caseNum, float score){
    switch(caseNum){
        case 1:
            if(score > 50 || score < 0){
                return false;
            }
            return true;
        case 2:
            if(score > 60 || score < 0){
                return false;
            }
            return true;
        case 3:
            if(score > 90 || score < 0){
                return false;
            }
            return true;
    }
    return 0;
}

float Quiz(float score) {
      float temp = (((score/50)*50)+50) * 0.2;
      return temp;    
}

float Midterm(float score){   
    float temp = ((score/60)*50+50) * 0.4;
    return temp;    
}

float Lab(float score){  
      float temp = ((score/90)*50+50) * 0.4;  
      return temp;
}

float ValidatorCallback (int validatorCase, float& score, bool loop, string typeTest){
    if(Validator(validatorCase, score) == false){
        loop = true;
        do{
          cout << "Please enter valid " << typeTest << " score: ";
          cin >> score;
          if(!Validator(validatorCase, score)){
              continue;
          } else {
              loop = false;
          }
        } while(loop);
    }
    return 0;
}

float Add(float quiz, float mid, float lab){
    return quiz + mid + lab;
}

float Convert(float finaScore){
    if(finaScore >= 97){
        return 1.0;
    }
    else if(finaScore >= 94){
        return 1.25;
    }
    else if(finaScore >= 91){
        return 1.50;
    }
    else if(finaScore >= 88){
        return 1.75;
    }
    else if(finaScore >= 85){
        return 2.0;
    }
    else if(finaScore >= 82){
        return 2.25;
    }
    else if(finaScore >= 79){
        return 2.50;
    }
    else if(finaScore >= 76){
        return 2.75;
    }
    else if(finaScore >= 74.5){
        return 3.0;
    } else {
        return 5.0;
    }
    
}

int main()
{
    Calculate:
        float quizScore, midScore, labScore, quizRate, midRate, labRate;
        bool loop;
        bool ask = true;

        cout << "Quiz score: ";
        cin >> quizScore;
        ValidatorCallback(1, quizScore, loop, "quiz");
        quizRate = Quiz(quizScore);
        
        cout << "Midterm score: ";
        cin >>midScore;
        ValidatorCallback(2, midScore, loop, "midterm exam");
        midRate = Midterm(midScore);
        
        cout << "Laboratory Activity score: ";
        cin >> labScore;
        ValidatorCallback(3, labScore, loop, "laboratory activity");
        labRate = Lab(labScore);
        
        cout << " " << endl;

        float finalGrade = Add(quizRate, midRate, labRate);
        cout <<"Computed grade: "<< finalGrade << endl;
        cout <<"Grade equivalent: "<< Convert(finalGrade) << endl;
        
        int choice;
        askRepeat:
            cout<< " " << endl;
            cout<< "Do you want to compute your grade again?" << endl;
            cout<< "press [1] = YES" << endl;
            cout<< "press [0] = NO" << endl;
            cin >> choice;
            
            if(choice == 1){
                goto Calculate;
            } else if (choice == 0){
                return EXIT_SUCCESS;
            } else {
                cout << "Invalid response!";
                goto askRepeat;
            }

    
    return EXIT_SUCCESS;
}
