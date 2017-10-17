#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node
{
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node* pter, char[256] nam, char[256] art)
{
  struct song_node * newthing = (struct song_node*)calloc(1,sizeof(song_node));
  newthing->artist = art;
  newthing->name = nam;
  newthing->next = pter;
  return newthing;
}


//return first node again with updated list
struct song_node * insert_place(struct song_node* pter, char[256] nam, char[256] art, int n)
{
  temp = pter;
  struct n
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
struct song_node * order_insert(struct song_node* pter, char[256] nam, char[256] art)
{

  int ctr = 0;
  // strcomp - + if first comes later; - if first comes before
  while (pter) {
    if (!strcomp(pter->artist, art)) {
	    
    }
    if (strcomp(pter->artist, art) < 0) {
	    
    }
    pter = pter->next
      }
  
}
