#include <map>
#include "DoubleStruct.h"
#include "Map.h"

void Map::insert(std::string loc, Double loclen) {
   SYMBOLmap.insert({loc, loclen});
}

void Map::insertSub(std::string loc, Double loclen) {
   SYMBOLmapSub.insert({loc, loclen});
}