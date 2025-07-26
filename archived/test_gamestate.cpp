#include "gamestate.h"
#include "minunit.h"


static void test_gamestate_init()
{
    mu_assert(GameState().to_string() == "\
+---+---+---+---+---+---+---+---+\n\
| r | n | b | q | k | b | n | r | 8\n\
+---+---+---+---+---+---+---+---+\n\
| p | p | p | p | p | p | p | p | 7\n\
+---+---+---+---+---+---+---+---+\n\
|   |   |   |   |   |   |   |   | 6\n\
+---+---+---+---+---+---+---+---+\n\
|   |   |   |   |   |   |   |   | 5\n\
+---+---+---+---+---+---+---+---+\n\
|   |   |   |   |   |   |   |   | 4\n\
+---+---+---+---+---+---+---+---+\n\
|   |   |   |   |   |   |   |   | 3\n\
+---+---+---+---+---+---+---+---+\n\
| P | P | P | P | P | P | P | P | 2\n\
+---+---+---+---+---+---+---+---+\n\
| R | N | B | Q | K | B | N | R | 1\n\
+---+---+---+---+---+---+---+---+\n\
  a   b   c   d   e   f   g   h"
    );

    GameState gs {};
    using namespace Bitboard;

    mu_assert(gs.wp == (A2 | B2 | C2 | D2 | E2 | F2 | G2 | H2));
    mu_assert(gs.wn == (B1 | G1));
    mu_assert(gs.wb == (C1 | F1));
    mu_assert(gs.wr == (A1 | H1));
    mu_assert(gs.wq == D1);
    mu_assert(gs.wk == E1);

    mu_assert(gs.bp == (A7 | B7 | C7 | D7 | E7 | F7 | G7 | H7));
    mu_assert(gs.bn == (B8 | G8));
    mu_assert(gs.bb == (F8 | C8));
    mu_assert(gs.br == (A8 | H8));
    mu_assert(gs.bq == D8);
    mu_assert(gs.bk == E8);
}

static void test_make_move()
{
    using namespace Bitboard;

    GameState gs0 {};
    mu_assert(gs0.wp == (A2 | B2 | C2 | D2 | E2 | F2 | G2 | H2));
    GameState gs1 { gs0.play_move({ .sqs = (E2 | E4), .piece_type = PieceType::PAWN }) };
    mu_assert(gs1.wp == (A2 | B2 | C2 | D2 | E4 | F2 | G2 | H2));
    GameState gs2 { gs1.play_move({ .sqs = (E7 | E5), .piece_type = PieceType::PAWN }) };
    mu_assert(gs2.bp == (A7 | B7 | C7 | D7 | E5 | F7 | G7 | H7));
    GameState gs3 { gs2.play_move({ .sqs = (G1 | F3), .piece_type = PieceType::KNIGHT }) };
    mu_assert(gs3.wn == (F3 | B1));
}


int main()
{
    mu_run(test_gamestate_init);
    mu_run(test_make_move)
}
