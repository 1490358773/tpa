#ifndef TPA_DEF_USE_FUNCTION_EVALUATOR_H
#define TPA_DEF_USE_FUNCTION_EVALUATOR_H

#include "Client/Taintness/DataFlow/TaintEnvStore.h"
#include "PointerAnalysis/DataFlow/DefUseModule.h"
#include "TPA/DataFlow/TPAWorkList.h"

#include <llvm/IR/CallSite.h>

namespace tpa
{
	class Context;
	class DefUseFunction;
}

namespace client
{
namespace taint
{

class TaintGlobalState;
class TaintTransferFunction;

class DefUseFunctionEvaluator
{
private:
	const tpa::Context* ctx;
	const tpa::DefUseFunction* duFunc;

	TaintGlobalState& globalState;

	using GlobalWorkListType = tpa::TPAWorkList<tpa::DefUseFunction>;
	using LocalWorkListType = typename GlobalWorkListType::LocalWorkList;
	GlobalWorkListType& globalWorkList;
	LocalWorkListType& localWorkList;

	TaintTransferFunction& transferFunction;

	void evalEntry(const tpa::DefUseInstruction*, const TaintStore&);
	void evalCall(const tpa::DefUseInstruction*, const TaintStore&);
	void applyCall(const tpa::DefUseInstruction*, const tpa::Context*, const llvm::Function*, const TaintStore&);
	void applyExternalCall(const tpa::DefUseInstruction*, const llvm::Function*, const TaintStore&);
	void evalReturn(const tpa::DefUseInstruction*, const TaintStore&);
	void applyReturn(const tpa::Context*, const llvm::Instruction*, std::experimental::optional<TaintLattice>, const TaintStore&);
	void evalInst(const tpa::DefUseInstruction*, const TaintStore&);

	std::experimental::optional<TaintLattice> getReturnTaintValue(const tpa::DefUseInstruction*);
	std::vector<TaintLattice> collectArgumentTaintValue(llvm::ImmutableCallSite, const llvm::Function*);
	bool updateParamTaintValue(const tpa::Context*, const llvm::Function*, const std::vector<TaintLattice>&);

	void propagateGlobalState(const tpa::Context*, const tpa::DefUseFunction*, const tpa::DefUseInstruction*, const TaintStore&, bool);
	void propagateState(const tpa::DefUseInstruction*, const TaintStore&, bool, bool);
	void propagateTopLevelChange(const tpa::DefUseInstruction*, bool, LocalWorkListType& workList);
	void propagateMemLevelChange(const tpa::DefUseInstruction*, const TaintStore&, bool, const tpa::Context*, LocalWorkListType& workList);
public:
	DefUseFunctionEvaluator(const tpa::Context* c, const tpa::DefUseFunction* f, TaintGlobalState& g, GlobalWorkListType& gl, TaintTransferFunction& t);
	void eval();
};

}
}

#endif
