#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    DONE Add song nodes.
    DONE Search for a song given song and artist name (return a pointer).
    DONE Search for an artist (return a pointer).
    DONE Print out all the entries under a certain letter.
    Print out all the songs of a certain artist
    DONE Print out the entire library.
    Shuffle - print out a series of randomly chosen songs.
    DONE Delete a song
    DONE Delete all the nodes.
*/


//LE LIBRARY OFICIAL
struct song * lib[26];
//int size = 0;


//=====================PRINTING=========================

//traverse through all the indices, calling print_list
void print_all()
{
  printf("\n======MUSIC LIBRARY======: \n");
  int letter = 0;
  char output;
  while (letter < 26) {
    output = letter + 97;
    if (lib[letter]) {
      printf("\n%c---\n", output);
      print_list(lib[letter]);
    }
    letter++;
  }
  printf("\n=========================\n");
}

//go straight to corresponding index, call printlist
void print_letter(char letre)
{
  printf("\n%c list ------- \n", letre);
  int index = letre - 97;
  print_list(lib[index]);
  printf("-------------- \n");
}

void print_art(char art[256])
{
  printf("\n%s list ------- \n", art);
  int index = art[0] - 97;
  print_artist(lib[index], art);
  printf("-------------- \n");
}

//====================REMOVALS & ADDS=======================


//go straight to proper index, call remove
void remove_song(char name[256], char art[256])
{
	lib[art[0]-97] = remove_node(lib[art[0]-97], name, art);
}

//move through each index, calling free_all
void remove_all()
{
  for (int letter = 0; letter < 26; letter++) {
    lib[letter] = free_all(lib[letter]);
  }
}

//go straight to proper index, call order_insert
void add_song(char name[256], char art[256])
{
  int letter = art[0] - 97;
  //  printf("%d\n", letter);
  lib[letter] = order_insert(lib[letter], name, art);
  //  print_list(lib[letter]);
}

//======================FIND==============================


//go straight to proper index, return pointer from find_node
struct song * find_song(char name[256], char art[256])
{
  int letter = art[0]-97;
  struct song *temp = lib[letter];
  temp = find_node(temp, name, art);
  return temp;
}

//go straight to proper index, return pointer from find_art
struct song * find_artist(char art[256])
{
  int letter = art[0]-97;
  struct song *temp = lib[letter];
  temp = find_art(temp, art);
  return temp;
}

//=================================SHUFFLE================
//Shuffle - print out a series of randomly chosen songs.

void shuffle(int len)
{
  printf("\nRandom playlist of length: %d\n",len);
  srand(time(NULL));
  //find total number of songs
  int total_songs = 0;
  for (int i=25;i>=0;i--) {
    total_songs+=list_count(lib[i]);
  }

  struct song *playpart;
  int r;

  //for length of playlist
  while (len--) {
    //random nth song
    r = rand() % total_songs;
    int index = 0;
    playpart = lib[index]; //start at first
    //traverse to rth number
    while (r) {
      //if playpart is not null
      if (playpart) {
	//go to next
	playpart = playpart->next;
	r--; //count it
      } else {
	playpart = lib[++index]; //don't count it, move to next letter
      }
    }
    //you ended the loop, perhaps on a NULL, if not, print.
    if (playpart) {
      printf("%s: %s\n", playpart->artist, playpart->name);
    } else {
      //if so, move to the next available song
      while (!playpart) {
	playpart = lib[++index];
      }
      printf("%s: %s\n", playpart->artist, playpart->name);
    }
  }

  
}
