#include "cppboard/bitboard.h"

namespace cppboard
{
    // ---------------------------------------------------------------------
    // Constructors (see header)

    // ---------------------------------------------------------------------
    // Public methods
    BitBoardState BitBoard::generateStateFromPos(const std::set<std::string> &poslist)
    {
        BitBoard bb;
        bb.setPos(poslist);
        return bb.state();
    }

    void BitBoard::setPos(const std::string &pos)
    {
        if (isValidPos(pos))
            bbs |= pos2state(pos);
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
            bbs &= ~pos2state(pos);
    }
    void BitBoard::clearPos(const std::set<std::string>& poslist)
    {
        for (auto pos: poslist) {
            clearPos(pos);
        }
    }
    void BitBoard::move(const std::string &from, const std::string &to)
    {
        if (cellActive(from) && !cellActive(to)) {
            clearPos(from);
            setPos(to);
        }
    }

    void BitBoard::activeCells(std::set<std::string> &actCells) const
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

    void BitBoard::activeCellsNdx(std::set<std::pair<int, int>> &actCellsNdx) const
    {
        std::pair<int,int> p;
        for (int row = 0; row < 8; row++) {
            for(int col = 0; col < 8; col++) {
                if (cellActiveByNdx(row, col)) {
                    p.first = row;
                    p.second = col;
                    actCellsNdx.insert(p);
                }
            }
        }

    }

    // ---------------------------------------------------------------------
    void BitBoard::stateToPosSet(BitBoardState s, std::set<std::string> &posSet)
    {
        BitBoard tmpBB(s);
        tmpBB.activeCells(posSet);
    }

    std::pair<int,int> BitBoard::posToCoordinates(const std::string &pos)
    {
        std::pair<int, int> coords = {INVALID_COORD , INVALID_COORD};
        if (isValidPos(pos)) {
            coords.first = pos.at(0) - 'a';
            coords.second = pos.at(1) - '1';
        }
        return coords;
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

    BitBoardState BitBoard::pos2state(const std::string &pos)
    {
        return 1ULL << posToBitPos(pos);
    }

    bool BitBoard::cellActiveByNdx(int row, int col) const
    {
        if (isValidCoords(row, col))
            return ((bbs & (1ULL << (row * 8 + col))) != 0);
        return false;
    }

} // namespace cppboard
