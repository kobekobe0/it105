#include <iostream>

using namespace std;

int main()
{
    int position[8][8] = 
        {
         {0,0,0,1,0,0,0,0},
         {0,0,0,0,1,0,0,0},
         {0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0},
         {0,0,0,0,0,0,0,0},
        };
        
    int queen1Column = 9;
    int queen1Row = 9;
    
    int queen2Column = 9;
    int queen2Row = 9;
        
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                if(position[i][j] == 1){
                    if(queen1Row != 9){
                        queen2Row = i+1;
                        queen2Column = j+1;
                        
                    } else {
                        queen1Row = i+1;
                        queen1Column = j+1;
                    }
                    
                }
            }
        };
        
        cout << "Q1Row: " << queen1Row << endl;
        cout << "Q1Col: " << queen1Column << endl;
        cout << endl;
        cout << "Q2Row: " << queen2Row << endl;
        cout << "Q2Col: " << queen2Column << endl;
        cout << endl;
        
        if(queen1Row == queen2Row){
            cout << "Can be captured";
        }else if(queen1Column == queen2Column){
            cout << "Can be captured";
        }else if (queen1Column - queen1Row == queen2Column - queen2Row || queen1Column + queen1Row == queen2Column + queen2Row){
            cout << "Can be captured diagonally";
        }else{
            cout << "Can't be captured";
        }
        
        
    return 0;
}