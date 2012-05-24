/*
 Copyright 2012 Tarik Sekmen.

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

#ifndef ILIXI_APPCOMPOSITOR_H_
#define ILIXI_APPCOMPOSITOR_H_

#include "ui/SurfaceView.h"
#include "types/AppInstance.h"
#include <directfb_windows.h>
#include <vector>

namespace ilixi
{
  class Compositor;
  //! Arranges SurfaceView(s) which belong to an Application.
  class AppCompositor : public Widget
  {
    friend class Compositor;
  public:
    AppCompositor(Compositor* compositor, AppInstance* instance,
        Widget* parent = 0);

    virtual
    ~AppCompositor();

    AppInstance*
    instance() const;

    void
    addWindow(IDirectFBWindow* window, bool eventHandling = true);

    void
    removeWindow(DFBWindowID windowID);

    float
    zoomFactor() const;

    void
    setZoomFactor(float zoomFactor);

  protected:
    Compositor* _compositor;
    AppInstance* _instance;

    virtual void
    compose();

  private:
    float _zoomFactor;

    void
    updateAppCompositorGeometry();

    void
    onWindowConfig(DFBWindowID windowID, const SaWManWindowReconfig *reconfig);
  };

} /* namespace ilixi */
#endif /* ILIXI_APPCOMPOSITOR_H_ */
