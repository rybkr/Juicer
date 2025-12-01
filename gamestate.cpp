#include "gamestate.h"

template <Color C = Color::NONE, PieceType Pt = PieceType::NONE>
constexpr bitboard_t GameState::bitboard() {
    switch (enum_key(C, Pt)) {
    case enum_key(Color::WHITE, PieceType::PAWN):
        return P;
    case enum_key(Color::WHITE, PieceType::KNIGHT):
        return N;
    case enum_key(Color::WHITE, PieceType::BISHOP):
        return B;
    case enum_key(Color::WHITE, PieceType::ROOK):
        return R;
    case enum_key(Color::WHITE, PieceType::QUEEN):
        return Q;
    case enum_key(Color::WHITE, PieceType::KING):
        return K;
    case enum_key(Color::BLACK, PieceType::PAWN):
        return p;
    case enum_key(Color::BLACK, PieceType::KNIGHT):
        return n;
    case enum_key(Color::BLACK, PieceType::BISHOP):
        return b;
    case enum_key(Color::BLACK, PieceType::ROOK):
        return r;
    case enum_key(Color::BLACK, PieceType::QUEEN):
        return q;
    case enum_key(Color::BLACK, PieceType::KING):
        return k;
    }
}

consteval GameState GameState::INIT() {
    return GameState(Bitboard::RANK_2, Bitboard::B1 | Bitboard::G1,
                     Bitboard::C1 | Bitboard::F1, Bitboard::A1 | Bitboard::H1,
                     Bitboard::D1, Bitboard::E1, Bitboard::RANK_7,
                     Bitboard::B8 | Bitboard::G8, Bitboard::C8 | Bitboard::F8,
                     Bitboard::A8 | Bitboard::H8, Bitboard::D8, Bitboard::E8);
}

consteval GameState GameState::EMPTY() {
    return GameState(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

