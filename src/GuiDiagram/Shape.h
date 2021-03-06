//---------------------------------------------------------------------------------------------------------------------
// Shape.h
//
// Copyright (C) 2018 Carsten Huber (Dipl.-Ing.)
//
// Description  : Declaration of class Shape.
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
#pragma once

#include "DiaShape.h"
#include "IShapeObserver.h"

#include <QBrush>
#include <QFont>
#include <QMenu>
#include <QGraphicsItem>
#include <QPen>

class UmlElement;

class Shape : public QGraphicsItem, public IShapeObserver
{
   ///@cond
   typedef QGraphicsItem super;
   ///@endcond
public: // Constants
   const double KSFMargin = 5.0;           ///< Margin for the selection frame.
   const double KSBSize   = 7.0;           ///< Size (width and height) of the sizing box.
   const double KSBSize2  = KSBSize / 2.0; ///< Half the size of the sizing box.

public: // Constructors
    Shape(QGraphicsItem* parent, DiaShape* shape);
    virtual ~Shape();

public: // Properties
   virtual UmlElement* element() const = 0;
   DiaShape* diaShape() const;
   
   QMenu* contextMenu() const;
   void setContextMenu(QMenu* value);

protected: // Methods
   void savePenStyle();
   void restorePenStyle();
   void aboutToDestroy() override;
   void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;

protected: // Attributes
   DiaShape*    _shape;     ///< DiaShape object associated with this class.
   QBrush       _brush;     ///< Brush to be used for drawing (e.g. the background).
   QFont        _font;      ///< Font to be used for drawing text.
   QPen         _linePen;   ///< Pen to be used for drawing lines.
   QPen         _textPen;   ///< Pen to be used for drawing text.
   Qt::PenStyle _savedLine; ///< Used for temporarily saving the pen style for lines.
   Qt::PenStyle _savedText; ///< Used for temporarily saving the pen style for text.
   
private:
   ///@cond
   QMenu*       _contextMenu;
   ///@endcond
};
