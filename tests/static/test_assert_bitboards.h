#ifndef TEST_ASSERT_BITBOARD_H_674D1A9A4E33E611
#define TEST_ASSERT_BITBOARD_H_674D1A9A4E33E611


#define X(square)                                             \
    static_assert(Bitboard::popcount(Bitboard::square) == 1); \
    static_assert(Bitboard::square == 1ULL << static_cast<int>(Square::square));
    SQUARES
#undef X

#define X(file)                                             \
    static_assert(Bitboard::popcount(Bitboard::file) == 8); \
    static_assert(Bitboard::file == 0x0101010101010101ULL << static_cast<int>(File::file));
    FILES
#undef X

#define X(rank)                                             \
    static_assert(Bitboard::popcount(Bitboard::rank) == 8); \
    static_assert(Bitboard::rank == 0xFFULL << (8 * static_cast<int>(Rank::rank)));
    RANKS
#undef X

static_assert(Bitboard::popcount(0x0ULL) == 0);
static_assert(Bitboard::popcount(0x1ULL) == 1);
static_assert(Bitboard::popcount(0xFFFFFFFFFFFFFFFFULL) == 64);


#endif // TEST_ASSERT_BITBOARD_H_674D1A9A4E33E611
