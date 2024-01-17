#include <iostream>
#include <limits>
#define PI 3.14
using namespace std;

/*
  validating data
  buffer - temporary array
*/

void initMenu();
void menuDecision(int);
double areaCircle(double);
double areaSquare(double);
double areaRectangle(double, double);
double areaTriangle(double, double);
bool isValid(string);
bool isValid();

int main()
{
  int choice;
  char cont;
  do {
    system("cls"); // clear screen
    initMenu();

    while(!(cin >> choice))
    {
      // cout << "state before: " << cin.rdstate() << endl;
      cin.clear();
      // cout << "state after: " << cin.rdstate() << endl;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      system("cls");
      initMenu();
      cout << "That is an invalid entry." << endl;
    }
    cin >> choice;

    menuDecision(choice);

    do {
      cout << "Do you want to continue the program? (Y/N)" << endl;
      cin >> cont;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      
    } while(cont !- 'y' && cont != 'Y' && cont != 'n' && cont != 'N');
  } while(cont == 'y' || cont == 'Y')
  return 0;
}

void initMenu()
{
  cout << "Enter option: " << endl;
  cout << "1. Circle" << endl;
  cout << "2. Square" << endl;
  cout << "3. Rectangle" << endl;
  cout << "4. Triangle \n" << endl;
}

void menuDecision(int choice)
{
  double r, a, b, h;
  switch(choice)
  {
    case 1:
      cout << "Enter the radius: " << endl;
      do {cin >> r} while(!isValid("The data entered is invalid. Please try again: "));
      areaCircle(r);
      break;
    case 2:
      cout << "Enter the side measurement of a square: " << endl;
      do {cin >> a} while(!isValid("The data entered is invalid. Please try again: "));
      areaSquare(a);
      break;
    case 3:
      cout << "Enter the width and height of a rectangle: " << endl;
      do {cin >> a >> b} while(!isValid("The data entered is invalid. Please try again: "));
      areaRectangle(a, b);
      break;
    case 4:
      cout << "Enter the base and height of a triangle: " << endl;
      do {cin >> a >> h} while(!isValid("The data entered is invalid. Please try again: "));
      areaTriangle(a, h);
      break;
    default:
      cout << "You didn't choose a valid option. Please review the menu and try again." << endl;
  }
}

double areaCircle(double r)
{
  double result = PI * r * r;

  cout << "The area of a circle with a radius of " << r << " = " << result << endl;

  return result;
}

double areaSquare(double a)
{
  double result = a * a;

  cout << "The area of a square with a side measurement of " << a << " = " << result << endl;

  return result;
}

double areaRectangle(double a, double b)
{
  double result = a * b;

  cout << "The area of a rectangle with a length of " << a << " and a width of " << b << " = " << result << endl;

  return result;
}

double areaTriangle(double a, double h)
{
  double result = (1 / 2.0) * a * h;

  cout << "The area of a triangle with a base of " << a << " and a height of " << h << " = " << result << endl;

  return result;
}

bool isValid(string error_msg) 
{
  if (cin.rdstate()) 
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls");
    initMenu();
    cout << error_msg << endl;
    return false;
  }

  return true;
}

bool isValid() 
{
  if (cin.rdstate()) 
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls");
    initMenu();
    return false;
  }

  return true;
}
