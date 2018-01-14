#include <iostream>
#include <iomanip>
#include <cmath>
#include "triangle.h"
using namespace std;

Triangle::Triangle()
{
   sideLength = 1;
   border = '#';
   fill = '*';
}

Triangle::Triangle(int length, char borderChar, char fillChar)
{
   if(length < 1)
      sideLength = 1;
   else  if(length > 39)
      sideLength = 39;
   else
       sideLength = length;


   if(borderChar < '!' || borderChar > '~')
      border = '#';
   else
      border = borderChar;


   if(fillChar < '!' || fillChar > '~')
      fill = '*';
   else
      fill = fillChar;
}

int Triangle::GetSize() const
{
   return sideLength;
}

int Triangle::Perimeter() const
{
   return (sideLength * 3);
}

double Triangle::Area() const
{
   cout << fixed;
   cout << setprecision(2);
   return ((sqrt(3)/4) * (sideLength * sideLength));
}

void Triangle::Grow()
{
   if(sideLength < 39)
      sideLength += 1;
}

void Triangle::Shrink()
{
   if(sideLength > 1)
      sideLength -= 1;
}

void Triangle::SetBorder(char b)
{
   if(b < '!' || b > '~')
      border = '#';
   else
      border = b;
}

void Triangle::SetFill(char f)
{
   if(f < '!' || f > '~')
      fill = '*';
   else
      fill = f;
}

void Triangle::Draw() const
{
   int i, space, j = 0, k = 0;

   for(i = 1; i <= sideLength - 1; i++)
   {
      for(space = 0; space < sideLength  - i; space++)
      {
         cout << " ";
      }
      while(j != i)
      {
         if(j == 0)
            cout << border  << " ";
         else if(j == i - 1)
            cout << border;
         else
            cout << fill <<  " ";
         j++;
      }
      j = 0;
      cout << endl;
   }
   while(k != sideLength)
   {
      cout << border << " ";
      k++;
   }
   cout << endl;
}

void Triangle::Summary() const
{
   cout << "Size of the triangle's side = " << sideLength << " units." << endl;
   cout << "Perimiter of triangle = " << Perimeter() << " units." << endl;
   cout << "Area of triangle = " << Area() << " units." << endl;
   cout << "Triangle looks like:" << endl;
   Draw();
   cout << endl;
}

