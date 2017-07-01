#pragma once

void kknd_srand_debug(int seed);
int kknd_rand_debug(const char *file, int line);

void kknd_srand(int seed);
int kknd_rand();

void kknd_srand_3(int seed);
int kknd_rand_3();

int rnd_capped(int maxrang);