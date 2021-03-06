// Copyright (C) 2012  Internet Systems Consortium, Inc. ("ISC")
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#ifndef DATASRC_MEMORY_SEGMENT_TEST_H
#define DATASRC_MEMORY_SEGMENT_TEST_H 1

#include <util/memory_segment_local.h>

#include <cstddef>              // for size_t
#include <new>                  // for bad_alloc

namespace bundy {
namespace datasrc {
namespace memory {
namespace test {

// A special memory segment that can be used for tests.  It normally behaves
// like a "local" memory segment.  If "throw count" is set to non 0 via
// setThrowCount(), it continues the normal behavior until the specified
// number of calls to allocate(), exclusive, and throws an exception at the
// next call.  For example, if count is set to 3, the next two calls to
// allocate() will succeed, and the 3rd call will fail with an exception.
// This segment object can be used after the exception is thrown, and the
// count is internally reset to 0.
class MemorySegmentMock : public bundy::util::MemorySegmentLocal {
public:
    MemorySegmentMock() : throw_count_(0) {}
    virtual void* allocate(std::size_t size) {
        if (throw_count_ > 0) {
            if (--throw_count_ == 0) {
                throw std::bad_alloc();
            }
        }
        return (bundy::util::MemorySegmentLocal::allocate(size));
    }
    void setThrowCount(std::size_t count) { throw_count_ = count; }

private:
    std::size_t throw_count_;
};

} // namespace test
} // namespace memory
} // namespace datasrc
} // namespace bundy

#endif // DATASRC_MEMORY_SEGMENT_TEST_H

// Local Variables:
// mode: c++
// End:
