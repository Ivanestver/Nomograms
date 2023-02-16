#include "surface.h"
#include <QtDataVisualization/QValue3DAxis>
#include <QtDataVisualization/Q3DTheme>

using namespace QtDataVisualization;

const float minSample = -8.0f;
const float maxSample = 8.0f;
const int sampleCountX = 16;
const int sampleCountZ = 16;
const int a = 5;
const int b = 3;

Surface::Surface(Q3DSurface* graph)
{
    this->graph = graph;
    graph->setAxisX(new QValue3DAxis);
    graph->setAxisY(new QValue3DAxis());
    graph->setAxisZ(new QValue3DAxis());

    proxy = new QSurfaceDataProxy();
    series = new QSurface3DSeries(proxy);
    createGraph();
    showGraph();
}

Surface::~Surface()
{
    delete graph;
}

void Surface::createGraph()
{
    float stepX = (maxSample - minSample) / float(sampleCountX - 1);
    float stepZ = (maxSample - minSample) / float(sampleCountZ - 1);

    auto* dataArray = new QSurfaceDataArray();
    for (int i = 0; i < sampleCountX; i++)
    {
        auto* row = new QSurfaceDataRow(sampleCountX);
        float x = qMin(maxSample, i*stepX + minSample);
        int idx = 0;
        for (int j = 0; j < sampleCountZ; j++)
        {
            float z = qMin(maxSample, j*stepZ + minSample);
            float y = ((x*x)/(a*a) + (z*z)/(b*b))/2;
            (*row)[idx++].setPosition(QVector3D(x, y, z));
        }
        *dataArray << row;
    }
    proxy->resetArray(dataArray);
}

void Surface::showGraph()
{
    series->setDrawMode(QSurface3DSeries::DrawSurfaceAndWireframe);
    series->setFlatShadingEnabled(true);

    graph->axisX()->setLabelFormat("%.2f");
    graph->axisZ()->setLabelFormat("%.2f");
    graph->axisX()->setRange(minSample, maxSample);
    graph->axisY()->setRange(minSample, maxSample);
    graph->axisZ()->setRange(minSample, maxSample);
    graph->axisX()->setLabelAutoRotation(30);
    graph->axisY()->setLabelAutoRotation(90);
    graph->axisZ()->setLabelAutoRotation(30);

    graph->addSeries(series);
}
