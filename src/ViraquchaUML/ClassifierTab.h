//---------------------------------------------------------------------------------------------------------------------
// ClassifierTab.h
//
// Copyright (C) 2018 Carsten Huber (Dipl.-Ing.)
//
// Description  : Declaration of class ClassifierTab.
// Compiles with: MSVC 15.2 (2017) or newer, GNU GCC 5.1 or newer
//
// *******************************************************************************************************************
// *                                                                                                                 *
// * This library is free software; you can redistribute it and/or modify it under the terms of the GNU General      *
// * Public License as published by the Free Software Foundation; either version 3.0 of the License, or (at your     *
// * option) any later version.                                                                                      *
// *                                                                                                                 *
// * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the      *
// * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License     *
// * for more details.                                                                                               *
// *                                                                                                                 *
// * You should have received a copy of the GNU General Public License along with this library; if not, see          *
// * http://www.gnu.org/licenses/gpl                                                                                 *
// *                                                                                                                 *
// *******************************************************************************************************************
//
// See https://github.com/CarstenH71/viraqucha_uml for the latest version of this software.
//---------------------------------------------------------------------------------------------------------------------
#pragma once

#include <QWidget>
#include "ui_ClassifierTab.h"
#include "IPropertiesTab.h"

class UmlClassifier;

class ClassifierTab : public QWidget, public IPropertiesTab
{
   ///@cond
   Q_OBJECT
   typedef QWidget super;
   ///@endcond
public: // Constructors
   ClassifierTab(QWidget*parent, UmlClassifier* elem);
   virtual ~ClassifierTab();

public: // Methods
   bool validateInput() override;
   void applyChanges() override;

private:
   void updateControls();

private: // Attributes
   ///@cond
   Ui::ClassifierTab ui;
   UmlClassifier* _element;
   ///@endcond
};
