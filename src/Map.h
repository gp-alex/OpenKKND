#pragma once


inline int global2map(int coordinate) {
    return coordinate >> 13;
}
inline int map2global(int coordinate) {
    return coordinate << 13;
}

inline bool map_is_same_tile(int coord1, int coord2) {
    return !map_is_different_tile(coord1, coord2);
}

inline bool map_is_different_tile(int coord1, int coord2) {
    // original code, equivalent to global2map(coord1) != global2map(coord2)
    return (coord1 ^ coord2) & 0xFFFFE000;
}


