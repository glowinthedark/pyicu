# ====================================================================
# Copyright (c) 2024 Open Source Applications Foundation.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
# OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
# ====================================================================
#

from unittest import TestCase, main
from icu import *

class TestIntPropertyMap(TestCase):

    def testGet(self):

        eastAsianWidthMap = Char.getIntPropertyMap(UProperty.EAST_ASIAN_WIDTH)
        self.assertEqual(0, eastAsianWidthMap.get(ord(u'क')))  # Neutral
        self.assertEqual(1, eastAsianWidthMap.get(ord(u'○')))  # Ambiguous
        self.assertEqual(2, eastAsianWidthMap.get(ord(u'ｶ')))  # Halfwidth
        self.assertEqual(3, eastAsianWidthMap.get(ord(u'ａ')))  # Fullwidth
        self.assertEqual(4, eastAsianWidthMap.get(ord(u'a')))  # Narrow
        self.assertEqual(5, eastAsianWidthMap.get(ord(u'😄')))  # Wide


if __name__ == "__main__":
    main()
