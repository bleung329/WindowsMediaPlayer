#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"
#include "library.h"

int main() {

  // printf("\nAdding:\nrunning with the wolves by aurora\nconqueror by aurora\nseven by catfish and the bottlemen\ndown the line by beach fossils\nwoods by black marble\nkong by bonobo\n");

  printf("\nTESTING ARRAY OF LINKED LISTS FUNCTIONS\n");
  printf("=========================================================\n");

  
  char * song = "running with the wolves";
  char * artist = "aurora";
  add_song(song, artist);

  song = "conqueror";
  artist = "aurora";
  add_song(song, artist);
    
  song = "seven";
  artist = "catfish and the bottlemen";
  add_song(song, artist);

  song = "down the line";
  artist = "beach fossils";
  add_song(song, artist);

  song = "woods";
  artist = "black marble";
  add_song(song, artist);

  song = "kong";
  artist = "bonobo";
  add_song(song, artist);

  printf("\ntesting print_all.....");
  print_all();

  printf("\nall artists of a?\n");
  print_letter('a');

  printf("\nall artists of b?\n");
  print_letter('b');

  printf("\nall songs of aurora?\n");
  artist = "aurora";
  print_art(artist);
  
  printf("\ntesting shuffled playlist.....\n");
  shuffle(3);
  
  struct song * selected;
  printf("\ntesting find_song: woods by black marble......\n");
  song = "kong";
  artist = "bonobo";
  selected = find_song(song, artist);
  if (selected) {
    printf("%s: %s\n", selected->artist, selected->name);
  }
  
  printf("\ntesting find_song: conquero by aurora......\n");
  song = "conquero";
  artist = "aurora";
  selected = find_song(song, artist);
  if (selected) {
    printf("%s: %s\n", selected->artist, selected->name);
  }

  printf("\ntesting remove_song: kong by bonobo.....");
  remove_song("kong","bonobo");
  print_all();
  
  printf("\nemptied.");
  remove_all();
  print_all();



}


