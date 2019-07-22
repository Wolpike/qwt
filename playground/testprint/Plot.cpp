#include "Plot.h"
#include <cmath>
#include <qwt_plot_curve.h>
#include <qwt_plot_canvas.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_layout.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_zoomer.h>
#include <qwt_legend.h>

namespace {

class CurveData: public QwtArraySeriesData<QPointF>
{
public:
    CurveData()
    {
    }

    QRectF boundingRect() const override
    {
        if ( d_boundingRect.width() < 0.0 )
            d_boundingRect = qwtBoundingRect( *this );

        return d_boundingRect;
    }

    inline void append( const QPointF &point )
    {
        d_samples += point;
    }

    void clear()
    {
        d_samples.clear();
        d_samples.squeeze();
        d_boundingRect = QRectF( 0.0, 0.0, -1.0, -1.0 );
    }
};

} // end of anonymous namespace

Plot::Plot(QWidget* parent):
    QwtPlot(parent)
{
    auto curvesin = new CurveData;
    auto curvecos = new CurveData;
    for(double d = -100.0; d <= 100.0; d += 0.1)
    {
        curvesin->append(QPointF(d, sin(d)));
        curvecos->append(QPointF(d, cos(d) * 2));
    }

    setTitle("Test sin/cos plot");
    setFooter("Sample Footer");
    insertLegend(new QwtLegend, QwtPlot::RightLegend);

    m_canvas = new QwtPlotCanvas;
    // m_canvas->setFrameStyle(QFrame::Box | QFrame::Plain);
    m_canvas->setLineWidth(1);
    m_canvas->setPalette(Qt::white);
    setCanvas(m_canvas);
    // setCanvasBackground(Qt::yellow);

    m_grid = new QwtPlotGrid;
    m_grid->attach(this);

    m_curve = new QwtPlotCurve("sin");
    m_curve->setPen(Qt::blue, 1);
    m_curve->setData(curvesin);
    m_curve->attach(this);
    m_curve->setAxes(QwtPlot::xBottom, QwtPlot::yLeft);

    m_curve2 = new QwtPlotCurve("cos");
    m_curve2->setPen(Qt::green, 1);
    m_curve2->setData(curvecos);
    m_curve2->attach(this);
    m_curve2->setAxes(QwtPlot::xBottom, QwtPlot::yRight);

    initAxis(QwtPlot::yLeft, "left");
    initAxis(QwtPlot::yRight, "right");

    // setAxisTitle(QwtPlot::xBottom, "N");
    // setAxisAutoScale(QwtPlot::xBottom, true);
    // axisScaleEngine(QwtPlot::xBottom)->setAttribute(QwtScaleEngine::Floating,true);
    // setAxisScale(QwtPlot::xBottom, -10, 0.0);
    // setAxisTitle(QwtPlot::yLeft, "Values");
    // setAxisAutoScale(QwtPlot::yLeft, true);
    // axisScaleEngine(QwtPlot::yLeft)->setAttribute(QwtScaleEngine::Floating,true);
    // setAxisScale(QwtPlot::yLeft, -1.0, 1.0);

    // setAxisScale(QwtPlot::xBottom, -100, 100);
    // setAxisScale(QwtPlot::yLeft, -2, 2);
    setAutoReplot(false);
    plotLayout()->setCanvasMargin( 0 );

    // (void) new QwtPlotPanner(m_canvas);
    (void) new QwtPlotMagnifier(m_canvas);
    (void) new QwtPlotZoomer(m_canvas);
}

void Plot::initAxis(int axis, const QString& title)
{
    setAxisTitle(axis, title);
    enableAxis(axis, true);
}
