//---------------------------------------------------------------------------------------------------------------------
// UmlElementFactory.h
//
// Copyright (C) 2017 Carsten Huber (Dipl.-Ing.)
//
// Description  : Declaration of class UmlElementFactory.
// Compiles with: MSVC 15.2 (2017) or newer, GNU GCC 5.1 or newer
//
// *******************************************************************************************************************
// *                                                                                                                 *
// * This file is part of ViraquchaUML.                                                                              *
// *                                                                                                                 *
// * ViraquchaUML is free software; you can redistribute it and/or modify it under the terms of the GNU General      *
// * Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your     *
// * option) any later version.                                                                                      *
// *                                                                                                                 *
// * ViraquchaUML is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the      *
// * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License     *
// * for more details.                                                                                               *
// *                                                                                                                 *
// * You should have received a copy of the GNU General Public License along with ViraquchaUML; if not, see          *
// * http://www.gnu.org/licenses/gpl                                                                                 *
// *                                                                                                                 *
// *******************************************************************************************************************
//
// See https://github.com/CarstenH71/viraqucha_uml for the latest version of this software.
//---------------------------------------------------------------------------------------------------------------------
#include "umlcommon_globals.h"
#include "UmlElement.h"
#include "IElementBuilder.h"

class UMLCOMMON_EXPORT UmlElementFactory final
{
private: // Constructors
   UmlElementFactory();

public:
   /// @cond
   UmlElementFactory(UmlElementFactory const&) = delete;
   void operator=(UmlElementFactory const&) = delete;
   /// @endcond
   virtual ~UmlElementFactory();

public: // Properties
   static UmlElementFactory& instance();

   bool isSubscribed(QString className);
   uint count() const;

public: // Methods
   UmlElement* build(QString className, QUuid identifier);
   void subscribe(QString className, IElementBuilder* builder);

private: // Attributes
   struct Data;
   Data* data;
};