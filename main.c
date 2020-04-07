#include <stdio.h>
#include "atm.h"

int main(void)
{
  unsigned short int amounts[] = {1, 10, 39, 589, 2590, 31999};

  for (int i = 0; i < 6; i++)
  {
    unsigned int notes = get_money(amounts[i]);
    printf("Amount you have entered is:- %u\n", amounts[i]);
    display_notes(notes);
    printf("\n");
  }

  return 0;
}
