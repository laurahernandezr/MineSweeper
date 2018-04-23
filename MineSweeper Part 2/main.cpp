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
    void createBoard(bool realBoard)
    {
        //fills the board with points
        for (int j = 0; j<size; j++)
        {
            for (int i = 0; i<size; i++)
            {
                real[i][j] = '.';
                playable[i][j] = '.';
                
            }
        }
        //fills the board with the bombs
        if (realBoard == true)
        {
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
                }
                else i--;
            }
        }
        //fills the board with numbers
        
        //adjacent numbers
        for (int j = 0; j<size; j++)
        {
            for (int i = 0; i<size; i++)
            {
                adjacent[i][j] = real[i][j];
                
            }
        }
        for (int i = 0; i<size; i++)
        {
            int x = (minesList[i][0]);
            int y =(minesList[i][1]);
            
                    if (x != 0) {
                        if (adjacent[x-1][y] != '*')
                        {
                            adjacent[x-1][y] = '0'+ 1;
                        }
                        //adjacent[(minesList[i][0]-1)][(minesList[i][1])-1] = '0'+ 1;
                        //adjacent[(minesList[i][0])+1][(minesList[i][1])-1] = '0'+ 1;
                    }
                    if (x!= size)
                    {
                          if (adjacent[x+1][y] != '*')
                          {
                                adjacent[x+1][y] = '0'+ 1;
                          }
                        //adjacent[(minesList[i][0])-1][(minesList[i][1])+1] = '0'+ 1;
                        //adjacent[(minesList[i][0])+1][(minesList[i][1])+1] = '0'+ 1;
                    }
                    if (y != 0)
                    {
                        if (adjacent[x][y-1] != '*')
                        {
                            adjacent[x][y-1] = '0'+ 1;
                        }
                        //adjacent[(minesList[i][0])-1][(minesList[i][1])-1] = '0'+ 1;
                        //adjacent[(minesList[i][0])-1][(minesList[i][1])+1] = '0'+ 1;
                    }
                    if (y != size)
                    {
                        if (adjacent[x][y+1] != '*')
                        {
                            adjacent[x][y+1] = '0'+ 1;
                        }
                        //adjacent[(minesList[i][0])+1][(minesList[i][1])-1] = '0'+ 1;
                        //adjacent[(minesList[i][0])+1][(minesList[i][1])+1] = '0'+ 1;
                        
                    }
            }
    }
        
    
    void printBoard(bool realBoard)
    { // prints number up
        cout<<"  ";
        for (int z = 0; z<size; z++) {
            cout << setw(2)<< z;
        }
        cout<<endl;
        // prints the actual board
        if (realBoard == true)
        {
            for(int y=0;y<size;y++)
            {
                //prints the numbers down
                cout<<setw(2)<<y;
                for(int x=0;x<size;x++)
                {
                    cout << setw(2)<< real[x][y];
                }

                cout<<endl;
                
            }
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
            // prints number up
            cout<<endl;
            cout<<"  ";
            for (int z = 0; z<size; z++) {
                cout << setw(2)<< z;
            }
             cout<<endl;
        //print adjacent
            for(int y=0;y<size;y++)
            {
    
                //prints the numbers down
                cout<<setw(2)<<y;
                for(int x=0;x<size;x++)
                {
                    cout << setw(2)<< adjacent[x][y];
                }
                
                cout<<endl;
            }
        }

        // prints the just playable
        else if (realBoard == false)
        {
            for(int y=0;y<size;y++)
            {
                cout<<setw(2)<<y+1;
                for(int x=0;x<size;x++)
                {
                    cout << setw(2)<< playable[x][y];
                }
                cout<<endl;
            }
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
        Board vboard("Beginner");
        vboard.createBoard(true);
        vboard.printBoard(true);
    }
    else if (level == 2)
    {
        Board v2board("Intermediate");
        v2board.createBoard(true);
        v2board.printBoard(true);
    }
    else if (level == 3)
    {
        Board v3board("Advanced");
        v3board.createBoard(true);
        v3board.printBoard(true);
    }
    return 0;
}
