#include "src/kknd.h"

#include "src/_unsorted_functions.h"
#include "src/_unsorted_data.h"

#include "src/File.h"

//----- (0040C700) --------------------------------------------------------
int file_list_alloc()
{
    int result; // eax@1
    File *v1; // esi@1
    int v2; // edx@2

    result = (int)malloc(0x280u);
    v1 = (File *)result;
    file_list = (File *)result;
    if (result)
    {
        v2 = 0;
        while (1)
        {
            memset(&v1[v2], 0, sizeof(File));
            file_list[v2].next = &file_list[v2 + 1];
            ++v2;
            if (v2 >= 19)
                break;
            v1 = file_list;
        }
        file_list[19].next = 0;
        file_list_first = (File *)&file_list_last;
        file_list_47792C = (File *)&file_list_last;
        file_list_free_pool = file_list;
        file_list_used = 0;
        result = 1;
    }
    return result;
}
// 477938: using guessed type int file_list_used;

//----- (0040C790) --------------------------------------------------------
File *file_list_fopen(const char *filename)
{
    File *v1; // edx@1
    const char *v2; // ebx@1
    File *file; // esi@2
    File *v4; // ecx@3
    File *result; // eax@5
    FILE *v6; // eax@6

    v1 = file_list_free_pool;
    v2 = filename;
    if (file_list_free_pool)
    {
        file_list_free_pool = file_list_free_pool->next;
        memset(v1, 0, sizeof(File));
        v4 = file_list_first;
        v1->prev = (File *)&file_list_last;
        v1->next = v4;
        file = v1;
        file_list_first->prev = v1;
        file_list_first = v1;
        ++file_list_used;
    }
    else
    {
        file = 0;
    }
    if (file)
    {
        file->flags = 1;
        v6 = fopen(v2, aRb);
        file->handle_or_FILE = v6;
        if (v6)
        {
            result = file;
        }
        else
        {
            file->next->prev = file->prev;
            file->prev->next = file->next;
            file->next = file_list_free_pool;
            file_list_free_pool = file;
            --file_list_used;
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}
// 477938: using guessed type int file_list_used;

//----- (0040C840) --------------------------------------------------------
int file_read(File *a1, void *out_data, int num_bytes)
{
    File *v3; // ebx@1
    int result; // eax@2
    int v5; // ecx@2

    v3 = a1;
    if (a1->flags & 2)
    {
        result = num_bytes;
        v5 = a1->view_end_ptr - (unsigned int)a1->view;
        if (num_bytes > v5)
            result = v5;
        memcpy(out_data, v3->view_current_ptr, result);
        v3->view_current_ptr = (char *)v3->view_current_ptr + result;
    }
    else
    {
        result = fread(out_data, 1u, num_bytes, (FILE *)a1->handle_or_FILE);
    }
    return result;
}

//----- (0040C8A0) --------------------------------------------------------
void *file_list_read_hunk(File *a1)
{
    unsigned int num_bytes_read; // eax@1
    File *v2; // ebx@1
    void *v3; // esi@2
    char *v4; // edx@4
    void *result; // eax@7
    unsigned __int16 v6; // dx@8
    void *v7; // ebp@8
    int v8; // eax@9
    void *v9; // esi@10
    int hunk_name_size[2]; // [sp+10h] [bp-8h]@4

    num_bytes_read = 8;
    v2 = a1;
    if (a1->flags & 2)
    {
        v3 = a1->view;
        if (a1->view_end_ptr - (int)v3 < 8)
            num_bytes_read = a1->view_end_ptr - (_DWORD)v3;
        v4 = (char *)a1->view_current_ptr;
        memcpy(hunk_name_size, a1->view_current_ptr, num_bytes_read);
        a1->view_current_ptr = &v4[num_bytes_read];
    }
    else
    {
        num_bytes_read = fread(hunk_name_size, 1u, 8u, (FILE *)a1->handle_or_FILE);
    }
    if (num_bytes_read >= 8)
    {
        LOBYTE_HEXRAYS(v6) = 0;
        HIBYTE_HEXRAYS(v6) = BYTE2(hunk_name_size[1]);
        hunk_name_size[1] = ((unsigned int)hunk_name_size[1] >> 24) | v6 | (((hunk_name_size[1] << 16) | hunk_name_size[1] & 0xFF00) << 8);
        result = malloc(hunk_name_size[1]);
        v7 = result;
        if (result)
        {
            v8 = hunk_name_size[1];
            if (v2->flags & 2)
            {
                v9 = v2->view;
                if (hunk_name_size[1] > v2->view_end_ptr - (int)v9)
                    v8 = v2->view_end_ptr - (_DWORD)v9;
                memcpy(v7, v2->view_current_ptr, v8);
                v2->view_current_ptr = (char *)v2->view_current_ptr + v8;
            }
            else
            {
                v8 = fread(v7, 1u, hunk_name_size[1], (FILE *)v2->handle_or_FILE);
            }
            if (v8 >= hunk_name_size[1])
            {
                result = v7;
            }
            else
            {
                free(v7);
                result = 0;
            }
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0040C9B0) --------------------------------------------------------
int file_seek(File *a1, __int32 length, int dir)
{
    return fseek((FILE *)a1->handle_or_FILE, length, dir);
}

//----- (0040C9D0) --------------------------------------------------------
int file_list_close(File *a1)
{
    File *v1; // esi@1
    int result; // eax@6

    v1 = a1;
    if (a1)
    {
        if (a1->flags & 2)
        {
            UnmapViewOfFile(a1->view);
            CloseHandle(v1->handle_8);
            CloseHandle(v1->handle_or_FILE);
        }
        else if (a1->handle_or_FILE)
        {
            fclose((FILE *)a1->handle_or_FILE);
        }
        v1->next->prev = v1->prev;
        v1->prev->next = v1->next;
        v1->next = file_list_free_pool;
        result = file_list_used - 1;
        file_list_free_pool = v1;
        --file_list_used;
    }
    return result;
}

//----- (0040CA40) --------------------------------------------------------
void file_list_free()
{
    File *v0; // esi@1
    File *v1; // edi@3

    v0 = file_list_first;
    if (file_list_first)
    {
        do
        {
            if ((File **)v0 == &file_list_last)
                break;
            v1 = v0->next;
            if (v0)
            {
                if (v0->flags & 2)
                {
                    UnmapViewOfFile(v0->view);
                    CloseHandle(v0->handle_8);
                    CloseHandle(v0->handle_or_FILE);
                }
                else if (v0->handle_or_FILE)
                {
                    fclose((FILE *)v0->handle_or_FILE);
                }
                v0->next->prev = v0->prev;
                v0->prev->next = v0->next;
                v0->next = file_list_free_pool;
                file_list_free_pool = v0;
                --file_list_used;
            }
            v0 = v1;
        } while (v1);
    }
    free(file_list);
}