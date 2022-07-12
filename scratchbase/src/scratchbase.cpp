#include "scratchbase.h"
#include "extensions/extdatabase.h"

using namespace scratchbase;
using namespace scratchbaseext;

ScratchBase::ScratchBase()
{

}

std::unique_ptr<IDatabase> ScratchBase::createEmptyDB(std::string &dbname) {
  return EmbeddedDatabase::createEmpty(dbname);
}

std::unique_ptr<IDatabase> ScratchBase::createEmptyDB(std::string &dbname,std::unique_ptr<KeyValueStore>& kvStore) {
  return EmbeddedDatabase::createEmpty(dbname,kvStore);
}

std::unique_ptr<IDatabase> ScratchBase::loadDB(std::string &dbname) {
  return EmbeddedDatabase::load(dbname);
}