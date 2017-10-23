#include "menu.hpp"
#include <algorithm>
#include <random>
#include <chrono>
#include <array>

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


int main()
{
  bool playAgain = true;
  while(playAgain)
  {
    std::cout << "\nThink of a number between 1 and 31\nYou will be shown some"
                 " cards with numbers on them, and be asked whether or not the"
                 " number you've chosen is present among the 16 visible\n\n";
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
  return 0;
}