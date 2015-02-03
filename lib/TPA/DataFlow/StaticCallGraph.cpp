#include "DataFlow/StaticCallGraph.h"

using namespace llvm;

namespace tpa
{

template <typename MapType, typename KeyType, typename ValueType>
static inline bool insertMap(MapType& m, const KeyType& k, const ValueType& v)
{
	using VectorType = SortedVectorSet<ValueType>;

	auto insertPair = m.insert(std::make_pair(k, VectorType()));
	auto setChanged = insertPair.first->second.insert(v);

	return insertPair.second || setChanged;
}

bool StaticCallGraph::insertCallEdge(CallSiteType callSite, CallTargetType callTgt)
{
	auto ret0 = insertMap(callMap, callSite, callTgt);
	auto ret1 = insertMap(revCallMap, callTgt, callSite);
	return ret0 || ret1;
	//callMap[callSite].insert(callTgt);
	//revCallMap[callTgt].insert(callSite);
}

iterator_range<StaticCallGraph::CallTargetVectorConstIterator> StaticCallGraph::getCallTargets(CallSiteType callSite) const
{
	auto itr = callMap.find(callSite);
	if (itr == callMap.end())
		return iterator_range<CallTargetVectorConstIterator>(CallTargetVectorConstIterator(), CallTargetVectorConstIterator());
	else
		return iterator_range<CallTargetVectorConstIterator>(itr->second.begin(), itr->second.end());
}

iterator_range<StaticCallGraph::CallSiteVectorConstIterator> StaticCallGraph::getCallSites(CallTargetType callTgt) const
{
	auto itr = revCallMap.find(callTgt);
	if (itr == revCallMap.end())
		return iterator_range<CallSiteVectorConstIterator>(CallSiteVectorConstIterator(), CallSiteVectorConstIterator());
	else
		return iterator_range<CallSiteVectorConstIterator>(itr->second.begin(), itr->second.end());
}

}
