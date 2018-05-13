#include "Infrastructure/File.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <list>

#include "src/kknd.h"

std::list<File*> files;

class FilesWatchdog {
 public:
  FilesWatchdog() {}
  virtual ~FilesWatchdog() {
    while (!files.empty()) {
      (*files.begin())->close();
    }
  }
};

FilesWatchdog files_watchdog;

File *File::open(const char *filename) {
  File *file = new File();
  fopen_s(&file->handle, filename, "rb");
  if (file->handle) {
    files.push_back(file);
  } else {
    delete file;
    file = nullptr;
  }

  return file;
}

int File::read(void *out_data, int num_bytes) {
  return fread(out_data, 1, num_bytes, handle);
}

template <typename T>
T byte_swap(T x) {
  union {
    T x;
    unsigned char x8[sizeof(T)];
  } source, dest;

  source.x = x;

  for (size_t i = 0; i < sizeof(T); i++) {
    dest.x8[i] = source.x8[sizeof(T) - i - 1];
  }

  return dest.x;
}

void *File::read_hunk() {
  char hunk_name[5] = {0};
  unsigned int num_bytes_read = fread(hunk_name, 4, 1, handle);
  if (num_bytes_read < 1) {
    return nullptr;
  }

  uint32_t size;
  num_bytes_read = fread(&size, 4, 1, handle);
  if (num_bytes_read < 1) {
    return nullptr;
  }
  size = byte_swap<uint32_t>(size);

  void *data = malloc(size);
  if (data) {
    num_bytes_read = fread(data, size, 1, handle);
    if (num_bytes_read < 1) {
      free(data);
      data = nullptr;
    }
  }

  return data;
}

int File::seek(size_t length, int dir) {
  return fseek(handle, length, dir);
}

void File::close() {
  files.remove(this);
  if (handle) {
    fclose(handle);
  }
  delete this;
}
