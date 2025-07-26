#ifndef TEST_ASSERT_BITBOARDS_H_EBF87B1F9710198C
#define TEST_ASSERT_BITBOARDS_H_EBF87B1F9710198C


// this file is meant to be included within the project to ensure bitboards are
// constructed properly

static_assert(Bitboard::RANK_2 == Bitboard::RANK_1 << 8);
static_assert(Bitboard::RANK_3 == Bitboard::RANK_2 << 8);
static_assert(Bitboard::RANK_4 == Bitboard::RANK_3 << 8);
static_assert(Bitboard::RANK_5 == Bitboard::RANK_4 << 8);
static_assert(Bitboard::RANK_6 == Bitboard::RANK_5 << 8);
static_assert(Bitboard::RANK_7 == Bitboard::RANK_6 << 8);
static_assert(Bitboard::RANK_8 == Bitboard::RANK_7 << 8);

static_assert(Bitboard::FILE_B == Bitboard::FILE_A << 1);
static_assert(Bitboard::FILE_C == Bitboard::FILE_B << 1);
static_assert(Bitboard::FILE_D == Bitboard::FILE_C << 1);
static_assert(Bitboard::FILE_E == Bitboard::FILE_D << 1);
static_assert(Bitboard::FILE_F == Bitboard::FILE_E << 1);
static_assert(Bitboard::FILE_G == Bitboard::FILE_F << 1);
static_assert(Bitboard::FILE_H == Bitboard::FILE_G << 1);

static_assert(Bitboard::B1 == Bitboard::A1 << 1); static_assert(Bitboard::C1 == Bitboard::B1 << 1); static_assert(Bitboard::D1 == Bitboard::C1 << 1); static_assert(Bitboard::E1 == Bitboard::D1 << 1); static_assert(Bitboard::F1 == Bitboard::E1 << 1); static_assert(Bitboard::G1 == Bitboard::F1 << 1); static_assert(Bitboard::H1 == Bitboard::G1 << 1);

static_assert(Bitboard::A2 == Bitboard::A1 << 8); static_assert(Bitboard::A3 == Bitboard::A2 << 8); static_assert(Bitboard::A4 == Bitboard::A3 << 8); static_assert(Bitboard::A5 == Bitboard::A4 << 8); static_assert(Bitboard::A6 == Bitboard::A5 << 8); static_assert(Bitboard::A7 == Bitboard::A6 << 8); static_assert(Bitboard::A8 == Bitboard::A7 << 8);
static_assert(Bitboard::B2 == Bitboard::B1 << 8); static_assert(Bitboard::B3 == Bitboard::B2 << 8); static_assert(Bitboard::B4 == Bitboard::B3 << 8); static_assert(Bitboard::B5 == Bitboard::B4 << 8); static_assert(Bitboard::B6 == Bitboard::B5 << 8); static_assert(Bitboard::B7 == Bitboard::B6 << 8); static_assert(Bitboard::B8 == Bitboard::B7 << 8);
static_assert(Bitboard::C2 == Bitboard::C1 << 8); static_assert(Bitboard::C3 == Bitboard::C2 << 8); static_assert(Bitboard::C4 == Bitboard::C3 << 8); static_assert(Bitboard::C5 == Bitboard::C4 << 8); static_assert(Bitboard::C6 == Bitboard::C5 << 8); static_assert(Bitboard::C7 == Bitboard::C6 << 8); static_assert(Bitboard::C8 == Bitboard::C7 << 8);
static_assert(Bitboard::D2 == Bitboard::D1 << 8); static_assert(Bitboard::D3 == Bitboard::D2 << 8); static_assert(Bitboard::D4 == Bitboard::D3 << 8); static_assert(Bitboard::D5 == Bitboard::D4 << 8); static_assert(Bitboard::D6 == Bitboard::D5 << 8); static_assert(Bitboard::D7 == Bitboard::D6 << 8); static_assert(Bitboard::D8 == Bitboard::D7 << 8);
static_assert(Bitboard::E2 == Bitboard::E1 << 8); static_assert(Bitboard::E3 == Bitboard::E2 << 8); static_assert(Bitboard::E4 == Bitboard::E3 << 8); static_assert(Bitboard::E5 == Bitboard::E4 << 8); static_assert(Bitboard::E6 == Bitboard::E5 << 8); static_assert(Bitboard::E7 == Bitboard::E6 << 8); static_assert(Bitboard::E8 == Bitboard::E7 << 8);
static_assert(Bitboard::F2 == Bitboard::F1 << 8); static_assert(Bitboard::F3 == Bitboard::F2 << 8); static_assert(Bitboard::F4 == Bitboard::F3 << 8); static_assert(Bitboard::F5 == Bitboard::F4 << 8); static_assert(Bitboard::F6 == Bitboard::F5 << 8); static_assert(Bitboard::F7 == Bitboard::F6 << 8); static_assert(Bitboard::F8 == Bitboard::F7 << 8);
static_assert(Bitboard::G2 == Bitboard::G1 << 8); static_assert(Bitboard::G3 == Bitboard::G2 << 8); static_assert(Bitboard::G4 == Bitboard::G3 << 8); static_assert(Bitboard::G5 == Bitboard::G4 << 8); static_assert(Bitboard::G6 == Bitboard::G5 << 8); static_assert(Bitboard::G7 == Bitboard::G6 << 8); static_assert(Bitboard::G8 == Bitboard::G7 << 8);
static_assert(Bitboard::H2 == Bitboard::H1 << 8); static_assert(Bitboard::H3 == Bitboard::H2 << 8); static_assert(Bitboard::H4 == Bitboard::H3 << 8); static_assert(Bitboard::H5 == Bitboard::H4 << 8); static_assert(Bitboard::H6 == Bitboard::H5 << 8); static_assert(Bitboard::H7 == Bitboard::H6 << 8); static_assert(Bitboard::H8 == Bitboard::H7 << 8);

#if CONSTEXPR_POPCOUNT_AVAILABLE

static_assert(Bitboard::popcount(Bitboard::RANK_1) == 8);
static_assert(Bitboard::popcount(Bitboard::RANK_2) == 8);
static_assert(Bitboard::popcount(Bitboard::RANK_3) == 8);
static_assert(Bitboard::popcount(Bitboard::RANK_4) == 8);
static_assert(Bitboard::popcount(Bitboard::RANK_5) == 8);
static_assert(Bitboard::popcount(Bitboard::RANK_6) == 8);
static_assert(Bitboard::popcount(Bitboard::RANK_7) == 8);
static_assert(Bitboard::popcount(Bitboard::RANK_8) == 8);

static_assert(Bitboard::popcount(Bitboard::FILE_A) == 8);
static_assert(Bitboard::popcount(Bitboard::FILE_B) == 8);
static_assert(Bitboard::popcount(Bitboard::FILE_C) == 8);
static_assert(Bitboard::popcount(Bitboard::FILE_D) == 8);
static_assert(Bitboard::popcount(Bitboard::FILE_E) == 8);
static_assert(Bitboard::popcount(Bitboard::FILE_F) == 8);
static_assert(Bitboard::popcount(Bitboard::FILE_G) == 8);
static_assert(Bitboard::popcount(Bitboard::FILE_H) == 8);

static_assert(Bitboard::popcount(Bitboard::A1) == 1); static_assert(Bitboard::popcount(Bitboard::B1) == 1); static_assert(Bitboard::popcount(Bitboard::C1) == 1); static_assert(Bitboard::popcount(Bitboard::D1) == 1); static_assert(Bitboard::popcount(Bitboard::E1) == 1); static_assert(Bitboard::popcount(Bitboard::F1) == 1); static_assert(Bitboard::popcount(Bitboard::G1) == 1); static_assert(Bitboard::popcount(Bitboard::H1) == 1);
static_assert(Bitboard::popcount(Bitboard::A2) == 1); static_assert(Bitboard::popcount(Bitboard::B2) == 1); static_assert(Bitboard::popcount(Bitboard::C2) == 1); static_assert(Bitboard::popcount(Bitboard::D2) == 1); static_assert(Bitboard::popcount(Bitboard::E2) == 1); static_assert(Bitboard::popcount(Bitboard::F2) == 1); static_assert(Bitboard::popcount(Bitboard::G2) == 1); static_assert(Bitboard::popcount(Bitboard::H2) == 1);
static_assert(Bitboard::popcount(Bitboard::A3) == 1); static_assert(Bitboard::popcount(Bitboard::B3) == 1); static_assert(Bitboard::popcount(Bitboard::C3) == 1); static_assert(Bitboard::popcount(Bitboard::D3) == 1); static_assert(Bitboard::popcount(Bitboard::E3) == 1); static_assert(Bitboard::popcount(Bitboard::F3) == 1); static_assert(Bitboard::popcount(Bitboard::G3) == 1); static_assert(Bitboard::popcount(Bitboard::H3) == 1);
static_assert(Bitboard::popcount(Bitboard::A4) == 1); static_assert(Bitboard::popcount(Bitboard::B4) == 1); static_assert(Bitboard::popcount(Bitboard::C4) == 1); static_assert(Bitboard::popcount(Bitboard::D4) == 1); static_assert(Bitboard::popcount(Bitboard::E4) == 1); static_assert(Bitboard::popcount(Bitboard::F4) == 1); static_assert(Bitboard::popcount(Bitboard::G4) == 1); static_assert(Bitboard::popcount(Bitboard::H4) == 1);
static_assert(Bitboard::popcount(Bitboard::A5) == 1); static_assert(Bitboard::popcount(Bitboard::B5) == 1); static_assert(Bitboard::popcount(Bitboard::C5) == 1); static_assert(Bitboard::popcount(Bitboard::D5) == 1); static_assert(Bitboard::popcount(Bitboard::E5) == 1); static_assert(Bitboard::popcount(Bitboard::F5) == 1); static_assert(Bitboard::popcount(Bitboard::G5) == 1); static_assert(Bitboard::popcount(Bitboard::H5) == 1);
static_assert(Bitboard::popcount(Bitboard::A6) == 1); static_assert(Bitboard::popcount(Bitboard::B6) == 1); static_assert(Bitboard::popcount(Bitboard::C6) == 1); static_assert(Bitboard::popcount(Bitboard::D6) == 1); static_assert(Bitboard::popcount(Bitboard::E6) == 1); static_assert(Bitboard::popcount(Bitboard::F6) == 1); static_assert(Bitboard::popcount(Bitboard::G6) == 1); static_assert(Bitboard::popcount(Bitboard::H6) == 1);
static_assert(Bitboard::popcount(Bitboard::A7) == 1); static_assert(Bitboard::popcount(Bitboard::B7) == 1); static_assert(Bitboard::popcount(Bitboard::C7) == 1); static_assert(Bitboard::popcount(Bitboard::D7) == 1); static_assert(Bitboard::popcount(Bitboard::E7) == 1); static_assert(Bitboard::popcount(Bitboard::F7) == 1); static_assert(Bitboard::popcount(Bitboard::G7) == 1); static_assert(Bitboard::popcount(Bitboard::H7) == 1);
static_assert(Bitboard::popcount(Bitboard::A8) == 1); static_assert(Bitboard::popcount(Bitboard::B8) == 1); static_assert(Bitboard::popcount(Bitboard::C8) == 1); static_assert(Bitboard::popcount(Bitboard::D8) == 1); static_assert(Bitboard::popcount(Bitboard::E8) == 1); static_assert(Bitboard::popcount(Bitboard::F8) == 1); static_assert(Bitboard::popcount(Bitboard::G8) == 1); static_assert(Bitboard::popcount(Bitboard::H8) == 1);

#endif // CONSTEXPR_POPCOUNT_AVAILABLE


#endif // TEST_ASSERT_BITBOARDS_H_EBF87B1F9710198C
