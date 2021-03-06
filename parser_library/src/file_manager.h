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

#ifndef HLASMPLUGIN_PARSERLIBRARY_FILE_MANAGER_H
#define HLASMPLUGIN_PARSERLIBRARY_FILE_MANAGER_H

#include <string>
#include <unordered_map>
#include <filesystem>
#include <vector>

#include "file.h"
#include "diagnosable.h"
#include "processor.h"

namespace hlasm_plugin {
namespace parser_library {

using file_ptr = std::shared_ptr<file>;
using processor_file_ptr = std::shared_ptr<processor_file>;

class file_manager : public virtual diagnosable
{
public:
	virtual file_ptr add_file(const file_uri &) = 0;
	virtual processor_file_ptr add_processor_file(const file_uri &) = 0;
	virtual void remove_file(const file_uri&) = 0;

	virtual file_ptr find(const std::string & key) = 0;
	virtual processor_file_ptr find_processor_file(const std::string & key) = 0;

    virtual std::unordered_map<std::string, std::string> list_directory_files(const std::string & path) = 0;

	virtual bool file_exists(const std::string & file_name) = 0;
	virtual bool lib_file_exists(const std::string & lib_path, const std::string & file_name) = 0;

	virtual void did_open_file(const std::string & document_uri, version_t version, std::string text) = 0;
	virtual void did_change_file(const std::string & document_uri, version_t version, const document_change * changes, size_t ch_size) = 0;
	virtual void did_close_file(const std::string & document_uri) = 0;
};

}
}
#endif // FILE_MANAGER_H
