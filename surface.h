#ifndef SURFACE_H
#define SURFACE_H

#include <QtDataVisualization/Q3DSurface>
#include <QtDataVisualization/QSurfaceDataProxy>
#include <QtDataVisualization/QHeightMapSurfaceDataProxy>
#include <QtDataVisualization/QSurface3DSeries>
#include "qobjectdefs.h"

#include <QObject>
#include <memory>

using namespace QtDataVisualization;

class Surface : public QObject
{
    Q_OBJECT
public:
    explicit Surface(Q3DSurface* graph);
    ~Surface();

private:
    void createGraph();
    void showGraph();

private:
    Q3DSurface* graph;
    QSurfaceDataProxy* proxy;
    QSurface3DSeries* series;
};

#endif // SURFACE_H
