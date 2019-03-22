/*******************************************************************************
 * CLI - A simple command line interface.
 * Copyright (C) 2019 Daniele Pallastrelli
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

#include <boost/test/unit_test.hpp>
#include "cli/history.h"

using namespace cli;
using namespace cli::detail;

BOOST_AUTO_TEST_SUITE(HistorySuite)

/*
content
- time_0_cmd
- time_1_cmd
- time_2_cmd
- time_3_cmd
- current_editing

arrow up goes through:
- current_editing
- time_3_cmd
- time_2_cmd
- time_1_cmd
- time_0_cmd (and stops here)

arrow down stops at "current_editing"
*/

BOOST_AUTO_TEST_CASE(NotFull)
{
    History history(10);
    history.NewCommand("item1");
    history.NewCommand("item2");
    history.NewCommand("item3");
    history.NewCommand("item4");

    BOOST_CHECK_EQUAL(history.Previous(""), "item4");
    BOOST_CHECK_EQUAL(history.Next(), "");
}

#if 0
BOOST_AUTO_TEST_CASE(Full)
{
    History history(3);
    history.Add("item1");
    history.Add("item2");
    history.Add("item3");
    history.Add("item4");

    BOOST_CHECK_EQUAL(history.GetCurrent(), "item4");
    history.ToPreviousEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item3");
    history.ToNextEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item4");
    history.ToNextEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item4");
    history.ToNextEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item4");

    history.ToPreviousEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item3");
    history.ToPreviousEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item2");
    history.ToPreviousEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item2");
    history.ToPreviousEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item2");

    history.ToNextEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item3");
    history.ToNextEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item4");
    history.ToPreviousEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item3");
    history.ToPreviousEntry();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item2");

    history.ResetCurrent();
    BOOST_CHECK_EQUAL(history.GetCurrent(), "item4");
}
#endif

BOOST_AUTO_TEST_SUITE_END()