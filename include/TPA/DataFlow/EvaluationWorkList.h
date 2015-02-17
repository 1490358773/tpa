#ifndef TPA_EVALUATION_WORKLIST_H
#define TPA_EVALUATION_WORKLIST_H

#include "Utils/Hashing.h"
#include "Utils/WorkList.h"

#include <unordered_map>

namespace tpa
{

class Context;

template <typename GraphType>
class EvaluationWorkList
{
private:
	using NodeType = typename GraphType::NodeType;

	// The function-level worklist
	using ContextFunctionPair = std::pair<const Context*, const GraphType*>;
	using FunctionWorkList = WorkList<ContextFunctionPair, PairHasher<const Context*, const GraphType*>>;

	// The intra-procedural level worklist
	struct PrioCompare
	{
		bool operator()(const NodeType* n0, const NodeType* n1) const
		{
			return n0->getPriority() < n1->getPriority();
		}
	};
public:
	using LocalWorkList = PrioWorkList<const NodeType*, PrioCompare>;
private:
	using WorkListMap = std::unordered_map<ContextFunctionPair, LocalWorkList, PairHasher<const Context*, const GraphType*>>;

	FunctionWorkList funWorkList;
	WorkListMap workListMap;
public:
	EvaluationWorkList() = default;

	bool isEmpty() const
	{
		return funWorkList.isEmpty();
	}

	void enqueue(const Context* ctx, const GraphType* g, const NodeType* node)
	{
		auto pair = std::make_pair(ctx, g);
		funWorkList.enqueue(pair);
		workListMap[pair].enqueue(node);
	}

	ContextFunctionPair dequeue()
	{
		assert(!funWorkList.isEmpty());
		return funWorkList.dequeue();
	}

	LocalWorkList& getLocalWorkList(const Context* ctx, const GraphType* g)
	{
		auto itr = workListMap.find(std::make_pair(ctx, g));
		assert(itr != workListMap.end());
		// The dequeued worklist may be empty if recursive call is involved
		//assert(!itr->second.isEmpty());
		return itr->second;
	}
};

}

#endif
