/*
 * Copyright (c) 2020-2024, NVIDIA CORPORATION.  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <cuda_fp16.h>

#include "tensorrt_llm/common/cudaUtils.h"
#include "tensorrt_llm/kernels/penaltyTypes.h"
#include "tensorrt_llm/runtime/common.h"

namespace tensorrt_llm
{
namespace kernels
{

template <typename T>
struct InvokeBatchApplyPenaltyParams
{
    T const* const* inputLogits;
    T* outputLogits;
    T const* biases;
    runtime::TokenIdType* penaltyWorkspace;
    runtime::TokenIdType const* penaltyWorkspacePrev;
    float const* temperatures;
    float const* repetitionPenalties;
    float const* presencePenalties;
    float const* frequencyPenalties;
    bool const accumulateVocab;
    runtime::SizeType const batchSize;
    runtime::SizeType const beamWidth;
    runtime::SizeType const maxSeqLen;
    runtime::SizeType const vocabSize;
    runtime::SizeType const vocabSizePadded;
    runtime::TokenIdType const** outputIdsPtr;
    runtime::SizeType32 const** parentIdsPtr;
    runtime::SizeType32 const* inputLengths;
    runtime::SizeType32 const* sequenceLengths;
    runtime::SizeType32 const* minLengths;
    runtime::TokenIdType const* endIds;
    runtime::SizeType32 const* batchSlots;
    runtime::SizeType const maxTokensPerStep;
    runtime::SizeType32 const* tokensPerStep;
    cudaStream_t stream;
};

template <typename T>
void invokeBatchApplyPenalty(InvokeBatchApplyPenaltyParams<T> const& params);

} // namespace kernels
} // namespace tensorrt_llm
