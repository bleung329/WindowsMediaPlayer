#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    DONE Add song nodes.
    DONE Search for a song given song and artist name (return a pointer).
    DONE Search for an artist (return a pointer).
    DONE Print out all the entries under a certain letter.
    DONE Print out all the songs of a certain artist
    DONE Print out the entire library.
    Shuffle - print out a series of randomly chosen songs.
    Delete a song
    DONE Delete all the nodes.
*/


//LE LIBRARY OFICIAL
struct song * lib[26];
int size;


//=====================PRINTING=========================

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

void print_letter(char letre)
{
  printf("\n%c list ------- \n", letre);
  int index = letre - 97;
  print_list(lib[index]);
  printf("-------------- \n");
}

//====================REMOVALS===========================

void remove_song(char name[256], char art[256])
{
	
}

void remove_all()
{
  int letter;
  for (letter = 0; letter < 26; letter++) {
    lib[letter] = free_all(lib[letter]);
  }
}


void add_song(char name[256], char art[256])
{
  int letter = art[0] - 97;
  //  printf("%d\n", letter);
  lib[letter] = order_insert(lib[letter], name, art);
  //  print_list(lib[letter]);
}

//================FIND==================

struct song * find_song(char name[256], char art[256])
{
  int letter = art[0]-97;
  struct song *temp = lib[letter];
  temp = find_node(temp, name, art);
  return temp;
}
struct song * find_artist(char art[256])
{
  int letter = art[0]-97;
  struct song *temp = lib[letter];
  temp = find_art(temp, art);
  return temp;
}