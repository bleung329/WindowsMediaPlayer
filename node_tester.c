#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

int main() {
  
  //  printf("%d\n", strcmp("abbae", "abble"));
  struct song * playlist = NULL;

  printf("\nTESTING LINKED LIST FUNCTIONS\n");
  printf("========================================\n");
  
  char * song = "running with the wolves";
  char * artist = "aurora";
  playlist = order_insert(playlist, song, artist);

  song = "conqueror";
  artist = "aurora";
  playlist = order_insert(playlist, song, artist);

  song = "seven";
  artist = "catfish and the bottlemen";
  playlist = order_insert(playlist, song, artist);

  song = "daydream";
  artist = "beach fossils";
  playlist = order_insert(playlist, song, artist);

  song = "anything you synthesize";
  artist = "american dollar";
  playlist = order_insert(playlist, song, artist);

  printf("\nprinting playlist...\n");
  print_list(playlist);
  
  printf("\nprinting size of playlist...\n");
  printf("%d\n",list_count(playlist));

  printf("\na randomly selected song...\n");
  struct song * randsong = rand_node(playlist);
  printf("%s, %s \n", randsong->artist, randsong->name);

  struct song * selected = NULL;
  song = "daydrea";
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
  printf("\nFinding aurora's first song:\n");
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

  printf("\nremoving all songs...\n");
  playlist = free_all(playlist);
  print_list(playlist);

}