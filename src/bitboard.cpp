#include "bitboard/bitboard.h"

namespace bitboard
{
    // ---------------------------------------------------------------------
    // Constructors (see header)

    // ---------------------------------------------------------------------
    // Public methods
    void BitBoard::setPos(const std::string &pos)
    {
        bbs |= 1ULL << posToBitPos(pos);
    }

    void BitBoard::setPos(const std::list<std::string>& poslist)
    {
        for (auto pos: poslist) {
            setPos(pos);
        }
    }

    bool BitBoard::cellIsActive(std::string &pos)
    {
        return ((bbs & (1ULL << posToBitPos(pos))) != 0);
    }

    void BitBoard::activeCells(std::list<std::string> &actCells)
    {
        std::string pos;
        for (char row = '1'; row <= '8'; row++) {
            for(char col = 'a'; col <= 'h'; col++) {
                pos = col;
                pos += row;
                if (cellIsActive(pos)) {
                    actCells.push_back(pos);
                }
            }
        }
    }

    // ---------------------------------------------------------------------
    // Private methods
    unsigned int BitBoard::posToBitPos(const std::string &pos) const
    {
        unsigned int row = pos.at(1) - '1';
        unsigned int col = pos.at(0) - 'a';
        return row * 8 + col;
    }

} // namespace bitboard
