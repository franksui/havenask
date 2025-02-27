/*
 * Copyright 2014-present Alibaba Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include "Allocators.h"

namespace iquan {

template <typename T, typename Alloc>
class StrongRef;

template <typename T>
class AliasRef;

template <typename T>
using LocalRef = StrongRef<T, LocalAllocator>;

template <typename T>
using GlobalRef = StrongRef<T, GlobalAllocator>;

template <typename T>
struct jnipp_remove_ref;

template <typename T>
struct jnipp_remove_ref {
    using type = T;
};

template <typename T, typename Alloc>
struct jnipp_remove_ref<StrongRef<T, Alloc>> {
    using type = T;
};

template <typename T>
struct jnipp_remove_ref<AliasRef<T>> {
    using type = T;
};

template <typename T>
using jnipp_remove_ref_t = typename jnipp_remove_ref<T>::type;

} // namespace iquan
