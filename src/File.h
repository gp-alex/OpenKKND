#pragma once

/* 248 */
struct File
{
    int flags;
    void *handle_or_FILE;
    void *handle_8;
    void *view;
    void *view_current_ptr;
    int view_end_ptr;
    File *next;
    File *prev;
};