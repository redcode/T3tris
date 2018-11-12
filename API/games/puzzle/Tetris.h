/* Tetris Game Logic
 ______ ____ ______ ______ __  _____
|_    _|  __|_    _|  _  /|__|/  __/
  |  | |  _|  |  | |     \|  |\__  \
- |__| |____| |__| |__|\__|__|/____/ -----------------------------------------
Copyright (C) 2000-2018 Manuel Sainz de Baranda y Goñi.

This library is free software:  you can redistribute it and/or modify it under
the terms of the GNU General Public License as published  by the Free Software
Foundation, either  version 3 of  the License, or  (at your option)  any later
version.

This library is distributed  in the hope that it will  be useful,  but WITHOUT
ANY WARRANTY; without even the  implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received  a copy of the GNU General Public License  along with
this library. If not, see <http://www.gnu.org/licenses/>.
--------------------------------------------------------------------------- */

#ifndef _games_puzzle_Tetris_H_
#define _games_puzzle_Tetris_H_

#include <Z/types/base.h>

#ifndef TETRIS_API
#	ifdef TETRIS_STATIC
#		define TETRIS_API
#	else
#		define TETRIS_API Z_API
#	endif
#endif

#define TETRIS_PIECE_COUNT	 7
#define TETRIS_INSERTION_PADDING 3
#define TETRIS_MINIMUM_WIDTH	 8
#define TETRIS_MINIMUM_HEIGHT	 8

typedef union {
	zuint8 value;

	struct {Z_BIT_FIELD(8, 5) (
		zuint8 top_edge    :1,
		zuint8 right_edge  :1,
		zuint8 bottom_edge :1,
		zuint8 left_edge   :1,
		zuint8 piece_index :4
	)} fields;
} TetrisCell;

#define TETRIS_CELL_MASK_TOP_EDGE    0x80
#define TETRIS_CELL_MASK_RIGHT_EDGE  0x40
#define TETRIS_CELL_MASK_BOTTOM_EDGE 0x20
#define TETRIS_CELL_MASK_LEFT_EDGE   0x10
#define TETRIS_CELL_MASK_COLOR_INDEX 0x0F

typedef struct {
	TetrisCell matrix[4][4];
	Z2DSInt8   a, b;
} TetrisPiece;

typedef struct {
	TetrisCell*	   matrix;
	TetrisPiece const* piece;
	TetrisPiece const* next_piece;
	Z2DSInt8	   matrix_size;
	Z2DSInt8	   piece_point;
	zuint8		   piece_rotation;
	zuint8		   piece_index;
	zuint8		   next_piece_index;
	zsint8		   top;
	zsint8		   full_row_indices[4];
	zuint8		   full_row_count;
} Tetris;

typedef zuint8 TetrisResult;

#define TETRIS_RESULT_OK	   0
#define TETRIS_RESULT_HIT	   1
#define TETRIS_RESULT_CONSOLIDATED 2
#define TETRIS_RESULT_GAME_OVER    3

typedef zsint8 TetrisDirection;

#define TETRIS_DIRECTION_DOWN	0
#define TETRIS_DIRECTION_LEFT  -1
#define TETRIS_DIRECTION_RIGHT	1

Z_C_SYMBOLS_BEGIN

TETRIS_API extern TetrisPiece const tetris_pieces[TETRIS_PIECE_COUNT][4];

TETRIS_API void		tetris_initialize      (Tetris*		object,
						TetrisCell*	matrix,
						Z2DSInt8	matrix_size,
						zuint8		next_piece_index);

TETRIS_API void		tetris_insert_piece    (Tetris*		object,
						zuint8		next_piece_index);

TETRIS_API TetrisResult tetris_move_piece      (Tetris*		object,
						TetrisDirection direction);

TETRIS_API TetrisResult tetris_rotate_piece    (Tetris*		object,
						TetrisDirection	direction);

TETRIS_API TetrisResult tetris_drop_piece      (Tetris*		object);

TETRIS_API void		tetris_remove_full_rows(Tetris*		object);

Z_C_SYMBOLS_END

#endif /* _games_puzzle_Tetris_H_ */
