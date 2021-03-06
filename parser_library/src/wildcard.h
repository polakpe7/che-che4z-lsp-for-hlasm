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

#ifndef HLASMPLUGIN_PARSERLIBRARY_WILDCARD_H
#define HLASMPLUGIN_PARSERLIBRARY_WILDCARD_H

#include <regex>

namespace hlasm_plugin {
namespace parser_library {

static const std::regex escape("(\\(|\\[|\\{|\\\\|\\^|\\-|\\=|\\$|\\!|\\||\\]|\\}|\\)|\\.)");
static const std::regex question("\\?");
static const std::regex nongreedy("(\\*|\\+)");
static const std::regex slash("\\/");

std::regex wildcard2regex(const std::string& wildcard);
}
}

#endif