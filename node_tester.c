#include <stdio.h>
#include <stdlib.h>
#include "song_node.h"

int main() {
  
  //  printf("%d\n", strcmp("abbae", "abble"));
  struct song * playlist = NULL;

  printf("\nTESTING LINKED LIST FUNCTIONS\n");
  printf("========================================\n");


  //inserting
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

  printf("\n.....\n");
  printf("testing print_list\n\n");
  print_list(playlist);


  //printing full list
  printf("\n.....\n");
  printf("testing list_count\n\n");
  printf("%d\n",list_count(playlist));


  //printing one node
  song = "seven";
  artist = "catfish and the bottlemen";
  printf("\n.....\n");
  printf("testing print_node\n\n");
  print_node(playlist, artist, song);

  print_list(playlist);
  
  //testing random nodes
  printf("\n.....\n");
  printf("testing rand_node\n\n");
  struct song * randsong = rand_node(playlist);
  printf("%s: %s \n", randsong->artist, randsong->name);
  randsong = rand_node(playlist);
  printf("%s: %s \n", randsong->artist, randsong->name);
  randsong = rand_node(playlist);
  printf("%s: %s \n", randsong->artist, randsong->name);

  
  //finding nodes by song & artist
  struct song * selected = NULL;
  song = "daydrea";
  artist = "beach fossils";
  printf("\n.....\n");
  printf("testing find_node: daydrea by beach fossils\n\n");
  selected = find_node(playlist, song, artist);
  if (selected) {
    printf("%s: %s\n", selected->artist, selected->name);
  }

  song = "daydream";
  artist = "beach fossils";
  printf("\n.....\n");
  printf("testing find_node: daydream by beach fossils\n\n");
  selected = find_node(playlist, song, artist);
  if (selected) {
    printf("%s: %s\n", selected->artist, selected->name);
  }


  //finding artist's first node
  artist = "aurora";
  printf("\n.....\n");
  printf("testing find_art: aurora\n\n");
  selected = find_art(playlist, artist);
  if (selected) {
    printf("%s: %s\n", selected->artist, selected->name);
  }


  //removals
  song = "anything you synthesize";
  artist = "american dollar";
  printf("\n.....\n");
  printf("testing remove_node: anything you synthesize by american dollar\n\n");
  playlist = remove_node(playlist, song, artist);
  print_list(playlist);
  
  song = "running with the wolves";
  artist = "aurora";
  printf("\n.....\n");
  printf("testing remove_node: running with the wolves by aurora\n\n");
  playlist = remove_node(playlist, song, artist);
  print_list(playlist);

  song = "seven";
  artist = "catfish and the bottlemen";
  printf("\n.....\n");
  printf("testing remove_node: seven by catfish and the bottlemen\n\n");
  playlist = remove_node(playlist, song, artist);
  print_list(playlist);

  song = "hallow33n tim3";
  artist = "kicked off the streets";
  printf("\n.....\n");
  printf("testing remove_node: hallow33n tim3 by kicked off the streets\n\n");
  playlist = remove_node(playlist, song, artist);
  print_list(playlist);


  //freeing all
  printf("\n.....\n");
  printf("testing free_all\n\n");
  playlist = free_all(playlist);
  print_list(playlist);

}
