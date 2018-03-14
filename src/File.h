#pragma once

#include <cstdio>

/* 248 */
class File {
 public:
  File() {}
  virtual ~File() {}
  static File *open(const char *filename);

  int read(void *out_data, int num_bytes);
  void *read_hunk();
  int seek(size_t length, int dir);
  void close();

 protected:
  FILE *handle;
};
