#pragma once

class File {
public:
    File() {}
    virtual ~File() {}
    static File *open(const char *filename);

    virtual int read(void *out_data, int num_bytes) = 0;
    virtual void *read_hunk() = 0;
    virtual int seek(unsigned long length, int dir) = 0;
    virtual void close() {}
};
