
int rand_seed;
int rand_seed_2;
int rand_seed_3;


void kknd_srand_3(int seed)
{
    rand_seed_3 = seed;
}

//----- (inlined) --------------------------------------------------------
int kknd_rand_3()
{
    rand_seed_3 = (3141 * rand_seed_3 + 13867) & 0xFFFF;
    return rand_seed_3;
}


void kknd_srand_debug(int seed)
{
    rand_seed_2 = seed;
}
//----- (0040F2F0) --------------------------------------------------------
int kknd_rand_debug(const char *file, int line)
{
    return rand_seed_2 = (3141 * rand_seed_2 + 13867) & 0xFFFF;
}

void kknd_srand(int seed)
{
    rand_seed = seed;
}
//----- (0040F320) --------------------------------------------------------
int kknd_rand()
{
    return rand_seed = (3141 * rand_seed + 13867) & 0xFFFF;
}

//----- (0040F350) --------------------------------------------------------
int rnd_capped(int maxrang)
{
    rand_seed = (3141 * rand_seed + 13867) & 0xFFFF;
    return rand_seed % maxrang;
}