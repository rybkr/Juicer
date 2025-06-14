#include "types.h"
#include "minunit.h"
#include <iostream>


static void test_bb_square_indices() {
    using namespace Board;

    mu_assert(int(Square::A1) == 0);
    mu_assert(int(Square::B1) == 1);
    mu_assert(int(Square::A2) == 8);
    mu_assert(int(Square::H8) == 63);
    mu_assert(int(Square::E4) == 28);
}

static void test_bb_square_bitmasks() {
    using namespace Bitboard;

    mu_assert(A1 == (1ULL));
    mu_assert(H8 == (1ULL << 63));
    mu_assert(E4 == (1ULL << 28));
    mu_assert(D6 == (1ULL << int(Board::Square::D6)));
}

static void test_make_square() {
    using namespace Board;

    mu_assert(Board::make_square(File::FILE_A, Rank::RANK_1) == Square::A1);
    mu_assert(Board::make_square(File::FILE_H, Rank::RANK_8) == Square::H8);
    mu_assert(Board::make_square(File::FILE_E, Rank::RANK_4) == Square::E4);
    mu_assert(static_cast<int>(Board::make_square(File::FILE_B, Rank::RANK_2)) == 9);
}

static void test_bb_make_square() {
    mu_assert(Bitboard::make_square(Board::File::FILE_A, Board::Rank::RANK_1) == 1ULL << int(Board::Square::A1));
    mu_assert(Bitboard::make_square(Board::File::FILE_H, Board::Rank::RANK_8) == 1ULL << int(Board::Square::H8));
    mu_assert(Bitboard::make_square(Board::File::FILE_E, Board::Rank::RANK_4) == 1ULL << int(Board::Square::E4));
}

static void test_bb_rank_file_bitmasks() {
    using namespace Bitboard;

    mu_assert(RANK_1 == (A1 | B1 | C1 | D1 | E1 | F1 | G1 | H1));
    mu_assert(RANK_2 == (A2 | B2 | C2 | D2 | E2 | F2 | G2 | H2));
    mu_assert(RANK_3 == (A3 | B3 | C3 | D3 | E3 | F3 | G3 | H3));
    mu_assert(RANK_4 == (A4 | B4 | C4 | D4 | E4 | F4 | G4 | H4));
    mu_assert(RANK_5 == (A5 | B5 | C5 | D5 | E5 | F5 | G5 | H5));
    mu_assert(RANK_6 == (A6 | B6 | C6 | D6 | E6 | F6 | G6 | H6));
    mu_assert(RANK_7 == (A7 | B7 | C7 | D7 | E7 | F7 | G7 | H7));
    mu_assert(RANK_8 == (A8 | B8 | C8 | D8 | E8 | F8 | G8 | H8));

    mu_assert(FILE_A == (A1 | A2 | A3 | A4 | A5 | A6 | A7 | A8));
    mu_assert(FILE_B == (B1 | B2 | B3 | B4 | B5 | B6 | B7 | B8));
    mu_assert(FILE_C == (C1 | C2 | C3 | C4 | C5 | C6 | C7 | C8));
    mu_assert(FILE_D == (D1 | D2 | D3 | D4 | D5 | D6 | D7 | D8));
    mu_assert(FILE_E == (E1 | E2 | E3 | E4 | E5 | E6 | E7 | E8));
    mu_assert(FILE_F == (F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8));
    mu_assert(FILE_G == (G1 | G2 | G3 | G4 | G5 | G6 | G7 | G8));
    mu_assert(FILE_H == (H1 | H2 | H3 | H4 | H5 | H6 | H7 | H8));

    mu_assert((FILE_E & RANK_6) == E6);
}

static void test_bb_diagonal_bitmasks() {
    using namespace Bitboard;
}


int main() {
    mu_run(test_bb_square_indices);
    mu_run(test_bb_square_bitmasks);
    mu_run(test_make_square);
    mu_run(test_bb_make_square);
    mu_run(test_bb_rank_file_bitmasks);
}
