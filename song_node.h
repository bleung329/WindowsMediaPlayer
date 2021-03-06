#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

/*
    DONE insert nodes at the front
    DONE insert nodes in order
    DONE print the entire list
    DONE find and return a pointer to a node based on artist and song name
    DONE find and return a pointer to the first song of an artist based on artist name
    DONE Return a pointer to random element in the list.
    DONE remove a single specified node from the list
    DONE free the entire list
*/

struct song
{
  char name[256];
  char artist[256];
  struct song *next;
};

int notSeeded;

//====================HELPERS===========================

//traverse through linked list while next is not null and print artist & name
void print_list(struct song * startpt)
{
  //	printf("\n--START--\n");
  while (startpt) {
    printf("%s: %s\n", startpt->artist, startpt->name);
    startpt = startpt->next;
  }
  //	printf("---END---\n");
}

/* traverse through list until you find a song by an artist. start new while
   loop and while it's not null and the artists are equal, print*/
void print_artist(struct song * startpt, char art[256])
{
  while (startpt) {
    if (!strcmp(startpt->artist, art)) {
      break;
    }
    startpt = startpt->next;
  }
  while (startpt && !strcmp(startpt->artist, art)) {
    printf("%s: %s\n", startpt->artist, startpt->name);
    startpt = startpt->next;
  }
}


//traverse through linked list until artist and name match given, then print
void print_node(struct song * startpt, char art[256], char nam[256])
{
  while (startpt) {
    if (!strcmp(startpt->artist, art) && !strcmp(startpt->name, nam)) {
      printf("%s: %s\n", startpt->artist, startpt->name);
      return;
    }
    startpt = startpt->next;
  }
}

//counts how many songs are in list
int list_count(struct song * startpt)
{
	int ctr = 0;
	while (startpt)
	{
		ctr+=1;
		startpt = startpt->next;
	}
	return ctr;
}


//====================INSERTIONS===========================

//create new node with given name & artist; set new's next to given first node
struct song * insert_front(struct song* pter, char nam[256], char art[256])
{
  //notifies rand_node that it should seed itself
  notSeeded = 1;
  struct song * newsong = (struct song*)malloc(sizeof(*pter));
  strcpy(newsong->artist, art);
  strcpy(newsong->name, nam);
  newsong->next = pter;
  return newsong;
}

//inserts node in alphabetically and returns the first node in the list
struct song * order_insert(struct song* pter, char nam[256], char art[256])
{
  // a leader and a follower
  struct song * temp1 = pter;
  struct song * temp2 = NULL;
  // STRCMP: - means it goes before, + means it goes after
  // goal: find the song in list that you know given song must go before
  while (temp1) {
    //if they're equal, look at song
    if (!strcmp(temp1->artist, art)) {
      if (strcmp(nam, temp1->name) < 0) {
	break;
      }
    } //if given song goes before,
    if (strcmp(art, temp1->artist) < 0) {
      break;
    }
    //housekeeping, to traverse through list
    temp2 = temp1;
    temp1 = temp1->next;
  }
  //temp2 exists -> insert new song before temp1 and as temp2's next
  //temp2 is null -> we're still at the beginning of list
  if (temp2) {
    temp2->next = insert_front(temp1, nam, art);
    return pter;
  } else {
    return insert_front(temp1, nam, art);
  }
}


//====================SEARCH FOR===========================

//traverse while not null, return pter if artist of pter match given
struct song * find_art( struct song * pter, char art[256])
{
  while (pter) {
    if (!strcmp(pter->artist, art)) {
      printf("Artist found.\n");
      return pter;
    }
    pter = pter->next;
  }
  printf("Artist not found.\n");
  return NULL;
}
  
// traverse while not null, return pter if name and artist of pter match given
struct song * find_node( struct song * pter, char nam[256], char art[256])
{ 
  while (pter) {
    if (!strcmp(pter->artist, art) && !strcmp(pter->name, nam)) {
      printf("Song found.\n");
      return pter;
    }
    pter = pter->next;
  }
  printf("Song not found.\n");
  return NULL;
}

//Returns random song from linked list
struct song * rand_node(struct song * pter)
{
  //seeds if something was inserted
  if (notSeeded) {
    srand(time(NULL));
    notSeeded = 0;
  }
  int list_len = list_count(pter);
  if (list_len) {
    int r = rand() % list_len;
    for (r; r; r--)
      {
	pter = pter->next;
      }
    return pter;
  } else {
    return NULL;
  }
}


//====================REMOVALS===========================

// remove a specific node in list
struct song * remove_node( struct song * pter, char nam[256], char art[256])
{
  //follower and leader again
  struct song * temp1 = pter;
  struct song * temp2 = NULL;
  //traverse while not null, compare their artists and names
  while (temp1) {
    if (!strcmp(temp1->artist, art) && !strcmp(temp1->name, nam)) {
      break;
    }
    //housekeeping to traverse
    temp2 = temp1;
    temp1 = temp1->next;
  }
  //both exist; right node exists and it's not first
  if (temp2 && temp1) {
    temp2->next = temp1->next;
    free(temp1);
  }
  //temp2 is the last node; right node was not found.
  else if (temp2) {
    printf("Not found.\n");
  }
  //temp2 is still NULL, you want to remove the first one
  else {
    temp2 = temp1->next;
    free(temp1);
    return temp2;
  }
  return pter;
}


// traverse through with a temp pointer to store next before freeing current
struct song * free_all(struct song * pter)
{
  struct song * temp1 = pter;
  while (pter) {
    temp1 = pter->next;
    free(pter);
    pter = temp1;
  }
  return pter;
}



