#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct shop
{
  int nos;
  string name;
};

class shopping
{
private:
  vector < shop > v;
public:
  void AddItem ();
  void DeleteItem ();
  void EditQuant ();
  void PrintList ();
  void Menu ();
};

void
shopping::AddItem ()
{
  cout <<endl<< "What is the name of the item you would like to add? Enter here:" <<
    endl;
  string s;
  cin.ignore ();
  getline (cin, s);
  cout << "What quantity do you need(Whole numbers only please!): " << endl;
  int n;
  cin.clear ();
  cin >> n;
  cout << "Ok. Adding this item to your list. Processing..." << endl;
  shop temp;
  temp.name = s;
  temp.nos = n;
  v.push_back (temp);
  cout << "Item added to the list." << endl;
}

void
shopping::PrintList ()
{
  if (v.size () == 0)
    {
      cout <<endl<< "Your list is empty. Would you like to add something?(Y/N)" <<
    endl;
      char a;
      cin >> a;
      if (a == 'Y')
    {
      AddItem ();
    }
      else
    {
      cout << "Taking you back to the menu. " << endl;
    }
    }
  else
    {
      cout << "Printing your list now: " << endl;
      cout << "S.no" << "\t\t\t\t\t\t\t" << "Item name" << "\t\t\t\t\t\t\t" <<
    "Quantity" << endl;
      cout << endl;
      for (unsigned int i = 0; i < v.size (); i++)
    {
      cout << i +
        1 << "\t\t\t\t\t\t\t" << v[i].name << "\t\t\t\t\t\t\t" << v[i].
        nos << endl << endl;
    }
    }
}

void
shopping::Menu ()
{
  cout << endl << endl <<
    "What would you like to do next? Here are your options: " << endl;
  cout << "a. Add an item to my list" << endl;
  cout << "b. Delete an item from my list" << endl;
  cout << "c. Edit an item's quantity" << endl;
  cout << "d. Print my list" << endl;
  cout << "e. I'm done! Show me my final list" << endl;
}

void
shopping::DeleteItem ()
{

  cout <<
    "What is the name of the item you want to delete?(Make sure to enter it in the same case as on your list: "
    << endl;
  string s;
  cin.ignore ();
  getline (cin, s);
  cin.clear ();
  unsigned int count;
  count = 0;
  cout << "Searching your list..." << endl;
  for (unsigned int i = 0; i < v.size (); i++)
    {
      count++;
      if (v[i].name == s)
    {
      v.erase (v.begin () + i);
      cout << "Item has been deleted. " << endl;
      break;
    }
    }
  if (count == v.size ())
    {
      cout << "Item not found. Do you want to try again?(Y/N)" << endl;
      char a;
      cin >> a;
      if (a == 'Y')
    {
      DeleteItem ();
    }
      else
    {
      cout << "Taking you back to the menu. " << endl;
    }
    }

}

void
shopping::EditQuant ()
{
  cout <<
    "For what item do you want to alter the quantity for? Enter here as is on the shopping list: "
    << endl;
  string s;
  cin.ignore ();
  getline (cin, s);
  cin.clear ();
  unsigned int count;
  count = 0;
  cout << "Searching your list..." << endl;
  for (unsigned int i = 0; i < v.size (); i++)
    {
      count++;
      if (v[i].name == s)
    {
      cout <<
        "What is the new quantity you want to put? Enter it in a whole number here: "
        << endl;
      int a;
      cin >> a;
      cout << "Great. Editing your quantity for you..." << endl;
      cout << "Item quantity edited. Taking you back to your menu. " <<
        endl;
      v[i].nos = a;
      break;
    }
    }
  if (count == v.size ())
    {
      cout << "Item not found. Do you want to try again?(Y/N)" << endl;
      char a;
      cin >> a;
      if (a == 'Y')
    {
      EditQuant ();
    }
      else
    {
      cout << "Taking you back to the menu. " << endl;
    }
    }

}

int
main ()
{
  cout << "Welcome to your shopping list! Enter your name here: " << endl;
  string name;
  cin.ignore ();
  getline (cin, name);
  cin.clear ();
  shopping n;
  bool loop;
  loop = true;
  while (loop)
    {
      n.Menu ();
      char a;
      cin >> a;
      switch (a)
    {
    case 'a':
      {
        n.AddItem ();
        break;
      }
    case 'b':
      {
        n.DeleteItem ();
        break;
      }
    case 'c':
      {
        n.EditQuant ();
        break;
      }
    case 'd':
      {
        n.PrintList ();
        break;
      }
    case 'e':
      {
        cout << "Here is your final list" << endl;
        n.PrintList ();
        cout << "Are you sure there is nothing you want to change?(Y/N)"
          << endl;
        char a;
        cin >> a;
        if (a == 'Y')
          {
        cout <<
          "Thank you for using the shopping list. Have a good day :-)"
          << endl;
        loop = false;
          }
      }

    }
    }


  return 0;
}
