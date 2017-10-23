/******************************************************************************
 * Author: Sean Foster                                               <menu.cpp>
 * Date: 10/22/2017
 * Description: Menu function displays input string as options list. 
 *              optionCount ensures a valid selection can be returned.
******************************************************************************/
#include "menu.hpp"

int menu(string menuOptions, int optionCount)
{
  string choice = "";
  int selection = 0;
  bool invalidSelection = true;
  //loops until valid selection is made
  while(invalidSelection)
  {
    //print out the menu and get the choice
    std::cout << menuOptions; 
    std::cin >> choice;
    if(isValidInt(choice))
    {
      selection = getValidInt(choice);
      if(selection > 0 && selection <= optionCount)
      {
        //exits the loop
        invalidSelection = false;
      }
      else
      {
        if(std::cin)
        {
          std::cin.ignore();
        }    
      }
    }
  } 
  return selection;
}