/*
 * Copyright (c) 2019 Broadcom.
 * The term "Broadcom" refers to Broadcom Inc. and/or its subsidiaries.
 *
 * This program and the accompanying materials are made
 * available under the terms of the Eclipse Public License 2.0
 * which is available at https://www.eclipse.org/legal/epl-2.0/
 *
 * SPDX-License-Identifier: EPL-2.0
 *
 * Contributors:
 *   Broadcom, Inc. - initial API and implementation
 */

#ifndef HLASMPLUGIN_PARSERLIBARY_FUZZERTEST_H
#define HLASMPLUGIN_PARSERLIBARY_FUZZERTEST_H
#include "common_testing.h"

TEST(fuzzer_test, entry_1)
{
	std::string input(R"(:'0:', A $sMNOP A
T (.~A
n N ICT
M(A la s
 NL
gA 
~a s
A la s
&Q,EU,,,T  &$=>"+<+++-



 COMM&u
&z[&%



%'l-**$D'  M C'&CAd
;
N ORG (.(. ))C )");

	analyzer a(input);
	a.analyze();
}

TEST(fuzzer_test, entry_2)
{
    std::string input(" ACTR LL'BTM 'M('SM''S(~''#S)((");

    analyzer a(input);
    a.analyze();
}

TEST(fuzzer_test, entry_3)
{
    std::string input(" (_=&LOCTRCEv(&ISEQ(--S'#)HUBP #' #&3#");

    analyzer a(input);
    a.analyze();
}

TEST(fuzzer_test, entry_4)
{
    std::string input(R"( @(PUSH@(&@(@+( ED'))D))))))))))9@(&@(@+( ED'BRXH))p(r
R
)");

    analyzer a(input);
    a.analyze();
}

#endif