#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    Add song nodes.
    Search for a song given song and artist name (return a pointer).
    Search for an artist (return a pointer).
    Print out all the entries under a certain letter.
    Print out all the songs of a certain artist
    Print out the entire library.
    Shuffle - print out a series of randomly chosen songs.
    Delete a song
    Delete all the nodes.
*/

struct song * lib[26];

void print_all()
{
  printf("\n======MUSIC LIBRARY======: \n");
  int letter = 0;
  char output;
  while (letter < 26) {
    output = letter + 97;
    if (lib[letter]) {
      printf("%c list\n", output);
      print_list(lib[letter]);
    }
    letter++;
  }
  printf("\n============================\n");
}

void remove_all()
{
  int letter;
  for (letter = 0; letter < 26; letter++) {
    free_all(lib[letter]);
  }
}


void add_song(char name[256], char art[256])
{
  int letter = name[0] - 97;
  //  printf("%d\n", letter);
  lib[letter] = order_insert(lib[letter], name, art);
  //  print_list(lib[letter]);
}

