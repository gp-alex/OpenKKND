#pragma once

void kknd_srand_debug(int seed);
int kknd_rand_debug(const char *file, int line);

#define kknd_srand_2(x) kknd_srand_debug((x)) 
#define kknd_rand_2() kknd_rand_debug(__FILE__, __LINE__) 

void kknd_srand(int seed);
int kknd_rand();

void kknd_srand_3(int seed);
int kknd_rand_3();

int rnd_capped(int maxrang);