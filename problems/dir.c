#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
void scanDirectory(const char *dirPath, int depth) {
  DIR *dir;
  struct dirent *entry;
  if ((dir = opendir(dirPath)) == NULL) {
    perror("opendir");
    return;
  }
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    for (int i = 0; i < depth; i++) {
      printf("- - -");
    }
    printf("%s\n", entry->d_name);
    if (entry->d_type == DT_DIR) {
      char newPath[1024];
      snprintf(newPath, sizeof(newPath), "%s/%s", dirPath, entry->d_name);
      scanDirectory(newPath, depth + 1);
    }
  }
  closedir(dir);
}
int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    return 1;
  }
  scanDirectory(argv[1], 0);
  return 0;
}
