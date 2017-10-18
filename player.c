#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

struct song_node * free_all(struct song_node * pter)
{
  struct song_node * temp1 = pter;
  while (pter) {
    temp1 = pter->next;
    free(temp1);
    pter = temp1;
  }
  return pter;
}

int main() {
  struct song_node * playlist;
  playlist =

    

}

