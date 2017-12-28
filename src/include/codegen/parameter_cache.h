//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// parameter_cache.h
//
// Identification: src/include/codegen/parameter_cache.h
//
// Copyright (c) 2015-2017, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#pragma once

#include "codegen/codegen.h"
#include "codegen/query_parameters_map.h"
#include "codegen/value.h"
#include "expression/parameter.h"
#include "type/type.h"

namespace peloton {
namespace codegen {

//===----------------------------------------------------------------------===//
// A parameter cache which stores the parameterized values for codegen runtime
//===----------------------------------------------------------------------===//
class ParameterCache {
 public:
  // Constructor
  ParameterCache(const QueryParametersMap &map) : parameters_map_(map) {}

  // Get the codegen value for the specific index
  codegen::Value GetValue(CodeGen &codegen,
                          llvm::Value *query_parameters_ptr,
                          uint32_t index) const;

 private:
  codegen::Value DeriveParameterValue(CodeGen &codegen,
      llvm::Value *query_parameters_ptr, uint32_t index,
      peloton::type::TypeId type_id, bool is_nullable) const;

 private:
  // Parameter information
  const QueryParametersMap &parameters_map_;

  // Parameter value storage
  std::vector<codegen::Value> values_;
};

}  // namespace codegen
}  // namespace peloton
