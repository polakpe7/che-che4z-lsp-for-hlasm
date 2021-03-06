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

#ifndef HLASMPLUGIN_PARSERLIBRARY_EXPRESSIONS_MACH_EXPR_TERM_H
#define HLASMPLUGIN_PARSERLIBRARY_EXPRESSIONS_MACH_EXPR_TERM_H

#include "mach_expression.h"
#include "../context/id_storage.h"

namespace hlasm_plugin::parser_library::expressions
{

class mach_expr_constant : public mach_expression
{
	value_t value_;
public:
	mach_expr_constant(std::string value_text, range rng);
	mach_expr_constant(int value, range rng);

	context::dependency_collector get_dependencies(context::dependency_solver& solver) const override;

	virtual value_t evaluate(mach_evaluate_info info) const override;

	virtual void fill_location_counter(context::address addr) override;

	virtual const mach_expression* leftmost_term() const override;

	void collect_diags() const override {}
};

class mach_expr_data_attr : public mach_expression
{
public:
	mach_expr_data_attr(context::id_index value, context::data_attr_kind attribute, range rng);

	context::id_index value;
	context::data_attr_kind attribute;

	context::dependency_collector get_dependencies(context::dependency_solver& solver) const override;

	virtual value_t evaluate(mach_evaluate_info info) const override;

	virtual void fill_location_counter(context::address addr) override;

	virtual const mach_expression* leftmost_term() const override;

	void collect_diags() const override {}
};

class mach_expr_symbol : public mach_expression
{
	
public:
	mach_expr_symbol(context::id_index value, range rng);

	context::id_index value;
	mach_expr_data_attr len_expr;

	static mach_expr_ptr from_id(context::id_index id, range rng);

	context::dependency_collector get_dependencies(context::dependency_solver& solver) const override;

	virtual value_t evaluate(mach_evaluate_info info) const override;

	virtual void fill_location_counter(context::address addr) override;

	virtual const mach_expression* leftmost_term() const override;

	void collect_diags() const override {}
};

class mach_expr_location_counter : public mach_expression
{
public:
	std::optional<context::address> location_counter;

	mach_expr_location_counter(range rng);

	context::dependency_collector get_dependencies(context::dependency_solver& solver) const override;

	virtual value_t evaluate(mach_evaluate_info info) const override;

	virtual void fill_location_counter(context::address addr) override;

	virtual const mach_expression* leftmost_term() const override;

	void collect_diags() const override {}
};

class mach_expr_self_def : public mach_expression
{
	value_t value_;
public:
	mach_expr_self_def(std::string option, std::string value, range rng);

	context::dependency_collector get_dependencies(context::dependency_solver& solver) const override;

	virtual value_t evaluate(mach_evaluate_info info) const override;

	virtual void fill_location_counter(context::address addr) override;

	virtual const mach_expression* leftmost_term() const override;

	void collect_diags() const override {}
};

class mach_expr_default : public mach_expression
{
public:
	mach_expr_default(range rng);

	context::dependency_collector get_dependencies(context::dependency_solver& solver) const override;

	virtual value_t evaluate(mach_evaluate_info info) const override;

	virtual void fill_location_counter(context::address addr) override;

	virtual const mach_expression* leftmost_term() const override;

	virtual void collect_diags() const override;
};

}

#endif