#include "rational.h"

using namespace std;

int main() {
    rational r, r1, r2;
    r.Init(5, 12);
    r.ipart();
    r.Read();
    r.Show();
    r.ipart();
    r2.Init(3923, 23);
    r2.ipart();
    r1.Init(5, 0);
    r1.ipart();
    return 0;
}
