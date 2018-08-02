#pragma once

class File {
public:
    File() {}
    virtual ~File() {}
    static File *open(const char *filename);

    virtual int read(void *out_data, int num_bytes);
    virtual void *read_hunk();
    virtual int seek(unsigned long length, int dir);
    virtual void close();
};
