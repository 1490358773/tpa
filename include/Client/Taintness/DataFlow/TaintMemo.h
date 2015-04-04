#ifndef TPA_TAINT_MEMO_H
#define TPA_TAINT_MEMO_H

#include "Client/Taintness/DataFlow/TaintEnvStore.h"
#include "MemoryModel/Precision/ProgramLocation.h"

#include <unordered_map>

namespace tpa
{
	class MemoryLocation;
}

namespace client
{
namespace taint
{

class TaintMemo
{
private:
	std::unordered_map<tpa::ProgramLocation, TaintStore> memo;
public:
	using const_iterator = decltype(memo)::const_iterator;

	TaintMemo() = default;

	// Return NULL if key not found
	const TaintStore* lookup(const tpa::ProgramLocation& pLoc) const
	{
		auto itr = memo.find(pLoc);
		if (itr == memo.end())
			return nullptr;
		else
			return &itr->second;
	}

	bool insert(const tpa::ProgramLocation& pLoc, const tpa::MemoryLocation* loc, TaintLattice tVal)
	{
		auto itr = memo.find(pLoc);
		if (itr == memo.end())
		{
			itr = memo.insert(std::make_pair(pLoc, TaintStore())).first;
		}
		
		return itr->second.weakUpdate(loc, tVal);
	}

	void update(const tpa::ProgramLocation& pLoc, TaintStore&& store)
	{
		memo[pLoc] = std::move(store);
	}

	const_iterator begin() const { return memo.begin(); }
	const_iterator end() const { return memo.end(); }
};

}
}

#endif