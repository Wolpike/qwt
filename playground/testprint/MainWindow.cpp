#include "MainWindow.h"
#include <QtWidgets>
#include <QPdfWriter>
#include <qwt_plot_renderer.h>
#include "Plot.h"

MainWindow::MainWindow()
{
    auto central = new QWidget;
    auto lc = new QVBoxLayout;
    QHBoxLayout* lh;
    QPushButton* button;
    lh = new QHBoxLayout;
    button = new QPushButton(tr("Print"));
    connect(button, &QPushButton::clicked, this, &MainWindow::printPlot);
    lh->addWidget(button);
    lc->addLayout(lh);
    m_plot = new Plot;
    lc->addWidget(m_plot);
    central->setLayout(lc);
    setCentralWidget(central);
}

void MainWindow::printPlot()
{
    QwtPlotRenderer renderer;
    QPdfWriter pdf("testprint3.pdf");
    QRectF r, r1, r2, r3, r4;
    pdf.setTitle("TestPrint");
    pdf.setPageOrientation(QPageLayout::Landscape);
    pdf.setPageSize(QPageSize(QPageSize::A1));
    QPainter painter(&pdf);
    r = pdf.pageLayout().fullRectPoints();
    double c = 16.3 / 2;
    r1 = QRectF(0, 0, r.width() * c, r.height() * c);
    r2 = QRectF(r.center().x() * c * 2, 0, r.width() * c, r.height() * c);
    r3 = QRectF(0, r.center().y() * c * 2, r.width() * c, r.height() * c);
    r4 = QRectF(r.center().x() * c * 2, r.center().y() * c * 2, r.width() * c, r.height() * c);
    qDebug() << r;
    renderer.render(m_plot, &painter, r1);
    renderer.render(m_plot, &painter, r2);
    renderer.render(m_plot, &painter, r3);
    renderer.render(m_plot, &painter, r4);
#if 0
    renderer.render(m_plot, &painter, QRectF(0, 0, r.width() * 16.3, r.bottom() * 16.3));
    // renderer.exportTo(m_plot, "testprint.pdf");
    renderer.renderDocument(m_plot, "testprint2.pdf", QSizeF( 640, 480 ));
#endif
}
