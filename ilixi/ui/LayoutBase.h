/*
 Copyright 2010, 2011 Tarik Sekmen.

 All Rights Reserved.

 Written by Tarik Sekmen <tarik@ilixi.org>.

 This file is part of ilixi.

 ilixi is free software: you can redistribute it and/or modify
 it under the terms of the GNU Lesser General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 ilixi is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public License
 along with ilixi.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ILIXI_LAYOUT_H_
#define ILIXI_LAYOUT_H_

#include "types/Margin.h"
#include "ui/Widget.h"
#include "types/RadioGroup.h"

namespace ilixi
{
  //! This base class provides an absolute layout.
  /*!
   * Each container stores its child widgets inside a layout. A layout's responsibility
   * is to set the geometry of child widgets and arrange them inside its canvas.
   */
  class LayoutBase : public Widget
  {
    friend class ContainerBase;
  public:
    /*!
     * Constructor.
     */
    LayoutBase(Widget* parent = 0);

    /*!
     * Destructor.
     */
    virtual
    ~LayoutBase();

    /*!
     * Returns a height which satisfies all widgets.
     */
    virtual int
    heightForWidth(int width) const;

    /*!
     * Returns a size which holds all widgets.
     */
    virtual Size
    preferredSize() const;

    /*!
     * Returns number of widgets inside this layout.
     */
    unsigned int
    count() const;

    /*!
     * Returns spacing between widgets.
     */
    unsigned int
    spacing() const;

    /*!
     * Sets spacing between widgets.
     */
    void
    setSpacing(unsigned int spacing);

    /*!
     * Adds a new widget to this layout. Widget is owned by layout.
     *
     * Returns true if successful.
     */
    virtual bool
    addWidget(Widget* widget);

    /*!
     * Aligns widgets inside layout.
     *
     * You should reimplement this method in your layout classes.
     */
    virtual void
    tile();

    /*!
     * Invalidates layout and notifies parent.
     */
    virtual void
    doLayout();

    /*!
     * Tiles if modified and paints children.
     */
    virtual void
    paint(const Rectangle& targetArea);

  protected:
    //! This flag specifies whether layout is modified since latest tiling operation.
    bool _modified;
    //! This property holds spacing between widgets inside the layout.
    unsigned int _spacing;

    struct LayoutElement
    {
      Widget* widget;
      Size size;
    };

    typedef std::list<LayoutElement> ElementList;

    /*!
     * Does nothing.
     */
    void
    compose();

  private:
    RadioGroup* _group;

    /*!
     * If pointer event occurs over widget handle it and return true.
     *
     * @param pointerEvent Reference to pointer event coming from parent widget.
     * @return True if event is consumed.
     */
    bool
    consumePointerEvent(const PointerEvent& pointerEvent);

    void
    updateChildrenFrameGeometry();
  };

}
#endif /* ILIXI_LAYOUT_H_ */
