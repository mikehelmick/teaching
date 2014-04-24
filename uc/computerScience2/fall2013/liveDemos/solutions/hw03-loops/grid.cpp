/**   @file grid.cpp    
      @author Paul Talaga     
      @date 09-23-2013      
      @version 0.2   
      
      This program asks the user for the dimensions of a grid, then prints the 
      board to the screen using ASCII characters: +, |, and -.
      
      */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void printRow(int width, double colwidth, char del, char middle){
  int colnum = 0;
  for(int x = 0; x < width; x++){
    if(x  == 0 || x == width -1 || (int)floor((double)colnum * colwidth) < x){
      cout << del;
      colnum++;
    }else{
      cout << middle;
    }
  }
}

int main(){
 cout << "Enter your desired width and height of the board in characters, separated by a space.:";
 int width;
 int height;
 cin >> width;
 cin >> height;
 
 cout << "\nHow many columns and rows do you want?  Separate by a space.:";
 int cols;
 int rows;
 cin >> cols;
 cin >> rows;
 
 double colwidth = (double)(width-2) / (double)cols;  // Bug in previous code had -1
 double rowheight = (double)(height-2) / (double)rows;// Bug in previous code had -1
 int rownum = 0;
 
 cout << endl << endl;
 for(int y = 0; y < height; y++){
  if(y  == 0 || y == height -1 || (int)floor((double)rownum * rowheight) < y){
    printRow(width, colwidth, '+', '-');
    rownum++;
  }else{
    printRow(width, colwidth, '|', ' ');
  }
  cout << endl;
 }
  
  
  
  return 0;
}
