#include "movegen.h"
#include "gamestate.h"
#include "minunit.h"


static void test_count_moves()
{
    GameState gs {};
    mu_assert(MoveList<GenType::LEGAL>(gs).size() == 20);
}


int main()
{
    mu_run(test_count_moves);
}
