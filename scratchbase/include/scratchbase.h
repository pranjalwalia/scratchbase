#ifndef SCRATCHBASE_H
#define SCRATCHBASE_H

#include <string>
#include <memory>

// WARNING: This should ONLY include Client API files
// i.e. NOT anything within include/extensions!

#include "database.h"

namespace scratchbase {

  class ScratchBase {
  public:
    ScratchBase();

    static std::unique_ptr<IDatabase> createEmptyDB(std::string& dbname);
    static std::unique_ptr<IDatabase> createEmptyDB(std::string& dbname, 
    std::unique_ptr<KeyValueStore>& kvStore);
    static std::unique_ptr<IDatabase> loadDB(std::string& dbname);
  };

}

#endif // SCRATCHBASE_H