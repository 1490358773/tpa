#include "Context/Context.h"
#include "PointerAnalysis/Analysis/SemiSparsePointerAnalysis.h"
#include "TaintAnalysis/Engine/TaintGlobalState.h"
#include "TaintAnalysis/Engine/Initializer.h"
#include "TaintAnalysis/Program/DefUseModule.h"
#include "TaintAnalysis/Support/TaintEnv.h"
#include "TaintAnalysis/Support/TaintMemo.h"

#include <llvm/IR/Function.h>

using namespace context;

namespace taint
{

Initializer::Initializer(TaintGlobalState& g, TaintMemo& m): duModule(g.getDefUseModule()), env(g.getEnv()), ptrAnalysis(g.getPointerAnalysis()), memo(m)
{
}

void Initializer::initializeMainArgs(TaintStore& store)
{
	auto const& entryFunc = duModule.getEntryFunction().getFunction();
	auto globalCtx = Context::getGlobalContext();
	if (entryFunc.arg_size() > 1)
	{
		// argv is not tainted
		auto argvValue = (++entryFunc.arg_begin());
		env.strongUpdate(TaintValue(globalCtx, argvValue), TaintLattice::Untainted);

		// *argv and **argv are tainted
		auto argvObj = ptrAnalysis.getMemoryManager().getArgvObject();
		store.strongUpdate(argvObj, TaintLattice::Tainted);
	}
}

void Initializer::initializeExternalGlobalVariables(TaintStore& store)
{
	auto globalCtx = Context::getGlobalContext();
	for (auto const& global: duModule.getModule().globals())
	{
		if (global.isDeclaration())
		{
			auto pSet = ptrAnalysis.getPtsSet(globalCtx, &global);
			for (auto obj: pSet)
				store.strongUpdate(obj, TaintLattice::Untainted);
		}
	}
	store.strongUpdate(ptrAnalysis.getMemoryManager().getUniversalObject(), TaintLattice::Either);
}

WorkList Initializer::runOnInitState(TaintStore&& initStore)
{
	WorkList workList;

	initializeMainArgs(initStore);
	initializeExternalGlobalVariables(initStore);

	auto entryCtx = context::Context::getGlobalContext();
	auto entryInst = duModule.getEntryFunction().getEntryInst();
	assert(entryInst != nullptr);
	
	auto pp = ProgramPoint(entryCtx, entryInst);
	memo.update(pp, std::move(initStore));
	workList.enqueue(pp);

	return workList;
}

}