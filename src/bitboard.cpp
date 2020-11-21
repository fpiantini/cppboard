#include "bitboard/bitboard.h"

namespace bitboard
{

    void BitBoard::setpos(const std::string &pos)
    {
        bbs |= 1ULL << posToBitpos(pos);
    }

    void BitBoard::setpos(const std::list<std::string>& poslist)
    {
        for (auto pos: poslist) {
            setpos(pos);
        }
    }

    unsigned int BitBoard::posToBitpos(const std::string &pos) const
    {
        unsigned int row = pos.at(1) - '1';
        unsigned int col = pos.at(0) - 'a';
        return row * 8 + col;
    }

} // namespace bitboard
