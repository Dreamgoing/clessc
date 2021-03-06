/*
 * Copyright 2012 Bram van der Kroef
 *
 * This file is part of LESS CSS Compiler.
 *
 * LESS CSS Compiler is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LESS CSS Compiler is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LESS CSS Compiler.  If not, see <http://www.gnu.org/licenses/>. 
 *
 * Author: Bram van der Kroef <bram@vanderkroef.net>
 */

#ifndef __CssPrettyWriter_h__
#define __CssPrettyWriter_h__

#include "CssWriter.h"
#include <iostream>

class CssPrettyWriter: public CssWriter {
private:
  int indent_size;

protected:
  void indent();
  void newline();

  virtual void writeSelector(const TokenList &selector);
    
public:
  CssPrettyWriter(std::ostream &out): CssWriter(out) {
    indent_size = 0;
  };
  CssPrettyWriter(std::ostream &out, SourceMapWriter &sourcemap):
    CssWriter(out, sourcemap) {
    indent_size = 0;
  }

  virtual void writeAtRule(const Token &keyword, const TokenList &rule);
  virtual void writeRulesetStart(const TokenList &selector);
  virtual void writeRulesetEnd();
  virtual void writeDeclaration(const Token &property, const TokenList &value);
  virtual void writeDeclarationDeliminator();
  virtual void writeMediaQueryStart(const TokenList &selector);
  virtual void writeMediaQueryEnd();
};

#endif
