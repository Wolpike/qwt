#pragma once

#include <qwt_plot.h>

class QwtPlotGrid;
class QwtPlotCurve;
class QwtPlotMarker;
class QwtPlotCanvas;

class Plot: public QwtPlot
{
    Q_OBJECT
public:
    Plot(QWidget* parent = 0);
private:
    void initAxis(int axis, const QString& title);
private:
    QwtPlotCanvas* m_canvas;
    QwtPlotGrid* m_grid;
    QwtPlotCurve* m_curve;
    QwtPlotCurve* m_curve2;
    // QwtPlotMarker* m_marker;
};
