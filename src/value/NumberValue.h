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

#ifndef __NumberValue_h__
#define __NumberValue_h__

#include "Value.h"
#include "StringValue.h"
#include "UnitValue.h"
#include <vector>
#include <cmath>
class FunctionLibrary;

class NumberValue: public Value {
  static bool isNumber(const Value &val);

  void verifyUnits(const NumberValue &n);
  double convert(const std::string &unit) const;
  
public:
  NumberValue(const Token &token);
  NumberValue(double value);
  NumberValue(double value, Token::Type type,
              const std::string* unit);
  NumberValue(const NumberValue &n);
  virtual ~NumberValue();
  
  virtual Value* add(const Value &v) const;
  virtual Value* substract(const Value &v) const;
  virtual Value* multiply(const Value &v) const;
  virtual Value* divide(const Value &v) const;

  virtual BooleanValue* equals(const Value &v) const;
  virtual BooleanValue* lessThan(const Value &v) const;

  void setType(const NumberValue &n);
  
  std::string getUnit() const;
  void setUnit(std::string unit);
  double getValue() const;
  void setValue(double d);

  static void loadFunctions(FunctionLibrary &lib);
  static Value* unit(const vector<const Value*> &args);
  static Value* ceil(const vector<const Value*> &args);
  static Value* floor(const vector<const Value*> &args);
  static Value* percentage(const vector<const Value*> &args);
  static Value* round(const vector<const Value*> &args);
  static Value* sqrt(const vector<const Value*> &args);
  static Value* abs(const vector<const Value*> &args);
  static Value* sin(const vector<const Value*> &args);
  static Value* asin(const vector<const Value*> &args);
  static Value* cos(const vector<const Value*> &args);
  static Value* acos(const vector<const Value*> &args);
  static Value* tan(const vector<const Value*> &args);
  static Value* atan(const vector<const Value*> &args);
  static Value* pi(const vector<const Value*> &args);
  static Value* pow(const vector<const Value*> &args);
  static Value* mod(const vector<const Value*> &args);
  static Value* convert(const vector<const Value*> &args);
};

#endif
