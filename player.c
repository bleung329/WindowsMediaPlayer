#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"
#include "library.c"

int main() {

  /*-------------LINKED LIST------------------------
  //  printf("%d\n", strcmp("abbae", "abble"));
  struct song library[25];
  
  struct song * playlist = NULL;
  char * song = "running with the wolves";
  char * artist = "aurora";
  playlist = order_insert(playlist, song, artist);
  print_list(playlist);
  song = "conqueror";
  artist = "aurora";
  playlist = order_insert(playlist, song, artist);
  print_list(playlist);
  song = "seven";
  artist = "catfish and the bottlemen";
  playlist = order_insert(playlist, song, artist);
  print_list(playlist);
  song = "daydream";
  artist = "beach fossils";
  playlist = order_insert(playlist, song, artist);
  print_list(playlist);
  song = "anything you synthesize";
  artist = "american dollar";
  playlist = order_insert(playlist, song, artist);
  print_list(playlist);
  printf("%d\n",list_count(playlist));
  struct song * randsong = rand_node(playlist);
  printf("%s, %s \n", randsong->artist, randsong->name);

  struct song * selected = NULL;
  song = "daydream";
  artist = "beach fossils";
  printf("\nFinding daydrea by beach fossils:\n");
  selected = find_node(playlist, song, artist);
  if (selected) {
    printf("Artist: %s\nName: %s\n", selected->artist, selected->name);
  }

  song = "daydream";
  artist = "beach fossils";
  printf("\nFinding daydream by beach fossils:\n");
  selected = find_node(playlist, song, artist);
  if (selected) {
    printf("Artist: %s\nName: %s\n", selected->artist, selected->name);
  }

  artist = "aurora";
  printf("\nFinding first song by aurora:\n");
  selected = find_art(playlist, artist);
  if (selected) {
    printf("Artist: %s\nName: %s\n", selected->artist, selected->name);
  }

  song = "anything you synthesize";
  artist = "american dollar";
  printf("\nRemoving anything you synthesize by american dollar...\n");
  playlist = remove_node(playlist, song, artist);
  print_list(playlist);
  
  song = "running with the wolves";
  artist = "aurora";
  printf("\nRemoving running with the wolves by aurora...\n");
  playlist = remove_node(playlist, song, artist);
  print_list(playlist);

  song = "seven";
  artist = "catfish and the bottlemen";
  printf("\nRemoving seven by catfish and the bottlemen...\n");
  playlist = remove_node(playlist, song, artist);
  print_list(playlist);

  song = "hallow33n tim3";
  artist = "kicked off the streets";
  printf("\nRemoving hallow33n tim3 by kicked off the streets...\n");
  playlist = remove_node(playlist, song, artist);
  print_list(playlist);

  
  free_all(playlist);
  -------------------------------------------*/

  printf("\nAdding:\nrunning with the wolves by aurora\nconqueror by aurora\nseven by catfish and the bottlemen\ndown the line by beach fossils\nwoods by black marble\nkong by bonobo\n");

  char * song = "running with the wolves";;
  char * artist = "aurora";;
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
  
  print_all();
  
  printf("\nall artists of a?\n");
  print_letter('a');

  printf("\nall artists of b?\n");
  print_letter('b');

  find_artist("aurora");

  printf("\nemptied.");
  remove_all();
  print_all();



}


