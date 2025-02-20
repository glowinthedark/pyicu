/* ====================================================================
 * Copyright (c) 2004-2010 Open Source Applications Foundation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions: 
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software. 
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * ====================================================================
 */

#ifndef _numberformat_h
#define _numberformat_h

extern PyTypeObject NumberFormatType_;

PyObject *wrap_NumberFormat(NumberFormat *, int);
PyObject *wrap_DecimalFormat(DecimalFormat *, int);
PyObject *wrap_RuleBasedNumberFormat(RuleBasedNumberFormat *, int);
PyObject *wrap_ChoiceFormat(ChoiceFormat *, int);

#if U_ICU_VERSION_HEX >= VERSION_HEX(64, 0, 0)

class t_formattednumber : public _wrapper {
public:
    icu::number::FormattedNumber *object;
    ConstrainedFieldPosition cfp;  // for iterator on t_formattedvalue
};

class t_formattednumberrange : public _wrapper {
public:
    icu::number::FormattedNumberRange *object;
    ConstrainedFieldPosition cfp;  // for iterator on t_formattedvalue
};

extern PyTypeObject FormattedNumberType_;
extern PyTypeObject FormattedNumberRangeType_;

PyObject *wrap_FormattedNumber(icu::number::FormattedNumber *object, int flag);
PyObject *wrap_FormattedNumberRange(
    icu::number::FormattedNumberRange *object, int flag);

#endif

void _init_numberformat(PyObject *m);


#endif /* _numberformat_h */
