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

#ifndef __Value_h__
#define __Value_h__

#include "../Token.h"
#include "../TokenList.h"
#include "ValueException.h"
#include <sstream>
using namespace std;

/**
 * 
 */
class Value {
protected:
  TokenList tokens;
  
public:
  enum Type {NUMBER, PERCENTAGE, DIMENSION, COLOR, STRING} type;
  Value();
  Value(Token* token);
  virtual ~Value();
  
  virtual TokenList* getTokens();
  
  virtual void add(Value* v) =0;
  virtual void substract(Value* v) =0;
  virtual void multiply(Value* v) =0;
  virtual void divide(Value* v) =0;

  static const char* typeToString(Type t);
};

#endif