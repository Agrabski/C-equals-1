/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "tree/ParseTree.h"

using namespace antlr4::tree;

ParseTree::ParseTree() : parent(nullptr)
{
}

antlr4::tree::ParseTree::ParseTree(ParseTree const& copy, ParseTree* parent)
{
	cloneChildrenFrom(parent, &copy);
}

antlr4::tree::ParseTree::ParseTree(ParseTree const& copy) : ParseTree(copy, nullptr)
{
}

bool ParseTree::operator == (const ParseTree& other) const {
	return &other == this;
}

void antlr4::tree::ParseTree::cloneChildrenFrom(not_null< ParseTree*>parent, ParseTree const* copy)
{
	for (auto const& c : copy->children)
		children.push_back(c->clone(this));
	this->parent = parent.get();

}
