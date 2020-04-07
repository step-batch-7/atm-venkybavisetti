#include <stdio.h>
#include "atm.h"

unsigned int get_money(unsigned short int money)
{
  unsigned short int balance = money;
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};
  unsigned int denomination_count = 0x0;

  for (int index = 0; index < 8 && money < 32000; index++)
  {
    denomination_count <<= 4;
    denomination_count = denomination_count | (balance / denominations[index]);
    balance = balance % denominations[index];
  }
  return denomination_count;
}

void display_notes(unsigned int notes)
{
  unsigned int masking_value = 0x10000000;
  int denominations[] = {2000, 500, 100, 50, 20, 10, 5, 1};

  for (int index = 0; index < 8; index++)
  {
    int note_count = notes / masking_value;
    note_count &&printf("%2d notes of Rs. %d\n", note_count, denominations[index]);
    notes %= masking_value;
    masking_value >>= 4;
  }
}