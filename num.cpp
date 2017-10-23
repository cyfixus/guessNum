/******************************************************************************
 * Author: Sean Foster                                                <num.cpp>
 * Date: 10/23/2017
 * Description: Asks the player to think of a number from 1 to 31 then presents
 *              five cards, shuffled, to the player. If the player indicates
 *              the presence of the number, the appropriate bit is toggled. The
 *              end result of the toggled bits is the player's number.
******************************************************************************/
#include "menu.hpp"
#include <algorithm>
#include <random>
#include <chrono>
#include <array>


/******************************************************************************
 * cardStrings returns the corresponding cardString
******************************************************************************/
string cardStrings(int card)
{
  string cardA = "\nDo you see your number below?"
              "\n1\t3\t5\t7"
              "\n9\t11\t13\t15"
              "\n17\t19\t21\t23"
              "\n25\t27\t29\t31\n"
              "\nType 1 for yes, 2 for no\n\n";
  string cardB = "\nDo you see your number below?"
              "\n2\t3\t6\t7"
              "\n10\t11\t14\t15"
              "\n18\t19\t22\t23"
              "\n26\t27\t30\t31\n"
              "\nType 1 for yes, 2 for no\n\n";
  string cardC = "\nDo you see your number below?"
              "\n4\t5\t6\t7"
              "\n12\t13\t14\t15"
              "\n20\t21\t22\t23"
              "\n28\t29\t30\t31\n"
              "\nType 1 for yes, 2 for no\n\n";
  string cardD = "\nDo you see your number below?"
              "\n8\t9\t10\t11"
              "\n12\t13\t14\t15"
              "\n24\t25\t26\t27"
              "\n28\t29\t30\t31\n"
              "\nType 1 for yes, 2 for no\n\n";
  string cardE = "\nDo you see your number below?"
              "\n16\t17\t18\t19"
              "\n20\t21\t22\t23"
              "\n24\t25\t26\t27"
              "\n28\t29\t30\t31\n"
              "\nType 1 for yes, 2 for no\n\n";
  switch(card)
  {
    case 0:
      return cardA;
    case 1:
      return cardB;
    case 2:
      return cardC;
    case 3:
      return cardD;
    case 4:
      return cardE;
  }
  return cardA;
}

/******************************************************************************
 * checkCard calls the menu on the card string to gather whether or not the 
 * player's number is on a particular card.
******************************************************************************/
int checkCard(int card)
{
  int present = 0;
  string cardContents = cardStrings(card);
  if(menu(cardContents,2) == 1)
  {
    present = 1;
  }
  return present;
}


/******************************************************************************
 * gameLoop provides the player instructions, then shuffles the array of
 * cards to present them in a random order to the player. The secret number
 * starts at 0 and is successively OR'd with the appropriate int representation
 * of the bit place. The result of checking each of appropriately toggling the
 * first five bit places will result arriving at the player's number. 
******************************************************************************/
void gameLoop()
{
  bool playAgain = true;
  while(playAgain)
  {
    std::cout << "\nThink of a number between 1 and 31\nYou will be shown some"
                 " cards with numbers on them, and be asked whether or not the"
                 " number you've chosen is present among the 16 visible\n\n";
    std::cout << "\nPress any key when ready.\n";
    std::string cont;
    std::getline(std::cin, cont);
    std::array<int,5> cards {0,1,2,3,4};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (cards.begin(), cards.end(), std::default_random_engine(seed));
    int secretNum = 0;
    for(int &i : cards)
    {
      if(checkCard(i) == 1)
        switch(i)
      {
        case 0:
          secretNum |= 1;
          break;
        case 1:
          secretNum |= 2;
          break;
        case 2:
          secretNum |= 4;
          break;
        case 3:
          secretNum |= 8;
          break;
        case 4:
          secretNum |= 16;
          break;
      }
    }
    std::cout << "\nI've figured it out...\n\n\tYour number was: " 
              << secretNum << std::endl;
    int choice = menu("\nWould you like to play again?\n1: yes\n2: no\n", 2);
    if(choice ==2)
      playAgain = false;
  }
}

/******************************************************************************
 * calls the gameLoop
******************************************************************************/
int main()
{
  gameLoop();
  return 0;
}