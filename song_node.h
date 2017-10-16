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

//Order by artist name
struct song_node * order_insert(struct song_node* pter, char[256] nam, char[256] art)
{

}
