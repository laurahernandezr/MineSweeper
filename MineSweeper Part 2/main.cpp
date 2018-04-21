//
//  main.cpp
//  MineSweeper Part 2
//
//  Created by Laura Hernandez on 4/21/18.
//  Copyright © 2018 Laura Hernandez. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Board{
private:
    int size;
    int mines;
    char matrix[25][25];
public:
    Board(string difficulty){
        if(difficulty == "Beginner")
        {
            size = 9;
            mines = 10;
            
        }else if (difficulty == "Intermediate")
        {
            size = 16;
            mines = 40;
        } else if(difficulty == "Advanced")
        {
            size = 25;
            mines = 100;
        }
    }
    void createBoard()
    {
        //fills the board with points
        for (int j = 0; j<size; j++)
        {
            for (int i = 0; i<size; i++)
            {
                matrix[i][j] = '.';
                
            }
        }
        //fills the board with the bombs
        int rnumb= 0;
        int rnumb2= 0;
        for(int i= 0; i<mines;i++){
            rnumb = rand() % size;
            rnumb2= rand() % size;
            if(rnumb == 0)
                rnumb++;
            if (rnumb2 == 0)
                rnumb2++;
            if (matrix[rnumb][rnumb2] != '*') {
                matrix[rnumb][rnumb2] = '*';
            }else i--;
        }
    }
    
    void printBoard()
    {
        cout<<"  ";
        for (int z = 1; z<size+1; z++) {
            cout << setw(2)<< (char)(z+64);
        }
        cout<<endl;
        
        for(int y=0;y<size;y++)
        {
            cout<<setw(2)<<y+1;
            for(int x=0;x<size;x++)
            {
                cout << setw(2)<< matrix[x][y];
            }
            cout<<endl;
        }
        
    }
    
    
    
};

int main() {
    srand(time(0));
    int level;
    cout <<"Please select a level: 1 for Beginner, 2 for Intermediate and 3 for Advanced"<<endl;
    cin >> level;
    
    if (level == 1){
        Board vboard("Beginner");
        vboard.createBoard();
        vboard.printBoard();
        
    }else if (level == 2){
        Board v2board("Intermediate");
        v2board.createBoard();
        v2board.printBoard();
    }else if (level == 3){
        Board v3board("Advanced");
        v3board.createBoard();
        v3board.printBoard();
    }
    
    
    
    
    return 0;
}
