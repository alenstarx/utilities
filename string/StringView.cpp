// Copyright 2014 The Android Open Source Project
//
// This software is licensed under the terms of the GNU General Public
// License version 2, as published by the Free Software Foundation, and
// may be copied, distributed, and modified under those terms.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

#include "StringView.h"

#include <algorithm>

int StringView::compare(const StringView& other) const {
    size_t minSize = std::min(mSize, other.size());
    if (!minSize) return true;
    int ret = memcmp(mString, other.str(), minSize);
    if (ret) return ret;
    if (mSize < other.size()) return -1;
    if (mSize > other.size()) return +1;
    return 0;
}

bool operator==(const StringView& x, const StringView& y) {
    if (x.size() != y.size()) return false;
    return !memcmp(x.str(), y.str(), x.size());
}

