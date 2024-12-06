#include <stdio.h>
#include <stdlib.h>

struct MusicPlayer {
  char *song;
  char *artist;
  char *movie;
  char *timing;
  struct MusicPlayer *next;
};

struct MusicPlayer *createNode(char *music, char *artist, char *movie,
                               char *timing) {
  struct MusicPlayer *node =
      (struct MusicPlayer *)(malloc(sizeof(struct MusicPlayer)));
  node->movie = movie;
  node->artist = artist;
  node->song = music;
  node->timing = timing;
  node->next = NULL;
  return node;
}
void addSongToPlaylist(struct MusicPlayer **playlist, char *music, char *artist,
                       char *movie) {
  struct MusicPlayer *NewNode = createNode(music, artist, movie, "04.00");
  if (*playlist == NULL) {
    *playlist = NewNode;
  } else {
    struct MusicPlayer *lastNode = *playlist;
    while (lastNode->next != NULL) {
      lastNode = lastNode->next;
    }
    lastNode->next = NewNode;
  }
}

void displayPlaylist(struct MusicPlayer *playlist) {
  printf("current Songs in Playlist:\n");
  while (playlist != NULL) {
    printf("%s from %s by %s\n", playlist->song, playlist->movie,
           playlist->artist);
    playlist = playlist->next;
  }
}

void next(struct MusicPlayer *playlist, int *current) {
  struct MusicPlayer *temp = playlist;
  int i = 0;
  for (; i < *current; i++) {
    temp = temp->next;
  }
  if (i == *current) {
    printf("Next Song :%s \n", temp->song);
    (*current)++;
  }
  free(temp);
}
int main() {
  struct MusicPlayer *playlist = NULL;
  addSongToPlaylist(&playlist, "Minnale", "G.V.Prakash Kumar", "Amaran");
  addSongToPlaylist(&playlist, "Manasilayo", "Anirudh", "Vettiyan");
  displayPlaylist(playlist);
  int currentsong = 0;
  next(playlist, &currentsong);
  next(playlist, &currentsong);
  return 0;
}
