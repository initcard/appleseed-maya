
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2016-2017 Esteban Tovagliari, The appleseedhq Organization
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_MAYA_EXPORTERS_CAMERAEXPORTER_H
#define APPLESEED_MAYA_EXPORTERS_CAMERAEXPORTER_H

// appleseed.maya headers.
#include "appleseedmaya/exporters/dagnodeexporter.h"

// appleseed.renderer headers.
#include "renderer/api/camera.h"

class CameraExporter
  : public DagNodeExporter
{
  public:

    static void registerExporter();

    static DagNodeExporter *create(
      const MDagPath&               path,
      renderer::Project&            project,
      AppleseedSession::SessionMode sessionMode);

    ~CameraExporter();

    virtual void createEntities(const AppleseedSession::Options& options);

    virtual void exportCameraMotionStep(float time);

    virtual void flushEntities();

  private:

    CameraExporter(
      const MDagPath&               path,
      renderer::Project&            project,
      AppleseedSession::SessionMode sessionMode);

    static bool isRenderable(const MDagPath& path);

    AppleseedEntityPtr<renderer::Camera> m_camera;
};

#endif  // !APPLESEED_MAYA_EXPORTERS_CAMERAEXPORTER_H
