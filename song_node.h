#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node
{
  char name[256];
  char artist[256];
  struct song_node *next;
};


struct song_node * insert_front(struct song_node* pter, char nam[256], char art[256])
{
  struct song_node * newthing = (struct song_node*)calloc(1,sizeof(*pter));
  strcpy(newthing->artist, art);
  strcpy(newthing->name, nam);
  newthing->next = pter;
  return newthing;
}


//return first node again with updated list
struct song_node * insert_place(struct song_node* pter, char nam[256], char art[256], int n)
{
  struct song_node * temp = pter;
  if (n == 0) {
    insert_front(pter, nam, art);
  }
  while (n - 1 > 0) {
    pter = pter->next;
    n--;
  }
  pter->next = insert_front(pter->next, nam, art);
  return temp;
  
}


//Order by artist name
//return the first node in the list
struct song_node * order_insert(struct song_node* pter, char nam[256], char art[256])
{
  int ctr = 0;
  struct song_node * temp = pter;
  // strcmp - + if first comes later; - if first comes before
  while (pter) {
    //if they're the same, ask about the song name
    if (!strcmp(pter->artist, art)) {
      if (strcmp(pter->name, nam) < 0) {
	return insert_place(temp, nam, art, ctr);
      }
    }
    //if this artist in the list goes after, then just insert newhere
    if (strcmp(pter->artist, art) < 0) {
      return insert_place(temp, nam, art, ctr);
    }
    //housekeeping
    pter = pter->next;
    ctr++;
  }
  //this is the end
  return insert_place(temp, nam, art, ctr);
}
