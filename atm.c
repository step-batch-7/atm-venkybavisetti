#include <stdio.h>
#include "atm.h"

unsigned int get_money(unsigned short int money)
{
  unsigned short int balance = money;
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned int denomination_count = 0x0;

  for (int index = 0; index < 8; index++)
  {
    denomination_count <<= 4;
    denomination_count = denomination_count | (balance / denominations[index]);
    balance = balance % denominations[index];
  }
  return denomination_count;
}
