//---------------------------------------------------------------------------------------------------------------------
// MessageBox.h
//
// Copyright (C) 2017 Carsten Huber (Dipl.-Ing.)
//
// Description  : Declaration of class MessageBox.
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

#include <QMessageBox>
#include <QWidget>

class MessageBox
{
public:
   MessageBox();
   ~MessageBox();

public:
   static int show(QWidget* parent, QString caption, QString text, QMessageBox::Icon icon, QFlags<QMessageBox::StandardButton> buttons, QMessageBox::StandardButton defbtn);
   static void error(QWidget* parent, QString caption, QString text);
   static void info(QWidget* parent, QString caption, QString text);
   static int question(QWidget* parent, QString caption, QString text, QFlags<QMessageBox::StandardButton> buttons, QMessageBox::StandardButton defbtn);
   static void warning(QWidget* parent, QString caption, QString text);
   static int warning(QWidget* parent, QString caption, QString text, QFlags<QMessageBox::StandardButton> buttons, QMessageBox::StandardButton defbtn);
};