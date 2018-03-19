/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ART_RUNTIME_VERIFY_OBJECT_INL_H_
#define ART_RUNTIME_VERIFY_OBJECT_INL_H_

#include <museum/8.1.0/art/runtime/verify_object.h>

#include <museum/8.1.0/art/runtime/mirror/object-inl.h>
#include <museum/8.1.0/art/runtime/obj_ptr-inl.h>

namespace facebook { namespace museum { namespace MUSEUM_VERSION { namespace art {

inline bool VerifyClassClass(ObjPtr<mirror::Class> c) {
  if (UNLIKELY(c == nullptr)) {
    return false;
  }
  // Note: We pass in flags to ensure that the accessors don't call VerifyObject.
  mirror::Class* c_c = c->GetClass<kVerifyNone>();
  return c_c != nullptr && c_c == c_c->GetClass<kVerifyNone>();
}

} } } } // namespace facebook::museum::MUSEUM_VERSION::art

#endif  // ART_RUNTIME_VERIFY_OBJECT_INL_H_