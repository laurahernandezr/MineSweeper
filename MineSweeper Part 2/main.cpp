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
#include <vector>

using namespace std;
class Board{
private:
    int size;
    int mines;
    char real[25][25];
    char playable[25][25];
    char adjacent[25][25];
    int minesList[100][2];
public:
    Board(string difficulty)
    {
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
    
    void createBoards()
    {
        //fills the real and playable board with points and adjacent with zeros
        for (int j = 0; j<size; j++)
        {
            for (int i = 0; i<size; i++)
            {
                real[i][j] = '.';
                playable[i][j] = '.';
                adjacent[i][j] = '0';
                
            }
        }
        //fills the real board and the adjacent board with the bombs
            int rnumb= 0;
            int rnumb2= 0;
        for(int i= 0; i<mines;i++)
        {
            rnumb = rand() % size;
            rnumb2= rand() % size;
            minesList[i][0] = rnumb;
            minesList[i][1] = rnumb2;
            if (real[rnumb][rnumb2] != '*')
            {
                real[rnumb][rnumb2] = '*';
                adjacent[rnumb][rnumb2] = '*';
            }
            else i--;
        }
        //fills adjacent with numbers
        for (int i = 0; i<mines; i++)
        {
            int x = (minesList[i][0]);
            int y =(minesList[i][1]);
            char charT = adjacent[x][y];
            
            for (int posx = -1; posx < 2; posx++)
            {
                for (int posy = -1; posy < 2; posy++)
                {
                    charT = adjacent[x + posx][y + posy];
                    if (charT != '*')
                    {
                    adjacent[x + posx][y + posy] = charT + 1;
                        
                    }
                }
            }
            
        }
    }
        
    
    void printBoard(string type)
    {
        // prints number up
        cout<<endl;
        cout<<"   ";
        for (int z = 0; z<size; z++) {
            cout << setw(3)<< z;
        }
        cout<<endl;
        if (type == "real")
        {
        // prints real board
            for(int y=0;y<size;y++)
            {
                //prints the numbers down
                cout<<setw(3)<<y;
                for(int x=0;x<size;x++)
                {
                    cout << setw(3)<< real[x][y];
                }
                cout<<endl;
            }
        }
        else if (type == "adjacent")
        {
        //print adjacent
                for(int y=0;y<size;y++)
                {
                    //prints the numbers down
                    cout<<setw(3)<<y;
                    for(int x=0;x<size;x++)
                    {
                        cout << setw(3)<< adjacent[x][y];
                    }
                    cout<<endl;
                }
            }

        // prints playable
        else if (type == "playable")
        {
            for(int y=0;y<size;y++)
            {
                cout<<setw(3)<<y+1;
                for(int x=0;x<size;x++)
                {
                    cout << setw(3)<< playable[x][y];
                }
                cout<<endl;
            }
        }
    }
    void printMinesList(){
        //prints the number of the mines list
        cout<<endl;
        for(int y=0;y<2;y++)
        {
            for(int x=0;x<mines;x++)
            {
                cout << setw(2)<< minesList[x][y];
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
    
    if (level == 1)
    {
        Board Bboard("Beginner");
        Bboard.createBoards();
        Bboard.printBoard("playable");
        Bboard.printBoard("real");
        Bboard.printMinesList();
        Bboard.printBoard("adjacent");
    }
    else if (level == 2)
    {
        Board Iboard("Intermediate");
        Iboard.createBoards();
        Iboard.printBoard("playable");
        Iboard.printBoard("real");
        Iboard.printMinesList();
        Iboard.printBoard("adjacent");
    }
    else if (level == 3)
    {
        Board Aboard("Advanced");
        Aboard.createBoards();
        Aboard.printBoard("playable");
        Aboard.printBoard("real");
        Aboard.printMinesList();
        Aboard.printBoard("adjacent");
    }
    return 0;
}
