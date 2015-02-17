#ifndef TPA_MEMO_H
#define TPA_MEMO_H

#include "MemoryModel/PtsSet/StoreManager.h"

#include <llvm/ADT/DenseMap.h>

#include <experimental/optional>

namespace tpa
{

class Context;

template <typename NodeType>
class Memo
{
private:
	using KeyType = std::pair<const Context*, const NodeType*>;
	using MapType = llvm::DenseMap<KeyType, Store>;

	StoreManager& storeManager;

	MapType memo;
public:
	Memo(StoreManager& s): storeManager(s) {}

	bool hasMemoState(const Context* ctx, const NodeType* node) const
	{
		return memo.count(std::make_pair(ctx, node));
	}

	std::experimental::optional<Store> lookup(const Context* ctx, const NodeType* node) const
	{
		auto itr = memo.find(std::make_pair(ctx, node));
		if (itr == memo.end())
			return std::experimental::optional<Store>();
		else
			return itr->second;
	}

	// Return true if the memo changes
	bool updateMemo(const Context* ctx, const NodeType* node, const Store& store)
	{
		auto key = std::make_pair(ctx, node);
		auto itr = memo.find(key);
		if (itr == memo.end())
		{
			memo.insert(std::make_pair(key, store));
			return true;
		}
		else
		{
			return storeManager.mergeStore(itr->second, store);
		}
	}

	bool updateMemo(const Context* ctx, const NodeType* node, const MemoryLocation* loc, const PtsSet* pSet)
	{
		auto key = std::make_pair(ctx, node);
		auto itr = memo.find(key);
		if (itr == memo.end())
		{
			auto emptyStore = storeManager.getEmptyStore();
			storeManager.strongUpdate(emptyStore, loc, pSet);
			memo.insert(std::make_pair(key, std::move(emptyStore)));
			return true;
		}
		else
		{
			return storeManager.weakUpdate(itr->second, loc, pSet);
		}
	}

	void clear() { memo.clear(); }
};

}

#endif
