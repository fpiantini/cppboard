#if !defined CPPBOARD_UNICHESSPSET_HEADER
#define CPPBOARD_UNICHESSPSET_HEADER

#include <string>
#include <set>

#include "cppboard/bitboard.h"

namespace cppboard
{

  // Class for uniform chess piece set representation.
  // Can be a single piece or a set of pieces
  class UniformChessPieceSet
  {
    public:
      BitBoardState pieceBoard() const { return ClearBoard; }
  };

} // namespace cppboard

#endif // #if !defined CPPBOARD_UNICHESSPSET_HEADER
