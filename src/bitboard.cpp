#include "bitboard/bitboard.h"

namespace bitboard
{
    // ---------------------------------------------------------------------
    // Constructors (see header)

    // ---------------------------------------------------------------------
    // Public methods
    void BitBoard::setPos(const std::string &pos)
    {
        if (isValidPos(pos))
            bbs |= pos2mask(pos);
    }

    void BitBoard::setPos(const std::set<std::string>& poslist)
    {
        for (auto pos: poslist) {
            setPos(pos);
        }
    }

    void BitBoard::clearPos(const std::string &pos)
    {
        if (isValidPos(pos))
            bbs &= ~pos2mask(pos);
    }
    void BitBoard::clearPos(const std::set<std::string>& poslist)
    {
        for (auto pos: poslist) {
            clearPos(pos);
        }
    }
    void BitBoard::move(const std::string &from, const std::string &to)
    {
        clearPos(from);
        setPos(to);
    }

    void BitBoard::activeCells(std::set<std::string> &actCells)
    {
        std::string pos;
        for (char row = '1'; row <= '8'; row++) {
            for(char col = 'a'; col <= 'h'; col++) {
                pos = col;
                pos += row;
                if (cellActive(pos)) {
                    actCells.insert(pos);
                }
            }
        }
    }

    // ---------------------------------------------------------------------
    // Private methods
    bool BitBoard::isValidPos(const std::string &pos)
    {
        // valid position are two characters strings
        // with correct row and column values
        return ((pos.size() == 2) &&
           isValidColumn(pos.at(0)) &&
           isValidRow(pos.at(1)));
    }
    bool BitBoard::isValidColumn(char col)
    {
        return (tolower(col) >= 'a' && tolower(col) <= 'h');
    }
    bool BitBoard::isValidRow(char row)
    {
        return (row >= '1' && row <= '8');
    }

    unsigned int BitBoard::posToBitPos(const std::string &pos)
    {
        unsigned int row = pos.at(1) - '1';
        unsigned int col = tolower(pos.at(0)) - 'a';
        return row * 8 + col;
    }

    BitBoardState BitBoard::pos2mask(const std::string &pos)
    {
        return 1ULL << posToBitPos(pos);
    }

} // namespace bitboard
