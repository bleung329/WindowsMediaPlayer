#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"


int main() {


  //  printf("%d\n", strcmp("abbae", "abble"));

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
  free_all(playlist);

}

