#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song
{
  char name[256];
  char artist[256];
  struct song *next;
};


//traverse through linked list while next is not null and print artist & name
void print_list(struct song * startpt)
{
	printf("\n--START--\n");
	while (startpt)
	{
	  printf("\nArtist: %s\nName: %s\n", startpt->artist, startpt->name);
		startpt = startpt->next;
	}
	printf("---END---\n");
}


//====================INSERTIONS===========================

//create new node with given name & artist; set new's next to given first node
struct song * insert_front(struct song* pter, char nam[256], char art[256])
{
  struct song * newsong = (struct song*)malloc(sizeof(*pter));
  strcpy(newsong->artist, art);
  strcpy(newsong->name, nam);
  newsong->next = pter;
  return newsong;
}

//return the first node in the list
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

//====================INSERTIONS===========================



//====================SEARCH FOR===========================

struct song * find_node( struct song *startpt,char artist[256], char nam[256])
{
	struct song *temp = startpt;
	

}

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
