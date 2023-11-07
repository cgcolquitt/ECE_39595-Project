#ifndef MAP_H_
#define MAP_H_
#include "DoubleStruct.h"
#include <string>
#include <map>

class Map {
public:
   virtual void insert(std::string loc, Double loclen);
   virtual void insertSub(std::string loc, Double loclen);

   std::map<std::string, Double> SYMBOLmap;
   std::map<std::string, Double> SYMBOLmapSub;
};
#endif /* MAP_H_ */