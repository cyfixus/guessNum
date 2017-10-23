/******************************************************************************
 * Author: Sean Foster                                          <validator.cpp>
 * Date: 10/15/2017
 * Description: Validates input string for int
******************************************************************************/
#include "validator.hpp"

/******************************************************************************
 * isValidInt takes in a string, and sets an iterator i to 0. this function 
 * accepts signed numbers by skipping the iterator ahead if the first 
 * character is the negative sign. each char of the string is iterated 
 * through,each char is validated as a digit, if neither, false is returned
******************************************************************************/
bool isValidInt(string checkString)
{
  int i = 0;
  if(checkString.at(i)=='-')
  {
    i++;
  }
  for(; i < (int)checkString.length(); i++)
  {
    if (!std::isdigit(checkString.at(i)))
    {
      return false;
    }
  }
  return true;
}

/******************************************************************************
 * getValidInt takes in a string, checks that its a valid int, then calls
 * std::stoi, to convert it to an int. caught exception returns -1
******************************************************************************/
int getValidInt(string checkString)
{
  int convertedInt = 0;
  if (isValidInt(checkString))
  {
    try{
      convertedInt = std::stoi(checkString, nullptr, 0);
      return convertedInt; 
    }
    catch (const std::out_of_range& oor)
    {
      return -1;
    }
  }
  return -1;
}