#include "cppboard/knightsboard.h"

namespace cppboard
{
    // ---------------------------------------------------------------------
    // Constructors (see header)

    // ---------------------------------------------------------------------
    // Public methods
    void KnightsBoard::validMoves(std::set<std::string> &posSet) const
    {
        std::set<std::string> actCells;
        // extracts the active cells
        activeCells(actCells);
        for (auto c: actCells) {
            addValidMovesForPos(c, actCells);
        }

    }

    // ---------------------------------------------------------------------
    // Private methods
    void KnightsBoard::addValidMovesForPos(const std::string &pos,
                                  std::set<std::string> &actCells)
    {
        std::pair<int,int> coords = posToCoordinates(pos);
        std::pair<int,int> tentativeCoords;

        // FIXME TO BE COMPLETED ....
        // +2 row -1 column
        //if (isValidCoords(coord.first + 2, coords.second - 1))
        //{}
        //tentativeCoords.first = coords.first + 2;
        //tentativeCoords.second = coords.second - 1;
        //tempCells.insert({(c.at(0) - 1), (c.at(1) + 2)});
        //}
        // +2 row +1 column
        // +1 row +2 column
        // -1 row +2 column
        // -2 row +1 column
        // -2 row -1 column
        // -1 row -2 column
        // +1 row -2 column

    }

} // namespace cppboard
