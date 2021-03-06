#pragma once

#include "xact/generalized_cas_1/Operation.h"
#include "xact/generalized_cas_1/Precondition.h"
#include <cstddef>
#include <vector>

namespace xact { namespace generalized_cas_1 {

class VectorStoragePolicy {
 protected:
  std::vector<Precondition> preconditions_;
  std::vector<Operation> operations_;
 public:
  Precondition* getPreconditionStorage();
  size_t getPreconditionCount() const;
  Operation* getOperationStorage();
  size_t getOperationCount() const;
  void pushPrecondition(const Precondition& condition);
  void pushPrecondition(Precondition&& condition);
  void pushOperation(const Operation& operation);
  void pushOperation(Operation&& operation);

  void clearPreconditionStorage();
  void clearOperationStorage();
};

}} // xact::generalized_cas_1
