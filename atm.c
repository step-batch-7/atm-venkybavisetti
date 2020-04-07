#include <stdio.h>
#include "atm.h"

unsigned int get_money(RS money)
{
  RS balance = money;
  rupee denominations = DENOMINATION_LIST;
  unsigned int denomination_count = 0x0;

  for (int index = 0; index < 8 && money <= ATM_LIMIT; index++)
  {
    denomination_count <<= 4;
    denomination_count |= (balance / denominations[index]);
    balance %= denominations[index];
  }
  return denomination_count;
}

void display_notes(unsigned int notes)
{
  unsigned int masking_value = 0x10000000;
  rupee denominations = DENOMINATION_LIST;

  for (int index = 0; index < 8; index++)
  {
    int note_count = notes / masking_value;
    note_count &&printf("%2d notes of Rs. %d\n", note_count, denominations[index]);
    notes %= masking_value;
    masking_value >>= 4;
  }
}