#ifndef __OBLOCK_H__
#define __OBLOCK_H__
#include "block.h"

class OBlock : public Block {
  public:
	OBlock(Board *b, int lvl);
	~OBlock();
	
	void clockwise(Board *b);
	void counterclockwise(Board *b);
};

#endif