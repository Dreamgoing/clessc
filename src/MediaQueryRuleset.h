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

#ifndef __MediaQueryRuleset_h__
#define __MediaQueryRuleset_h__

#include "LessRuleset.h"
#include "Stylesheet.h"
#include "Selector.h"
#include <map>
#include <list>


class MediaQueryRuleset: public LessRuleset {
private:
  static const Token BUILTIN_AND;
  
public:
  MediaQueryRuleset();
  virtual ~MediaQueryRuleset();


  virtual void process(Stylesheet &s, Selector* prefix,
                       ProcessingContext &context);
};

#endif
